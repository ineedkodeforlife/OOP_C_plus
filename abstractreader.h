#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <vector>
#include <fstream>

#include <films.h>


class AbstractReader
{
public:
    int count_line;
    AbstractReader();
    virtual std::vector<Films> readAll() {std::vector<Films> film; return film;};
    virtual bool is_open() const = 0;
    virtual operator bool () = 0;
    virtual AbstractReader& operator>> (Films &c) = 0;
};

#endif // ABSTRACTREADER_H
