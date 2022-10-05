#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QMessageBox>
#include <QStyleFactory>

#include "streamplayerjs.h"
#include "stations.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidget)
{

    ui->setupUi(this);

    m_stationButtons = {
        ui->num1PB, ui->num2PB, ui->num3PB, ui->num4PB, ui->num5PB,
        ui->num6PB, ui->num7PB, ui->num8PB, ui->num9PB, ui->num10PB,
        ui->num11PB, ui->num12PB, ui->num13PB, ui->num14PB, ui->num15PB
    };

    ui->jsConsoleGB->setVisible(ui->jsConsolePB->isChecked());

    showFullScreen();

    m_streamPlayerJs = new StreamPlayerJs{this, m_js};

    int i = 0;

    for (const auto & station : stations) {
        m_stationButtons[i]->setText(station.first);
        m_stationButtons[i++]->setToolTip(QString{"URL: "} + std::get<0>(station.second));
    }

    ui->playPB->setIconSize({96,96});

    m_stationButtons[0]->click();
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
    ui->volumeLCD->display(value);
    m_streamPlayerJs->setVolume(value, m_nowPlaying);
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

    for (auto button : m_stationButtons) {
        if (button->isChecked()) {

            ui->urlLE->setText(std::get<0>(stations[button->text()]));
            ui->encTE->setText(std::get<1>(stations[button->text()]));
            ui->bitrateLCD->display(std::get<2>(stations[button->text()]));

            if (m_nowPlaying) {
                m_streamPlayerJs->stop();
                play();
            }

            return;
        }
    }
}

void MainWidget::setCustomStation() {

    ui->encTE->setText("---");
    ui->bitrateLCD->display("---");

    ui->urlLE->setEnabled(true);

    if (m_nowPlaying) m_streamPlayerJs->stop();

    ui->playPB->setChecked(false);
}

void MainWidget::aboutQtInfo() {

    QMessageBox::aboutQt(this);
}

void MainWidget::setUIStyle() {

    QApplication::setStyle(
        QStyleFactory::create(
            ui->fusionRB->isChecked() ? "Fusion" : "Windows"));
}

