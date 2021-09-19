/* La funcion de este programa es leer un archivo de texto en el que tenemos registros con fechas y con el algoritmo de ordenamiento QuickSort, ordenamos un arreglo
y desplegamos en pantalla un rango de registros en base a dos fechas delimitantes introducidas por el usuario. 

Jonathan Joaquín Quirino Carrasco | A01640100

Fecha de creación: Jueves 16 de Septiembre 2021
Fecha de modificación: Domingo 19 de Septiembre 2021

*/

#include <iostream>
#include <fstream>
#include <vector>
#include "dateTime.h"


/* Una estructura la cual contendrá un objeto fecha, un string de fecha y un string de ip + descripcion */
struct LOG{
    dateTime date;
    std::string dateString;
    std::string ipDesc;
} logs;

/* En esta funcion se intercambian las posiciones de dos valores tipo fecha en, este caso, un vector */
void swap(LOG* a, LOG* b){
    LOG t = *a;
    *a = *b;
    *b = t;
}

/* Se crea una particion en nuestro vector para empezar iterar a partir de ella, se nos regresa i + 1 */
int partition (std::vector<LOG> &arr, int low, int high){
    
    dateTime pivot = arr[high].date;
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++){

        dateTime dateIndx = arr[j].date;

        if (dateIndx <= pivot){
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* Con esta funcion ordenamos nuestro vector, toma como parametros el vector, la posicion inicial y la final */ 
void quickSort(std::vector<LOG> &arr, int low, int high){
    if (low < high){

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* En este funcion recibimos nuestro vector vectorLogs, el tamaño n del mismo y el valor a buscar k 
Obtenemos la posición donde se encuentra k. De no estar, se nos regresa -1*/
int binarySearch(std::vector<LOG> vectorLogs, int n, dateTime k) {
  int low = 0;
  int high = n - 1;
  

  while (low <= high) {
    int m = low + (high - low) / 2;

    if (k == vectorLogs[m].date){
        return m;
    }else if (k < vectorLogs[m].date) {
        high = m - 1;
    }else {
        low = m + 1;
    }
      
  }
  return -1;
}

/* Recibimos nuestro vector y una variable int igual a cero la cual servirá para calcular el tamaño de nuestro vector
En esta funcion leemos el archivo bitacora.txt y, por cada linea, creamos un struct tipo LOG que guarda los datos
para manipular y ordenar nuestro vector mas adelante */
void loadLogs(std::vector<LOG> &vectorLogs, int &logNums){
    logNums = 0;
    std::string month = "";
    std::string day = "";
    std::string time = "";

    std::ifstream file;

    file.open("bitacora.txt");

    std::string line;

    while (getline(file, line)){
        
        std::string month = line.substr(0,3);
        int day = stoi(line.substr(4,6));
        int hour = stoi(line.substr(7,9));
        int min = stoi(line.substr(10,12));
        int sec = stoi(line.substr(13,15));
        std::string fullDate = line.substr(0,15);
        std::string ipDesc = line.substr(16, line.size());
        

        dateTime date(month, day, hour, min, sec);

        LOG newLog;
        newLog.date = date;
        newLog.dateString = fullDate;
        newLog.ipDesc = ipDesc;

        
        vectorLogs.push_back(newLog);

        logNums++;
    }
}

/* Por cada posicion del vector generamos un string que iremos escribiendo linea por linea en un archivo nuevo llamado bitacora_ordenada.txt */
void writeToNewTxt(std::vector<LOG> vectorLogs, int numLogs){
    
    std::ofstream out("bitacora_ordenada.txt");

    for (int i = 0; i < numLogs; i++){
        std::string line;

        if (i == numLogs - 1){
            line = vectorLogs[i].dateString + " " + vectorLogs[i].ipDesc;
            out << line;
        }else {
            line = vectorLogs[i].dateString + " " + vectorLogs[i].ipDesc + "\n";
            out << line;
        }
        
    }

    out.close();
}

/* Imprimimos el rango de valores en nuestro vectordependiendo de las posiciones (x, y) que hemos obtenido de nuestra binarySearch, 
donde n es el tamaño del vector */
void printRange(std::vector<LOG> vectorLogs, int n, int x, int y){

    for (int i = x; i <= y; i++){
        std::cout << vectorLogs[i].dateString << " ";
        std::cout << vectorLogs[i].ipDesc << std::endl;
    }
}


/* Funcion principal del programa */
int main(){

    std::vector<LOG> vectorLogs;
    int n = 0;

    std::cout << "El arreglo esta siendo leido de bitacora.txt y ordenado" << std::endl;

    loadLogs(vectorLogs, n);
    quickSort(vectorLogs, 0, n - 1);
    
    std::cout << "El arreglo ha sido ordenado!!" << std::endl;

    writeToNewTxt(vectorLogs, n);

    

    std::string val1;
    std::string val2;
    int res1, res2 = -1;

    std::cout << "Introduzca los dos registros a buscar (Por fecha y hora en orden ascendente, ej. :  \n'Oct 08 02:41:40'\n'Oct 20 12:35:02'" << std::endl;

    std::cout << "Fecha de inicio:" << std::endl;
    std::getline(std::cin, val1);

    std::cout << "Fecha de fin:" << std::endl;
    std::getline(std::cin, val2);

    std::string month = val1.substr(0,3);
    int day = stoi(val1.substr(4,6));
    int hour = stoi(val1.substr(7,9));
    int min = stoi(val1.substr(10,12));
    int sec = stoi(val1.substr(13,15));

    dateTime fecha1(month, day, hour, min, sec);

    res1 =  binarySearch(vectorLogs, n, fecha1);

    month = val2.substr(0,3);
    day = stoi(val2.substr(4,6));
    hour = stoi(val2.substr(7,9));
    min = stoi(val2.substr(10,12));
    sec = stoi(val2.substr(13,15));

    dateTime fecha2(month, day, hour, min, sec);
    res2 =  binarySearch(vectorLogs, n, fecha2);

    if (res1 == -1 || res2 == -1){
        std::cout << "Las fechas o alguna de las fechas introducidas no han sido encontradas en los registros.\nIntenta correr de nuevo el programa e introducir fechas diferentes" << std::endl;
    } else{
        printRange(vectorLogs, n, res1, res2);
    }
    


    return 0;
}