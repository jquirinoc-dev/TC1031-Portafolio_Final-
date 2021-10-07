#include "Log.h"
#include "DoubleLinkedList.h"

int main(){

    /* DoubleLinkedList<Log> myLogList; */
    DoubleLinkedList<Log> myLogList;
    int n = 0;

    myLogList.loadLogs("bitacora.txt");
    myLogList.writeToNewTxt("bitacora_nueva.txt");

    

    /* printLogs(myLogList, n); */
    //myLogList.sort();
    //printLogs(myLogList, n);
    /* writeToNewTxt(myLogList, 0, n, "bitacora ordenada.txt"); */
    

    /* std::cout << n; */

    return 0;
}