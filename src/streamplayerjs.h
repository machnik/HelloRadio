#ifndef STREAMPLAYERJS_H
#define STREAMPLAYERJS_H

#include "player.h"
#include "javascript.h"

class StreamPlayerJs : public Player {

    Q_OBJECT

public:
    explicit StreamPlayerJs(QObject *parent, JavaScript & js);

    virtual void playPause();
    virtual void stop();
    virtual void setVolume(int volume);

private:
    JavaScript & m_js;
};

#endif // STREAMPLAYERJS_H
