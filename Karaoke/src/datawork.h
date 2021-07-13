#ifndef DATAWORK_H
#define DATAWORK_H

#include <QList>
#include <QString>
#include "song.h"

namespace DataWork {
    QList<Song> readData();
    void storeData(QList<Song> &songs);
};

#endif // DATAWORK_H
