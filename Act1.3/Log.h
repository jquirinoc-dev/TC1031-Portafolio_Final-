#ifndef _LOG_H_
#define _LOG_H_

#include <iostream>
#include "dateTime.h"
#include <vector>

class Log{
    private:
        dateTime date;
        // nuevos campos
        std::string mes;
        std::string dia;
        std::string hora;
        std::string minuto;
        std::string segundo;
        std::string ip;
        std::string descripcion;


    public:
        Log();
        Log(std::string m, std::string d, std::string h, std::string mi, std::string s, std::string ipa, std::string desc, dateTime date);
        dateTime getDate();
        std::string getAll();
        std::vector<Log> vectorLogs();
        void writeToNewTxt(std::vector<Log>, std::string);
        void swap(Log*, Log*);
        int partition(std::vector<Log>&, int, int);
        void quickSort(std::vector<Log>&, int, int);
        int binarySearch(std::vector<Log>, int, dateTime);
        void printRange(std::vector<Log>,int, int);

};

Log::Log(){
  mes = "";
  dia = "";
  hora = "";
  minuto = "";
  segundo = "";
  ip = "";
  descripcion = "";
}

Log::Log(std::string m, std::string d, std::string h, std::string mi, std::string s, std::string ipa, std::string desc, dateTime dt){
  mes = m;
  dia = d;
  hora = h;
  minuto = mi;
  segundo = s;
  ip = ipa;
  descripcion = desc;
  date = dt;
}

 dateTime Log::getDate(){
    return date;
}

std::string Log::getAll(){
    return mes + " " + dia + " " + hora + ":" + minuto + ":" + segundo + " " + ip + " " + descripcion + "\0";
}

std::vector<Log> Log::vectorLogs(){

    std::vector<Log> returnedVector;
    
    std::string month, day, hour, min, sec, ipa, desc;
    std::ifstream in("bitacora.txt");

    while(std::getline(in, month, ' ')){
        std::getline(in, day, ' ');
        std::getline(in,hour,':');
        std::getline(in,min,':');
        std::getline(in,sec,' ');
        std::getline(in,ipa,' ');
        std::getline(in,desc);
        //std::cout << desc << std::endl;
        dateTime dt(month, stoi(day), stoi(hour), stoi(min), stoi(sec));
        Log tmpLog(month, day, hour, min, sec, ipa, desc, dt);

        returnedVector.push_back(tmpLog);
        
        std::cout << tmpLog.getAll() << std::endl;
    }

    return returnedVector;
}

void Log::writeToNewTxt(std::vector<Log> vectorLogs, std::string txtName){
    
    std::ofstream out(txtName);

    for (int i = 0; i < vectorLogs.size(); i++){
        std::string line;

        if (i == vectorLogs.size() - 1){
            line = vectorLogs[i].getAll();
            out << line;
        }else {
            line = vectorLogs[i].getAll() + "\n";
            out << line;
        }
        
    }

    out.close();
}

void Log::swap(Log* a, Log* b){
    Log t = *a;
    *a = *b;
    *b = t;
}

int Log::partition(std::vector<Log> &arr, int low, int high){
    
    dateTime pivot = arr[high].getDate();
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++){

        dateTime dateIndx = arr[j].getDate();

        if (dateIndx <= pivot){
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Log::quickSort(std::vector<Log> &arr, int low, int high){
    if (low < high){

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int Log::binarySearch(std::vector<Log> vectorLogs, int n, dateTime k) {
  int low = 0;
  int high = n - 1;
  

  while (low <= high) {
    int m = low + (high - low) / 2;

    if (k == vectorLogs[m].getDate()){
        return m;
    }else if (k < vectorLogs[m].getDate()) {
        high = m - 1;
    }else {
        low = m + 1;
    }
      
  }
  return -1; 
}

void Log::printRange(std::vector<Log> vectorLogs, int x, int y){

    for (int i = x; i <= y; i++){
        std::cout << vectorLogs[i].getAll() << std::endl;
    }
}

#endif