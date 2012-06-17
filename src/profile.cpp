#include "profile.hpp"

Profile::Profile()
{}

quint8 Profile::ws() const
{
    return m_stats[WS];
}

quint8 Profile::bs() const
{
    return m_stats[BS];
}

quint8 Profile::s() const
{
    return m_stats[S];
}

quint8 Profile::t() const
{
    return m_stats[T];
}

quint8 Profile::w() const
{
    return m_stats[W];
}

quint8 Profile::i() const
{
    return m_stats[I];
}

quint8 Profile::a() const
{
    return m_stats[A];
}

quint8 Profile::ld() const
{
    return m_stats[LD];
}

quint8 Profile::sv() const
{
    return m_stats[SV];
}

void Profile::setWs(quint8 ws)
{
    m_stats[WS] = ws;
}

void Profile::setBs(quint8 bs)
{
    m_stats[BS] = bs;
}

void Profile::setS(quint8 s)
{
    m_stats[S] = s;
}

void Profile::setT(quint8 t)
{
    m_stats[T] = t;
}

void Profile::setW(quint8 w)
{
    m_stats[W] = w;
}

void Profile::setI(quint8 i)
{
    m_stats[I] = i;
}

void Profile::setA(quint8 a)
{
    m_stats[A] = a;
}

void Profile::setLd(quint8 ld)
{
    m_stats[LD] = ld;
}

void Profile::setSv(quint8 sv)
{
    m_stats[SV] = sv;
}
