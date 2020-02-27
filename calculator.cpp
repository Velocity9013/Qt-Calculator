#include "calculator.h"
#include "ui_calculator.h"

#include <QDebug>


Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
    , total(0)
    , buffernum (0)
    , currentval (0)
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

    connect(ui->pushButton_add, SIGNAL(released()),this, SLOT(operator_pressed()));
    connect(ui->pushButton_subtract, SIGNAL(released()),this, SLOT(operator_pressed()));
    connect(ui->pushButton_times, SIGNAL(released()),this, SLOT(operator_pressed()));
    connect(ui->pushButton_divide, SIGNAL(released()),this, SLOT(operator_pressed()));
    connect(ui->pushButton_equal, SIGNAL(released()),this, SLOT(operator_pressed()));
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


void Calculator::on_pushButton_clear_released()
{

}

void Calculator::on_pushButton_equal_released()
{
    double currenttotal;
    currentval = ui->label->text().toDouble();
    QString totalString;

    //addition
    if(ui->pushButton_add->isChecked()){
        currenttotal = buffernum + currentval;
        total += currenttotal;
        ui->pushButton_add->setChecked(false);
    }else if(ui->pushButton_subtract->isChecked()){
        currenttotal = buffernum - currentval;
        total -= currenttotal;
        ui->pushButton_subtract->setChecked(false);
    }else if(ui->pushButton_times->isChecked()){
        currenttotal = buffernum * currentval;
        total *= currenttotal;
        ui->pushButton_times->setChecked(false);
    }else if(ui->pushButton_divide->isChecked()){
        currenttotal = buffernum / currentval;
        total /= currenttotal;
        ui->pushButton_divide->setChecked(false);
    }

    totalString = QString::number(total);
    ui->label->setText(totalString);

}

void Calculator::operator_pressed()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if(button->text() == "+"){
        ui->pushButton_add->setChecked(true);
    }
    if(button->text() == "-"){
        ui->pushButton_subtract->setChecked(true);
    }
    if(button->text() == "X"){
        ui->pushButton_times->setChecked(true);
    }
    if(button->text() == "/"){
        ui->pushButton_divide->setChecked(true);
    }
}
