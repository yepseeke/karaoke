#include "word.h"

Word::Word(qreal begin, QString word)
{
    _begin = begin;
    _word = word;
}

void Word::set_flag(bool f)
{
    _flag = f;
}


