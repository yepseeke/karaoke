#ifndef LINE_H
#define LINE_H

#include <QList>
#include "word.h"

class Line
{
private:
    qreal _start, _finish;
    QList<Word> m_lines;
public:
    Line(qreal, qreal, QList<Word>);
};

#endif // LINE_H
