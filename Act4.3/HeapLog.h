#ifndef _HEAPLOG_H_
#define _HEAPLOG_H_

#include <iostream>

class HeapLog{
    private:
        std::string ip;
        int numAdj;
    public:
        HeapLog();
        HeapLog(std::string, int);
        int getNumAdj();
};

HeapLog::HeapLog(){}

HeapLog::HeapLog(std::string i, int n){
    ip = i;
    numAdj = n;
}

HeapLog::getNumAdj(){
    return numAdj;
}
