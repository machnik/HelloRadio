#ifndef JAVASCRIPT_H
#define JAVASCRIPT_H

#include <QObject>

class JavaScript : public QObject {

    Q_OBJECT

public:
    explicit JavaScript(QObject *parent = nullptr);

    void run(const QString & code);
};

#endif // JAVASCRIPT_H
