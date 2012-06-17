#include "armee.hpp"

Armee::Armee(QString nom)
{
    m_nom = nom;
}

QString Armee::nom() const
{
    return m_nom;
}

const Armee::type_liste_unit& Armee::hqs() const
{
    return m_hqs;
}

const Armee::type_liste_unit& Armee::elites() const
{
    return m_elites;
}

const Armee::type_liste_unit& Armee::troops() const
{
    return m_troops;
}

const Armee::type_liste_unit& Armee::fastAttacks() const
{
    return m_fastAttacks;
}

const Armee::type_liste_unit& Armee::heavySupports() const
{
    return m_heavySupports;
}

void Armee::addHq(const Unit& hq)
{
    m_hqs << hq;
}

void Armee::addElite(const Unit& elite)
{
    m_elites << elite;
}

void Armee::addTroop(const Unit& troop)
{
    m_troops << troop;
}

void Armee::addFastAttack(const Unit& fastAttack)
{
    m_fastAttacks << fastAttack;
}

void Armee::addHeavySupport(const Unit& heavySupport)
{
    m_heavySupports << heavySupport;
}

QDataStream& operator<<(QDataStream& flux, const Armee& armee)
{
    flux << armee;
    return flux;
}

QDataStream& operator>>(QDataStream& flux, Armee& armee)
{
    flux >> armee;
    return flux;
}

bool Armee::operator==(const Armee& a) const
{
    return m_nom == a.m_nom;
}


bool Armee::SetComparator::operator()(const Armee& a1, const Armee& a2) const
{
    return a1.m_nom < a2.m_nom;
}
