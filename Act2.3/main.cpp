#include "Log.h"
#include "DoubleLinkedList.h"
#include "dateTime.h"
#include <string>
#include <iostream>

int main(){

    /* DoubleLinkedList<Log> myLogList; */
    DoubleLinkedList<Log> myLogList;
    int n = 0;

    myLogList.loadLogs("bitacora.txt");
    /* myLogList.printListRange(0, myLogList.getNumElements()); */

    /* myLogList.writeToNewTxt("bitacora_nueva.txt", 0, myLogList.getNumElements() - 1); */


    /* printLogs(myLogList, n); */
    myLogList.iterativeQuickSort();
    //printLogs(myLogList, n);
    myLogList.writeToNewTxt("bitacora_ordenada.txt", 0, myLogList.getNumElements() - 1);

    std::string val1, val2;

    std::cout << "\n\n----Captura de los datos para la primera busqueda----" << std::endl;
    std::cout << "Introduzca los dos registros a buscar (Por fecha y hora en orden ascendente, ej. :  \n'Oct 08 02:41:40'\n'Oct 20 12:35:02'" << std::endl;
    
    std::cout << "Fecha de inicio:" << std::endl;
    std::getline(std::cin, val1);

    std::string month = val1.substr(0,3);
    int day = stoi(val1.substr(4,6));
    int hour = stoi(val1.substr(7,9));
    int min = stoi(val1.substr(10,12));
    int sec = stoi(val1.substr(13,15));

    dateTime fecha1(month, day, hour, min, sec);

    int res1, res2;
    
    res1 =  myLogList.binarySearch(fecha1);

    std::cout << "Fecha de fin:" << std::endl;
    std::getline(std::cin, val2);

    month = val2.substr(0,3);
    day = stoi(val2.substr(4,6));
    hour = stoi(val2.substr(7,9));
    min = stoi(val2.substr(10,12));
    sec = stoi(val2.substr(13,15));

    dateTime fecha2(month, day, hour, min, sec);

    res2 =  myLogList.binarySearch(fecha2);

    if (res1 == -1 || res2 == -1){
        std::cout << "Las fechas o alguna de las fechas introducidas no han sido encontradas en los registros.\nIntenta buscar esas fechas más adelante" << std::endl;
    } else {
        myLogList.printRange(res1, res2);
        myLogList.writeToNewTxt("test01.txt", res1, res2);
    }

    
    
    std::cout << "\n\n----Captura de los datos para la segunda busqueda----" << std::endl;
    std::cout << "Introduzca los dos registros a buscar (Por fecha y hora en orden ascendente, ej. :  \n'Oct 08 02:41:40'\n'Oct 20 12:35:02'" << std::endl;
    
    std::cout << "Fecha de inicio:" << std::endl;
    std::getline(std::cin, val1);

    month = val1.substr(0,3);
    day = stoi(val1.substr(4,6));
    hour = stoi(val1.substr(7,9));
    min = stoi(val1.substr(10,12));
    sec = stoi(val1.substr(13,15));

    dateTime fecha3(month, day, hour, min, sec);
    
    int res3, res4;
    
    res3 =  myLogList.binarySearch(fecha3);

    std::cout << "Fecha de fin:" << std::endl;
    std::getline(std::cin, val2);

    month = val2.substr(0,3);
    day = stoi(val2.substr(4,6));
    hour = stoi(val2.substr(7,9));
    min = stoi(val2.substr(10,12));
    sec = stoi(val2.substr(13,15));

    dateTime fecha4(month, day, hour, min, sec);

    res4 =  myLogList.binarySearch(fecha4);

    if (res3 == -1 || res4 == -1){
        std::cout << "Las fechas o alguna de las fechas introducidas no han sido encontradas en los registros.\nIntenta buscar esas fechas más adelante" << std::endl;
    } else {
        myLogList.printRange(res3, res4);
        myLogList.writeToNewTxt("test02.txt", res3, res4);
    }
    

    std::cout << "\n\n----Captura de los datos para la tercera busqueda----" << std::endl;
    std::cout << "Introduzca los dos registros a buscar (Por fecha y hora en orden ascendente, ej. :  \n'Oct 08 02:41:40'\n'Oct 20 12:35:02'" << std::endl;
    
    std::cout << "Fecha de inicio:" << std::endl;
    std::getline(std::cin, val1);

    month = val1.substr(0,3);
    day = stoi(val1.substr(4,6));
    hour = stoi(val1.substr(7,9));
    min = stoi(val1.substr(10,12));
    sec = stoi(val1.substr(13,15));

    dateTime fecha5(month, day, hour, min, sec);
    
    int res5, res6;
    
    res5 =  myLogList.binarySearch(fecha5);

    std::cout << "Fecha de fin:" << std::endl;
    std::getline(std::cin, val2);

    month = val2.substr(0,3);
    day = stoi(val2.substr(4,6));
    hour = stoi(val2.substr(7,9));
    min = stoi(val2.substr(10,12));
    sec = stoi(val2.substr(13,15));

    dateTime fecha6(month, day, hour, min, sec);

    res6 =  myLogList.binarySearch(fecha6);

    if (res5 == -1 || res6 == -1){
        std::cout << "Las fechas o alguna de las fechas introducidas no han sido encontradas en los registros.\nIntenta buscar esas fechas más adelante" << std::endl;
    } else {
        myLogList.printRange(res5, res6);
        myLogList.writeToNewTxt("test03.txt", res5, res6);
    }




    /* std::cout << n; */

    return 0;
}