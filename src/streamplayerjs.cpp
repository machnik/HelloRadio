#include "streamplayerjs.h"

StreamPlayerJs::StreamPlayerJs(QObject *parent, JavaScript & js) : Player{parent}, m_js{js} {}

void StreamPlayerJs::playPause() {

    auto code = QString {                                                       "\
        var AudioContext = window.AudioContext || window.webkitAudioContext;     \
        const context = new AudioContext();                                      \
                                                                                 \
        globalThis.audio = new Audio();                                          \
        globalThis.audio.crossOrigin = 'anonymous';                              \
                                                                                 \
        const sourceAudio = context.createMediaElementSource(globalThis.audio);  \
        sourceAudio.connect(context.destination);                                \
                                                                                 \
        const playHandler = () => {                                              \
            globalThis.audio.play();                                             \
            globalThis.audio.removeEventListener('canplaythrough', playHandler); \
        };                                                                       \
                                                                                 \
        const errorHandler = e => {                                              \
            console.error('Error', e);                                           \
            globalThis.audio.removeEventListener('error', errorHandler);         \
        };                                                                       \
                                                                                 \
        globalThis.audio.addEventListener('canplaythrough', playHandler, false); \
        globalThis.audio.addEventListener('error', errorHandler);                \
                                                                                 \
        globalThis.audio.src = '%1';                                             \
        globalThis.audio.volume = '%2';                                          \
        globalThis.audio.play();                                                 \
    "}.arg(m_source).arg(QString::number(m_volume/100.));

    m_js.run(code);
}

void StreamPlayerJs::stop() {
    m_js.run("globalThis.audio.pause()");
}

void StreamPlayerJs::setVolume(int volume) {
    m_volume = volume;
    m_js.run(QString {"globalThis.audio.volume = "} + QString::number(volume/100.) + ";");
}
