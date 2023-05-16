#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "films.h"
#include "csvreader.h"
#include <jsonreader.h>
#include <iostream>

#include "cswriter.h"
#include "result.h"
#include <QFileDialog>
#include "QString"

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FindFilm()
{
    ui->TextBrowser->clear();
    ui->TextBrowser->GreenText("Поиск..");

    bool flag=0;
    for (auto &c: film){
        if(ui->SearchEdit_2->text().isEmpty()){
            flag=1;
            ui->TextBrowser->append(c.to_string());
        }else if(c.name==ui->SearchEdit_2->text().toStdString()){
        ui->TextBrowser->append(c.to_string());
        flag=1;
        }
    }
    if(!flag)
           ui->TextBrowser->RedText("Нет такой записи!");
}

void MainWindow::AddFilm()
{

        Films films;
        films.year=ui->year->text().toInt();
        ui->year->clear();
        films.zanr=ui->zanr->text().toStdString();
        ui->zanr->clear();
        films.name=ui->Name_2->text().toStdString();
        ui->Name_2->clear();
        films.time=ui->Time->text().toInt();
        ui->Time->clear();
        film.push_back(films);
}
void MainWindow::UploadFilm(){
     CSWriter newfile(fileName);
     if(newfile.is_open())
     {
       newfile.addAll(film);

     }
}





void MainWindow::read(AbstractReader& reader){

    if (reader.is_open()){
        //Чтение из файла в вектор
        reader.count_line=0;

        film = reader.readAll();
        film.clear();
        Films films;
        while(true){
        reader.count_line++;
        try {
        if(!(reader >> films))break;
        cout << films << endl;
        film.push_back(films);
        }  catch (CSVException &c) {
            std::cerr<< "Error in line " << c.GetLine()<<endl;
        }
        }

    }

}


void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "C:\\Users\\Vitaliy\\Documents",
                                                      tr("Base (*.csv *.json)"));
    this->fileName= fileName;
    //Открытие файла
    if(fileName.right(1) == QString::fromStdString("v")){
        CSVReader csv(fileName);
        read(csv);

    }
    if(fileName.right(1) == QString::fromStdString("n")){
        JsonReader json(fileName);
        read(json);
    }

    // сортировка
        std::sort(film.begin(), film.end());
}



