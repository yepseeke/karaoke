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
    roles[LanguageRole] = "language";
    roles[SingerRole] = "singer";
    roles[SongRole] = "song";
    roles[IdRole] = "id";
    roles[TotalviewRole] = "totalview";
    roles[KeyRole] = "key";
    return roles;
}

QVariant SongList::data(const QModelIndex &index, int role) const {
    if(!index.isValid())
        return QVariant();
    switch(role) {
    case LanguageRole:
        return QVariant(m_songs[index.row()].language);
    case SingerRole:
        return QVariant(m_songs[index.row()].singer);
    case SongRole:
        return QVariant(m_songs[index.row()].song);
    case IdRole:
        return QVariant(m_songs[index.row()].id);
    case TotalviewRole:
        return QVariant(m_songs[index.row()].totalview);
    case KeyRole:
        return QVariant(key);
    default:
        return QVariant();
    }
}

void SongList::readList(QString path) {
    beginResetModel();
    m_songs = DataWork::readData(path);
    endResetModel();
}

void SongList::storeList(){
    DataWork::storeData(m_songs);
}

void SongList::getSongList(QString path, QString language, QString singer){
    QList<Song> tmp = DataWork::readData(path);
    beginResetModel();
    m_songs.clear();
    for (auto it = tmp.begin(); it != tmp.end(); ++it)
        if(it->language==language&&it->singer==singer)
            m_songs.append(*it);
    endResetModel();
}

bool cmp(Song s1, Song s2){
    return s1.totalview < s2.totalview;
}

void SongList::sortList(){
    beginResetModel();
    for(auto i = m_songs.begin();i!=m_songs.end();++i)
        for(auto j = m_songs.begin();j!=m_songs.end();++j)
            if(i->totalview>j->totalview)
                swap(*i,*j);
    endResetModel();
}

void SongList::addSong(QString language, QString singer, QString song, qint64 id, qint64 totalview ){
    auto songsSize = m_songs.size();
        beginInsertRows(QModelIndex(), songsSize, songsSize);
        m_songs.append(Song(language, singer, song, id, totalview));
        endInsertRows();
}

void SongList::findaddelemandplusplusList(QString language, QString singer, QString song, qint64 id){
    for(auto i = m_songs.begin();i!=m_songs.end();++i)
        if(i->id == id){
            i->totalview+=1;
            return;
        }
    addSong(language, singer, song, id, 1);
}
