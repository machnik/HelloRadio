#include "javascript.h"

#ifdef Q_OS_WASM
    #include <emscripten.h>
#else
    #include <QMessageBox>
#endif

JavaScript::JavaScript(QObject *parent) : QObject{parent} {}

void JavaScript::run(const QString & code) {

#ifdef Q_OS_WASM
    emscripten_run_script(code.toLatin1());
#else
    QMessageBox msgBox;
    msgBox.setText("Not running in WASM!");
    msgBox.exec();
#endif

}
