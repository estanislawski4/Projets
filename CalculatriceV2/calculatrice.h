#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>
#include <QJSEngine>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculatrice;
}
QT_END_NAMESPACE

class Calculatrice : public QMainWindow
{
    Q_OBJECT

public:
    Calculatrice(QWidget *parent = nullptr);
    ~Calculatrice();
    QString evaluateExpression(const QString &expression);

private:
    Ui::Calculatrice *ui;

private slots:
    void onButtonC_clicked();
    void onButtonEqual_clicked();
    void onQPushButtonClicked();
};
#endif // CALCULATRICE_H
