#ifndef RESULT_H
#define RESULT_H


#include <QMainWindow>

#include "mainwindow.h"
#include <QTextBrowser>

namespace Ui { class MainWindow; }
class Result: public QTextBrowser
{
public:
    Result(QWidget* parent);

    void GreenText(QString text);
    void RedText(QString text);
};


#endif // RESULT_H
