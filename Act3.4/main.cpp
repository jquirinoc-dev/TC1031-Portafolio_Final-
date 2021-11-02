#include <iostream>
#include "MaxHeap.h"
#include "Log.h"
#include "ipAddress.h"


int main(){
    
    /* ipAddress firstip("10.15.189.242:5537");
    ipAddress newip("10.15.175.231:6166");

    std::cout << "Ip Decimal: " << newip.getIp();

    if (firstip > newip){
        std::cout << "\nfirst ip (" << firstip.getIpDecimal() << ") es mayor que newip (" << newip.getIpDecimal() << ")" << std::endl;
    } */

    MaxHeap<Log> myMaxHeap(16807);

    myMaxHeap.loadLogs("BitacoraHeap.txt");
    /* myMaxHeap.printMaxHeap(); */

    myMaxHeap.writeToNewTxt("test.txt", 0, myMaxHeap.getSize() - 1);

    myMaxHeap.heapSort();

    myMaxHeap.writeToNewTxt("SortTest.txt", 0, myMaxHeap.getSize() - 1);
}