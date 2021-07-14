#ifndef FILTR_H
#define FILTR_H

#include <QAbstractListModel>
#include <QList>
#include "song.h"
#include "songlist.h"


class Filtr : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Filtr(QObject *parent = nullptr);

    enum FiltrRoles {
        ElemRole = Qt::UserRole + 1,
        KeyRole
    };
    virtual int rowCount(const QModelIndex&) const { return m_elements.size(); }
    virtual QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void setKey(QString cur){key = cur;}
    Q_INVOKABLE QString getKey(){return key;}
    Q_INVOKABLE void getLanguages(QString);
    Q_INVOKABLE void getBands(QString, QString);
    Q_INVOKABLE void readText(QString);
private:
    QList<QString> m_elements;
    QString key;
};

#endif // FILTR_H
