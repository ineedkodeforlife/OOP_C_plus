#include "cswriter.h"

CSWriter::CSWriter(const QString& filename)
{
    fout.open(filename.toLatin1().data());
}

CSWriter::~CSWriter(){
    fout.close();
}

void CSWriter::addAll(vector <Films> newfilm){
    for (const auto &c: newfilm)
    {
    fout<<c.year <<";" << c.zanr<< ";" <<c.name << ";" << c.time<<endl;
    }

}

CSWriter& CSWriter::operator=(CSWriter&& orher){
    fout = std::move(orher.fout);
    return *this;
}

CSWriter::CSWriter(CSWriter&& orther){
    fout = std::move(orther.fout);
}
