#ifndef STATIONS_H
#define STATIONS_H

#include <QString>
#include <array>

using Station = std::tuple<const char*, const char*>;

static constexpr std::array stations {
    Station {"RMF FM", "https://rs6-krk2.rmfstream.pl/RMFFM48"},
    Station {"RMF Classic", "https://rs9-krk2.rmfstream.pl/RMFCLASSIC48"},
    Station {"RMF MAXXX", "https://rs202-krk.rmfstream.pl/HOPBEC"},
    Station {"Radio ZET", "https://r.dcs.redcdn.pl/sc/o2/Eurozet/live/audio.livx?audio=5"},
    Station {"Radio 357", "https://stream.rcs.revma.com/ye5kghkgcm0uv"},
    Station {"Radio Park FM", "https://sluchaj2.radiopark.biz.pl:8443/stream"},
    Station {"Open FM Impreza", "https://stream.open.fm/2"},
    Station {"Radio Nowy Świat", "https://stream.rcs.revma.com/ypqt40u0x1zuv"},
    Station {"Radio Złote Przeboje", "https://radiostream.pl/tuba9-1.mp3"},
    Station {"VOX FM", "https://r.dcs.redcdn.pl/sc/o2/Eurozet/live/audio.livx?audio=5"},
    Station {"Radio Pogoda", "https://pl-play.adtonos.com/radio-pogoda"},
    Station {"Meloradio", "https://r.dcs.redcdn.pl/sc/o2/Eurozet/live/meloradio.livx?audio=5"},
    Station {"Muzo FM", "https://stream.rcs.revma.com/1nnezw8qz7zuv"},
    Station {"Antyradio", "https://n-22-12.dcs.redcdn.pl/sc/o2/Eurozet/live/antyradio.livx"},
    Station {"Rock Radio", "https://pl-play.adtonos.com/rock-radio"}
};

#endif // STATIONS_H
