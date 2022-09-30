#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QMessageBox>

#include "streamplayerjs.h"
#include "stations.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainWidget) {

    ui->setupUi(this);

    ui->jsConsoleGB->setVisible(ui->jsConsolePB->isChecked());

    showFullScreen();

    m_streamPlayerJs = new StreamPlayerJs{this, m_js};

    m_stationButtons = {
        ui->num1PB, ui->num2PB, ui->num3PB, ui->num4PB, ui->num5PB, ui->num6PB,
        ui->num7PB, ui->num8PB, ui->num9PB, ui->num10PB, ui->num11PB, ui->num12PB,
        ui->num13PB, ui->num14PB, ui->num15PB
    };

    for (size_t i=0; i<stations.size(); ++i) {
        m_stationButtons[i]->setText(std::get<0>(stations[i]));
        m_stationButtons[i]->setToolTip(std::get<1>(stations[i]));
    }

    ui->playPB->setIconSize({96,96});
}

MainWidget::~MainWidget() {
    delete ui;
}

void MainWidget::play() {

    m_nowPlaying = ui->playPB->isChecked();

    if (m_nowPlaying) {
        m_streamPlayerJs->setSource(ui->urlLE->text());
        m_streamPlayerJs->playPause();

    } else {
        m_streamPlayerJs->stop();
    }
}

void MainWidget::volume(int value) {
    m_streamPlayerJs->setVolume(value);
    ui->volumeLCD->display(value);
}

void MainWidget::urlChanged(QString url) {
    ui->playPB->setEnabled(!url.isEmpty());
}

void MainWidget::toggleJsConsole() {
    ui->jsConsoleGB->setVisible(ui->jsConsolePB->isChecked());
}

void MainWidget::javaScriptChanged() {
    ui->runJsPB->setDisabled(ui->jsPTE->toPlainText().isEmpty());
}

void MainWidget::runJavaScript() {
    m_js.run(ui->jsPTE->toPlainText());
}

void MainWidget::setPresetStation() {

    ui->urlLE->setEnabled(false);

    for (const auto button : m_stationButtons) {
        if (button->isChecked()) {

            const QString & url { button->toolTip() };

            ui->urlLE->setText(url);

            if (m_nowPlaying) {
                m_streamPlayerJs->stop();
                play();
            }

            return;
        }
    }
}

void MainWidget::setCustomStation() {

    ui->urlLE->setEnabled(true);

    if (m_nowPlaying) m_streamPlayerJs->stop();

    ui->playPB->setChecked(false);
}

void MainWidget::aboutQtInfo() {

    QMessageBox::aboutQt(this);
}

