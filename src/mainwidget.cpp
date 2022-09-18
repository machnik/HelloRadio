#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QMessageBox>

#include "streamplayerjs.h"

#include <array>

static const std::array stations {
    std::pair {"Megaton Cafe Radio", "http://us2.internet-radio.com:8443/stream"},
    std::pair {"Radio Estilo Leblon", "http://us4.internet-radio.com:8193/stream"},
    std::pair {"Motown Magic Oldies", "http://airspectrum.cdnstream1.com:8024/1302_192"},
    std::pair {"Venice Classic Radio Auditorium", "http://116.202.241.212:8010/stream"},
    std::pair {"Angel Radio", "http://94.75.227.133:7030/stream"},
    std::pair {"Dance UK Radio", "http://uk2.internet-radio.com:8024/stream"},
    std::pair {"Jazz Central", "http://149.255.59.3:8027/stream"},
    std::pair {"Urban Radio", "http://us1.internet-radio.com:8242/stream"},
    std::pair {"Italy Classical Radio", "http://philae.shoutca.st:8204/stream"}
};

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainWidget) {

    ui->setupUi(this);

    ui->jsConsoleGB->setVisible(ui->jsConsolePB->isChecked());

    showFullScreen();

    m_streamPlayerJs = new StreamPlayerJs{this, m_js};

    m_stationButtons = {
        ui->num1PB, ui->num2PB, ui->num3PB, ui->num4PB, ui->num5PB, ui->num6PB,
        ui->num7PB, ui->num8PB, ui->num9PB
    };

    for (size_t i=0; i<stations.size(); ++i) {
        m_stationButtons[i]->setText(stations[i].first);
        m_stationButtons[i]->setToolTip(stations[i].second);
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

