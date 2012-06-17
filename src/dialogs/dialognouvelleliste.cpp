#include "dialognouvelleliste.hpp"

#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

DialogNouvelleListe::DialogNouvelleListe(const QStringList& lst, QWidget *parent) :
    QDialog(parent)
{
    QFormLayout* layout = new QFormLayout;

    le = new QLineEdit;
    combo = new QComboBox;
    combo->addItems(lst);

    QHBoxLayout* hl = new QHBoxLayout;
    QPushButton* b = new QPushButton(tr("Ok"));
    connect(b, SIGNAL(clicked()), this, SLOT(accept()));
    hl->addWidget(b);

    b = new QPushButton(tr("Annuler"));
    connect(b, SIGNAL(clicked()), this, SLOT(reject()));
    hl->addWidget(b);

    layout->addRow(new QLabel(tr("Nom de la liste")), le);
    layout->addRow(new QLabel(tr("ArmÃ©e")), combo);
    layout->addRow(hl);
    setLayout(layout);
}

QPair<QString, QString> DialogNouvelleListe::execute(QWidget* parent, const QStringList& lst)
{
    DialogNouvelleListe* dial = new DialogNouvelleListe(lst, parent);
    if(dial->exec() == QDialog::Rejected) return QPair<QString, QString>();
    return qMakePair(dial->nomArmee(), dial->nomListe());
}

QString DialogNouvelleListe::nomArmee()const
{
    return combo->currentText();
}

QString DialogNouvelleListe::nomListe() const
{
    return le->text();
}
