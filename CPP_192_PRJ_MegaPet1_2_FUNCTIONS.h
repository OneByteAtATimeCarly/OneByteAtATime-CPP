//PRJ - MegaPet1 - Classes - 2006 - C. S. Germany
//File 2 of 3
//Functions for MegaPet

//Function Definitions

//---------------------------------------------------------------------------------------------------------------------------

int RANDOM(int x)
{   return (rand()%1) + x; }

//---------------------------------------------------------------------------------------------------------------------------

void Information()
{
     system("CLS"); cout << endl;
        
     cout << "\n\tIt is the year 2032. Transgenics has made many advances"
          << "\n\tin the last 10 years. Manipulating the genetic code of"
          << "\n\tcountless species, chimeras have been created for medical"
          << "\n\tresearch and organ transplantation. Thousands of new species"
          << "\n\thave emerged, not as the result of millions of years of"
          << "\n\tevolution, but as the fulfillment of humanity's whimsical"
          << "\n\tdesire for diversion. Some of these species are used as"
          << "\n\tservants, engineered to become a docile working class. They"
          << "\n\tpossess enough intelligence and human DNA to obey simple"
          << "\n\tverbal commands and follow basic routines for humanity's"
          << "\n\tunwanted, menial tasks. They now fill the positions considered"
          << "\n\ttoo dangerous for genetically pure humans. The species selected"
          << "\n\tfor these human/animal hybrid classes had a predisposed,"
          << "\n\tinstinctual disposition towards social behavior and include"
          << "\n\tsuch species as sheep, horses, cattle, dogs and wolves.\n\n\n\n\t\t\t";
         
     system("PAUSE"); system("CLS"); cout << endl << endl;
          
     cout << "\n\tOther species were bred for military purposes"
          << "\n\tas \"super soldiers\" capable of much greater speed, agility"
          << "\n\tand strength on the battlefield than a genetically pure human."
          << "\n\tThis greatly reduced human fatalities in conventional warfare"
          << "\n\tand increased the destructive yield of battlefield operatives."
          << "\n\tNow one hybrid soldier can do the work of 10 of its pure-human"
          << "\n\tcounter-parts. Unfortunately, due to the battlefield's demand"
          << "\n\tfor increased intelligence and adaptability, a developmental"
          << "\n\tbreeding \"arms race\" ensued, creating hybrids with increasingly"
          << "\n\thigher percentages of human DNA, greater intellectual capacity"
          << "\n\tand more advanced brain structures to facilitate autonomy and"
          << "\n\tingenuity. As a result, despising their second-class citizenship,"
          << "\n\tmany of these hybrids have gone AWOL and started various"
          << "\n\tunderground militias demanding rights for chimeras and hybrids"
          << "\n\tequal to those of genetically-pure humans."
          << "\n\n\n\n\t\t\t";

     system("PAUSE"); system("CLS"); cout << endl << endl << endl;         
         
     cout << "\n\tStill other animal hybrids were created, not by mixing human "
          << "\n\tand animal DNA, but by mixing DNA from disparate animal classes."
          << "\n\tThese hybrid designs were patented by \"Transgenics, LTD\""
          << "\n\tand are now sold as \"pets\" to an ever-widening customer base"
          << "\n\tthat is experiencing continuously increasing demand.\n\n\t\t\t"
          << "\n\tAs a researcher for \"Transgenics, LTD.\", you have been"
          << "\n\tassigned the task of breeding the company's four most"
          << "\n\tpopular genetic concoctions. They are described as follows:"
          << "\n\n\n\n\t\t\t";
    
     system("PAUSE"); system("CLS");
         
     cout << "\n\n\t1. Liger - Part lion and part tiger. Aggressive tendencies"
          << "\n\thave been removed from this animal to mitigate the risk of "
          << "\n\tit killing and eating its owners. Nevertheless, research is"
          << "\n\tstill pending futher market investigation into the safety of"
          << "\n\tthis hybrid."
          << "\n\n\t2. Grog - The Grog's original creators wanted to combine"
          << "\n\tthe cuddliness of a bear, of which the public is so fond of"
          << "\n\taesthetically, with the social aptitude and trainability of"
          << "\n\ta dog, a species which humans have domesticated for thousands"
          << "\n\tof years. During the development phase, Trangenic's home"
          << "\n\tsecurity division suggested giving the hybrid genetic material"
          << "\n\tfrom a grizzly rather than a more docile black bear. Their"
          << "\n\treasoning is that the increased size and aggression resulting"
          << "\n\tfrom the grizzly genes could be activated and employed for"
          << "\n\tself-defense purposes. Designers reasoned that the the genetic"
          << "\n\tmaterial from the dog species would give this hybrid a"
          << "\n\tpredisposition towards obedience and offset any threat posed to"
          << "\n\towners by the more aggressive grizzly genes. "
          << "Research is pending...\n\n\n\t\t\t";  

     system("PAUSE"); system("CLS"); cout << endl << endl;
    
     cout << "\n\t3. Snabbit - Researchers, seeking a way to increase the"
          << "\n\trate of reproduction among certain snakes whose venom"
          << "\n\tforms a key component for many lucrative pharmaceuticals,"
          << "\n\tbegan mixing the the DNA of various snake species with"
          << "\n\tDNA from mammilian rabbits. These hybrids breed rapidly,"         
          << "\n\tand although are useful for research, they have also become"         
          << "\n\tpopular as pets for the adventurous who usually have their"
          << "\n\tvenom glands removed."
          << "\n\n\t4. Kizard - A whimsical pet created by crossing the genetic"
          << "\n\tcharacterisitics of a Kangaroo with a reptilian lizard."
          << "\n\tThese hybrids are resistant to disease, can leap up to"
          << "\n\t20 feet in the air to escape danger, and have the ability"
          << "\n\tto regenerate almost any part of their bodies that is lost"
          << "\n\tor dammaged.";          
                             
     cout << "\n\n\n\n\t\t\t";

     system("PAUSE"); system("CLS");
              
}

//---------------------------------------------------------------------------------------------------------------------------

void CreatePet()
{
     char choice[10];
     system("CLS");
     while(choice[0] != 'q')
     {
         cout << "\n\t\t\tDescriptions:\n\n\t\t\t"
              << "Liger = Lion + Tiger\n\t\t\t"
              << "Grog = Grizzly + Dog\n\t\t\t"
              << "Snabbit = Snake + Rabbit\n\t\t\t"            
              << "Kizard = Kangaroo + Lizard\n\n";
                    
         cout << "\n\t\t\t**** Create a Pet ****"
              << "\n\t\t\t*                    *"
              << "\n\t\t\t*    (L)iger         *"
              << "\n\t\t\t*    (G)rog          *"
              << "\n\t\t\t*    (S)nabbit       *"
              << "\n\t\t\t*    (K)izard        *"
              << "\n\t\t\t*    (I)nformation   *"
              << "\n\t\t\t*    (Q)uit          *"
              << "\n\t\t\t*                    *"
              << "\n\t\t\t**********************\n\n\t\t\t";
            
         cin >> choice;
         choice[0] = tolower(choice[0]);
       
         switch(choice[0])
         {
            case 'l' : ThePet = new Liger(); ThePet->ChoosePet();
                       choice[0] = 'q'; CreatedPet = true; break;
            case 'g' : ThePet = new Grog(); ThePet->ChoosePet();
                       choice[0] = 'q'; CreatedPet = true; break;
            case 's' : ThePet = new Snabbit(); ThePet->ChoosePet();
                       choice[0] = 'q'; CreatedPet = true; break;
            case 'k' : ThePet = new Kizard(); ThePet->ChoosePet();
                       choice[0] = 'q'; CreatedPet = true; break;
            case 'i' : Information(); break;          
            case 'q' : cout << "\n\t\tExiting!\n"; break;
            default : cout << "\n\t\tSorry, that was not an option.\n"; break; 
         }                
     }
     if(CreatedPet) { cout << "\n\t\t"; system("PAUSE"); }
     system("CLS");
}

//---------------------------------------------------------------------------------------------------------------------------

void LoadPet()
{
    
}

//---------------------------------------------------------------------------------------------------------------------------

void SavePet()
{
    
}

//---------------------------------------------------------------------------------------------------------------------------

void Interact()
{
     char choice[10];
   
     while(choice[0] != 'q' && ThePet->GetHealth() > 0)
     {   
         cout << "\n\t\tHours: " << Hours;
                
         ThePet->DisplayPet();  
                
         cout << "\n\n\t\t*****Interact With Pet****"
              << "\n\t\t*                        *"
              << "\n\t\t*  (F)eed      (S)leep   *"
              << "\n\t\t*  (P)et       (T)alk    *"
              << "\n\t\t*  (C)hallenge (K)ick    *"
              << "\n\t\t*  (Q)uit                *"
              << "\n\t\t*                        *"             
              << "\n\t\t**************************\n\n\t\t";
            
         cin >> choice;
         choice[0] = tolower(choice[0]);
       
         switch(choice[0])
         {
            case 'f' : ThePet->Eat(); break;
            case 's' : ThePet->Sleep(); break;
            case 'p' : ThePet->ShowAffection(); break;
            case 'c' : ThePet->Challenge(); break;
            case 'k' : ThePet->Suffer(); break;
            case 't' : ThePet->Communicate(); break;            
            case 'q' : cout << "\n\t\tExiting!\n"; break;
            default : cout << "\nSorry, that was not an option.\n";  
         }      
       
         //If homeostatis - if pet is well fed and rested, increase health
         if(ThePet->GetHunger() == 0 && ThePet->GetEnergyLevel() == 10)
         { 
            if(ThePet->GetHealth() + 10 < 100)
            { ThePet->SetHealth(ThePet->GetHealth() + 10); }
            else { ThePet->SetHealth(100); }
         }
        
         //Adjust Health for hunger level every 2 hours - requires feeding
         if(Hours % 2 == 0)
         {
             switch(ThePet->GetHunger())
             {
                 case 0 : break; //do nothing
                 case 1 : break; //do nothing
                 case 2 : break; //do nothing            
                 case 3 : if((ThePet->GetHealth() - 1) > 0)
                          { ThePet->SetHealth(ThePet->GetHealth() - 1); }
                          else { ThePet->SetHealth(0); }
                          break;
                 case 4 : if((ThePet->GetHealth() - 5) > 0)
                          { ThePet->SetHealth(ThePet->GetHealth() - 5); }
                          else { ThePet->SetHealth(0); }
                          break;
                 case 5 : if((ThePet->GetHealth() - 10) > 0)
                          { ThePet->SetHealth(ThePet->GetHealth() - 10); }
                          else { ThePet->SetHealth(0); }
                          break;
                 default : break;                                  
             }
         }       
       
         //Pet increases hunger each 8 hours
         if(Hours % 8 == 0)
         {
              if((ThePet->GetHunger() + 1) < 5)
              { ThePet->SetHunger(ThePet->GetHunger() + 1); }
              else { ThePet->SetHunger(5); }
         }
           
          //Pet grows more tired every 10 hours
         if(Hours % 10 == 0)
         {
               if((ThePet->GetEnergyLevel() - 1) >= 0)
               { ThePet->SetEnergyLevel(ThePet->GetEnergyLevel() - 1); }
               else { ThePet->SetEnergyLevel(0); }
         } 
        
        
         //Adjust for energy level every 2 hours - requires sleep
         if(Hours % 2 == 0)
         {
             if(ThePet->GetEnergyLevel() > 0 && ThePet->GetEnergyLevel() < 3)
             {
                if((ThePet->GetHealth() - 5) > 0)
                { ThePet->SetHealth(ThePet->GetHealth() - 5); }
                else { ThePet->SetHealth(0); }                          
             }
        
             if(ThePet->GetEnergyLevel() > 3 && ThePet->GetEnergyLevel() < 6)
             {
                if((ThePet->GetHealth() - 2) > 0)
                { ThePet->SetHealth(ThePet->GetHealth() - 2); }
                else { ThePet->SetHealth(0); }             
             }  
         }
         //Advance hours to age pet
         Hours++;
     }
}

//---------------------------------------------------------------------------------------------------------------------------

