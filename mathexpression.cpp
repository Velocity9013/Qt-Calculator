#include "mathexpression.h"

#include <QString>
#include <QStringList>

MathExpression::MathExpression()
{

}


void MathExpression::inputNumber(QChar c)
{
    if(isEmpty()){
        append(c);
    }
    else if(back().isDigit()){
        append(c);
    }
    else{
        append(" ");
        append(c);
    }

}

void MathExpression::inputOperator(QChar c)
{
    if(isEmpty()){
        append("0 ");
        append(c);
    }else if(back().isDigit()){
        append(" ");
        append(c);
    }else{
        chop(1);
        append(c);
    }
}

void MathExpression::inputDot()
{
    if(split(' ').last().contains('.')){
        return;
    }else{
        append(".");
    }
}

double MathExpression::evaluate()
{
    QStringList splitstr = split(' ');
    double result = splitstr.first().toDouble();

    for(int i = 1; i < splitstr.size(); i+=2){
        QChar operation = splitstr.at(i).front();

        double operand = splitstr.at(i + 1).toDouble();

        if(operation == '+'){
            result += operand;
        }else if(operation == '-'){
            result -= operand;
        }else if(operation == '*'){
            result *= operand;
        }else if(operation == 0x00F7){
            result /= operand;
        }
    }

    return result;
}

void MathExpression::del()
{
    chop(1);
    if(!isEmpty()){
        if(back() == ' '){
            chop(1);
        }
    }
}

void MathExpression::plusminus()
{
    if(!isEmpty()){
        if(back().isDigit()){
            double result = split(' ').last().toDouble();
            chop(split(' ').last().length());
            result *= -1;
            append(QString::number(result));
        }
    }
}
