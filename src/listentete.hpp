#ifndef LISTENTETE_HPP
#define LISTENTETE_HPP

#include <QString>

class ListEnTete
{
public:
    ListEnTete(QString nom);

    QString nom() const;

    bool operator==(const ListEnTete& l) const;

private:
    QString m_nom;
};

#endif // LISTENTETE_HPP
