#include "Unit.h"
#include <iostream>
#include <exception>
using std::istream;
using std::ostream;

namespace ariel{


class PhysicalNumber{
double num;//the physical number
Unit type;//the type of the physical number

public:

//constructors
PhysicalNumber(const double phyNum,const Unit type);     //constructor by getting all the values
PhysicalNumber(const PhysicalNumber &object);   //constructing by getting object

friend ostream& operator<<(ostream& os,const PhysicalNumber& num);
friend istream& operator>>(istream& os,PhysicalNumber& num);

//boolean operators
friend bool operator<=(const PhysicalNumber &num1,const PhysicalNumber &num2);
friend bool operator>=(const PhysicalNumber &num1,const PhysicalNumber &num2);
friend bool operator!=(const PhysicalNumber &num1,const PhysicalNumber &num2);
friend bool operator<(const PhysicalNumber &num1,const PhysicalNumber &num2);
friend bool operator>(const PhysicalNumber &num1,const PhysicalNumber &num2);
friend bool operator==(const PhysicalNumber &num1,const PhysicalNumber &num2);

//equal operator 
PhysicalNumber& operator=(const PhysicalNumber &phyNumber);

//+= -= operators
PhysicalNumber& operator+=(const PhysicalNumber &phyNumber);   
PhysicalNumber& operator-=(const PhysicalNumber &phyNumber);

//++ --  post/ pre operators
PhysicalNumber& operator++();
PhysicalNumber  operator++(int num);
PhysicalNumber& operator--();
PhysicalNumber  operator--(int num);

//+ / - operators
const PhysicalNumber operator+(const PhysicalNumber &phyNumber)const;
const PhysicalNumber operator+()const;
const PhysicalNumber operator-(const PhysicalNumber &phyNumber)const;
const PhysicalNumber operator-()const;

};//end PhysicalNumber

 ostream& operator<<(ostream& os,const PhysicalNumber& num);
 istream& operator>>(istream& os,PhysicalNumber& num);



 bool operator<=(const PhysicalNumber &num1,const PhysicalNumber &num2);
 bool operator>=(const PhysicalNumber &num1,const PhysicalNumber &num2);
 bool operator!=(const PhysicalNumber &num1,const PhysicalNumber &num2);
 bool operator<(const PhysicalNumber &num1,const PhysicalNumber &num2);
 bool operator>(const PhysicalNumber &num1,const PhysicalNumber &num2);
 bool operator==(const PhysicalNumber &num1,const PhysicalNumber &num2);
}//namespace ariel
