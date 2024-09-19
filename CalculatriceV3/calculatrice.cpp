#include "calculatrice.h"
#include "ui_calculatrice.h"

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
    , NB_TOUCHES(16)
{
    ui->setupUi(this);
    const QString tableDesSymboles[ ] = {"7", "8", "9", "+" ,"4", "5", "6", "-", "1", "2", "3", "*",
                                        "C", "0", "=", "/"};
    grille = new QGridLayout;
    afficheur = new QLineEdit;
    afficheur->setMinimumHeight(50);
    afficheur->setStyleSheet("background-color: rgb(143, 240, 164);");
    afficheur->setAlignment(Qt::AlignRight | Qt::AlignTrailing);
    afficheur->setPlaceholderText("Je dois calculer quel nombre ?");
    touches = new QPushButton*[NB_TOUCHES];
    grille->addWidget(afficheur,0,0,1,4);

    for (int i = 0; i < NB_TOUCHES; ++i) {
        touches[i] = new QPushButton;
        touches[i]->setText(tableDesSymboles[i]);
        touches[i]->setMinimumSize(50, 50);
        int row = 1 + i / 4;
        int col = i % 4;
        grille->addWidget(touches[i], row, col);
        connect(touches[i], SIGNAL(clicked()), this, SLOT(onPushButtonClicked()));
    }

    this->setLayout(grille);
}

Calculatrice::~Calculatrice()
{
    delete afficheur;
    for (int i = 0; i < NB_TOUCHES; ++i) {
        delete touches[i];
    }
    delete[] touches;
    delete grille;
    delete ui;
}

void Calculatrice::onPushButtonClicked()
{
    QPushButton *buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text();

    if (buttonText == "C") {
        afficheur->clear();
    } else if (buttonText == "=") {
        QString expression = afficheur->text();
        QJSEngine engine;
        QJSValue result = engine.evaluate(expression);
        afficheur->setText(result.toString());
    } else {
        afficheur->setText(afficheur->text() + buttonText);
    }
}
