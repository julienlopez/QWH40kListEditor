#ifndef UNIT_HPP
#define UNIT_HPP

#include "profile.hpp"

#include <QString>

class Unit : public Profile
{
public:
    Unit(QString nom, quint8 min, quint8 max, quint8 cost);

    QString nom() const;
    quint8 max() const;
    quint8 min() const;
    quint8 cost() const;

private:
    QString m_nom;
    quint8 m_max;
    quint8 m_min;
    quint8 m_cost;
};

#endif // UNIT_HPP
