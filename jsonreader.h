#ifndef JSONREADER_H
#define JSONREADER_H

#include "abstractreader.h"
#include <fstream>
#include <json.hpp>
#include "csvexception.h"

class JsonReader : public AbstractReader
{
    std::ifstream fin;

public:
    JsonReader(const QString& filename);
    ~JsonReader();
    virtual bool is_open() const {return fin.is_open(); };
    virtual AbstractReader& operator>> (Films &film);

    virtual operator bool (){
        return this->is_open();
    }
private:
    int index = 0;
    nlohmann::json json;
};

#endif // JSONREADER_H
