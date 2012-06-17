#include "list.hpp"

List::List(QString nom): ListEnTete(nom), m_saveState(nom)
{

    m_saveState = *this;
}

bool List::estModifiee() const
{
    return (*this) == m_saveState;
}

