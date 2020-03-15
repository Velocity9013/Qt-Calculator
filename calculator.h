#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "mathexpression.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    MathExpression expression;

private slots:
    void buttonClicked();

};
#endif // CALCULATOR_H
