#ifndef DIALOGNOUVELLELISTE_HPP
#define DIALOGNOUVELLELISTE_HPP

#include <QDialog>

class QLineEdit;
class QComboBox;

class DialogNouvelleListe : public QDialog
{
    Q_OBJECT
public:
    explicit DialogNouvelleListe(const QStringList& lst, QWidget *parent = 0);

    static QPair<QString, QString> execute(QWidget* parent, const QStringList& lst);

    QString nomArmee()const;
    QString nomListe() const;

private:
    QLineEdit* le;
    QComboBox* combo;
};

#endif // DIALOGNOUVELLELISTE_HPP
