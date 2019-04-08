#pragma once
#include <iostream>
using std::string;
namespace ariel{

//strings that ilustrates the enum variables
const string type[9]={"km",   "m",  "cm",   "hour", "min", "sec",   "ton",   "kg",  "g"};

//values that ilustrates the enum values for each type
const long value[9]={ 100000 ,100,   1     ,3600,    60,     1,    1000000, 1000,   1  };

enum  Unit {
//distance units

KM=0,//number 0  (kilometer)
M=1,//number 1  (meter)
CM=2,//number 2 (centimeter)



//time units

HOUR=3,//number 3 (Hour)
MIN=4,//number 4  (minute)
SEC=5, //number 5


// wheight units

TON=6, //number 6 (1000 kilograms)
KG=7, //number 7 (kilograms)
G=8 //number 8 (gram)

};//unit


}//namespace ariel
