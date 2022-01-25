/*
 Viernes, 15 de octubre del 2021
 A01639631 Alan Paul García Rosales
 
 Compilacion para debug:  
    g++ -std=c++17 -g -o main *.cpp 
  Ejecucion con valgrind:
    valgrind --leak-check=full -v ./main
  
  Compilacion para ejecucion:  
    g++ -std=c++17 -O3 -o main *.cpp 
  Ejecucion:
    ./main
 
 https://replit.com/join/prmmaxdjov-paulgarciaro
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "dateTime.h"
#include "Registro.h"
#include "DoubleLinkedList.h"
#include "Bitacora.h"

using namespace std;

int main() {
    //Creamos un vector donde se guardaran los registros de la bitácora desordenada
    Bitacora binnacle;
    binnacle.leerDatos(); // Leemos los datos del archivo bitacora.txt
    binnacle.sort();//Funcion para ordenar la DoubleLinkedList de tipo registro
    binnacle.crearBitacoraOrdenada();//Funcion para crear el archivo con la bitacora ordenada
    binnacle.busquedaDatos();//Funcion para realizar la búsqueda de datos

    return 0;
}

/*

  Referencias bibliográficas:

GeeksforGeeks. (2021, septiembre 6). Iterative Quick Sort. Recuperado 15 de octubre de 2021, de https://www.geeksforgeeks.org/iterative-quick-sort/

GeeksforGeeks. (2021, septiembre 21). Doubly Linked List | Set 1 (Introduction and Insertion). Recuperado 15 de octubre de 2021, de https://www.geeksforgeeks.org/doubly-linked-list/

GeeksforGeeks. (2021, septiembre 21). QuickSort on Doubly Linked List. Recuperado 15 de octubre de 2021, de https://www.geeksforgeeks.org/quicksort-for-linked-list/?

GeeksforGeeks. (2021, octubre 15). Merging and Sorting Two Unsorted Stacks. Recuperado 15 de octubre de 2021, de https://www.geeksforgeeks.org/merging-sorting-two-unsorted-stacks/

Martínez, M. M. (s. f.). Método Quick Sort. Universidad Autónoma del Estado de Hidalgo. Recuperado 15 de octubre de 2021, de http://cidecame.uaeh.edu.mx/lcc/mapa/PROYECTO/libro9/mtodo_quick_sort.html

Quicksort: Iterative or Recursive. (2012, 23 septiembre). Stack Overflow. Recuperado 15 de octubre de 2021, de https://stackoverflow.com/questions/12553238/quicksort-iterative-or-recursive

*/