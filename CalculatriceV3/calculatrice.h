#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QJSEngine>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculatrice;
}
QT_END_NAMESPACE

class Calculatrice : public QWidget
{
    Q_OBJECT

public:
    Calculatrice(QWidget *parent = nullptr);
    ~Calculatrice();

private:
    Ui::Calculatrice *ui;
    const int NB_TOUCHES;
    QGridLayout *grille;
    QPushButton **touches;
    QLineEdit *afficheur;

private slots:
    void onPushButtonClicked();
};

#endif // CALCULATRICE_H
