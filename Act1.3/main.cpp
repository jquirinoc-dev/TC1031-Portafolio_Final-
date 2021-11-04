/* La funcion de este programa es leer un archivo de texto en el que tenemos registros con fechas y con el algoritmo de 
ordenamiento QuickSort, ordenamos un arreglo
y desplegamos en pantalla un rango de registros en base a dos fechas delimitantes introducidas por el usuario. 

Jonathan Joaquín Quirino Carrasco | A01640100

Fecha de creación: Jueves 16 de Septiembre 2021
Fecha de modificación: Jueves 7 de Octubre 2021

*/

#include <iostream>
#include <fstream>
#include <vector>
#include "dateTime.h"
#include "Log.h"



/* Funcion principal del programa */
int main(){

    Log newLog;

    std::vector<Log> vectorLogs = newLog.vectorLogs();
    std::cout << vectorLogs.size() << std::endl;

    std::cout << "El arreglo esta siendo leido de bitacora.txt y ordenado" << std::endl;


    newLog.quickSort(vectorLogs, 0, vectorLogs.size() - 1);
    
    std::cout << "El arreglo ha sido ordenado!!" << std::endl;
    std::cout << vectorLogs.size() << std::endl;

    newLog.writeToNewTxt(vectorLogs, "bitacora_ordenada.txt");
    std::cout << vectorLogs.size() << std::endl;
   
    std::string val1;
    std::string val2;

    std::cout << "Introduzca los dos registros a buscar (Por fecha y hora en orden ascendente, ej. :  \n'Oct 08 02:41:40'\n'Oct 20 12:35:02'" << std::endl;

    std::cout << "Fecha de inicio:" << std::endl;
    std::getline(std::cin, val1);

    std::string month = val1.substr(0,3);
    int day = stoi(val1.substr(4,6));
    int hour = stoi(val1.substr(7,9));
    int min = stoi(val1.substr(10,12));
    int sec = stoi(val1.substr(13,15));

    dateTime fecha1(month, day, hour, min, sec);

    std::cout << "Fecha de fin:" << std::endl;
    std::getline(std::cin, val2);

    month = val2.substr(0,3);
    day = stoi(val2.substr(4,6));
    hour = stoi(val2.substr(7,9));
    min = stoi(val2.substr(10,12));
    sec = stoi(val2.substr(13,15));

    dateTime fecha2(month, day, hour, min, sec);

    int res1, res2;
    
    res1 =  newLog.binarySearch(vectorLogs, vectorLogs.size(), fecha1);
    res2 =  newLog.binarySearch(vectorLogs, vectorLogs.size(), fecha2);

    if (res1 == -1 || res2 == -1){
        std::cout << "Las fechas o alguna de las fechas introducidas no han sido encontradas en los registros.\nIntenta correr de nuevo el programa e introducir fechas diferentes" << std::endl;
    } else {
        newLog.printRange(vectorLogs, res1, res2);
    }
    


    return 0;
}