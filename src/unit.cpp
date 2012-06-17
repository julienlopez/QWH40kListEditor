#include "unit.hpp"

Unit::Unit(QString nom, quint8 min, quint8 max, quint8 cost)
{
    m_nom = nom;
    m_max = max;
    m_min = min;
    m_cost = cost;
}

QString Unit::nom() const
{
    return m_nom;
}

quint8 Unit::max() const
{
    return m_max;
}

quint8 Unit::min() const
{
    return m_min;
}

quint8 Unit::cost() const
{
    return m_cost;
}
