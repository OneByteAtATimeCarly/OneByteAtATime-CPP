//PRJ - Command Line Monster - 2004 - C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class Monster 
{
public:
	Monster() { cout << "A monster!\n"; };
        Monster(int ag) { cout << "A monster!\n";
	                  age = ag; } 
	Monster(char * nam) { cout << "A monster!\n"; 
	                      name = nam; }
	~Monster() { cout << "Monster destroyed.\n"; }
        //Accessor Methods
	void setAge(int ag) { age = ag; }
	int getAge() { return age; }
	void setName(char * nam) { name = nam; }
	char * getName() { return name; }
private:
       int age;
       char * name;

}; //close Monster class specification

//---------------------------------------------------------------------------------------------------------------------------

//Note: int argc is number of command-line arguments and char argv is a char string for the arguments

void main(int argc, char ** argv) {
     //offset for program name, since that is accepted as the first argument
     int size = argc - 1;
     Monster * MonsterArray = new Monster[size];
     for(int x = 0; x < size; x++) 
     { 
         MonsterArray[x].setName(*(argv+1));
         argv++; 

     } //close for loop

     for(x = 0; x < size; x++) 
     {
         cout << "Monster number " << x+1 << " is named "
              << MonsterArray[x].getName() << ".\n"
              << "After argument number " << x+1 << " that you typed in.\n\n";

     } //close for loop
     delete [] MonsterArray;

} // close main()

//---------------------------------------------------------------------------------------------------------------------------


