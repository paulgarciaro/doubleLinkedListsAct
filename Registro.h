//
// Created by Paul García on 19/09/21.
//

#ifndef ACTINTEGRADORA_REGISTRO_H
#define ACTINTEGRADORA_REGISTRO_H
#include <iostream>
#include <string>
#include "dateTime.h"
using namespace std;

class Registro {
private:
    string ip, falla, mes, hora;
    int dia;
    dateTime fecha;
public:
    Registro();
    Registro(string _mes, int _dia, string _hora, string _ip, string _falla);
    void setFecha(dateTime);
    void setIp(string);
    void setFalla(string);
    void setMes(string);
    void setDia(int);
    void setHora(string);
    dateTime getFecha();
    string getIp();
    string getFalla();
    string getLine();
    void imprimir();

};

#include <utility>

Registro::Registro() {
    this -> ip = "desconocido";
    this -> falla = "desconocida";
    this -> fecha = dateTime();
}

Registro::Registro(string _mes, int _dia, string _hora, string _ip, string _falla) {
    this -> mes = _mes;
    this -> dia = _dia;
    this -> hora = _hora;
    this -> ip = _ip;
    this -> falla = _falla;
    std::string hh = hora.substr(0, 2);
    std::string mm = hora.substr(3, 2);
    std::string ssg = hora.substr(6, 2);
    dateTime _fecha(_mes, _dia, stoi(hh), stoi(mm), stoi(ssg));
    this -> fecha = _fecha;
}

void Registro::setFecha(dateTime _fecha) {
    this -> fecha = _fecha;
}

void Registro::setIp(string _ip) {
    this -> ip = _ip;
}

void Registro::setFalla(string _falla) {
    this -> falla = _falla;
}
//Complejidad O(1)
dateTime Registro::getFecha() {
    return this -> fecha;
}

string Registro::getIp() {
    return this -> ip;
}

string Registro::getFalla() {
    return this -> falla;
}

void Registro::setMes(string _mes) {
    this -> mes = _mes;
}

void Registro::setDia(int _dia) {
    this -> dia = _dia;
}

void Registro::setHora(string _hora) {
    this -> hora = _hora;
}

void Registro::imprimir() {
    cout << this -> mes <<  " ";
    if(dia<10){
      std::cout << "0" <<this -> dia << " ";
    }else{
      std::cout << this -> dia << " ";
    } 
    std::cout << this -> hora << " " << this -> ip << " " << this -> falla << std::endl;
}

string Registro::getLine() {
    string line;
    line += this -> mes;
    line += " ";
    if(dia<10){
      line += "0";
      line += to_string(this -> dia);
      line += " ";
    }else{
    line += to_string(this -> dia);
    line += " ";
    }
    line += this -> hora;
    line += " ";
    line += this -> ip;
    line += " ";
    line += this -> falla;
    return line;
}




#endif //ACTINTEGRADORA_REGISTRO_H
