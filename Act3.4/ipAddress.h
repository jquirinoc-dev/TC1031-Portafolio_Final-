#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <iostream>
#include <string>
#include <math.h>

class ipAddress {
    public:

        ipAddress();
        ipAddress(std::string);
        int getIpDecimal();
        std::string getIpString();
        bool operator ==(const ipAddress&);
        bool operator !=(const ipAddress&);
        bool operator >(const ipAddress&);
        bool operator <(const ipAddress&);
        bool operator >=(const ipAddress&);
        bool operator <=(const ipAddress&);
    
    private:
        int first;
        int second;
        int third;
        int fourth;
        int port;
        int decimalIp;
};

ipAddress::ipAddress(){}

ipAddress::ipAddress(std::string fullIp){

    first = stoi(fullIp.substr(0,2));
    second = stoi(fullIp.substr(3,5));
    third = stoi(fullIp.substr(6,9));
    fourth = stoi(fullIp.substr(10,13));
    port = stoi(fullIp.substr(14,17));

    /* std::cout << first << "." << second << "." << third << "." << fourth << ":" << port << std::endl; */

    decimalIp = (pow(256, 3) * first) + (pow(256, 2) * second) + (pow(256, 1) * third) + (pow(256, 0) * fourth);
}

int ipAddress::getIpDecimal(){
    return decimalIp;
}

std::string ipAddress::getIpString(){
  return std::to_string(first) + "." + std::to_string(second) + "." + std::to_string(third) + "." + std::to_string(fourth);
}

bool ipAddress::operator==(const ipAddress &other) {
  return this->decimalIp == other.decimalIp;
}

bool ipAddress::operator!=(const ipAddress &other) {
  return this->decimalIp != other.decimalIp;
}

bool ipAddress::operator>(const ipAddress &other) {
  return this->decimalIp > other.decimalIp;
}

bool ipAddress::operator<(const ipAddress &other) {
  return this->decimalIp < other.decimalIp;
}

bool ipAddress::operator>=(const ipAddress &other) {
  return this->decimalIp >= other.decimalIp;
}

bool ipAddress::operator<=(const ipAddress &other) {
  return this->decimalIp <= other.decimalIp;
}


#endif