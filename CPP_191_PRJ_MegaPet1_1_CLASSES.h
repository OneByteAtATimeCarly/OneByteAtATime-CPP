//PRJ - MegaPet1 - Classes - 2006 - C. S. Germany
//File 1 of 3
//Classes for MegaPet

//---------------------------------------------------------------------------------------------------------------------------

//Globals
int GlobalX;
bool CreatedPet;
int Hours;

//---------------------------------------------------------------------------------------------------------------------------

//Function Prototypes
int RANDOM(int x);
void CreatePet();
void LoadPet();
void SavePet();
void Interact();

//---------------------------------------------------------------------------------------------------------------------------

//Base Class ADT
class Pet
{
      enum SEX{male, female};
      enum EMOTIONS{ECSTATIC, JOYFUL, HAPPY, CONTENT, MELANCHOLY, DEPRESSED, SUICIDAL};
      public:
      //---------------------------------------------------------------------       
      Pet() 
      { 
          cout << "\n\t\tCreating a BASE class Pet object.";
          Alive = true;  Claws = true;  LiveBirth = true;
          Gender = female;  Age = 1;  Size = 10;
          Weight = 50;  Health = 100;  Hunger = 0;
          EnergyLevel = 10;  SexDrive = 5;  EmotiveState = ECSTATIC; 
          PetName = "GenericPet";            
      }
      //--------------------------------------------------------------------- 
      ~Pet() { cout << "\n\t\tDestroying a BASE class Pet object."; }
      //--------------------------------------------------------------------- 

      //Functions      
      void ChoosePet()
      {
           char Preference[10];
           cout << "\n\t\tWhat would you like to name your pet? ";
           cin >> PetName;
           
           cout << "\n\t\tWhat sex do you prefer? (m)ale or (f)emale ";
           cin  >> Preference;
           Preference[0] = tolower(Preference[0]);
           
           switch(Preference[0])
           {
               case 'm' : cout << "\n\t\tYou pick a male."; Gender = male; break;
               case 'f' : cout << "\n\t\tYou pick a female."; Gender = female; break;
               default : cout << "\n\t\tYou pick a female."; Gender = female; break;  
           }    
           
           cout << "\n\t\tDo you prefer a (y)ounger pet or an (o)lder pet? "; 
           cin  >> Preference;
           Preference[0] = tolower(Preference[0]);
           
           switch(Preference[0])
           {
               case 'y' : cout << "\n\t\tYou get a young pet!"; Age = 1; break;
               case 'o' : cout << "\n\t\tYou get a old pet!"; Age = 5; break;
               default : cout << "\n\t\tUndecided? You get an older pet!"; Age = 5; break;  
           }   
           
           cout << "\n\t\tWould you like to procure a (s)mall or (l)arge animal?";
           cin >> Preference;
           Preference[0] = tolower(Preference[0]);
           switch(Preference[0])
           {
               case 'l' : cout << "\n\t\tYou obtain a large pet!"; Size = 7; break;
               case 's' : cout << "\n\t\tYou obtain a small pet!"; Size = 2; break;
               default : cout << "\n\t\tYou obtain a large pet!"; Age = 7; break;  
           }
           
           cout << endl << endl; 
           DisplayPet();                 
      }
      
      //---------------------------------------------------------------------       

      void DisplayPet()
      {
           if(Health > 0 && Health < 11) { EmotiveState = SUICIDAL; }
           if(Health > 10 && Health < 21) { EmotiveState = DEPRESSED; }
           if(Health > 20 && Health < 31) { EmotiveState = MELANCHOLY; }
           if(Health > 30 && Health < 51) { EmotiveState = CONTENT; }
           if(Health > 50 && Health < 71) { EmotiveState = HAPPY; }
           if(Health > 70 && Health < 91) { EmotiveState = JOYFUL; }                                            
           if(Health > 90 && Health < 101) { EmotiveState = ECSTATIC; }
                                 
           cout << "\n\t\t------------------------- Pet Stats -------------------------\n";
           cout << "\t\tName: " << PetName << "  Species: " << species << "  Sex: ";
           
           if(Gender == male) { cout << "Male";  }
           else { cout << "Female"; }
           
           cout << "  Age: " << Age << "\n\t\tHealth: " << Health 
                << "  EnergyLevel: " << EnergyLevel << "  Hunger: "
                << Hunger << "  Size: " << Size;
           cout << "\n\t\t-------------------------------------------------------------\n";
           
           cout << "\t\t" << PetName << " is feeling: ";
           
           switch(EmotiveState)
           {
               case ECSTATIC : cout << " Ecstatic!\n"; break;                               
               case JOYFUL : cout << " So Joyful!\n"; break;
               case HAPPY : cout << " Happy.\n"; break;
               case CONTENT : cout << " Content.\n"; break;                             
               case MELANCHOLY : cout << " Not too good, not too bad.\n"; break;
               case DEPRESSED : cout << " Sad, depressed and lonely...\n"; break;
               case SUICIDAL : cout << " Suicidal!\n"; break;                                  
           }     
           
           cout << "\t\t" << PetName << " is"; 
           
           switch(EnergyLevel)
           {
               case 10 : cout << " full of limitless energy.\n"; break; 
               case 9 : cout << " energetic and happy.\n"; break;
               case 8 : cout << " strong and capable.\n"; break;
               case 7 : cout << " gung ho about life in general.\n"; break;
               case 6 : cout << " fairly rested.\n"; break;
               case 5 : cout << " neither tired nor abundantly energetic.\n"; break;
               case 4 : cout << " a little tired.\n"; break;
               case 3 : cout << " very tired.\n"; break;
               case 2 : cout << " completely exhausted.\n"; break;
               case 1 : cout << " unable to stay awake - barely conscious.\n"; break;
               case 0 : cout << " feeling like death is immenent without sleep.\n"; break;
               default : cout << " something indescribable.\n"; break;
           }
      }
      //--------------------------------------------------------------------- 
      
      void GiveLiveBirth() { cout << "\n\t\tGiving live birth! Ouch!"; }
      
      void Regurgitate() { cout << "\n\t\tPet regurgitating..."; }
      
      void Eat() 
      { 
           if((Hunger - 1) > 0)
           {
               cout << "\n\t\tYou feed your pet. It feels better."; 
               Hunger = Hunger - 2;
               if((Health + 2) < 100) { Health = Health + 2; }
               else { Health = 100; }
           }
           else 
           { 
                cout << "\n\t\tYour pet is full and does not require any feeding."; 
                Hunger = 0; 
           }        
      }
      
      void Sleep() 
      { 
           if((EnergyLevel + 1) < 10)
           {
              cout << "\n\t\tYou cuase your pet to sleep, increasing its energy.";
              EnergyLevel = EnergyLevel + 2;
              if((Health + 5) < 100) { Health = Health + 2;}
              else { Health = 100; }              
           } 
           else 
           { 
                cout << "\n\t\tYour pet does not require any sleep."; 
                EnergyLevel = 10;
           }
      }
      
      void Play()
      {
           cout << "\n\t\tYou pet your pet and it feels better.";
           if(EmotiveState + 1 < 7) { EmotiveState++; }
           else { EmotiveState - 7; }
           
      }
      
      void ShowAffection() { cout << "\n\t\tYou pet your pet."; }
      
      void Communicate() 
      { 
           cout << "\n\t\tYou communicate with your pet."; 
           int x = 1;
           
           //Keep from saying the same random statement twice
           while(GlobalX == x) { x = RANDOM(5); } 
           GlobalX = x;       
               
           switch(EmotiveState)
           {
                case ECSTATIC : switch(x)
                                {
                                    case 1 : cout << "\n\t\tI am leaping with joy!"; break;
                                    case 2 : cout << "\n\t\tI am so Happy I could cry!"; break;
                                    case 3 : cout << "\n\t\tLife couldn't get any better!"; break;
                                    case 4 : cout << "\n\t\tI feel great!"; break;
                                    case 5 : cout << "\n\t\tI feel awesome!"; break;
                                    default: cout << "\n\t\tNever Happen"; break;                    
                                } break;
                case JOYFUL :  switch(x)
                                {
                                    case 1 : cout << "\n\t\tI am happy."; break;
                                    case 2 : cout << "\n\t\tI feel very good."; break;
                                    case 3 : cout << "\n\t\tLife is good."; break;
                                    case 4 : cout << "\n\t\tNice day!"; break;
                                    case 5 : cout << "\n\t\tYour the greatest, Master!"; break;
                                    default: cout << "\n\t\tNever Happen"; break;                    
                                } break;
                case HAPPY :  switch(x)
                                {
                                    case 1 : cout << "\n\t\tI am in a good mood!"; break;
                                    case 2 : cout << "\n\t\tLife is wonderful!"; break;
                                    case 3 : cout << "\n\t\tYou rock, Master!"; break;
                                    case 4 : cout << "\n\t\tOh yeah, lovin it."; break;
                                    case 5 : cout << "\n\t\tWeeeeee!"; break;
                                    default: cout << "\n\t\tNever Happen"; break;                    
                                } break;
                case CONTENT :  switch(x)
                                {
                                    case 1 : cout << "\n\t\tI am fine."; break;
                                    case 2 : cout << "\n\t\tI am o.k., you're o.k."; break;
                                    case 3 : cout << "\n\t\tI am doing alright."; break;
                                    case 4 : cout << "\n\t\tI am o.k."; break;
                                    case 5 : cout << "\n\t\tI am getting my needs met."; break;
                                    default: cout << "\n\t\tNever Happen"; break;                    
                                } break;
                case MELANCHOLY :  switch(x)
                                {
                                    case 1 : cout << "\n\t\tThings could be worse..."; break;
                                    case 2 : cout << "\n\t\tI was thinking..."; break;
                                    case 3 : cout << "\n\t\tMaybe so, maybe not..."; break;
                                    case 4 : cout << "\n\t\tI am getting buy..."; break;
                                    case 5 : cout << "\n\t\tI'm hanging in there..."; break;
                                    default: cout << "\n\t\tThings could be better..."; break;                    
                                } break;
                case DEPRESSED :  switch(x)
                                {
                                    case 1 : cout << "\n\t\tI feel sad."; break;
                                    case 2 : cout << "\n\t\tI don't feel very happy."; break;
                                    case 3 : cout << "\n\t\tI feel so depressed."; break;
                                    case 4 : cout << "\n\t\tI don't feel good at all."; break;
                                    case 5 : cout << "\n\t\tI am not in a good mood."; break;
                                    default: cout << "\n\t\tNever Happen"; break;                    
                                } break;
                case SUICIDAL :  switch(x)
                                {
                                    case 1 : cout << "\n\t\tLife sux. I wish I were dead!"; break;
                                    case 2 : cout << "\n\t\tI hate you master!"; break;
                                    case 3 : cout << "\n\t\tI feel like biting you!"; break;
                                    case 4 : cout << "\n\t\tI am going to wizz in your shoes!"; break;
                                    case 5 : cout << "\n\t\tI am completely miserable..."; break;
                                    default: cout << "\n\t\tNever Happen"; break;                    
                                } break;
                default : cout << "\n\t\tNever happen..."; break;
                
           }
           
           switch(Hunger)
           {
               case 0 : cout << "\n\t\t" << PetName << " is full and content."; break;
               case 1 : cout << "\n\t\t" << PetName << " is just a little hungry."; break;
               case 2 : cout << "\n\t\t" << PetName << " is hungry for food"; break;
               case 3 : cout << "\n\t\t" << PetName << " is very hungry."; break;
               case 4 : cout << "\n\t\t" << PetName << " is ravenous!"; break;              
               case 5 : cout << "\n\t\t" << PetName << " is starving to death!"; break;
               default : cout << "\n\t\tHunger value outside range. Error!"; break;
           }
      }
      
      void Suffer() { cout << "\n\t\tPet suffering abuse!"; }
      void Challenge() { cout << "\n\t\tPet challenging another pet."; }
      
      //Public Accesor Methods
      void SetAlive(bool x) { Alive = x; }
      void SetClaws(bool x) { Claws = x; }
      void SetLiveBirth(bool x) { LiveBirth = x;}
      void SetHealth(int x) { Health = x; }
      void SetHunger(int x) { Hunger = x; }
      void SetEnergyLevel(int x) { EnergyLevel = x; }
      void SetSexDrive(int x) { SexDrive = x; }
      void SetEmotiveState(int x) { EmotiveState = x; }
      void SetAge(int x) { Age = x; }
      void SetSize(int x) { Size = x; }
      void SetWeight(int x) { Weight = x; } 
      void SetGender(int x) { Gender = x; }
      void SetSpecies(string x) { species = x; } 
      void SetPetName(string x) { PetName = x; }
      void SetDescription(string desc) { description = desc; }
      
      bool GetAlive() { return Alive; }
      bool GetClaw() { return Claws; }
      bool GetLiveBirth() { return LiveBirth; }
      int GetHealth() { return Health; }
      int GetHunger() { return Hunger; }
      int GetEnergyLevel() { return EnergyLevel; }
      int GetSexDrive() { return SexDrive; }
      int GetEmotiveState() { return EmotiveState; }
      int GetAge() { return Age; }
      int GetSize() { return Size; }
      int GetWeight() { return Weight; }
      int GetGender() { return Gender; }
      string GetSpecies() { return species; }
      string GetPetName() { return PetName; }
      string GetDescription() { return description; }
      
      private:
      //Private Data
      bool Alive;
      bool Claws;
      bool LiveBirth;
      int Gender;
      int Age;
      int Size;
      int Weight;
      int Health;
      int Hunger;
      int EnergyLevel;
      int SexDrive;
      int EmotiveState;
      string description;
      string species; 
      string PetName;           
};

//---------------------------------------------------------------------------------------------------------------------------

//ADT for Mammal
class MammalMorph : public Pet
{
      public:
      MammalMorph() { cout << "\n\t\tCreating a MammalMorph object."; }
      ~MammalMorph() { cout << "\n\t\tDestroying a MammalMorph object."; }
      
      //Functions
      
      //Public Accesor Methods
      void SetHairy(bool x) { Hairy = x; }
      bool GetHairy() { return Hairy; }
      
      void SpellFireBall(){  }
      
      private:
      //Private Data
      bool Hairy;
};

//---------------------------------------------------------------------------------------------------------------------------

//ADT for ReptileMorph
class ReptileMorph : public Pet
{
      public:
      ReptileMorph() {  }
      ~ReptileMorph() {  }
      
      //Functions
      void LayEggs() { cout << "\n\t\tLaying eggs..."; }
      //Public Accesor Methods
      int GetScaleDensity() { return ScaleDensity; }
      void SetScaleDensity(int x) { ScaleDensity = x; }
      
      private:
      int ScaleDensity;
      //Private Data
      
};

//---------------------------------------------------------------------------------------------------------------------------

class Liger : public MammalMorph
{
      public:
      Liger() { cout << "\n\t\tCreating a Liger."; SetSpecies("Liger"); }
      ~Liger() { cout << "\n\t\tDestroying a Liger."; }
      
      //Functions
      void Purr() { cout << "\n\t\tLiger purring..."; }
      void ChaseMice() { cout << "\n\t\tLiger is chasing mice..."; }
      void ScratchVindictively() { cout << "\n\t\tLiger is scratching furniture..."; } 
      void LigerScratch() { cout << "\n\t\tThe Liger lunges with deadly claws!"; }          
      
      //Public Accesor Methods
      bool GetLazy() { return Lazy; }
      void SetLazy(bool x) { Lazy = x; }
      
      private:
      //Private Data
      bool Lazy;
};

//---------------------------------------------------------------------------------------------------------------------------

class Grog : public MammalMorph
{
      public:
      Grog() { cout << "\n\t\tCreating a Grog."; SetSpecies("Grog"); }
      ~Grog() { cout << "\n\t\tDestroying a Grog."; }
      
      //Functions
      void Bark() { cout << "\n\t\tGrog barking!"; }
      void WagTail() { cout << "\n\t\tTail wagging!"; }
      void ChaseLiger() { cout << "\n\t\tChasing Liger..."; }
      void ChewThings() { cout << "\n\t\tChewing something expensive."; }
      void GrogBite() { cout << "\n\t\tThe Grog bites with crushing pressure!"; }
      
      //Public Accesor Methods
      bool GetLoyalty() { return Loyal; }
      void SetLoyalty(bool x) { Loyal = x; }
      
      private:
      //Private Data
      bool Loyal;
};

//---------------------------------------------------------------------------------------------------------------------------

class Snabbit : public ReptileMorph
{
      public:
      Snabbit() { cout << "\n\t\tCreating a Snabbit."; SetSpecies("Snabbit"); }
      ~Snabbit() { cout << "\n\t\tDestroying a Snabbit."; }
      
      //Functions
      void ShedSkin() { }
      void UnhingeJaws() { }
      void SnabbitBite() { cout << "\n\t\tThe Snabbit lunges with poisonous fangs!"; }
      
      //Public Accesor Methods
      bool GetPoisionous() { return Poisonous; }
      void SetPoisonous(bool x) { Poisonous = x; }
      
      private:
      //Private Data
      bool Poisonous;
};

//---------------------------------------------------------------------------------------------------------------------------

class Kizard : public ReptileMorph
{
      public:
      Kizard() { cout << "\n\t\tCreating a Kizard."; SetSpecies("Kizard"); }
      ~Kizard() { cout << "\n\t\tDestroying a Kizard."; }
      
      //Functions
      void TongueLash() { cout << "\n\t\tLashing with tongue...";  }
      void Regenerate() { cout << "\n\t\tRegenerating severed body part..."; }
      void KizardLash() { cout << "\n\t\tTHe Kizard lashes with its tail!"; }
      
      //Public Accesor Methods
      bool GetCamoSkin() { return CamoSkin; }
      void SetCamoSkin(bool x) { CamoSkin = x; }
      
      private:
      //Private Data
      bool CamoSkin;
};

//---------------------------------------------------------------------------------------------------------------------------

