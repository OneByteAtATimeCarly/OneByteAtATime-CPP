//PRJ - Checkers Game Console - 2006 - C. S. Germany
//File 2 of 4: CLASSES

//---------------------------------------------------------------------------------------------------------------------------

class Checker
{
      public:
             
      Checker() 
      { 
          cout << "\n  Created a Checker."; 
          KING = false;
          selected = false;
      }
      
      Checker(int CLR)
      {
          color = CLR;
          KING = false; 
          selected = false;
          
          cout << "\n  Created a ";
          
          switch(color)
          {
              case BLACK : cout << "BLACK"; break;
              case RED : cout << "RED"; break;
              case BLANK : cout << "BLANK Space"; break;
              default : cout << "\n This should never happen!"; break;     
          } 
           
          cout << " Checker!";               
      }
      
      ~Checker() 
      {  }   
      
      string TYPE()
      {    
           if(selected)
           {
               switch(color)
               {
                  case BLACK : return "(B)";
                  case RED : return "(R)"; 
                  case BLANK : return "   ";
                  default : cout << "\n This should never happen!"; 
                            break;     
               }                        
           }
           else
           {
               switch(color)
               {
                  case BLACK : return " B ";
                  case RED : return " R "; 
                  case BLANK : return "   ";
                  default : cout << "\n This should never happen!"; 
                            break;     
               }                
           }
     
      }
      
      //Accessors
      int GetColor() { return color; }
      void SetColor(int x) { color = x; }
      bool GetKing() { return KING; }
      void SetKing(bool x) { KING = x; }
      bool GetSelected() { return selected; }
      void SetSelected(bool x) { selected = x; }
      
      private:
      int color;
      bool KING;
      bool selected;       
};

//---------------------------------------------------------------------------------------------------------------------------

class Player
{
      public:
      Player() 
      { 
         cout << "\n Creating a Player object."; 
         SetPlayerName("Anonymous");
         SetPlayerScore(0);
      }
      ~Player() { cout << "\n Destroying a Player object."; } 
      
      //Accessors
      void SetPlayerName(string x) { PlayerName = x; }
      string GetPlayerName() { return PlayerName; }
      void SetPlayerColor(int x) { PlayerColor = x; }
      int GetPlayerColor() { return PlayerColor; }
      void SetPlayerScore(int x) { PlayerScore = x; }
      int GetPlayerScore() { return PlayerScore; }
      
      //Data members
      private:
      string PlayerName;
      int PlayerColor;
      int PlayerScore;
};

//---------------------------------------------------------------------------------------------------------------------------












