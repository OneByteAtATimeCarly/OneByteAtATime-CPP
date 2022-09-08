//Bitwise Operators - 2004 C. S. Germany

//Bitwise operators allow the C++ programmer to control and manipulate individual bits of memory.  This can be useful
//for setting "flags" on objects to determine what state they are in.   Each byte is composed of 8 bits, so in a 4 byte long
//there would be 32 bits.  Each bit can be used for a flag, so that's 32 possible flags.  When we set a bit, we make its
//value 1.  When we clear it, we make it 0.  It boils down to on/of - binary.  Manipulating bits via bitwise operators is know as "bit twiddling".  The bitwise operators are used to set //individual bits.  They look very similar to the logical operators, but they are shorter.  Let's take a look:

//     & - AND, = 1 if both bits are 1, but 0 if either or both bits are 0.
//     | - OR, = 1 if either bit is set or if both are set.
//     ^ - exclusive OR, = 1 if the two bits are different.
//     ~ - complement, = clears every bit in a number that's set, and sets every bit in a number that's clear.  Like: 1010011 = 0101 1100
//     << - shift left, = shifts bits to the left
//     >> - shift right, = shifts bits to the right


//Masking operations - Used to set a particular bit.  For a 4 byte flag, to set the 8th bit to true, you would need to OR the flag with 128.
//It's 128 because 27 is 128, and that 27 is the 8th bit place in the byte.  Remember:   128  64  32  16  8  4  2  1 .  So 128 = 1000 0000 in
//binary, the 8th bit is switched on and the other 7 are switched off. 

//Bit Fields - Using bit fields can save memory .  Using built-in data types, the smallest type is a char, which is 1 byte (8 bits).
//Using bit fields, you could store 8 binary values in 1 byte.  That's 8 possible on's and off's, which could be used like Booleans.
//A bitfield's type is always declared to be an unsigned int.  After declaring the bitfield's name, a colon is written followed by a number.
//The number refers to how many bitsare assigned to the variable.  Syntax:  unsigned MyBitField : 1;  Example:

//     unsigned MyBitField : 1 =  2 possible values, (on | off).
//     unsigned MyBitField : 2 =  4 possible values, (on, on  | off, off  |  on, off  |  off, on).
//     unsigned MyBitField : 3 =  8 possible values, (and so on and so on ...)

//The example below conserves memory by using bitfields and many enumerated constants to do its job. Recall that enumerated constants,
//like elements in an array, all have numerical index-like values, starting at 0 and advancing, unless otherwise specified.

//Example:

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;
#include <string.h>

//---------------------------------------------------------------------------------------------------------------------------

enum STATUS { FullTime, PartTime } ;
enum SalaryLevel { E1, E2 } ;
enum HOUSING { Dorm, OffCampus };
enum BenefitPlan { Partial, Full, FullFamily, NoBenefits };

//---------------------------------------------------------------------------------------------------------------------------

class Employee
{
public:
	Employee():
		myStatus(FullTime),
		mySalaryLevel(E1),
		myHousing(Dorm),
		myBenefitPlan(NoBenefits)
	{}

	~Employee(){}


	STATUS GetStatus();
	void SetStatus(STATUS);
	unsigned GetPlan() { return myBenefitPlan; }
private:
        //Note:  These are bit fields, and as such use much les memory than bools or int's
	unsigned myStatus : 1;
	unsigned mySalaryLevel: 1;
	unsigned myHousing : 1;
	unsigned myBenefitPlan : 2;
};

//---------------------------------------------------------------------------------------------------------------------------

STATUS Employee::GetStatus()
{
	if(myStatus)
		return FullTime;
	else
		return PartTime;
}

//---------------------------------------------------------------------------------------------------------------------------

void Employee::SetStatus(STATUS theStatus)
{
	myStatus = theStatus;
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
	Employee Orion;
	if(Orion.GetStatus()== PartTime)
		cout << "Orion is part time" << endl;
	else
		cout << "Orion is full time" << endl;
	Orion.SetStatus(PartTime);
	if(Orion.GetStatus())
		cout << "Orion is part time" << endl;
	else
		cout << "Orion is full time" << endl;
	cout << "Orion is on the \"" ;
	char Plan[80];
	switch(Orion.GetPlan())
	{
	case Partial: strcpy(Plan,"partial benefits"); break;
	case Full: strcpy(Plan,"full benefits"); break;
	case FullFamily: strcpy(Plan,"full Family Benefits"); break;
	case NoBenefits: strcpy(Plan,"no benefits");break;
	default : cout << "Something bad went wrong!\n"; break;
	}
	cout << Plan << "\" benefit plan." << endl;

	return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









