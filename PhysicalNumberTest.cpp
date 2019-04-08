/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

//my tests
PhysicalNumber km(1, Unit::KM);
PhysicalNumber m(200, Unit::M);
PhysicalNumber cm(33, Unit::CM);

PhysicalNumber hour(1, Unit::HOUR);
PhysicalNumber min(30, Unit::MIN);
PhysicalNumber sec(6, Unit::SEC);

PhysicalNumber ton(1, Unit::TON);
PhysicalNumber kg(300, Unit::KG);
PhysicalNumber g(70, Unit::G);

PhysicalNumber Plusplus(1, Unit::KG);
PhysicalNumber Minusminus(1, Unit::KG);
PhysicalNumber Minusworth(1, Unit::KG);
PhysicalNumber Plusworth(1, Unit::KG);

PhysicalNumber big(3, Unit::KG);
PhysicalNumber small(1, Unit::KG);

PhysicalNumber worth1(1, Unit::KG);
PhysicalNumber worth2(1, Unit::KG);
PhysicalNumber print(14.4, Unit::KG);

PhysicalNumber unaryPlus(2, Unit::KG);
PhysicalNumber unaryMinus(2, Unit::KG);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

	//my test cases
        .setname("My Test case")

	
        .CHECK_OUTPUT(min+hour, "90[min]")//30min+1hour = 90min

	//distance+time = exception
	.CHECK_THROWS(km-=hour)//cant substruct time to distance
	.CHECK_THROWS(km+=min)//cant add time to distance
	.CHECK_THROWS(km-sec)//cant substruct time to distance

	//time+weight = exception
	.CHECK_THROWS(sec+=ton)//cant add weight to time
	.CHECK_THROWS(sec-=kg)	//cant substruct weight to time
	.CHECK_THROWS(sec+g)//cant add weight to time

	//wheight+distance=exception
	.CHECK_THROWS(ton+=km)//cant add distance to weight
	.CHECK_THROWS(ton-=m)//cant substruct distance to weight
	.CHECK_THROWS(ton+cm)//cant add distance to weight

	// ++ -- check
	.CHECK_OUTPUT(++Plusplus,"2[kg]")//Plusplus was 1 and ++plusplus=2
	.CHECK_OUTPUT(Plusplus++,"2[kg]")//Plusplus is 2 and after will be 3
	.CHECK_OUTPUT(Plusplus++,"3[kg]")////Plusplus is 3 and after will be 4
	.CHECK_OUTPUT(--Minusminus,"0[kg]")//Minusminus is 1..and after will be 0
	.CHECK_OUTPUT(Minusminus--,"0[kg]")//Minusminus is 0..and after will be -1
 	.CHECK_OUTPUT(Minusminus--,"-1[kg]")//Minusminus is -1..and after will be -2


	//+= -= 
	 .CHECK_OUTPUT((Plusworth+=Minusworth),"2[kg]")
	 .CHECK_OUTPUT((Minusworth-=Plusworth),"-1[kg]")

	//<= >= == != < >
	.CHECK_EQUAL(big>small,true)// big > small
	.CHECK_EQUAL(small<big,true)//small < big
	.CHECK_EQUAL(worth1==worth2,true)// worth1=1 worth2=1
	.CHECK_THROWS(big==sec)//big is not == to sec throw exception
	.CHECK_EQUAL(big>=small,true)// big > so he is >= small
	.CHECK_EQUAL(worth1>=worth2,true)// worth1=1 worth2=1 they are equal so worth1>= worth2
	.CHECK_EQUAL(worth1<=worth2,true)// worth1=1 worth2=1 they are equal so worth1<= worth2
	.CHECK_EQUAL(worth1>worth2,false)// worth1=1 worth2=1 they are equal so false
	.CHECK_EQUAL(worth1<worth2,false)// worth1=1 worth2=1 they are equal so false
	
	//print object	
	.CHECK_OUTPUT(print,"14.4[kg]")//print holds 14.4[kg] check the print function
    .CHECK_THROWS(istringstream("700[1kg]") >> a)
	.CHECK_THROWS(istringstream("700[as]") >> a)
.CHECK_THROWS(istringstream("700[kggkg]") >> a)

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
