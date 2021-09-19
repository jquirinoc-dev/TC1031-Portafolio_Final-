#include <iostream>
#include <fstream>
#include <vector>
#include "dateTime.h"

struct LOG{
    dateTime date;
    std::string dateString;
    std::string ipDesc;
} logs;

void swap(LOG* a, LOG* b){
    LOG t = *a;
    *a = *b;
    *b = t;
}
 
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
 
void quickSort(std::vector<LOG> &arr, int low, int high){
    if (low < high){

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(std::vector<LOG> vectorLogs, int n, dateTime k, int *compara) {
  int low = 0;
  int high = n - 1;
  
  *compara = 0;

  while (low <= high) {
    int m = low + (high - low) / 2;
    (*compara)++;
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

void printRange(std::vector<LOG> vectorLogs, int n, int x, int y){

    for (int i = x; i <= y; i++){
        std::cout << vectorLogs[i].dateString << " ";
        std::cout << vectorLogs[i].ipDesc << std::endl;
    }
}

int main(){

    std::vector<LOG> vectorLogs;
    int n = 0;

    std::cout << "El arreglo esta siendo leido de bitacora.txt y ordenado" << std::endl;

    loadLogs(vectorLogs, n);
    quickSort(vectorLogs, 0, n - 1);
    

    /* for (int i = 0; i < n; i++){
        std::cout << vectorLogs[i].dateString << " ";
        std::cout << vectorLogs[i].ipDesc << std::endl;
    } */

    std::cout << "El arreglo ha sido ordenado!!" << std::endl;

    writeToNewTxt(vectorLogs, n);

    

    std::string val1;
    std::string val2;
    int res1, res2 = -1;

    std::cout << "Introduzca los dos registros a buscar (Por fecha y hora en orden ascendente, ej. :  \n'Oct 08 02:41:40'\n'Oct 20 12:35:02'" << std::endl;

    std::getline(std::cin, val1);
    /* std::cout << val1 << std::endl; */
    std::getline(std::cin, val2);
    /* std::cout << val2 << std::endl; */

    int comparaciones = 0;

    std::string month = val1.substr(0,3);
    int day = stoi(val1.substr(4,6));
    int hour = stoi(val1.substr(7,9));
    int min = stoi(val1.substr(10,12));
    int sec = stoi(val1.substr(13,15));

    dateTime fecha1(month, day, hour, min, sec);

    res1 =  binarySearch(vectorLogs, n, fecha1, &comparaciones);

    month = val2.substr(0,3);
    day = stoi(val2.substr(4,6));
    hour = stoi(val2.substr(7,9));
    min = stoi(val2.substr(10,12));
    sec = stoi(val2.substr(13,15));

    dateTime fecha2(month, day, hour, min, sec);
    res2 =  binarySearch(vectorLogs, n, fecha2, &comparaciones);

    /* if (res1 == -1){
        std::cout << "Element not found" << std::endl;
    } else{
        std::cout << "Element date1 found in pos " << res1 << std::endl;
    }

    if (res2 == -1){
        std::cout << "Element not found" << std::endl;
    } else{
        std::cout << "Element date2 found in pos " << res2 << std::endl;
    } */

    if (res1 == -1 || res2 == -1){
        std::cout << "Las fechas o alguna de las fechas introducidas no han sido encontradas en los registros.\nIntenta correr de nuevo el programa e introducir fechas diferentes" << std::endl;
    } else{
        printRange(vectorLogs, n, res1, res2);
    }
    


    return 0;
}