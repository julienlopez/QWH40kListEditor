#include "listentete.hpp"

ListEnTete::ListEnTete(QString nom)
{
    m_nom = nom;
}

QString ListEnTete::nom() const
{
    return m_nom;
}

bool ListEnTete::operator==(const ListEnTete& l) const
{
    return m_nom == l.m_nom;
}
