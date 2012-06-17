#include "mainwindow.hpp"
#include "dialogs/dialognouvelleliste.hpp"
#include "listhandler.hpp"
#include "list.hpp"

#include <QStatusBar>
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>
#include <QFile>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    creerActions();
    creerMenus();
    creerBarreEtat();

    setWindowTitle(tr("QWH40kListEditor"));
    showMaximized();

    //setCentralWidget(new QWidget());

    Armee necrons("N�crons");
    Unit warriors("Guerriers n�crons", 5, 20, 13);
    necrons.addTroop(warriors);
    m_armees.insert(necrons);
    /*
    QFile f("armees.adf");
    if(!f.open(QIODevice::ReadOnly)) qDebug() << "Erreur (2)";
    QDataStream flux(&f);
    quint32 nb;
    flux >> nb;
    qDebug() << nb << " armées �  charger";
    Armee a;
    for(quint32 i = 0; i < nb; ++i)
    {
        flux >> a;
        qDebug() << "chargement de " << a.nom();
        m_armees.insert(a);
    }
    f.close();
    */
}

MainWindow::~MainWindow()
{
    QFile f("armees.adf");
    if(!f.open(QIODevice::WriteOnly)) qDebug() << "Erreur (2)";
    QDataStream flux(&f);
    flux << (quint32)m_armees.size();
    qDebug() << "sauvegarde de " << m_armees.size() << " armées";
    for(type_containter_armees::const_iterator i = m_armees.begin(); i != m_armees.end(); ++i)
    {
        qDebug() << "écriture de " << i->nom();
        flux << *i;
    }
    f.close();
}

void MainWindow::creerActions()
{
    m_actionNouvelleListe = new QAction(tr("&Nouvelle liste"), this);
    connect(m_actionNouvelleListe, SIGNAL(triggered()), this, SLOT(onActionNouvelleListe()));
    m_actionNouvelleListe->setShortcut(tr("Ctrl+N"));
    m_actionOuvrirListe = new QAction(tr("&Ouvrir une liste"), this);
    connect(m_actionOuvrirListe, SIGNAL(triggered()), this, SLOT(onActionOuvrirListe()));
    m_actionOuvrirListe->setShortcut(tr("Ctrl+O"));
    m_actionFermerListe = new QAction(tr("Fermer une liste"), this);
    connect(m_actionFermerListe, SIGNAL(triggered()), this, SLOT(onActionFermerListe()));
    m_actionFermerListe->setShortcut(tr("Ctrl+W"));
    m_actionSauverListe = new QAction(tr("&Sauver une liste"), this);
    connect(m_actionSauverListe, SIGNAL(triggered()), this, SLOT(onActionSauverListe()));
    m_actionSauverListe->setShortcut(tr("Ctrl+S"));
    m_actionQuitter = new QAction(tr("&Quitter"), this);
    connect(m_actionQuitter, SIGNAL(triggered()), this, SLOT(onActionQuitter()));
    m_actionQuitter->setShortcut(tr("Ctrl+Q"));

    m_actionGererArmees = new QAction(tr("Gérer les armées"), this);
    connect(m_actionGererArmees, SIGNAL(triggered()), this, SLOT(onActionGererArmees()));

    m_actionAPropos = new QAction(tr("A Propos"), this);
    connect(m_actionAPropos, SIGNAL(triggered()), this, SLOT(onActionAPropos()));
    m_actionAProposQt = new QAction(tr("A Propos de Qt"), this);
    connect(m_actionAProposQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::creerMenus()
{
    QMenu* menu = menuBar()->addMenu(tr("&Fichier"));

    menu->addAction(m_actionNouvelleListe);
    menu->addAction(m_actionOuvrirListe);
    menu->addAction(m_actionSauverListe);
    menu->addAction(m_actionFermerListe);
    menu->addSeparator();
    menu->addAction(m_actionQuitter);

    menu = menuBar()->addMenu(tr("&Armées"));
    menu->addAction(m_actionGererArmees);


    menu = menuBar()->addMenu(tr("&?"));
    menu->addAction(m_actionAPropos);
    menu->addAction(m_actionAProposQt);
}

void MainWindow::creerBarreEtat()
{
    //m_progression = new QProgressBar(this);
    statusBar()->show();
}

void MainWindow::onActionNouvelleListe()
{
    List* currentList = ListHandler::currentList();
    if(currentList && currentList->estModifiee()) //gestion de la sauvegarde
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Il y a une liste modifiée encore ouverte"), tr("Voulez-vous sauvegarder la liste actuelle"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes)
        {

        }
        else if (reply == QMessageBox::No)
        {

        }
        else return;
    }
    QStringList lst;
    foreach(const Armee& a, m_armees) lst << a.nom();
    QPair<QString, QString> pair = DialogNouvelleListe::execute(this, lst);
    if(pair.first.isEmpty() || pair.second.isEmpty()) return;
    qDebug() << pair.first << " => " << pair.second;
    std::set<Armee>::const_iterator i = m_armees.begin();
    for(; i != m_armees.end(); ++i)
        if(i->nom() == pair.first) break;
    if(i == m_armees.end())
    {
        QMessageBox::warning(this, tr("Armée non existante"), tr("Impossible de créer une liste pour l'armée ") + pair.first + tr(", l'armée n'éxiste pas."));
        return;
    }
    ListHandler::createList(pair.second, *i);
}

void MainWindow::onActionOuvrirListe()
{

}

void MainWindow::onActionSauverListe()
{

}

void MainWindow::onActionFermerListe()
{

}

void MainWindow::onActionQuitter()
{

}

void MainWindow::onActionGererArmees()
{

}

void MainWindow::onActionAPropos()
{
    QMessageBox::information(this, tr("A propos de QWH40kListEditor"), "");
}
