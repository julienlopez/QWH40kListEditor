#ifndef LIST_HPP
#define LIST_HPP

#include "listentete.hpp"

class List : public ListEnTete
{
public:
    List(QString nom);

    bool estModifiee() const;

private:
    ListEnTete m_saveState;
};

#endif // LIST_HPP
