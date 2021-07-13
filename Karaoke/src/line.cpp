#include "line.h"

Line::Line(qreal start, qreal finish, QList<Word> lines)
{
    _start = start;
    _finish = finish;
    for (auto it = lines.begin(); it != lines.end(); ++it)
        m_lines.append(*it);
}
