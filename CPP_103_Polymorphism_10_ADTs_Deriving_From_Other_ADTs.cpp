//Polymorphism 10 - Deriving ADTs from other ADTs - 2004 C. S. Germany

//ADT - Abstract Data Type.  An ADT, or Abstract Data Type, represents an ambiguous or vague concept like Shape, rather than an object of physical reality like Circle.
//ADT's are always base classes to other classes.  You can not make an instance of a class that is an ADT.  You declare a class to be an ADT by including 1 or more pure
//virtual functions in the class declaration.

//Pure Virtual Functions - Pure virtual functions are used to create ADT's.  Virtual functions are made pure by initializing them with 0.
//Example: virtual void Draw() = 0;  Once a class contains a pure virtual method, we can assume certain implications:

//The pure virtual method will NEVER be used, and it must ALWAYS be overridden in each derived class.
//The class that contains it is an ADT, and the base class for derived classes.
//Since the class is an ADT, there will NEVER be an instance or object of that class, only of derived classes.

//Any class deriving from an ADT inherits the pure virtual function as pure and so must override every pure virtual function in order to instantiate objects.
//If Rectangle inherits from Shape, and Shape has 3 pure virtual functions, then Rectangle must override all 3 of those pure virtual functions, else it will
//be an ADT itself.

//Typically pure virtual functions are never implemented, no objects are created that use them, and the ADT works purely as the definition of an interface to objects
//that derive from it.   The ADT never created objects of itself, only its derived classes have instances.  In this way it functions more as an organizational tool of
//the "Is-A/Has-A" relationship than an actual, working class structure.  You can provide an implementation to a pure virtual function, so that it can be called by
//objects derived from the ADT.  You might do this to provide common functionality to all of the overridden functions.  Below Shape is an ADT, the Circle class
//overrides Draw(), and then chains up to the base class function for additional functionality.

//The Shape class has now become an ADT.  If only one function is declared pure virtual, the class is an ADT.  Circle and Rectangle override Draw(),
//but chain up to the base method to take advantage of shared functionality.  You can derive ADTs from other ADTs.  In the code below, no Animal objects
//or Mammal objects can be instantiated because they are both base classes and both are ADTs.  However, all Mammals may inherit the Reproduce() method
//without overriding it.

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>
enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown } ;
enum BOOL { FALSE, TRUE };

//---------------------------------------------------------------------------------------------------------------------------

class Animal             //ADT. Common base to both horse and fish.
{
      public:
      Animal(int);
      virtual ~Animal() { cout << "Animal destructor...\n"; }

      //Virtual methods
      virtual int GetAge() const { return itsAge; }
      virtual void SetAge(int age) { itsAge = age; }

      //Pure virtual methods
      virtual void Sleep() const = 0;
      virtual void Eat() const = 0;
      virtual void Reproduce() const = 0;
      virtual void Move() const = 0;
      virtual void Speak() const = 0;

      private:
      int itsAge;
};

//---------------------------------------------------------------------------------------------------------------------------

Animal::Animal(int age):itsAge(age)
{ cout << "Animal constructor...\n"; }

//---------------------------------------------------------------------------------------------------------------------------

class Mammal : public Animal          //ADT.  Multiple inheritance.
{
      public:
      Mammal(int age):Animal(age)
             { cout << "Mammal constructor...\n"; }
      ~Mammal() { cout << "Mammal destructor...\n";}

      virtual void Reproduce() const 
              { cout << "Mammal reproducing!\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

class Fish : public Animal
{
      public:
      Fish(int age):Animal(age)
          { cout << "Fish constructor...\n";}
      virtual ~Fish() {cout << "Fish destructor...\n"; }

        //Virtual Methods.  Fish class MUST override the 5 pure virtual methods of Animal base class.
      virtual void Sleep() const { cout << "fish snoring...\n"; }
      virtual void Eat() const { cout << "fish feeding...\n"; }
      virtual void Reproduce() const { cout << "fish laying eggs...\n"; }
      virtual void Move() const { cout << "fish swimming...\n"; }
      virtual void Speak() const { }
};

//---------------------------------------------------------------------------------------------------------------------------

class Horse : public Mammal
{
      public:
      Horse(int age, COLOR color ):Mammal(age), itsColor(color)
            { cout << "Horse constructor...\n"; }
      virtual ~Horse() { cout << "Horse destructor...\n"; }

      virtual void Speak() const { cout << "Whinny!... \n"; }
      virtual COLOR GetItsColor() const { return itsColor; }
      virtual void Sleep() const { cout << "Horse snoring...\n"; }
      virtual void Eat() const { cout << "Horse feeding...\n"; }
      virtual void Move() const { cout << "Horse running...\n";}

      protected:
      COLOR itsColor;
};

//---------------------------------------------------------------------------------------------------------------------------

class Dog : public Mammal
{
      public:
      Dog(int age, COLOR color ):
      Mammal(age), itsColor(color) { cout << "Dog constructor...\n"; }
      virtual ~Dog() { cout << "Dog destructor...\n"; }

      virtual void Speak()const { cout << "Whoof!... \n"; }
      virtual void Sleep() const { cout << "Dog snoring...\n"; }
      virtual void Eat() const { cout << "Dog eating...\n"; }
      virtual void Move() const { cout << "Dog running...\n"; }
      virtual void Reproduce() const { cout << "Dogs reproducing...\n"; }

      protected:
      COLOR itsColor;
};

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    Animal *pAnimal=0;
    int choice;
    BOOL fQuit = FALSE;

    while(1)
    {
        cout << "(1)Dog (2)Horse (3)Fish (0)Quit: ";
        cin >> choice;

        switch (choice)
        {
             case 1: pAnimal = new Dog(5,Brown);
                     break;
             case 2: pAnimal = new Horse(4,Black);
                     break;
             case 3: pAnimal = new Fish (5);
                     break;
             default: fQuit = TRUE;
                      break;
        }
   
        if(fQuit)
           break;

        pAnimal->Speak();
        pAnimal->Eat();
        pAnimal->Reproduce();
        pAnimal->Move();
        pAnimal->Sleep();
        delete pAnimal;
        cout << "\n";
    } //close while true loop

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









