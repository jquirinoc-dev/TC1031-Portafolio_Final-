#include <iostream>
#include "ipAddress.h"
#include "Log.h"

int main(){
    
    ipAddress firstip("10.15.189.242:5537");
    ipAddress newip("10.15.175.231:6166");

    /* std::cout << "Ip Decimal: " << newip.getIp(); */

    if (firstip > newip){
        std::cout << "\nfirst ip (" << firstip.getIpDecimal() << ") es mayor que newip (" << newip.getIpDecimal() << ")" << std::endl;
    }
}