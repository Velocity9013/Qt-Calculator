#ifndef MATHEXPRESSION_H
#define MATHEXPRESSION_H

#include <QString>

class MathExpression : public QString
{
public:
    MathExpression();
    void inputNumber(QChar c);
    void inputOperator(QChar c);
    void inputDot();
    double evaluate();
};

#endif // MATHEXPRESSION_H
