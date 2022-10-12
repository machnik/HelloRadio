#ifndef STATIONS_H
#define STATIONS_H

#include <QString>
#include <map>

std::map<QString, std::tuple<QString, QString, int>> stations {

    {"RMF FM", {"https://rs6-krk2.rmfstream.pl/RMFFM48", "AAC", 48}},
    {"RMF Classic", {"https://rs9-krk2.rmfstream.pl/RMFCLASSIC48", "AAC", 48}},
    {"RMF MAXXX", {"https://rs202-krk.rmfstream.pl/HOPBEC", "AAC", 48}},
    {"Radio ZET", {"https://r.dcs.redcdn.pl/sc/o2/Eurozet/live/audio.livx?audio=5", "MP3", 128}},
    {"Radio 357", {"https://stream.rcs.revma.com/ye5kghkgcm0uv", "AAC", 128}},
    {"Radio Park FM", {"https://sluchaj2.radiopark.biz.pl:8443/stream", "MP3", 128}},
    {"Open FM Impreza", {"https://stream.open.fm/2", "AAC", 48}},
    {"Nowy Świat", {"https://stream.rcs.revma.com/ypqt40u0x1zuv", "MP3", 128}},
    {"Złote Przeboje", {"https://radiostream.pl/tuba9-1.mp3", "MP3", 128}},
    {"VOX FM", {"https://r.dcs.redcdn.pl/sc/o2/Eurozet/live/audio.livx?audio=5", "MP3", 128}},
    {"Radio Pogoda", {"https://pl-play.adtonos.com/radio-pogoda", "MP3", 128}},
    {"Meloradio", {"https://r.dcs.redcdn.pl/sc/o2/Eurozet/live/meloradio.livx?audio=5", "MP3", 128}},
    {"Muzo FM", {"https://stream.rcs.revma.com/1nnezw8qz7zuv", "MP3", 128}},
    {"Antyradio", {"https://n-22-12.dcs.redcdn.pl/sc/o2/Eurozet/live/antyradio.livx", "AAC", 128}},
    {"Rock Radio", {"https://pl-play.adtonos.com/rock-radio", "MP3", 128}},
    {"CINEMIX", {"https://kathy.torontocast.com:1825/stream", "MP3", 128}},
    {"ABC Lounge", {"https://listen.openstream.co/4457/audio", "MP3", 128}},
    {"Latina Radio", {"https://start-latina.ice.infomaniak.ch/start-latina-high.mp3", "MP3", 192}},
    {"Open FM Film", {"https://stream.open.fm/38", "AAC", 48}},
    {"TOK FM", {"https://radiostream.pl/tuba10-1.mp3", "MP3", 128}}
};

#endif // STATIONS_H
