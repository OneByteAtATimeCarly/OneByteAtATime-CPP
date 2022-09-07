//Linked Lists - 1 - The Basics - 2004 C. S. Germany

//Linked Lists - Linked Lists are data structures that consist of small links that snap together - LEGOs, once again!. 
//They can be compared to arrays in the way that they can store and sort elements.  However, arrays have several key disadvantages:

//The size of an array is fixed.  If less elements are used than memory is allocated, memory is wasted.  If more elements are required
//than has been allocated for the array while the program is running, it will crash.  Without linked lists, the workaround for this is
//cumbersome: create an array dynamically on the heap and use realloc() to dynamically resize it at run-time.

//Inserting new elements into an array can be expensive performance-wise, since the old elements have to be shifted over in memory.
//Arrays allocate memory for all their elements in one block of memory. By contrast, linked lists allocate memory for each object
//they store in its own separate block.  These separate segments of memory are often called nodes or segments, and are chained together
//with pointers. Each node usually consists of two fields:

//    1) "data" field - used to store the data type/object.
//    2) "next" field - a pointer that links one node to the next.

//The basic idea behind creating a linked list is to create a class to hold an object of data that points at the next container in the list. 
//You then create a container for each object you need to store, and then you chain them together as needed.  Linked lists consist of "nodes",
//modules of the list that hold the objects the list stores.  The linked list does little work other than delegating to the nodes.  It is a
//dynamically sized collection.  Linked lists have an advantage over arrays in that they can be sized dynamically at run time, whereas arrays
//are static and can not.  Once operating properly, you can reuse code for a number of objects in the list without having to rewrite anything.

//Linked lists operate under this fundamental premise of encapsulation: Each object does ONE thing very well, then delegates to other objects
//anything that is not its core mission.  Let's review some basics:

//nodes - the containers of a linked list are called nodes. The 1st is called the HEAD, the middle is called INTERNAL, and the last is called the TAIL node. 

//Lists come in 3 fundamental forms:

//    Singly linked - each node points to next one but not backward
//    Doubly linked - moves backward AND forward in the chain
//    Trees - complex structure of nodes where each can point in 2 or 3 directions (binary trees).

//A very simple Linked List 

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

class node
{    public:
     int x;
     node *next;    //Points to node object itself
};

//---------------------------------------------------------------------------------------------------------------------------

void LinkedList() 
{

     node *root;         //This won't change, or we would lose the list in memory
     node *conductor;     //This will point to each node as it traverses the list
     root = new node;    //root creates a new node object on the heap and points to it

       //root is a pointer to a node object accessing that object's next data member.
       //This data member is itself a pointer to another node object.
       //It is initialized to NULL, otherwise it would not function correctly.
     root->next = NULL;

     //pointer stores a value in the "int x" data member of the node object it points to.
     root->x=12;

     conductor = root;     //The conductor now points to the first node.

     if(conductor != NULL)
     {
          while(conductor->next != NULL)
          {
             conductor = conductor->next;
          }
     }

     conductor->next = new node;     //Creates a node at the end of the list
     conductor = conductor->next;    //Points to that node
     conductor->next = NULL;         //Prevents it from going any further
     conductor->x = 42;
     conductor = root;

     if(conductor != NULL)          //Makes sure there is a place to start
     {
        while(conductor->next != NULL)
        {
           cout << conductor->x << "\n";
           conductor = conductor->next;
        }
        cout << conductor->x << "\n";
     }
} //close function

//---------------------------------------------------------------------------------------------------------------------------

void main() 
{

     LinkedList();
}

//---------------------------------------------------------------------------------------------------------------------------





