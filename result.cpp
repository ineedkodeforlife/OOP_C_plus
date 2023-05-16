#include "result.h"


Result::Result(QWidget* parent):QTextBrowser(parent)
{

}

void Result::GreenText(QString text)

{
    auto color = this->textColor();
    this->setTextColor(Qt::green);
    this->append(text);
    this->setTextColor(color);
}


void Result::RedText(QString text)

{
    auto color = this->textColor();
    this->setTextColor(Qt::red);
    this->append(text);
    this->setTextColor(color);
}
