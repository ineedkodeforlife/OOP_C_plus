#include "csvreader.h"


CSVReader::CSVReader(const QString& filename)
{
 fin.open(filename.toLatin1().data());
}
CSVReader::~CSVReader(){
    fin.close();
}



CSVReader& CSVReader::operator=(CSVReader&& orher){
    fin = std::move(orher.fin);
    return *this;
}

CSVReader::CSVReader(CSVReader&& orther){
    fin = std::move(orther.fin);
}

AbstractReader& CSVReader::operator>> (Films &film){

    if (fin.is_open() && !fin.eof()) {
        std::string line;
        getline(fin, line);

        if (!line.empty()){
            auto v = split(line, ';');
            try {
            film.year = std::stoi(v[0]);
            film.zanr = (v[1]);
            film.name = (v[2]);
            film.time = stoi(v[3]);

        }  catch (const std::logic_error) {
            throw CSVException(count_line);

        }

    }
    }
    return *this;
}
