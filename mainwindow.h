#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QString"
#include "films.h"
#include <abstractreader.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString fileName;


public:
    vector <Films> film;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void read(AbstractReader& reader);
public slots:
    void FindFilm();
    void AddFilm();
    void UploadFilm();
//    void Search();

private slots:

    void on_pushButton_2_clicked();

//    void on_Search_clicked();

//    void on_add_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
