#include "Log.h"
#include "DoubleLinkedList.h"


/*
void writeToNewTxt(DoubleLinkedList<Log> logList, int start, int end, std::string fileName){
    
    std::ofstream out(fileName);

    for (int i = start; i <= end; i++){
        std::string line;

        if (i == end){
            line = logList.getData(i).getStringDate() + " " + logList.getData(i).getIpDesc();
            out << line;
        }else {
            line = logList.getData(i).getStringDate() + " " + logList.getData(i).getIpDesc() + "\n";
            out << line;
        }
        
    }

    out.close();
}

void printLogs(DoubleLinkedList<Log> logList, int n){

    for (int i = 0; i < n; i++){
        std::cout << logList.getData(i).getStringDate() << " " << logList.getData(i).getIpDesc() << std::endl;
    }
}
*/

int main(){

    /* DoubleLinkedList<Log> myLogList; */
    DoubleLinkedList<Log> myLogList;
    int n = 0;

    myLogList.loadLogs();

    

    /* printLogs(myLogList, n); */
    //myLogList.sort();
    //printLogs(myLogList, n);
    /* writeToNewTxt(myLogList, 0, n, "bitacora ordenada.txt"); */
    

    /* std::cout << n; */

    return 0;
}