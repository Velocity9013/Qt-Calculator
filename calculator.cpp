#include "calculator.h"
#include "ui_calculator.h"

#include <QDebug>

double firstnum;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
    , total(0)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(released()),this, SLOT(numpressed()));
    connect(ui->pushButton_1, SIGNAL(released()),this, SLOT(numpressed()));
    connect(ui->pushButton_2, SIGNAL(released()),this, SLOT(numpressed()));
    connect(ui->pushButton_3, SIGNAL(released()),this, SLOT(numpressed()));
    connect(ui->pushButton_4, SIGNAL(released()),this, SLOT(numpressed()));
    connect(ui->pushButton_5, SIGNAL(released()),this, SLOT(numpressed()));
    connect(ui->pushButton_6, SIGNAL(released()),this, SLOT(numpressed()));
    connect(ui->pushButton_7, SIGNAL(released()),this, SLOT(numpressed()));
    connect(ui->pushButton_8, SIGNAL(released()),this, SLOT(numpressed()));
    connect(ui->pushButton_9, SIGNAL(released()),this, SLOT(numpressed()));

    connect(ui->pushButton_add, SIGNAL(released()),this, SLOT(plus()));
    connect(ui->pushButton_equal, SIGNAL(released()),this, SLOT(equal()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::numpressed(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    number.append(button->text());
    ui->label->setText(number);
}

// not working
void Calculator::decimalpressed()
{
    ui->label->setText(ui->label->text() + ".");
}


void Calculator::plus(){
    double secondnum = 0;
    secondnum = ui->label->text().toDouble();
    firstnum = number.toDouble();
    total = firstnum + secondnum;

}
//testing
void Calculator::equal(){
    ui->label->setText(QString::number(total));
}

