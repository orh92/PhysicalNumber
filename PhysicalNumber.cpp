#include "PhysicalNumber.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;
using std::istream, std::ostream;
using ariel::PhysicalNumber;
using ariel::Unit;


//constructor for phy number with num and type
PhysicalNumber::PhysicalNumber(const double num,const Unit type){
//check if the unit type is legal?
this->num=num;
this->type=type;
}//end constructor by getting values



//constructor for phy num by getting an phy num and build like him
PhysicalNumber::PhysicalNumber(const PhysicalNumber &object){
//check if the unit type is legal?
this->num=object.num;
this->type=object.type;
}//end constructor by getting object



//operator =
PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber &phyNumber){
this->num=phyNumber.num;
this->type=phyNumber.type;
return *this;
}//end operator =



//operator +=
 PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &phyNumber){
if((this->type/3 )!=(phyNumber.type/3)){throw std::invalid_argument("not the same type of unit(+= operator faild)");}
else{
this->num+=(phyNumber.num*(double(value[phyNumber.type])/value[this->type]));//casting the new number to my value type
return *this;}

}//end operator +=



//operator -=
 PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber &phyNumber){
if((this->type/3 )!=(phyNumber.type/3)){throw std::invalid_argument("not the same type of unit(-= operator faild)");}
else{
this->num-=(phyNumber.num*(double(value[phyNumber.type])/value[this->type]));//casting the new number to my value type
}
return *this;
}//end operator -=



//++ operator return the value after++ (befor)
PhysicalNumber& PhysicalNumber::operator++(){
++this->num;
return *this;
}//end ++ operator befor



//++ operator that return the value and after that ++(after)
PhysicalNumber PhysicalNumber::operator++(int num){
PhysicalNumber numBeforthePlusPLus=PhysicalNumber(*this);
++this->num;
return numBeforthePlusPLus;
}//end ++ operator after



//-- operator return the value after-- (befor)
PhysicalNumber& PhysicalNumber::operator--(){
--this->num;
return *this;
}//end -- operator befor



//-- operator that return the value and after that --(after)
PhysicalNumber PhysicalNumber::operator--(int num){
PhysicalNumber numBefortheMinusMinus=PhysicalNumber(*this);
--this->num;
return numBefortheMinusMinus;
}//end -- operator after



// << operator output friend function
ostream& ariel::operator<<(ostream& os,const PhysicalNumber& num){
return os<< num.num<<"[" << type[num.type]<<"]";
}

//  >> operator input friend function
istream& ariel::operator>>(istream& is,PhysicalNumber& num){
double number;
string st="";
is>>number>>st;
//take the number and insert to phynumber,if its not a number throw exception
try{num.num=number;}catch(...){throw std::invalid_argument("invalid input of double");}
//after done with number, check the string if he is exist in the enum class
const std::string st1=st.substr(1,(st.size()-2));
for(int i=0;i<(sizeof(type)/sizeof(type[0]));i++){
if(st1==type[i]){ 
num.type= Unit(i);
return is; }
}
throw std::invalid_argument("invalid input of the string");
return is;

}


//operator +
const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& phyNumber)const{
if(this->type/3 != phyNumber.type/3){throw std::invalid_argument("canot use the (+ operator) because diffrent types");}
else{
double number=(this->num+(phyNumber.num)*(double(value[phyNumber.type])/value[this->type]));
return PhysicalNumber(number,this->type);
}
}//end operator +


//operator +
const PhysicalNumber PhysicalNumber::operator+()const{
return PhysicalNumber(this->num,this->type);
}//end operator +


//operator -
const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &phyNumber)const{
if(this->type/3 != phyNumber.type/3){throw std::invalid_argument("canot use the (- operator) because diffrent types");}
else{
double number=(this->num-(phyNumber.num)*(double(value[phyNumber.type])/value[this->type]));
return PhysicalNumber(number,this->type);
}
}//end operator -


//operator -
const PhysicalNumber PhysicalNumber::operator-()const{
return PhysicalNumber(-this->num,this->type);
}//end operator -


bool ariel::operator<=(const PhysicalNumber &num1,const PhysicalNumber &num2){
if(num1.type/3 != num2.type/3){throw std::invalid_argument("canot use the (<= operator) because diffrent types");}
else{
//do the cast to the num2 to the type of num1 and then check
PhysicalNumber newNum=PhysicalNumber(num2);
newNum.num=newNum.num*(double(value[newNum.type])/value[num1.type]);
newNum.type=num1.type;
return(num1.num<=newNum.num);
}
}//end <= operator


bool ariel::operator>=(const PhysicalNumber &num1,const PhysicalNumber &num2){
if(num1.type/3 != num2.type/3){throw std::invalid_argument("canot use the (>= operator) because diffrent types");}
else{
PhysicalNumber newNum=PhysicalNumber(num2);
newNum.num=newNum.num*(double(value[newNum.type])/value[num1.type]);
newNum.type=num1.type;
return(num1.num>=newNum.num);

}
}//end >= operator


bool ariel::operator!=(const PhysicalNumber &num1,const PhysicalNumber &num2){
if(num1.type/3 != num2.type/3){throw std::invalid_argument("canot use the (!= operator) because diffrent types");}
else{
PhysicalNumber newNum=PhysicalNumber(num2);
newNum.num=newNum.num*(double(value[newNum.type])/value[num1.type]);
newNum.type=num1.type;
return(num1.num!=newNum.num);

}
}//end != operator


bool ariel::operator<(const PhysicalNumber &num1,const PhysicalNumber &num2){
if(num1.type/3 != num2.type/3){throw std::invalid_argument("canot use the (< operator) because diffrent types");}
else{
PhysicalNumber newNum=PhysicalNumber(num2);
newNum.num=newNum.num*(double(value[newNum.type])/value[num1.type]);
newNum.type=num1.type;
return(num1.num<newNum.num);

}
}//end < operator


bool ariel::operator>(const PhysicalNumber &num1,const PhysicalNumber &num2){
if(num1.type/3 != num2.type/3){throw std::invalid_argument("canot use the (> operator) because diffrent types");}
else{
PhysicalNumber newNum=PhysicalNumber(num2);
newNum.num=newNum.num*(double(value[newNum.type])/value[num1.type]);
newNum.type=num1.type;
return(num1.num>newNum.num);

}
}//end > operator


bool ariel::operator==(const PhysicalNumber &num1,const PhysicalNumber &num2){
if(num1.type/3 != num2.type/3){throw std::invalid_argument("canot use the (== operator) because diffrent types");}
else{
PhysicalNumber newNum=PhysicalNumber(num2);
newNum.num=newNum.num*(double(value[newNum.type])/value[num1.type]);
newNum.type=num1.type;
return(num1.num==newNum.num);

}
}//end == operator



