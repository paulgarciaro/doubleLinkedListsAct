//
// Created by Paul García on 11/10/21.
//

#ifndef ACTINTEGRAL2_3_BITACORA_H
#define ACTINTEGRAL2_3_BITACORA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Registro.h"
#include "dateTime.h"
#include "DoubleLinkedList.h"
using namespace std;

class Bitacora {
private:
    DoubleLinkedList<Registro> bit;
    int size;
public:
    Bitacora();
    int binarySearch(dateTime k); //Complejidad O(n)
    void busquedaDatos(); //Complejidad O(log n)
    void crearBitacoraOrdenada(); //Complejidad O(n)
    void leerDatos(); //Complejidad O(n)
    void sort(); //Complejidad O(n log n)
};

Bitacora::Bitacora() {
    this -> size = this -> bit.getNumElements();

}

//Complejidad O(n)
void Bitacora::leerDatos() {
  string mes, dia, hora, ip, razon, razon1, razon2, razon3, razon4, razon5, line;
  ifstream infile("bitacora.txt");
  int i = 0;
  if(infile.is_open()){
    while (getline(infile, line)) {
        istringstream ss(line);

        ss >> mes >> dia >> hora >> ip >> razon >> razon1 >> razon2 >> razon3 >> razon4 >> razon5;

        string razonFinal;
        razonFinal = razon + " " + razon1 + " " + razon2 + " " + razon3 + " " + razon4 + " " + razon5;

        string hh = hora.substr(0, 2);
        string mm = hora.substr(3, 2);
        string ssg = hora.substr(6, 2);
        string ads = ip.substr(0, ip.find(":"));
        string pto = ip.substr(ip.find(":") + 1, 6);
        Registro bitT(mes, stoi(dia), hora, ip, razonFinal);
        bit.addLast(bitT);
        i++;
    }
    // Te faltó actualizar tu variable size en clase bitacora
    // es distinta a la variable size dentro de DoubleLinkedList
    this -> size = bit.getNumElements();
    infile.close();
  }else{
    std::cout << "El archivo no ha abierto correctamente" << std::endl;
  }if(!infile.is_open()){
    std::cout << "El archivo 'bitacora.txt' ha cerrado correctamente\n";
  }
}

//Complejidad O(n log n)
void Bitacora::sort() {
    this -> bit.quickSort();
}

//Complejidad O(n)
int Bitacora::binarySearch(dateTime k) {
    int low = 0;
    int high = this->size - 1;
    while (low <= high) {
        int m = low + (high - low) / 2;
        if (k == bit[m].getFecha()) {
            return m;
        } else if (k < bit[m].getFecha()) {
            high = m - 1;
        } else {
            low = m + 1;
        }
    }
    return -1;
}

//Complejidad O(n)
void Bitacora::busquedaDatos() {
//La variable n se refiere al tamaño del vector menos uno.

    //Declaración de las variables que me servirán para realizar la búsqueda en la bitácora
    string mes, hora;
    int dia;
    int firstIndex, lastIndex;

    do{
        cout << "Ingrese la fecha desde la cual quiere comenzar a buscar: " << endl;
        cout << "Mes: " << endl;
        cin >> mes;
        cout << "Día: " << endl;
        cin >> dia;
        cout << "Hora [hh:mm:ss]: " << endl;
        cin >> hora;
        std::string hh = hora.substr(0, 2);
        std::string mm = hora.substr(3, 2);
        std::string ssg = hora.substr(6, 2);
        dateTime fechaInicio(mes, dia, stoi(hh), stoi(mm), stoi(ssg));
        firstIndex = binarySearch(fechaInicio);
        if (firstIndex == -1) {
            cout << "La fecha de inicio de búsqueda no fue encontrada, ingrésela de nuevo" << endl;
        }
    }while(firstIndex == -1);


    do {
        cout << "Ingrese la fecha en la cual quiere terminar de buscar: " << endl;
        cout << "Mes: " << endl;
        cin >> mes;
        cout << "Día: " << endl;
        cin >> dia;
        cout << "Hora: " << endl;
        cin >> hora;
        string hh = hora.substr(0, 2);
        string mm = hora.substr(3, 2);
        string ssg = hora.substr(6, 2);
        dateTime fechaFin(mes, dia, stoi(hh), stoi(mm), stoi(ssg));
        lastIndex = this -> binarySearch(fechaFin);
    }while(lastIndex == -1);

    if(bit[firstIndex].getFecha() > bit[lastIndex].getFecha()){
        cout << "La fecha de inicio de búsqueda es mayor a la fecha final de búsqueda, reintentar." << endl;
    }else if(bit[firstIndex].getFecha() == bit[lastIndex].getFecha()){
        cout << "Las fechas son iguales, mostrando un solo registro..." << endl;
        bit[firstIndex].imprimir();
    }else if(bit[firstIndex].getFecha() < bit[lastIndex].getFecha()){
        int contador = firstIndex;
        cout << "----------------------------------------------------------" << endl;
        cout << "Estos son los registros comprendidos en las fechas dadas: " << endl;
        cout << "----------------------------------------------------------" << endl;
        ofstream consulta("consulta.txt");
        std::string lineaRegistro;
        if(consulta.is_open()){
          while(contador <= lastIndex){
              bit[contador].imprimir();
              lineaRegistro = bit[contador].getLine();
              consulta << lineaRegistro << "\n";
              contador++;
        }
        consulta.close();
        }else{
          std::cout << "El archivo de consulta no ha abierto correctamente\n"; 
        }if(!consulta.is_open()){
          std::cout << "El archivo 'consulta.txt' ha cerrado correctamente" << std::endl;
        }else{
          std::cout << "WARN: El archivo 'consulta.txt' no ha cerrado correctamente\n";
        }
        
    }
}

//Complejidad O(n)
void Bitacora::crearBitacoraOrdenada() {
    ofstream bitOrdenada("bitacora_ordenada.txt");    string lineaRegistro;
    if(bitOrdenada.is_open()){
      for(int i = 0; i<this->size; i++){
          lineaRegistro = bit[i].getLine();
          bitOrdenada << lineaRegistro << "\n";
      }
    }else{
      std::cout << "El archivo con la bitácora ordenada no se ha creado correctamente\n";
    }
    bitOrdenada.close();
    if(!bitOrdenada.is_open()){
      std::cout << "El archivo 'bitacora_ordenada.txt' ha cerrado correctamente\n";
    }else{
      std::cout<<"WARN: El archivo 'bitacora_ordenada.txt' no ha cerrado correctamente\n";
    }
}

#endif //ACTINTEGRAL2_3_BITACORA_H
