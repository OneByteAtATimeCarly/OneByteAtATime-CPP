//Linked Lists - 2 - A More Developed Linked List - 2004 C. S. Germany

//A More Developed Linked List 

//In this example, enumerated constants are returned by the Compare() method which must be supported by every object held in the linked list.
//Inside the main() function, a local linked list is defined.  Then an infinite loop begins.  The linked list immediately delegates responsibility
//for inserting new objects to its HEAD node, invoking the Insert() method.  The HEAD node passes this responsibility to whatever node its pointer
//"myNext" is pointing to.  In the first case, before there are any objects stored, it points to the TAIL node.  The method TailNode::Insert inserts
//each object it is handed immediately before itself.  The TAIL node passes in its own "this" pointer (passes in itself).  Once the InternalNode is
//created, its address is assigned to the pointer dataNode, and the address is returned from the TailNode::Insert method.  Then it goes to
//HeadNode::Insert(), where the address of InternalNode is assigned to HeadNode's "myNext" pointer.  Finally the HeadNode's address is returned to
//the Linked List where it is thrown away (nothing is done with it because the linked list already knows the address of the HeadNode.  Insert() is
//declared in the base class Node.  If you change the value of HeadNode::Insert() you'll get a compile time error.  It is simpler to return the
//HeadNode and let the linked list throw it away.  Here's what happens:

//     1 - Data is inserted into the list.
//     2 - The linked list passes the data to the HEAD.
//     3 - The HEAD blindly passes the data to whatever node it is pointing to.
//     4 - In the first loop through the list, the HEAD is pointing to the TAIL.
//     5 - The TAIL then immediately creates a new InternalNode.
//     6 - The TAIL initializes the new InternalNode to point to the TAIL.
//     7 - The TAIL returns the address of the new node to the HEAD node.
//     8 - The HEAD reassigns its "myNext" pointer to point to the new node.

//Let's review this process:

//The Linked list maintains the HEAD node.
//The HEAD node passes new data. 
//The TAIL node creates new nodes and inserts them whenever handed data. 
//The Internal nodes ask existing objects to compare themselves with new objects. 
//Depending on results, they insert new objects or instead, pass them along. 
//The Internal node has no idea how to do comparison, that is left to Data object itself. 
//In this way each individual object is given a narrow, well-defined set of responsibilities - hence encapsulation. 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
//          0          1         2
enum { kIsSmaller, kIsLarger, kIsSame};

//---------------------------------------------------------------------------------------------------------------------------

//Class ProtoTypes
class Node;
class HeadNode;
class TailNode;
class InternalNode;

//---------------------------------------------------------------------------------------------------------------------------

//The Data class is the object to be to put into the linked list.  It holds in int data member.  Any class
//in this linked list must support two methods: Show (displays the value) and Compare (returns relative position).

class Data
{
      public:
      Data(int val):myValue(val){}
      ~Data(){}

      int Compare(const Data &);
      void Show() { cout << myValue << endl; }

      private:
      int myValue;
};

//---------------------------------------------------------------------------------------------------------------------------

// Compare defined outside Data class, used to decide where in the list a particular object belongs.

int Data::Compare(const Data & theOtherData)
{
    if (myValue < theOtherData.myValue)
        return kIsSmaller;
    if (myValue > theOtherData.myValue)
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
      virtual Node *Insert(Data *theData)= 0;
      virtual void Show() = 0;

      private:
};

//---------------------------------------------------------------------------------------------------------------------------

// This is the node which holds the actual object. In this case the object is of type Data We'll see how to
// make this more general when we cover templates. Derives from ADT "node".

class InternalNode: public Node
{
      public:
      InternalNode(Data *theData, Node *next);
      ~InternalNode(){ delete myNext; delete myData; }

      virtual Node *Insert(Data *theData);
      virtual void Show() { myData->Show(); myNext->Show(); }  //delegate!

      private:
      Data *myData;        // the data itself
      Node *myNext;        // points to next node in the linked list
};

//---------------------------------------------------------------------------------------------------------------------------

// All the constructor does is initialize

InternalNode::InternalNode(Data *theData, Node *next):
myData(theData),myNext(next) { }

//---------------------------------------------------------------------------------------------------------------------------

// The meat of the list. When you put a new object into the list, it is passed to
// the node which figures out where it goes and inserts it into the list

Node *InternalNode::Insert(Data *theData)
{
       // Is the new Data object bigger or smaller than me?
      int result = myData->Compare(*theData);

      switch(result)
      {
       // If it is the same as me, it comes first
        case kIsSame:      // fall through
        case kIsLarger:    // new data comes before me
             {
               InternalNode *dataNode = new InternalNode(theData, this);
               return dataNode;
             }

           // it is bigger than I am so pass it on to the next node and let HIM handle it.
        case kIsSmaller:
               myNext = myNext->Insert(theData);
               return this;
      } //close switch

      return this;       // appease MSC
}

//-----------------------------------------------------------------------------------------

// Tail node is just a sentinel

class TailNode : public Node
{
      public:
      TailNode(){}
      ~TailNode(){}

      virtual Node *Insert(Data *theData);
      virtual void Show() { }

      private:
};

//---------------------------------------------------------------------------------------------------------------------------

// If data comes to me, it must be inserted before me. I am the tail and NOTHING comes after me.
Node *TailNode::Insert(Data *theData)
{
     InternalNode *dataNode = new InternalNode(theData, this);
     return dataNode;
}

//-----------------------------------------------------------------------------------------

// The Head node has no data, it just points to the very beginning of the list.

class HeadNode : public Node
{
      public:
      HeadNode();
      ~HeadNode() { delete myNext; }

      virtual Node *Insert(Data *theData);
      virtual void Show() { myNext->Show(); }

      private:
      Node *myNext;
};

//---------------------------------------------------------------------------------------------------------------------------

// Head node constructor defined outside class. As soon as the head is created, it creates the tail.
HeadNode::HeadNode()
{ myNext = new TailNode; }

//---------------------------------------------------------------------------------------------------------------------------

// Nothing comes before the head so just, pass the data on to the next node.
Node *HeadNode::Insert(Data *theData)
{
       myNext = myNext->Insert(theData);
       return this;
}

//-----------------------------------------------------------------------------------------

// Linked list.  The work of adding and sorting objects is delegated outside this class.

class LinkedList
{
      public:
      LinkedList();
      ~LinkedList() { delete myHead; }

      void Insert(Data *theData);
      void ShowAll() { myHead->Show(); }

      private:
      HeadNode *myHead;
};

//---------------------------------------------------------------------------------------------------------------------------

// At birth, I create the head node. It creates the tail node. So an empty list points to the head
// which points to the tail and has nothing between.  LinkedList constructor defined outside.

LinkedList::LinkedList()
{ myHead = new HeadNode; }

//---------------------------------------------------------------------------------------------------------------------------

// Delegate, delegate, delegate
void LinkedList::Insert(Data *pData)
{ myHead->Insert(pData); }

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Data *pData;
    int val;
    LinkedList ll;

// Ask the user to produce some values put them in the list.
    for (;;)
    {
        cout << "What value? (0 to stop): ";
        cin >> val;

        if (!val)
            break;

        pData = new Data(val);
        ll.Insert(pData);
    }

     // Now walk the list and show the data.
   ll.ShowAll();

   return 0;         // ll falls out of scope and is destroyed!
}

//---------------------------------------------------------------------------------------------------------------------------







