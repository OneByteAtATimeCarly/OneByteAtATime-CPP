//Command Line Arguments 2 - 2004 C. S. Germany

//Below is another example of passing in parameters to the command line when executing an application.

//---------------------------------------------------------------------------------------------------------------------------

#include <fstream>
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

class Monster
{
      public:
      Monster(int Strength, long points):itsStrength(Strength),HitPoints(points){ }
      ~Monster(){}

      int GetStrength() const { return itsStrength; }
      void SetStrength(int Strength) { itsStrength = Strength; }

      long GetHitPoints() const { return HitPoints; }
      void SetHitPoints(long points) { HitPoints = points; }

      private:
      int itsStrength;
      long HitPoints;
};

//---------------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])              // returns 1 on error
{
    //If argument count is not at least 2, that is the program name and a monster name. display syntax
    if(argc != 2)
    {
        cout << "Usage: " << argv[0] << " <FileName>" << endl;
        return(1);
    }

     //Create a file for output using the name passed in as a parameter
    ofstream OutputFile(argv[1],ios::binary);

    if(!OutputFile)
    {
        cout << "Unable to open " << argv[1] << " for writing.\n";
        return(1);
    }

    Monster Mothra(50,100);

    OutputFile.write((char*) &Mothra, sizeof Mothra);
    OutputFile.close();


      //Open a file for input using the name passed in as a parameter
    ifstream InputFile(argv[1],ios::binary);

    if(!InputFile)
    {
        cout << "Unable to open " << argv[1] << " for reading.\n";
        return(1);
    }

    Monster MothraTwo(1,1);

    cout << "MothraTwo Strength: " << MothraTwo.GetStrength() << endl;
    cout << "MothraTwo points: " << MothraTwo.GetHitPoints() << endl;

    InputFile.read((char*) &MothraTwo, sizeof MothraTwo);

    cout << "MothraTwo Strength: " << MothraTwo.GetStrength() << endl;
    cout << "MothraTwo points: " << MothraTwo.GetHitPoints() << endl;

    InputFile.close();

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









