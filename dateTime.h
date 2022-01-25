//
// Created by Paul García on 19/09/21.
//

#ifndef ACTINTEGRADORA_DATETIME_H
#define ACTINTEGRADORA_DATETIME_H

#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>

class dateTime {
public:
    dateTime();
    dateTime(std::string mes, int dia, int horas, int minutos, int segundos);
    time_t getDate();
    bool operator ==(const dateTime&);
    bool operator !=(const dateTime&);
    bool operator >(const dateTime&);
    bool operator <(const dateTime&);

private:
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // Struct que contiene todos los datos de la fecha-hora
    struct tm dateStruct;
    // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
    time_t date;

};

dateTime::dateTime() {
    dateStruct.tm_sec = 0;
    dateStruct.tm_min = 0;
    dateStruct.tm_hour = 0;
    dateStruct.tm_mday = 0;
    dateStruct.tm_mon = 1;
    dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
    dateStruct.tm_isdst = 0;
    // Obtener el Unix timestamp a partir del struct tm anterior
    date = mktime(&dateStruct);
}

dateTime::dateTime(std::string mes, int dia, int horas, int minutos, int segundos) {
    // Almacenar los campos de la fecha-hora en el struct tm
    dateStruct.tm_sec = segundos;
    dateStruct.tm_min = minutos;
    dateStruct.tm_hour = horas;
    dateStruct.tm_mday = dia;
    for (int i=0; i < meses.size(); i++) {
        if (meses[i]==mes)
            dateStruct.tm_mon = i;
    }
    dateStruct.tm_isdst = 0;
    dateStruct.tm_year = 2021 - 1900;  // Asumimos el año 2021
    // Obtener el Unix timestamp a partir del struct tm anterior
    date = mktime(&dateStruct);
}

time_t dateTime::getDate() {
    return this -> date;
}

bool dateTime::operator==(const dateTime &other) {
    return this->date == other.date;
}

bool dateTime::operator!=(const dateTime &other) {
    return this->date != other.date;
}

bool dateTime::operator>(const dateTime &other) {
    return this->date > other.date;
}

bool dateTime::operator<(const dateTime &other) {
    return this->date < other.date;
}

#endif //ACTINTEGRADORA_DATETIME_H