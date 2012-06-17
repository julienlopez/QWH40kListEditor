#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "armee.hpp"

#include <set>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    typedef std::set<Armee, Armee::SetComparator> type_containter_armees;

private:
    type_containter_armees m_armees;

    QAction* m_actionNouvelleListe;
    QAction* m_actionOuvrirListe;
    QAction* m_actionSauverListe;
    QAction* m_actionFermerListe;
    QAction* m_actionQuitter;

    QAction* m_actionGererArmees;

    QAction* m_actionAPropos;
    QAction* m_actionAProposQt;

    void creerActions();
    void creerMenus();
    void creerBarreEtat();

private slots:
    void onActionNouvelleListe();
    void onActionOuvrirListe();
    void onActionSauverListe();
    void onActionFermerListe();
    void onActionQuitter();
    void onActionGererArmees();
    void onActionAPropos();
};



#endif // MAINWINDOW_HPP
