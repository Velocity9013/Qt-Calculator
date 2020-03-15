#include "calculator.h"
#include "ui_calculator.h"

#include <QString>
#include <QDebug>


Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_1, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_7, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_8, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_9, SIGNAL(clicked()),this, SLOT(buttonClicked()));

    connect(ui->pushButton_add, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_subtract, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_times, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_divide, SIGNAL(clicked()),this, SLOT(buttonClicked()));

    connect(ui->pushButton_equal, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_clear, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_delete, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_decimal, SIGNAL(clicked()),this, SLOT(buttonClicked()));
    connect(ui->pushButton_plusminus, SIGNAL(clicked()),this, SLOT(buttonClicked()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::buttonClicked()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());

    if (senderButton == ui->pushButton_0)
        expression.inputNumber('0');
    if (senderButton == ui->pushButton_1)
        expression.inputNumber('1');
    if (senderButton == ui->pushButton_2)
        expression.inputNumber('2');
    if (senderButton == ui->pushButton_3)
        expression.inputNumber('3');
    if (senderButton == ui->pushButton_4)
        expression.inputNumber('4');
    if (senderButton == ui->pushButton_5)
        expression.inputNumber('5');
    if (senderButton == ui->pushButton_6)
        expression.inputNumber('6');
    if (senderButton == ui->pushButton_7)
        expression.inputNumber('7');
    if (senderButton == ui->pushButton_8)
        expression.inputNumber('8');
    if (senderButton == ui->pushButton_9)
        expression.inputNumber('9');
    if (senderButton == ui->pushButton_add)
        expression.inputOperator('+');
    if (senderButton == ui->pushButton_subtract)
        expression.inputOperator('-');
    if (senderButton == ui->pushButton_times)
        expression.inputOperator('*');
    if (senderButton == ui->pushButton_divide)
        expression.inputOperator(QChar(0x00F7));
    if (senderButton == ui->pushButton_clear)
        expression.clear();
    if (senderButton == ui->pushButton_decimal)
        expression.inputDot();
    if (senderButton == ui->pushButton_delete)
        expression.del();
    if (senderButton == ui->pushButton_plusminus)
        expression.plusminus();

    ui->textDisplay->setText(expression);

    if(senderButton == ui->pushButton_equal){
        double ans = expression.evaluate();

        ui->textDisplay->setText("<p>" + expression + "</p>" + "<h1>" + QString::number(ans) + "</h1>");
        expression.clear();
    }
}

