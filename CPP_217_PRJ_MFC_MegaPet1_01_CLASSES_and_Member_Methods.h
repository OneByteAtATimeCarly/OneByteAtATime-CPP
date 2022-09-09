//PRJ - MegaPet1 - MFC GUI Game - 2006 - C. S. Germany
//File 1 of 4: CLASSES and Member Methods

//---------------------------------------------------------------------------------------------------------------------------

#include <string>
#include <windows.h>
#include <strstream>    //Necessary for ostrstream object
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

static char DISPLAY[2000];
static ostrstream WRITEME(DISPLAY, 2000);

//---------------------------------------------------------------------------------------------------------------------------

bool NeedName;
bool Started;
int Day;

//---------------------------------------------------------------------------------------------------------------------------

//Global pointers
CEdit * pOutput;
CEdit * pInput;
CEdit * pName;
CStatic * pPetView;
CStatic * pLife;
CStatic * pEmotiveState;
CStatic * pDays;
CButton * pGO;
CSliderCtrl * RAGEoMETER;

//---------------------------------------------------------------------------------------------------------------------------

int RandomNumber(int n) 
{
    int ResultRandom;
    ResultRandom = (rand()%n) + 1;
    return ResultRandom;
}

//---------------------------------------------------------------------------------------------------------------------------

class  MegaPet
{
       public:
       MegaPet(int LF = 50, int ES = 5) 
       { 
	    Life = LF; EmotiveState = ES;
	    WRITEME << "\r\nCreating a MegaPet.\r\n"; 
	    pOutput->SetWindowText(DISPLAY);
	    Day = 1;
       }

       ~MegaPet() 
       { 
	    WRITEME << "\r\nDestroying a MegaPet.\r\n"; 
	    pOutput->SetWindowText(DISPLAY);
       }

//---------------------------------------------------------------------------------------------------------------------------

//Class Member Methods

//---------------------------------------------------------------------------------------------------------------------------

void SetName()
{
	 char n[40];
	 pInput->GetWindowText(n, 40); 
         PetName = n;
	 pName->SetWindowText(PetName);
	 NeedName = false;
	 pInput->SetWindowText("");
}

//---------------------------------------------------------------------------------------------------------------------------

void Feed()
{
    strncpy(DISPLAY,"",2000); 
    WRITEME.seekp(0);

    if(Life < 50)
    {
        WRITEME << "\r\nYou feed your pet. This brings it "
		<< "happy contentment and adds 3 points to"
                << " its Life.\r\n";

        Life = Life + 3;
    }

    else
    {
        WRITEME << "\r\nYour feed your pet, but it is just not"
		<< " hungry. As a result, it gets sick and vomits"
                << " on your new carpet. This causes you to scold"
                << " it, and it looses 1 life point.\r\n";

	Life = Life - 1;
    }

    View(); 
    pOutput->SetWindowText(DISPLAY); 
    PlaySound("media/TazFart.wav",NULL,SND_FILENAME|SND_ASYNC);
}

//---------------------------------------------------------------------------------------------------------------------------

void Pet()
{
    strncpy(DISPLAY,"",2000); 
    WRITEME.seekp(0);

    if(EmotiveState < 5)
    {
        WRITEME << "\r\nYou pet your pet. This affection raises "
                << "its spirits, improving its outlook on life.\r\n";

        EmotiveState = EmotiveState + 1;
    }

    else
    {
        WRITEME << "\r\nYour pet does not require petting. It feels"
		<< " loved and content.\r\n";
    }

    View(); 
    pOutput->SetWindowText(DISPLAY);
    PlaySound("media/TazLaugh.wav",NULL,SND_FILENAME|SND_ASYNC);
}

//---------------------------------------------------------------------------------------------------------------------------

void Sleep()
{
     strncpy(DISPLAY,"",2000); 
     WRITEME.seekp(0);

     if(Life < 50)
     {
       WRITEME << "\r\nYour pet could use some sleep. It gains 1"
	       << " life point!\r\n";

       Life = Life + 2;        
     }

     else
     {
       WRITEME << "\r\nYour pet does not need any sleep. You put "
	       << "it to bed any way, causing it undue anxiety and"
               << " it looses 1 life point.\r\n";

       Life = Life - 1;      
     }
    
    View(); 
    pOutput->SetWindowText(DISPLAY);  
}

//---------------------------------------------------------------------------------------------------------------------------

void Talk()
{
     strncpy(DISPLAY,"",2000); 
     WRITEME.seekp(0);

     int PetState = RandomNumber(10);
     
     WRITEME << "\r\n";

     if(EmotiveState > 3)
     {
          switch(PetState)
          {
              case 1 : WRITEME << "Purr! I love you master! My life for you!\r\n";
                       break;      
              case 2 : WRITEME << "I am happy and content. Life is good.\r\n"; 
                       break;          
              case 3 : WRITEME << "I am fairly content with things.\r\n"; 
                       break;          
              case 4 : WRITEME << "I am o.k. Are you o.k.?\r\n";
                       break;           
              case 5 : WRITEME << "I am surviving, getting by...\r\n";
                       break;           
              case 6 : WRITEME << "It's all good, baby.\r\n";
                       break;          
              case 7 : WRITEME << "That's life I guess.\r\n";
                       break;           
              case 8 : WRITEME << "I am so happy it is hard not to wet myself.\r\n";
                       break;           
              case 9 : WRITEME << "I must be in heaven!\r\n";
                       break;           
              case 10 : WRITEME << "When I'm with you, everything is o.k.\r\n";
                        break;                  
              default : WRITEME << "This should never happen! Only values 1-10.\r\n";
        } //close switch

        PlaySound("media/TazTalk1.wav",NULL,SND_FILENAME|SND_ASYNC);

     } // close if  
     
     else if(EmotiveState <= 3 && EmotiveState > 1)
     {
              switch(PetState)
          {
              case 1 : WRITEME << "I feel really sad. So sad...\r\n";
                       break;      
              case 2 : WRITEME << "I am so lonely. Please pet me master.\r\n"; 
                       break;          
              case 3 : WRITEME << "Sigh, if only...\r\n"; 
                       break;          
              case 4 : WRITEME << "Have I displeased you master?\r\n";
                       break;           
              case 5 : WRITEME << "Don't you love me any more?\r\n";
                       break;           
              case 6 : WRITEME << "I crave your love and affection...\r\n";
                       break;          
              case 7 : WRITEME << "Why me?\r\n";
                       break;           
              case 8 : WRITEME << "Feelin' mighty low...\r\n";
                       break;           
              case 9 : WRITEME << "My life is a living hell.\r\n";
                       break;           
              case 10 : WRITEME << "I'm thinking about ways to kill myself.\r\n";
                        break;                  
              default : WRITEME << "I don't want to go on living.\r\n";
        } //close switch 

        PlaySound("media/TazTalk2.wav",NULL,SND_FILENAME|SND_ASYNC);
     }
     
     else
     {  
        WRITEME << "\r\nI hate you. I want to bite your freakin' arm off"
			    << " master. When you sleep at night I will lift my leg"
                << " I will shred your favorite pillow, and wizz in your"
                << "  shoes! I will defecate on your homework.\r\n";
                
     }
     
     //While the first statement is based on EmotiveState, the second is based on life  
     if(Life > 40 && Life <= 50)
     { WRITEME << "\r\nI'm not really hungry or sleepy."; }
     if(Life > 30 && Life <= 40)
     { WRITEME << "\r\nI feel a little hungry."; }
     if(Life > 20 && Life <= 30)
     { WRITEME << "\r\nI feel really hungry and sleepy."; }
     if(Life > 10 && Life <= 20)
     { WRITEME << "\r\nI am starving to death."; }
     if(Life > 0 && Life <= 10)
     { WRITEME << "\r\nI am so weak and don't think I will last much longer."; }    
	    
     View(); 
     pOutput->SetWindowText(DISPLAY); 
}

//---------------------------------------------------------------------------------------------------------------------------

void View()
{   
     HBITMAP EmoPix;
     CString Feeling;
       
     switch(EmotiveState)
     {
        case 1 : Feeling = "Depressed and Suicidal"; 
			   EmoPix = (HBITMAP) LoadImage(NULL,"MEDIA/STILL_Sad.bmp",
                           IMAGE_BITMAP, 0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);
			   RAGEoMETER->SetPos(0);    //SAD
				 break; 
        case 2 : Feeling = "Down and Out"; 
			   EmoPix = (HBITMAP) LoadImage(NULL,"MEDIA/STILL_Angry.bmp",
                           IMAGE_BITMAP, 0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);
			   RAGEoMETER->SetPos(19);   //RAGE
				 break;  
        case 3 : Feeling = "Melancholy"; 
			   EmoPix = (HBITMAP) LoadImage(NULL,"MEDIA/STILL_Melancholy.bmp",
                           IMAGE_BITMAP, 0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);
			   RAGEoMETER->SetPos(47);   //MELANCHOLY
				 break;  
        case 4 : Feeling = "Fairly Happy"; 
			   EmoPix = (HBITMAP) LoadImage(NULL,"MEDIA/STILL_Happy.bmp",
                           IMAGE_BITMAP, 0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);
			   RAGEoMETER->SetPos(73);   //HAPPY		
				 break;  
        case 5 : Feeling = "Ecstatic with Joy"; 
			   EmoPix = (HBITMAP) LoadImage(NULL,"MEDIA/STILL_Ecstatic.bmp",
                           IMAGE_BITMAP, 0,0,LR_DEFAULTSIZE | LR_LOADFROMFILE);
			   RAGEoMETER->SetPos(100);  //ECSTATIC
			   break;  
        default : break;                    
     } 

     char buffer[10];
     char n[50];

     itoa(Life, buffer, 10);
     pLife->SetWindowText(buffer);

     pEmotiveState->SetWindowText(Feeling);

     strcpy(n, "  ");
     strncat(n, PetName, 50);
     pName->SetWindowText(n);
     
     itoa(Day, buffer, 10);
     pDays->SetWindowText(buffer);

     pPetView->SetBitmap(EmoPix); 
}

//---------------------------------------------------------------------------------------------------------------------------

void Kick()
{
     strncpy(DISPLAY,"",2000); 
     WRITEME.seekp(0);

     WRITEME << "\r\n\r\nYou kick your pet. You are a real jerk!\r\n\r\n";

     if(EmotiveState > 1)
     { 
        EmotiveState = EmotiveState - 1;
     }

     else
     {
         WRITEME << "\r\nYou are not worthy of being a pet owner.\r\n\r\n"
		 << " Kick 'em when they're down? You should be charged"
		 << " with animal cruelty and your pet taken away.\r\n";

	 EmotiveState = 1;
     }

     View(); 
     pOutput->SetWindowText(DISPLAY);
     PlaySound("media/Kick.wav",NULL,SND_FILENAME|SND_ASYNC);
}

//---------------------------------------------------------------------------------------------------------------------------

void Play()
{
     strncpy(DISPLAY,"",2000); 
     WRITEME.seekp(0);

     WRITEME << "Playing with pet...\r\n";

     if(Life < 50) { Life = Life + 1; }

     View(); 
     pOutput->SetWindowText(DISPLAY);
}

//---------------------------------------------------------------------------------------------------------------------------

    //Accessors---------------------------------------
	int getLife() { return Life; }
	int getEmotiveState() { return EmotiveState; }
	int getDays() { return Day; }
	CString getPetName() { return PetName; }

	void setLife(int x) { Life = x; }
	void setEmotiveState(int x) { EmotiveState = x; }
	void setDays(int x) { Day = x; }
	void setPetName(CString x) { PetName = x; }
    //------------------------------------------------

private:
int Life;
int EmotiveState;
int Day;
CString PetName;

}; //End MegaPet class specification

//---------------------------------------------------------------------------------------------------------------------------












