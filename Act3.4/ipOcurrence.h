#ifndef _IPOCURRENCE_H_
#define _IPOCURRENCE_H_

#include <iostream>
#include <string>

Class ipOcurrence {
    public:
        ipOcurrence(std::string, int);
        std::string getLine();
    private:
        std::string ip;
        int ocurrences;
};

ipOcurrences::ipOcurrences(std::string ipa, int oc){
    ip = ipa;
    ocurrences = oc;
}

std::string ipOcurrences::getLine(){
    return ipa + " " + std::to_string(ocurrences);
}