#ifndef _LOG_H_
#define _LOG_H_

#include <iostream>
#include "dateTime.h"

class Log{
    private:
        dateTime date;
        // nuevos campos
        std::string mes;
        std::string dia;
        std::string hora;
        std::string minuto;
        std::string segundo;
        std::string ip;
        std::string descripcion;


    public:
        Log();
        Log(std::string m, std::string d, std::string h, std::string mi, std::string s, std::string ipa, std::string desc, dateTime date);
        dateTime getDate();
        std::string getAll();

};

Log::Log(){
  mes = "";
  dia = "";
  hora = "";
  minuto = "";
  segundo = "";
  ip = "";
  descripcion = "";
}

Log::Log(std::string m, std::string d, std::string h, std::string mi, std::string s, std::string ipa, std::string desc, dateTime dt){
  mes = m;
  dia = d;
  hora = h;
  minuto = mi;
  segundo = s;
  ip = ipa;
  descripcion = desc;
  date = dt;
}

 //O(1)
 //Regresa un dato tipo dateTime
 dateTime Log::getDate(){
    return date;
}

//O(1)
//Regresa un string con todos los datos de un Log (registro) en formato
std::string Log::getAll(){
    return mes + " " + dia + " " + hora + ":" + minuto + ":" + segundo + " " + ip + " " + descripcion + "\0";
}

#endif