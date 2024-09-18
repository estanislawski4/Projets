#include "calculatrice.h"
#include "ui_calculatrice.h"

Calculatrice::Calculatrice(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
    QList<QPushButton*> allButtons = findChildren<QPushButton*>();

    // foreach(QPushButton* button, allButtons) {
    //     if(button->text() != "=" && button->text() != "C") {
    //         connect(button, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
    //     }
    // }

    for (QPushButton* button : allButtons) {
        if(button->text() != "=" && button->text() != "C") {
            connect(button, &QPushButton::clicked, this, &Calculatrice::onQPushButtonClicked);
        } else if (button->text() == "=") {
            connect(button, &QPushButton::clicked, this, &Calculatrice::onButtonEqual_clicked);
        } else if (button->text() == "C") {
            connect(button, &QPushButton::clicked, this, &Calculatrice::onButtonC_clicked);
        }
    }
}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::onQPushButtonClicked()
{
    QPushButton *touche = qobject_cast<QPushButton*>(sender());
    QString buttonText = touche->text();

    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text() + buttonText);
}

void Calculatrice::onButtonC_clicked()
{
    ui->lineEditAfficheur->clear();
}

void Calculatrice::onButtonEqual_clicked()
{
    QString expression = ui->lineEditAfficheur->text();

    QString result = evaluateExpression(expression);
    ui->lineEditAfficheur->setText(result);
}

QString Calculatrice::evaluateExpression(const QString& expression)
{
    QJSEngine engine;
    QJSValue value = engine.evaluate(expression);
    return value.toString();
}
