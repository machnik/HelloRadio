#ifndef STREAMPLAYERJS_H
#define STREAMPLAYERJS_H

#include "player.h"
#include "javascript.h"

class StreamPlayerJs : public Player {

    Q_OBJECT

public:
    explicit StreamPlayerJs(QObject *parent, JavaScript & js);

    virtual void playPause() override;
    virtual void stop() override;
    virtual void setVolume(int volume, bool immediately = true) override;

private:

    JavaScript & m_js;
    bool m_initialized = false;
};

#endif // STREAMPLAYERJS_H
