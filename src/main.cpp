#include "mainwidget.h"

#include <QApplication>
#include <QFile>

void loadApplicationStylesheet(QApplication &);

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    loadApplicationStylesheet(app);

    MainWidget w;
    w.show();
    return app.exec();
}

void loadApplicationStylesheet(QApplication & app) {

    QFile stylesheetFile { ":visual/stylesheet.qss" };

    if (stylesheetFile.open(QFile::ReadOnly | QFile::Text)) {

        QString styleSheet;

        styleSheet += "QWidget { font-size: 20px; }\n";

        QTextStream ts { &stylesheetFile };
        styleSheet += ts.readAll();

        app.setStyleSheet(styleSheet);
    }
}
