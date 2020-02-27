#ifndef CALCULATOR_H
#define CALCULATOR_H

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
    enum Operation{add, subtract, empty};

private:
    Ui::Calculator *ui;
    QString number;
    Operation operation;
    double total;
    double buffernum;
    double currentval;

private slots:
    void numpressed();
    void on_pushButton_clear_released();
    void on_pushButton_equal_released();
    void operator_pressed();
};
#endif // CALCULATOR_H
