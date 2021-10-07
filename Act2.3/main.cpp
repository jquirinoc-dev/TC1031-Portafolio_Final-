#include <iostream>
#include <fstream>
#include "dateTime.h"
#include "DoubleLinkedList.h"
#include "Log.h"

struct LOG{
    dateTime date;
    std::string dateString;
    std::string ipDesc;
} logs;

dateTime generateDate(std::string stringDate){

    std::string month = stringDate.substr(0,3);
    int day = stoi(stringDate.substr(4,6));
    int hour = stoi(stringDate.substr(7,9));
    int min = stoi(stringDate.substr(10,12));
    int sec = stoi(stringDate.substr(13,15));
    
    dateTime date(month, day, hour, min, sec);

    return date;
}

void loadLogs(DoubleLinkedList<std::string> &logList, int &logNums){
    logNums = 0;
    std::string month = "";
    std::string day = "";
    std::string time = "";

    std::ifstream file;

    file.open("bitacora.txt");

    std::string line;

    while (getline(file, line)){

        /* dateTime date = generateDate(line);
        std::string fullDate = line.substr(0,15);
        std::string ipDesc = line.substr(16, line.size());

        Log newLog(date, fullDate, ipDesc);
 */
        logList.addLast(line);

        logNums++;
    }
}


int main(){

    /* DoubleLinkedList<Log> myLogList; */
    DoubleLinkedList<std::string> myLogList;
    DoubleLinkedList<std::string> myStringLogList;
    int n = 0;

    loadLogs(myLogList, n);
    myLogList.printList();

    /* std::cout << n; */

    return 0;
}