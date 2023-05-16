#include "jsonreader.h"

#include <iostream>

#include <QString>

JsonReader::JsonReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
    fin >> json;
}
JsonReader::~JsonReader(){
    fin.close();
}

AbstractReader& JsonReader::operator>>(Films &film){
    if (!(this->json[index].empty())){
            std::string tempStr;

            json[index].at("year").get_to(film.year);
            json[index].at("zanr").get_to(film.zanr);
            json[index].at("name").get_to(film.name);
            json[index].at("time").get_to(film.time);

            index++;
        }else {
            fin.close();
        }

        return *this;
}
