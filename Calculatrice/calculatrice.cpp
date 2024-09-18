#include "calculatrice.h"
#include "ui_calculatrice.h"

Calculatrice::Calculatrice(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::on_pushButton1_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"1");
}

void Calculatrice::on_pushButton2_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"2");
}

void Calculatrice::on_pushButton3_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"3");
}

void Calculatrice::on_pushButton4_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"4");
}


void Calculatrice::on_pushButton5_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"5");
}


void Calculatrice::on_pushButton6_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"6");
}


void Calculatrice::on_pushButton7_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"7");
}


void Calculatrice::on_pushButton8_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"8");
}


void Calculatrice::on_pushButton9_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"9");
}


void Calculatrice::on_pushButton0_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"0");
}


void Calculatrice::on_pushButtonEffacer_clicked()
{
    ui->lineEditAfficheur->setText("");
}


void Calculatrice::on_pushButtonAdditionner_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"+");
}


void Calculatrice::on_pushButtonSoustraire_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"-");
}


void Calculatrice::on_pushButtonMultiplier_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"*");
}


void Calculatrice::on_pushButtonDiviser_clicked()
{
    ui->lineEditAfficheur->setText(ui->lineEditAfficheur->text()+"/");
}


void Calculatrice::on_pushButtonEgal_clicked()
{
    QJSEngine myEngine;
    QJSValue result = myEngine.evaluate(ui->lineEditAfficheur->text());
    ui->lineEditAfficheur->setText(result.toString());
}

