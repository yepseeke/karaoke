#include <algorithm>
#include <QVariant>
#include <QDebug>
#include <QFile>
#include "datawork.h"
#include "filtr.h"

Filtr::Filtr(QObject* parent) : QAbstractListModel(parent), m_elements()
{

}

QHash<int, QByteArray> Filtr::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[ElemRole] = "element";
    roles[KeyRole] = "key";
    return roles;
}

QVariant Filtr::data(const QModelIndex &index, int role) const {
    if(!index.isValid())
        return QVariant();
    switch(role) {
    case ElemRole:
        return QVariant(m_elements[index.row()]);
    case KeyRole:
        return QVariant(key);
    default:
        return QVariant();
    }
}
void Filtr::getLanguages(QString path) {
    QList<Song> cur = DataWork::readData(path);
    beginResetModel();
    for (auto it = cur.begin(); it != cur.end(); ++it)
        m_elements.append(it->language);
    m_elements.removeDuplicates();
    endResetModel();
}

void Filtr::getBands(QString path, QString language){
    QList<Song> cur = DataWork::readData(path);
    beginResetModel();
    m_elements.clear();
    for (auto it = cur.begin(); it != cur.end(); ++it)
        if(it->language==language)
            m_elements.append(it->singer);
    m_elements.removeDuplicates();
    endResetModel();
}

void Filtr::readText(QString path){
    QFile file(path);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
            m_elements.append(file.readLine());
        }
        file.close();
    }
}
