#ifndef SONGLIST_H
#define SONGLIST_H

#include <QAbstractListModel>
#include <QList>
#include "song.h"


class SongList : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SongList(QObject *parent = nullptr);

    enum SongRoles {
        LanguageRole = Qt::UserRole + 1,
        SingerRole,
        SongRole,
        IdRole,
        TotalviewRole,
        KeyRole
    };
    virtual int rowCount(const QModelIndex&) const { return m_songs.size(); }
    virtual QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void setKey(qint64 _key) {key = _key;}
    Q_INVOKABLE qint64 getKey() {return key;}
    Q_INVOKABLE void setSing(QString cur) {sing = cur;}
    Q_INVOKABLE QString getSing(QString cur) {return sing;}
    friend bool cmp(Song s1, Song s2);
    Q_INVOKABLE void sortList();
    void addSong(QString language, QString singer, QString song, qint64 id, qint64 totalview );
    Q_INVOKABLE void readList(QString);
    Q_INVOKABLE void storeList();
    Q_INVOKABLE void getSongList(QString, QString, QString);
    Q_INVOKABLE void findaddelemandplusplusList(QString language, QString singer, QString song, qint64 id);
private:
    QList<Song> m_songs;
    qint64 key;
    QString sing;
};

#endif // SONGLIST_H
