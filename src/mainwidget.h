#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include "javascript.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class StreamPlayerJs;
class QPushButton;

class MainWidget : public QWidget {

    Q_OBJECT

public:
    MainWidget(QWidget * parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget * ui = nullptr;
    JavaScript m_js;

    StreamPlayerJs * m_streamPlayerJs = nullptr;

    std::array<QPushButton*, 15> m_stationButtons;

    bool m_nowPlaying = false;

private slots:
    void play();
    void volume(int value);
    void urlChanged(QString url);
    void toggleJsConsole();
    void javaScriptChanged();
    void runJavaScript();
    void setPresetStation();
    void setCustomStation();
    void aboutQtInfo();
    void setUIStyle();
};
#endif // MAINWIDGET_H
