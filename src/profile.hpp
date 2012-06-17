#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <QtGlobal>

class Profile
{
public:
    Profile();

    enum STAT{WS=0,BS,S,T,W,I,A,LD,SV};

    quint8 ws() const;
    quint8 bs() const;
    quint8 s() const;
    quint8 t() const;
    quint8 w() const;
    quint8 i() const;
    quint8 a() const;
    quint8 ld() const;
    quint8 sv() const;

    void setWs(quint8 ws);
    void setBs(quint8 bs);
    void setS(quint8 s);
    void setT(quint8 t);
    void setW(quint8 w);
    void setI(quint8 i);
    void setA(quint8 a);
    void setLd(quint8 ld);
    void setSv(quint8 sv);

    void setAttributes(quint8 ws, quint8 bs, quint8 s, quint8 t, quint8 w, quint8 i, quint8 a, quint8 ld, quint8 sv);

private:
    quint8 m_stats[9];
};

#endif // PROFILE_HPP
