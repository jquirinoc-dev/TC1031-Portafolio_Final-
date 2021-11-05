#ifndef _IPOCURRENCE_H_
#define _IPOCURRENCE_H_

#include <iostream>
#include <string>

class ipOcurrence {
    public:
        ipOcurrence();
        ipOcurrence(std::string, int);
        std::string getAll();
        int getIp();
    private:
        std::string ip;
        int ocurrences;
};

ipOcurrence::ipOcurrence(){
    ip = "";
    ocurrences = 0;
}

ipOcurrence::ipOcurrence(std::string ipa, int oc){
    ip = ipa;
    ocurrences = oc;
}

std::string ipOcurrence::getAll(){
    return ip + " " + ":" + std::to_string(ocurrences);
}

int ipOcurrence::getIp(){
    return ocurrences;
}

#endif