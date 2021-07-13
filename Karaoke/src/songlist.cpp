#include "songlist.h"
#include <QVariant>
#include "datawork.h"
#include <QDebug>
#include <algorithm>
using namespace std;

SongList::SongList(QObject* parent) : QAbstractListModel(parent), m_songs()
{

}

QHash<int, QByteArray> SongList::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[CountryRole] = "country";
    roles[BandRole] = "band";
    roles[SongnameRole] = "songname";
    roles[TotalviewRole] = "totalview";
    return roles;
}

QVariant SongList::data(const QModelIndex &index, int role) const {
    if(!index.isValid())
        return QVariant();
    switch(role) {
    case CountryRole:
        return QVariant(m_songs[index.row()].country);
    case BandRole:
        return QVariant(m_songs[index.row()].band);
    case SongnameRole:
        return QVariant(m_songs[index.row()].songname);
    case TotalviewRole:
        return QVariant(m_songs[index.row()].totalview);
    default:
        return QVariant();
    }
}

void SongList::readList() {
    beginResetModel();
    m_songs = DataWork::readData();
    endResetModel();
}

void SongList::storeList(){
    DataWork::storeData(m_songs);
}

void SongList::getSongList(QString language, QString band){
    QList<Song> tmp = DataWork::readData();
    beginResetModel();
    m_songs.clear();
    for (auto it = tmp.begin(); it != tmp.end(); ++it)
        if(it->country==language&&it->band==band)
            m_songs.append(*it);
    endResetModel();
}

bool cmp(const Song& s1,const Song& s2){
    return s1.totalview < s2.totalview;
}

void SongList::sortList(){
    beginResetModel();
    std::sort(m_songs.begin(),m_songs.end(), [](const Song& s1, const Song& s2)
    {
        return s1.totalview < s2.totalview;
    });
    endResetModel();
}

void SongList::findelemList(QString singer, QString song, QString language, qint8 id)
{
    for (auto i = m_songs.begin(); i != m_songs.end(); ++i)
        if (i->band == singer && i->country == language && i->songname == song && i->totalview == id)
        {
            i->totalview+=1;
            break;
        }
}
