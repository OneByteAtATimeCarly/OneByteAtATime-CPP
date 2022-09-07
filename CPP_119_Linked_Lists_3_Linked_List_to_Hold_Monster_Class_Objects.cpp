//Linked Lists - 3 - A Linked List to Hold Monster Class Objects - 2004 C. S. Germany

//A Linked List to Hold Monster Class Objects 

//Demonstrates an object-oriented approach to linked lists. The list delegates to the node.  The node is an
//abstract data type. Three types of nodes are used: head nodes, tail nodes and internal nodes. Only the internal
//nodes hold data.  The Data class is created to serve as an object to hold in the linked list.

//The Monster class is the object to be to put into the linked list.  It holds in int Monster member.  Any class
//in this linked list must support two methods: Show (displays the value) and Compare (returns relative position).


//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
//          0          1         2
enum { kIsSmaller, kIsLarger, kIsSame};

//---------------------------------------------------------------------------------------------------------------------------

//Class Prototypes
class Node;
class HeadNode;
class TailNode;
class InternalNode;

//---------------------------------------------------------------------------------------------------------------------------

class Monster {
public:
	static int x;
    Monster(char * nam, int str) 
	{ name = nam;
	  strength = str; }
	~Monster() { cout << "Monster detroyed.\n"; }
	char * GetName() { return name;}
    int GetStrength() { return strength; }
    int Compare(const Monster &);
	void Show() { cout << name << x << ":" << strength << endl;
	             x++;}
private:
	char * name;
	int strength;
};
//Static member data is shared by all instances of a class.  static data members must be initialized OUTSIDE the class.
int Monster::x = 0;
// Compare defined outside Monster class, used to decide where in the list a particular object belongs.
int Monster::Compare(const Monster & theOtherMonster)
{
    if (strength < theOtherMonster.strength)
        return kIsSmaller;
    if (strength > theOtherMonster.strength)
        return kIsLarger;
else
return kIsSame;
}

//---------------------------------------------------------------------------------------------------------------------------

//ADT representing the node object in the list. Every derived class must override Insert and Show

class Node
{
      public:
      Node(){}
      virtual ~Node(){}
      //Pure virtual functions
      virtual Node *Insert(Monster *theMonster)= 0;
      virtual void Show() = 0;
      private:
};

//---------------------------------------------------------------------------------------------------------------------------

// This is the node which holds the actual object. In this case the object is of type Monster We'll see how to
// make this more general when we cover templates. Derives from ADT "node"

class InternalNode: public Node
{
      public:
      InternalNode(Monster *theMonster, Node *next);
      ~InternalNode(){ delete myNext; delete myMonster; }
      virtual Node *Insert(Monster *theMonster);
      virtual void Show() { myMonster->Show(); myNext->Show(); }  //delegate!
      private:
      Monster *myMonster;        // the Monster itself
      Node *myNext;        // points to next node in the linked list
};

//---------------------------------------------------------------------------------------------------------------------------

// All the constructor does is initialize
InternalNode::InternalNode(Monster *theMonster, Node *next):

//---------------------------------------------------------------------------------------------------------------------------

myMonster(theMonster),myNext(next) { }

//---------------------------------------------------------------------------------------------------------------------------

// The meat of the list. When you put a new object into the list, it is passed to 
// the node which figures out where it goes and inserts it into the list

Node *InternalNode::Insert(Monster *theMonster)
{
       // Is the new Monster object bigger or smaller than me?
      int result = myMonster->Compare(*theMonster);
      switch(result)
      {
       // If it is the same as me, it comes first
        case kIsSame:      // fall through
        case kIsLarger:    // new Monster comes before me
             {
               InternalNode *MonsterNode = new InternalNode(theMonster, this);
               return MonsterNode;
             }
           // it is bigger than I am so pass it on to the next node and let HIM handle it.
        case kIsSmaller:
               myNext = myNext->Insert(theMonster);
               return this;
      } //close switch
      return this;       // appease MSC
}

//---------------------------------------------------------------------------------------------------------------------------

// Tail node is just a sentinel

class TailNode : public Node
{
      public:
      TailNode(){}
      ~TailNode(){}
      virtual Node *Insert(Monster *theMonster);
      virtual void Show() { }
      private:
};

//---------------------------------------------------------------------------------------------------------------------------

// If Monster comes to me, it must be inserted before me. I am the tail and NOTHING comes after me

Node *TailNode::Insert(Monster *theMonster)
{
     InternalNode *MonsterNode = new InternalNode(theMonster, this);
     return MonsterNode;
}

//---------------------------------------------------------------------------------------------------------------------------

// The Head node has no Monster, it just points to the very beginning of the list

class HeadNode : public Node
{
      public:
      HeadNode();
      ~HeadNode() { delete myNext; }
      virtual Node *Insert(Monster *theMonster);
      virtual void Show() { myNext->Show(); }
      private:
      Node *myNext;
};

//---------------------------------------------------------------------------------------------------------------------------

// Head node constructor defined outside class. As soon as the head is created, it creates the tail

HeadNode::HeadNode()
{ myNext = new TailNode; }

//---------------------------------------------------------------------------------------------------------------------------

// Nothing comes before the head so just, pass the Monster on to the next node

Node *HeadNode::Insert(Monster *theMonster)
{
       myNext = myNext->Insert(theMonster);
       return this;
}

//---------------------------------------------------------------------------------------------------------------------------

// Linked list.  The work of adding and sorting objects is delegated outside this class

class LinkedList
{
      public:
      LinkedList();
      ~LinkedList() { delete myHead; }
      void Insert(Monster *theMonster);
      void ShowAll() { myHead->Show(); }
      private:
      HeadNode *myHead;
};

//---------------------------------------------------------------------------------------------------------------------------

// At birth, I create the head node. It creates the tail node. So an empty list points to the head
// which points to the tail and has nothing between.  LinkedList constructor defined outside

LinkedList::LinkedList()
{ myHead = new HeadNode; }
// Delegate, delegate, delegate
void LinkedList::Insert(Monster *pMonster)
{ myHead->Insert(pMonster); }

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Monster Giant("Frank", 250);
    Monster *pMonster;
    int val;
    LinkedList MonsterList;
    //Ask the user to name some Monsters and put them in the list.
    for (;;)
    {
        cout << "What value? (0 to stop): ";
        cin >> val;
        if (!val)
            break;
        
        pMonster = new Monster("Monster",val);
        MonsterList.Insert(pMonster);
    }
     // Now walk the list and show the Monster.
   MonsterList.ShowAll();
   return 0;         // MonsterList falls out of scope and is destroyed!  A lot of cleaning up goes on!
}

//---------------------------------------------------------------------------------------------------------------------------






