#ifndef FILMS_H
#define FILMS_H
#include <string>
#include <QString>
#include <iostream>
using namespace std;

class Films
{
public:
    int year;
    std::string zanr;
    std::string name;
    int time;
    QString to_string();
    // Создана для того, чтобы при сортировке не использывать лямба функции
    friend bool operator< (const Films& d1, const Films& d2){
        return d1.time < d2.time;
    }
    friend std::ostream& operator<< (std::ostream& out,  Films& film){
        out <<"year: " << film.year << " Zanr: " << film.zanr<< " Name: " << film.name  << " Time: " << film.time ;
        return out;
    }
};

#endif // FILMS_H

