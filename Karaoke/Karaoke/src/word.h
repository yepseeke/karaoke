#ifndef WORD_H
#define WORD_H

#include <QString>

class Word
{
    qreal _begin;
    QString _word;
    bool _flag = false;
public:
    Word(qreal, QString);
    void set_flag(bool);
};

#endif // WORD_H
