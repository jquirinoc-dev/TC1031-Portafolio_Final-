#ifndef _LOG_H_
#define _LOG_H_

#include <iostream>
#include "dateTime.h"

class Log{
    private:
        dateTime date;
        std::string dateString;
        std::string ipDesc;
    public:
        Log();
        Log(dateTime, std::string, std::string);
        bool operator !=(const Log&);
        bool operator ==(const Log&);
        bool operator >(const Log&);
        bool operator <(const Log&);
        bool operator >=(const Log&);
        bool operator <=(const Log&);

};


Log::Log(){
    dateString = "Date";
    ipDesc = "ip and Desc";
}

Log::Log(dateTime date_, std::string dateS, std::string ip){
    date = date_;
    dateString = dateS;
    ipDesc = ip;
}

bool Log::operator==(const Log &other) {
  return this->date == other.date && this->dateString == other.dateString && this->ipDesc == other.ipDesc;
}

bool Log::operator!=(const Log &other) {
  return this->date != other.date || this->dateString != other.dateString || this->ipDesc != other.ipDesc;
}

bool Log::operator>(const Log &other) {
    return this->date > other.date;
}

bool Log::operator<(const Log &other) {
    return this->date < other.date;
}

bool Log::operator>=(const Log &other) {
    return this->date >= other.date;
}

bool Log::operator<=(const Log &other) {
    return this->date <= other.date;
}

#endif // _LOG_H_