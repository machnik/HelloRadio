#include "mainwidget.h"

#include <QApplication>
#include <QFile>

void loadApplicationStylesheet(QApplication &);

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    MainWidget w;
    w.show();
    return app.exec();
}
