#ifndef ARMEE_HPP
#define ARMEE_HPP

#include "unit.hpp"

#include <QDataStream>

class Armee
{
public:

    typedef QList<Unit> type_liste_unit;
    Armee(QString nom = QString());

    QString nom() const;

    const type_liste_unit& hqs() const;
    const type_liste_unit& elites() const;
    const type_liste_unit& troops() const;
    const type_liste_unit& fastAttacks() const;
    const type_liste_unit& heavySupports() const;

    void addHq(const Unit& hq);
    void addElite(const Unit& elite);
    void addTroop(const Unit& troop);
    void addFastAttack(const Unit& fastAttack);
    void addHeavySupport(const Unit& heavySupport);

    friend QDataStream& operator<<(QDataStream& flux, const Armee& armee);
    friend QDataStream& operator>>(QDataStream& flux, Armee& armee);

    bool operator==(const Armee& a) const;

    struct SetComparator : public std::binary_function<const Armee&, const Armee&, bool>
    {
        bool operator()(const Armee& a1, const Armee& a2) const;
    };

private:
    QString m_nom;

    type_liste_unit m_hqs;
    type_liste_unit m_elites;
    type_liste_unit m_troops;
    type_liste_unit m_fastAttacks;
    type_liste_unit m_heavySupports;

};

#endif // ARMEE_HPP
