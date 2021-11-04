/* La funcion de este programa es leer un archivo de texto en el que tenemos registros con IPs frecuentadas y cargar cada
uno de estos registros a una posicion de una estructura MaxHeap, ordenar esta lista por IP, obtener las 5 IP mas frecuentadas
y escribir los resultados en archivos .txt

Jonathan Joaquín Quirino Carrasco | A01640100

Fecha de creación: Jueves 28 de Octubre 2021
Fecha de modificación: Sabado 6 de Noviembre 2021

*/


#include <iostream>
#include "MaxHeap.h"
#include "Log.h"
#include "ipAddress.h"
#include "ipOcurrence.h"

//Funcion principal de nuestro programa.
int main(){
    
    MaxHeap<Log> myMaxHeap(16807);

    myMaxHeap.loadLogs("BitacoraHeap.txt");
    myMaxHeap.heapSort();
    myMaxHeap.writeToNewTxt("bitacora_ordenada.txt", 0, myMaxHeap.getSize() - 1);

    myMaxHeap<ipOcurrence> myNewMaxHeap(800);
}