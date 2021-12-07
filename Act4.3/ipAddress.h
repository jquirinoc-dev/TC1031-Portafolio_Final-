#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <iostream>

class ipAddress {
    public:
        ipAddress();
        ipAddress(std::string);
        std::string getIp();
        std::string getIpNoPort();
        long int getNumericIp();
        int getIpGrado();
        void setIpGrado(int);
        void addToDegree();
        bool operator ==(ipAddress);
        bool operator !=(ipAddress);
        bool operator >(ipAddress);
        bool operator <(ipAddress);
        bool operator >=(ipAddress);
        bool operator <=(ipAddress);


    private:
        std::string ipString;
        std::string ipNoPort;
        int ipValor[4];
        long int numericIp;
        int gradoIp;
};




#endif // _IPADDRESS_H_