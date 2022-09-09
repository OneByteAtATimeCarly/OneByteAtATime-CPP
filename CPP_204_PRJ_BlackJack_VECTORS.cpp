//PRJ - BlackJack Game Console - VECTORS - 2006 - C. S. Germany
//Blackjack example, using vectors

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------

class Card
{
public:
       
    enum rank{ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
               JACK, QUEEN, KING};  
                        
    enum suit{CLUBS, DIAMONDS, HEARTS, SPADES};
    
    Card(rank r = ACE, suit s = SPADES, bool ifu = true) 
    { 
         m_Rank = r; 
         m_Suit = s; 
         m_CardFaceUp = ifu; 
    }    

    //overloading << operator so can send Card object to standard output 
    friend ostream& operator<<(ostream& os, const Card& aCard);

    //returns the value of a card, 1 - 11
    int GetValue() const
    {
         //if a cards is face down, its value is 0
         int value = 0;
         if(m_CardFaceUp)
         {
             //value is number showing on card
             value = m_Rank;
             //value is 10 for face cards
             if(value > 10)
                value = 10;
         }
         
         return value;
    }

    //flips a card; if face up, becomes face down and vice versa
    void Flip()
    {
         m_CardFaceUp = !(m_CardFaceUp);
    }
    
private:
    rank m_Rank;
    suit m_Suit;
    bool m_CardFaceUp;
};

//---------------------------------------------------------------------------------------------------------------------------

class HandOfCards
{
public:
       
    HandOfCards() 
    { 
        m_Cards.reserve(7); 
        Deck = new Card[52];          
    }
 
    virtual ~HandOfCards()  //don't use the keyword virtual outside of class definition
    {
         Clear();
    }

    //adds a card to the hand
    void Add(Card* pCard)
    {
         m_Cards.push_back(pCard);
    }
 
    //clears hand of all cards
    void Clear()
    {
        //iterate through vector, freeing all memory on the heap
        vector<Card*>::iterator iter = m_Cards.begin();
        for(iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            delete *iter;
            *iter = 0;
        }
        
        //clear vector of pointers
        m_Cards.clear();
    }
 
    //gets hand total value, intelligently treats aces as 1 or 11
    int GetTotal() const
    {
        //if no cards in hand, return 0
        if(m_Cards.empty())
            return 0;
  
        //if a first card has value of 0, then card is face down; return 0
        if(m_Cards[0]->GetValue() == 0)
            return 0;
    
        //add up card values, treat each Ace as 1
        int total = 0;
        vector<Card*>::const_iterator iter;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            total += (*iter)->GetValue();
                  
        //determine if hand contains an Ace
        bool containsAce = false;
        for(iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            if((*iter)->GetValue() == Card::ACE)
            containsAce = true;
          
        //if hand contains Ace and total is low enough, treat Ace as 11
        if(containsAce && total <= 11)
           //add only 10 since we've already added 1 for the Ace
           total += 10;   
            
        return total;
    }

protected:
    Card * Deck;      
    vector<Card*> m_Cards;
};

//---------------------------------------------------------------------------------------------------------------------------

class GenericPlayer : public HandOfCards
{
    //Remember that friend functions must be defined outside of the class  
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
       
    GenericPlayer(const string& name = "") { m_Name = name; }
    
    virtual ~GenericPlayer() {  }

    //indicates whether or not generic player wants to keep hitting
    //Function below is PURE virtual since it's initialized to 0
    //This means it will never be used.
    virtual bool IsHitting() const = 0;

    //returns whether generic player has busted - has a total greater than 21
    bool IsBusted() const   { return (GetTotal() > 21); }

    //announces that the generic player busts
    void Bust() const  { cout << m_Name << " busts.\n"; }

protected:
    string m_Name;
};

//---------------------------------------------------------------------------------------------------------------------------

class Player : public GenericPlayer
{
public:

    Player(const string & name = ""): GenericPlayer(name) {  }

    virtual ~Player() { }

    //returns whether or not the player wants another hit       
    bool IsHitting() const
    {
        cout << m_Name << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }

    //announces that the player wins
    void Win() const  { cout << m_Name <<  " wins.\n"; }

    //announces that the player loses
    void Lose() const  { cout << m_Name <<  " loses.\n"; }

    //announces that the player pushes
    void Push() const  { cout << m_Name <<  " pushes.\n"; }
};

//---------------------------------------------------------------------------------------------------------------------------

class House : public GenericPlayer
{
public:
       
    House(const string & name = "House"): GenericPlayer(name) { }

    virtual ~House() { }

    //indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const  { return (GetTotal() <= 16); } 

    //flips over first card
    void FlipFirstCard()
    {
        if(!(m_Cards.empty()))
            m_Cards[0]->Flip();
        else { cout << "No card to flip!\n"; }
    }
};

//---------------------------------------------------------------------------------------------------------------------------

class Deck : public HandOfCards
{
public:
    Deck()
    { 
       m_Cards.reserve(52);
       Populate();
    }
    
    virtual ~Deck() { }

    //create a standard deck of 52 cards
    void Populate()
    {
        Clear();
        //create standard deck
        for(int s = Card::CLUBS; s <= Card::SPADES; ++s)
            for(int r = Card::ACE; r <= Card::KING; ++r)
                Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
    }

    //shuffle cards
    void Shuffle()
    {
        random_shuffle(m_Cards.begin(), m_Cards.end());
    }

    //deal one card to a hand
    void Deal(HandOfCards& aHandOfCards)
    {
        if(!m_Cards.empty())
        {
            aHandOfCards.Add(m_Cards.back());
            m_Cards.pop_back();
        }
        else
        {
            cout << "Can't deal - there aren't any cards left.";
        }
    }

    //give additional cards to a generic player 
    void AdditionalCards(GenericPlayer& aGenericPlayer)
    {
        cout << endl;
        //continue to deal a card as long as generic player isn't busted and
        //wants another hit
        while( !(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting() )
        {
            Deal(aGenericPlayer);
            cout << aGenericPlayer << endl;
        
            if(aGenericPlayer.IsBusted())
                aGenericPlayer.Bust();
        }
    } 
};

//---------------------------------------------------------------------------------------------------------------------------

class GameOfHands
{
public:
       
    GameOfHands(const vector<string>& names)
    {
        //create a vector of players from a vector of names       
        vector<string>::const_iterator pName;
        for(pName = names.begin(); pName != names.end(); ++pName)      
            m_Players.push_back(Player(*pName));

        srand(time(0));    //seed the random number generator
        m_Deck.Populate();
        m_Deck.Shuffle();
    }
    
    ~GameOfHands() { }
    
        //plays the game of blackjack    
    void Play()
    {         
        //deal initial 2 cards to everyone
        vector<Player>::iterator pPlayer;
        for (int i = 0; i < 2; ++i)
        {
            for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
                m_Deck.Deal(*pPlayer);
                m_Deck.Deal(m_House);
        }
    
        //hide house's first card
        m_House.FlipFirstCard();    
    
        //display everyone's hand
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
            cout << *pPlayer << endl;
        cout << m_House << endl;

        //deal additional cards to players
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        m_Deck.AdditionalCards(*pPlayer);    
    
        //reveal house's first card
        m_House.FlipFirstCard();    
        cout << endl << m_House; 
  
        //deal additional cards to house
        m_Deck.AdditionalCards(m_House);

        if(m_House.IsBusted())
        {
            //everyone still playing wins
            for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
                if( !(pPlayer->IsBusted()) )
                    pPlayer->Win();
        }
        else
        {
             //compare each player still playing to house
            for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
                if( !(pPlayer->IsBusted()) )
                {
                    if(pPlayer->GetTotal() > m_House.GetTotal())
                        pPlayer->Win();
                    else if (pPlayer->GetTotal() < m_House.GetTotal())
                        pPlayer->Lose();
                    else
                        pPlayer->Push();
                }
        }

        //remove everyone's cards
        for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
            pPlayer->Clear();
        m_House.Clear();
    } //close Play() function

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;  
};

//---------------------------------------------------------------------------------------------------------------------------

//Overloaded Function Prototypes
ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
    cout << "\t\tWelcome to Blackjack!\n\n";
    
    int NumberOfPlayers = 0;
    while(NumberOfPlayers < 1 || NumberOfPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> NumberOfPlayers;
    }   

    vector<string> names;
    string name;
    
    for(int i = 0; i < NumberOfPlayers; ++i)
    {
        cout << "Enter name for this player: ";
        cin >> name;
        names.push_back(name);
    }
    
    cout << endl;

    //the game loop        
    GameOfHands aGameOfHands(names);
    char again = 'y';
    
    while(again != 'n' && again != 'N')
    {
        aGameOfHands.Play();
        cout << "\nWould you like to play the game again? (Y/N): ";
        cin >> again;
    } 
   
    system("PAUSE");

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

//Function Definitions

//---------------------------------------------------------------------------------------------------------------------------

//overloads << operator so Card object can be sent to cout

ostream & operator<<(ostream & os, const Card & aCard)
{
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", 
                            "10", "J", "Q", "K"};
    const string SUITS[] = {"c", "d", "h", "s"};

    if(aCard.m_CardFaceUp)
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    else
        os << "XX";

    return os;
}

//---------------------------------------------------------------------------------------------------------------------------

//overloads << operator so a GenericPlayer object can be sent to cout

ostream & operator<<(ostream & os, const GenericPlayer & aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";
    
    vector<Card*>::const_iterator pCard;
    if(!aGenericPlayer.m_Cards.empty())
    {
        for(pCard = aGenericPlayer.m_Cards.begin(); 
            pCard != aGenericPlayer.m_Cards.end(); ++pCard)
            os << *(*pCard) << "\t";

        if(aGenericPlayer.GetTotal() != 0)
           cout << "(" << aGenericPlayer.GetTotal() << ")";
    }
    else
    {
        os << "<empty>";
    }
        
    return os;
}

//---------------------------------------------------------------------------------------------------------------------------










