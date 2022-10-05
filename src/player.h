#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject {

    Q_OBJECT

public:
    explicit Player(QObject *parent = nullptr);
    void setSource(const QString & source);
    const QString & source();

    virtual void playPause() = 0;
    virtual void stop() = 0;
    virtual void setVolume(int volume, bool immediately) = 0;

protected:
    QString m_source;
    int m_volume = 80;
};

#endif // PLAYER_H
