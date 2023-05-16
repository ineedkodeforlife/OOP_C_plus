#include "films.h"
#include <QString>

QString Films::to_string() {
    return("Год выпуска: " +QString::number (year) + " Жанр: " + QString::fromStdString(zanr)
           + " Название: " + QString::fromStdString(name)  + " Год выпуска: " + QString::number(time) );
}
