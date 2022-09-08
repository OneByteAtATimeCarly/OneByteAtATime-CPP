//Templates - 4 - Passing By Reference - 2004 C. S. Germany

//Passing Templates By Reference

//You can treat template items just as any other type.  You can pass them as parameters by reference/pointer or by value,
//and you can return them as return values to functions, also by value or by reference.  Below is a rewrite of main() using
//the above example, to demonstrate passing template objects by reference and using them in functions.  You will need to
//include all of the code in the table above up to the main() function.

//In this example, we are including all of the class declaration code defined in the previous example for the
//Monster, Cat, and Data objects as well as the ADT Node, and the classes InternalNode, HeadNode, TailNode, and LinkedList.
//Then, just after the LinkedList class, we are adding new code to pass by reference.

//This example is like the previous, but this time LinkedLists are passed by reference to their respective functions for
//processing. This can be powerful.  Once lists are instantiated, they can be treated as fully defined types, passed into
//functions and returned as values.  Each instance of the template is an actual object, and can be used like any other
//object, as though it were a separate class instance.


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
enum { ValueIsSmaller, ValueIsLarger, ValueIsSame};

//---------------------------------------------------------------------------------------------------------------------------

// First object class to put into the linked list.  Any class in this linked list must support two methods:
// Show (displays the value) and Compare (returns relative position)

class Data 
{
      public:
      Data(int val):myValue(val){}
      ~Data()
      {
        cout << "Deleting Data object with value: ";
        cout << myValue << ".\n";
      }

      int Compare(const Data &);
      void Show() { cout << "The value of this Data object is " << myValue << ".\n"; }

      private:
      int myValue;
};

//---------------------------------------------------------------------------------------------------------------------------

//Compare is used to decide where in the list a particular object belongs. 
int Data::Compare(const Data & theOtherObject)
{
    if(myValue < theOtherObject.myValue)
        return ValueIsSmaller;
    if(myValue > theOtherObject.myValue)
        return ValueIsLarger;
    else
        return ValueIsSame;
}

//---------------------------------------------------------------------------------------------------------------------------

// Another class to put into the linked list. Again, every class in this linked list
// must support two methods: Show (displays the value) and Compare (returns relative position).
class Monster
{
      public:
      Monster(int strength): mystrength(strength){}
      ~Monster()
      {
         cout << "Deleting the Monster that has strength ";
         cout << (mystrength * 100) << ".\n";
      }

      int Compare(const Monster &);
      void Show()
           { cout << "This Monster has strength " << (mystrength * 100) << "!\n"; }

      private:
      int mystrength;
};

//---------------------------------------------------------------------------------------------------------------------------

//Compare is used to decide where in the list a particular object belongs. 
int Monster::Compare(const Monster & theOtherMonster)
{
    if(mystrength < theOtherMonster.mystrength)
        return ValueIsSmaller;
    if(mystrength > theOtherMonster.mystrength)
        return ValueIsLarger;
    else
        return ValueIsSame;
}

//---------------------------------------------------------------------------------------------------------------------------

// Another class to put into the linked list. Again, every class in this linked list
// must support two methods: Show (displays the value) and Compare (returns relative position).

class Cat
{
      public:
      Cat(int age): myAge(age){}
      ~Cat()
      {
          cout << "Deleting the Cat that is ";
          cout << myAge << " year(s) old.\n";
      }

      int Compare(const Cat &);
      void Show() 
      { cout << "This cat is " << myAge << " year(s) old!\n"; }

      private:
      int myAge;
};

//---------------------------------------------------------------------------------------------------------------------------

//Compare is used to decide where in the list a particular object belongs. 

int Cat::Compare(const Cat & theOtherCat)
{
    if(myAge < theOtherCat.myAge)
         return ValueIsSmaller;
    if(myAge > theOtherCat.myAge)
         return ValueIsLarger;
    else
         return ValueIsSame;
}
//---------------------------------------------------------------------------------------------------------------------------

// ADT representing the node object in the list.  As an ADT, it will never
// have a direct instance.  Every derived class must override Insert and Show.

template <class T>
class Node
{
      public:
      Node(){}
      virtual ~Node(){}

      virtual Node * Insert(T * theObject) = 0;
      virtual void Show() = 0;

      private:
};

//---------------------------------------------------------------------------------------------------------------------------

template <class T>
class InternalNode: public Node<T>
{
      public:
      InternalNode(T * theObject, Node<T> * next);
      ~InternalNode(){ delete myNext; delete myObject; }

      virtual Node<T> * Insert(T * theObject);
      virtual void Show() 
      { 
              myObject->Show(); 
              myNext->Show(); 
      } //delegate!

      private:
      T * myObject;         //the Object itself
      Node<T> * myNext;     //points to next node in the linked list
};

//---------------------------------------------------------------------------------------------------------------------------

//Constructor definitions - all the constructor does is initialize.
template <class T>
InternalNode<T>::InternalNode(T * theObject, Node<T> * next):
myObject(theObject),myNext(next)
{  }

//---------------------------------------------------------------------------------------------------------------------------

// When you put a new object into the list it is passed to the node which figures out
// where it goes and inserts it into the list

template <class T>
Node<T> * InternalNode<T>::Insert(T * theObject)
{

           //Is the new value bigger or smaller than me?
        int result = myObject->Compare(*theObject);


        switch(result)
        { 
           // by convention if it is the same it comes first
           case ValueIsSame:      //fall through
           case ValueIsLarger:    //new Object comes before me
           {
              InternalNode<T> * ObjectNode = new InternalNode<T>(theObject, this);
              return ObjectNode;
           }
           case ValueIsSmaller:
                                     //It is bigger, so pass it on to the next node and let it handle it.
                            myNext = myNext->Insert(theObject);
                            return this;
        } //close switch

        return this;
}

//---------------------------------------------------------------------------------------------------------------------------

//Tail node is just a sentinel
template <class T>
class TailNode : public Node<T>
{
      public:
      TailNode(){}
      ~TailNode(){}

      virtual Node<T> * Insert(T * theObject);
      virtual void Show() { }

      private:

};

//---------------------------------------------------------------------------------------------------------------------------

//If Object comes to me, it must be inserted before me as I am the tail and NOTHING comes after me.

template <class T>
Node<T> * TailNode<T>::Insert(T * theObject)
{
        InternalNode<T> * ObjectNode = new InternalNode<T>(theObject, this);
        return ObjectNode;
}

//---------------------------------------------------------------------------------------------------------------------------

//The Head node has no Object, it just points to the very beginning of the list.

template <class T>
class HeadNode : public Node<T>
{
      public:
      HeadNode();
      ~HeadNode() { delete myNext; }

      virtual Node<T> * Insert(T * theObject);
      virtual void Show() { myNext->Show(); }

      private:
      Node<T> * myNext;
};

//---------------------------------------------------------------------------------------------------------------------------

//As soon as the head is created, it creates the tail.
template <class T>
HeadNode<T>::HeadNode()
{   myNext = new TailNode<T>;   }

//---------------------------------------------------------------------------------------------------------------------------

//Nothing comes before the head, so just pass the object on to the next node.

template <class T>
Node<T> * HeadNode<T>::Insert(T * theObject)
{
        myNext = myNext->Insert(theObject);
        return this;
}

//---------------------------------------------------------------------------------------------------------------------------

//This class starts the ball rolling and the other classes implement the List.

template <class T>
class LinkedList
{
      public:
      LinkedList();
      ~LinkedList() { delete myHead; }

      void Insert(T * theObject);
      void ShowAll() { myHead->Show(); }

      private:
      HeadNode<T> * myHead;
};

//---------------------------------------------------------------------------------------------------------------------------

// At birth, LinkedList creates the head node.  The head node then creates the tail node by its
// constructor. So an empty list points to the head which points to the tail and has nothing between.

template <class T>
LinkedList<T>::LinkedList()
{   myHead = new HeadNode<T>;   }

//---------------------------------------------------------------------------------------------------------------------------

//Delegate the task out to other classes
template <class T>
void LinkedList<T>::Insert(T * pObject)
{   myHead->Insert(pObject);   }

//---------------------------------------------------------------------------------------------------------------------------

//Function prototypes
void MonsterFunction(LinkedList<Monster> & ListOfMonsters);
void CatFunction(LinkedList<Cat> & ListOfCats);
void DataFunction(LinkedList<Data> & ListOfData);

//--------------------------------------------------------------------------------------------------------------------

int main()
{
    //Create instances of the template classes, passing in Monster, Cat and Data
    LinkedList<Monster> ListOfMonsters;
    LinkedList<Cat> ListOfCats;
    LinkedList<Data> ListOfData;

    //Call the functions
    MonsterFunction(ListOfMonsters);
    CatFunction(ListOfCats);
    DataFunction(ListOfData);

    //Iterate through the list and show objects

    ListOfMonsters.ShowAll();

    cout << "\n";

    ListOfCats.ShowAll();

    cout << "\n";

    ListOfData.ShowAll();

    cout << "\n ************ \n\n";

    return 0; // The lists fall out of scope and are destroyed!
}

//--------------------------------------------------------------------------------------------------------------------

//Function definitions

//--------------------------------------------------------------------------------------------------------------------

void MonsterFunction(LinkedList<Monster> & ListOfMonsters)
{
     Monster * pMonster;
     int val;

       //Ask the user to produce some values, put them in the list.
     for (;;)
     {
        cout << "\nOf what strength is your Monster? (0 to stop): ";
        cin >> val;

        if(!val)
           break;

        pMonster = new Monster(val);
        ListOfMonsters.Insert(pMonster);
     } //close infinite loop
}  //close function

//--------------------------------------------------------------------------------------------------------------------

void CatFunction(LinkedList<Cat> & ListOfCats)
{
     Cat * pCat;
     int val;

       //Ask the user to produce some values, put them in the list.
     for (;;)
     {
        cout << "\nHow old is your cat? (0 to stop): ";
        cin >> val;

        if(!val)
           break;

        pCat = new Cat(val);
        ListOfCats.Insert(pCat);
     } //close infinite loop
}  //close function


//--------------------------------------------------------------------------------------------------------------------

void DataFunction(LinkedList<Data> & ListOfData)
{
     Data * pData;
     int val;

       //Ask the user to produce some values and put them in the list.
     for(;;)
     {
         cout << "\nWhat value? (0 to stop): ";
         cin >> val;

         if(!val)
            break;

         pData = new Data(val);
         ListOfData.Insert(pData);
     } //close infinite loop

} //close function

//---------------------------------------------------------------------------------------------------------------------------







