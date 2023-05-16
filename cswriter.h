#ifndef CSWRITER_H
#define CSWRITER_H


#include "csvreader.h"
#include <iostream>

class CSWriter
{
    ofstream fout;
public:

    ~CSWriter();

    void addAll(vector <Films> newfilm);
    bool is_open() const {return fout.is_open();};
    CSWriter(const QString& filename);
    CSWriter& operator= (CSWriter&& orther);
    CSWriter(CSWriter&& orther);

};

#endif // CSWRITER_H
