#include "Log.h"
#include "DoubleLinkedList.h"

int main(){

    /* DoubleLinkedList<Log> myLogList; */
    DoubleLinkedList<Log> myLogList;
    int n = 0;

    myLogList.loadLogs("bitacora.txt");
    /* myLogList.printListRange(0, myLogList.getNumElements()); */

    myLogList.writeToNewTxt("bitacora_nueva.txt");


    /* printLogs(myLogList, n); */
    myLogList.sortUsingStacks();
    //printLogs(myLogList, n);
    myLogList.writeToNewTxt("bitacora_ordenada.txt");
    

    /* std::cout << n; */

    return 0;
}