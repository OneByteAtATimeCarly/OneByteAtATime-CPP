//Lists 3 - Example 3 - 2004 C. S. Germany


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <list>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{

//The "list" class does not have the same "random access" capability as the "vector" class,
//but it is possible to add elements at the end of the list and take them off the front.

  list<int> ListOfIntegers;

//Add some values at the end of the list, which is initially empty.
//The member function "push_back" adds an item to the end of the list.

  int value = 0;
  int value1 = 500;
  int value2 = 700;

  ListOfIntegers.push_back(value1);
  ListOfIntegers.push_back(value2);
  ListOfIntegers.push_back(600);
  ListOfIntegers.push_back(650);

//Output the list values, by repeatedly getting the item from the "front" of the list, outputting it,
//and then removing it from the front of the list.

  cout << endl << "List values:" << endl;

  //Loop as long as there are still elements in the list.

  while(ListOfIntegers.size() > 0)
  {
    //Get the value of the "front" list item.
    value = ListOfIntegers.front();
    cout << value << endl;

    //Remove the item from the front of the list using the "pop_front" member function.
    ListOfIntegers.pop_front();
  }

} //close main()

//---------------------------------------------------------------------------------------------------------------------------










