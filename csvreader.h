#ifndef CSVREADER_H
#define CSVREADER_H
#include<algorithm>
#include <string>
#include <fstream>
#include <vector>
#include "films.h"
#include "funtion.h"
#include "abstractreader.h"
#include "csvexception.h"
#include <QString>

using namespace std;

class CSVReader : public AbstractReader
{
    ifstream fin;

public:
    CSVReader(const QString& filename);
    ~CSVReader();
    CSVReader& operator= (CSVReader&& orther);
    CSVReader(CSVReader&& orther);

    virtual bool is_open() const {return fin.is_open();};

    virtual AbstractReader& operator>> (Films &film);

    virtual operator bool (){
        return !(this->fin.eof());
    }
private:
    int index = 0;
    vector<Films> csv;

};

#endif // CSVREADER_H
