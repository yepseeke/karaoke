#include "song.h"

Song::Song(QString singer, QString song, QString language, qint8 id)
{
    this->country = language;
    this->band = singer;
    this->songname = song;
    this->totalview = id;
}
