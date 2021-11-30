#include<cmath> 
#include "ipAddress.h"

ipAddress::ipAddress() {
    ipString = "0.0.0.0:0000";
    ipNoPort = "0.0.0.0";
    gradoIp = 0;
}

ipAddress::ipAddress(std::string _ip) {
    ipString = _ip;
    int pos1 = ipString.find(":");
    ipNoPort = ipString.substr(0, pos1);
    std::string temporal = ipNoPort;
    gradoIp = 0;

    for (int i = 0; i < 4; i++) {

        int separador = ipNoPort.find(".");
        std::string temp = ipNoPort.substr(0, separador);
        ipValor[i] = std::stoi(temp);

        temp = ipNoPort.substr(0, separador + 1);
        ipNoPort = ipNoPort.substr(temp.length(), ipNoPort.length());

    }
    ipNoPort = temporal;

    numericIp =
            ipValor[0]*std::pow(256,3) + 
            ipValor[1]*std::pow(256,2) +
            ipValor[2]*std::pow(256,1) +
            ipValor[3]*std::pow(256,0);
    
}

std::string ipAddress::getIp() {
    return ipString;
}

void ipAddress::setIpGrado(int g){
  gradoIp = g;
}

void ipAddress::addToDegree(){
  gradoIp++;
}

int ipAddress::getIpGrado(){
  return gradoIp;
}

std::string ipAddress::getIpNoPort() {
    return ipNoPort;
}

long int ipAddress::getNumericIp(){
  return numericIp;
}

bool ipAddress::operator == (ipAddress other) {
  
    return numericIp == other.getNumericIp();


}

bool ipAddress::operator != (ipAddress other) {
  
    return numericIp != other.getNumericIp();

}

bool ipAddress::operator > (ipAddress other) {

    if (numericIp > other.getNumericIp()) {

      return true;
 
    } else {

    return false;

    }

}

bool ipAddress::operator<( ipAddress other) {

    if (numericIp < other.getNumericIp()) {

        return true;

    } else {

        return false;

    }

}

bool ipAddress::operator>=( ipAddress other) {

    if (numericIp >= other.getNumericIp()) {

        return true;

    } else {

        return false;

    }

}

bool ipAddress::operator<=( ipAddress other) {

    if (numericIp <= other.getNumericIp()) {

        return true;

    } else {

        return false;

    }

}