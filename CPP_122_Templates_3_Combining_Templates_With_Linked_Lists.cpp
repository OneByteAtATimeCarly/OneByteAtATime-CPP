//Templates - 3 - Combining Templates With Linked Lists - 2004 C. S. Germany

//Combining Templates With Linked Lists

//In the template and linked list combination below, the same list can handle three different objects since the Node (ADT),
//Internal Node, TailNode and HeadNode have been declared as template classes.  Note that each class declaration and method
//is preceded with "template class <T>".  This tells the compiler that you are parameterizing this list on a type that you
//will define later when you instantiate the list. So the declaration of the Node class must now become:

//     template <class T>
//     class Node

//This says that Node will not exist as a class in and of itself, but rather that you will instantiate Nodes of Monsters,
//Nodes of Cats and Nodes of Data objects.  The actual type you will pass in is represented by "T".  The InternalNode will
//now become "InternalNode<T>".  The InternalNode<T> points to a "T" (whatever type of object is passed to it) and a Node<T>,
//not to a hard-coded Data object and another Node.

//The Insert() has been re-defined.  Where there used to be a specific type of object, Data, now there is "T", representing
//whatever object is passed in.  The parameter is a pointer to "T".  Later, when specific lists are instantiated, the compiler
//will replace "T" with the corresponding instances of Monster, Data and Cat.  In this way, the InternalNode can continue
//working indifferent to the actual data type used.  It only asks the objects to compare themselves.  For this reason, each
//object passed into the template must support two methods:  Show() and Compare().  Depending on the nature of the object's
//data members, these methods will differ from class to class.  But as long as they are provided, this List can sort any
//number of generic objects.


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

int main()
{
    Cat * pCat;
    Data * pData;
    int val;

    LinkedList<Cat> ListOfCats;
    LinkedList<Data> ListOfData;

    //Ask the user to produce some values and put them in the list.
    for(;;)
    {
        cout << "What value? (0 to stop): ";
        cin >> val;

        if(!val)
             break;

        pMonster = new Monster(val);
        pData = new Data(val);
        pCat = new Cat(val);

        ListOfMonsters.Insert(pMonster);
        ListOfData.Insert(pData);
        ListOfCats.Insert(pCat);

    } //close for loop

     //Let ShowAll() iterate through the list and show the object.
    cout << "\n ************ \n";

    ListOfMonsters.ShowAll();

    cout << "\n";

    ListOfData.ShowAll();

    cout << "\n";

    ListOfCats.ShowAll();

    cout << "\n ************ \n\n";

    return 0;  //On exit, the lists fall out of scope and are destroyed!
}

//---------------------------------------------------------------------------------------------------------------------------




