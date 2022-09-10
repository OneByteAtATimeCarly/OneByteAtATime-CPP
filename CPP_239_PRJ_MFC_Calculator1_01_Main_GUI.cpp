//PRJ - Calculator 1 - MFC GUI App - 2006 - C. S. Germany
//File 1 of 3: Main File - MFC GUI

//---------------------------------------------------------------------------------------------------------------------------

/*
01/16/2010 C. S. Germany
2008 Notes:
--------------------------------------------------------------------------	
To create a scaled down 2008 template project:
   1. Create an EMPTY Win32 project. Click -> "File" -> -> "New"
	  -> "Project" -> "Win32" -> "Win32 Project".
   2. Name is and select a directory.
   3. Select "Application Settings" -> "Empty Project" then click "Finish".
   4. Rt-click project, select "Properties" -> "Configuration Properties"
      -> "General" -> "Use of MFC" and change it to 
      "Use MFC in a Static Library". This will give you MFC components.
   5. Disable Incremental Linking. Rt-click project, select "Properties" 
	  -> "Configuration Properties" -> "Linker" -> "General" ->
      "Enable Incremental Linking" and set it to "NO".
   6. Add a resources file. Rt-click resources and add a DIALOG object.
   7. Change the enumerated constant in the CDialog class to match the
	  Dialog object ID in the resource file.
--------------------------------------------------------------------------
To remove 2008 warnings (you can ignore them if you choose):
   1.Rt-click PROJECT and select -> "Properties" -> "Configuration Properties"
     -> "C/C++" -> "General" -> "Debug Information Formant" and 
     -> "Program Database for Edit and Continue /ZI". Set it to "Disabled".
   2.Rt-click PROJECT and select -> "Properties" -> "Configuration Properties"
     -> "C/C++" -> "Code Generation" -> "Enable Minimal Rebuild" and 
     -> "Yes (/Gm)". Set it to "No".
   3.Use "_atoi_s()" instead of "itoa()" to avoid deprecation warning.
   4.Use "sprintf_s()" instead of "sprintf()" to avoid deprecation warning.
--------------------------------------------------------------------------
Significant changes needed for going from 2003 to 2008 are:
   1. When calling SetWindowText() in 2008 the string passed in must be
      cast/converted to unicode by prefixing it with "L".
   2. You must use CStrings with SetWindowText() and MessageBox.
   3. You must convert from CString to char array and char array to CString
      when using atoi and itoa with GetWindowText() and SetWindowText().
--------------------------------------------------------------------------
*/

//---------------------------------------------------------------------------------------------------------------------------

#include <afxwin.h>     // MFC core and standard components
#include <afxcmn.h>	
#include "CPP_240_PRJ_MFC_Calculator1_02_Resources.h"   // main symbols
#include <cmath>

//---------------------------------------------------------------------------------------------------------------------------

//Globals
CEdit * pInputOutput;
CButton * pEquals;
CBrush CalculatorBrush;
double Number1;
double Number2;
double Result;
double Memory;
bool NextExpression;
bool NeedToClear;
bool ClickedEquals;
bool PasteMemory;
char oper;
CString TEMP;

//---------------------------------------------------------------------------------------------------------------------------

class Calculator : public CDialog
{
    public:
    Calculator(CWnd* pParent = NULL): CDialog(Calculator::IDD, pParent) {    }
    // Dialog Data, name of dialog form
    enum{IDD = IDD_Interface};

    //--------------------------------------------------------
    //Called right after constructor. Initialize things here.
    virtual BOOL OnInitDialog() 
    { 
            CDialog::OnInitDialog();
	        pInputOutput = (CEdit *) GetDlgItem(IDC_InputOutput);
			pEquals = (CButton *) GetDlgItem(IDC_NumEquals);
	        //pInputOutput->SetFocus();
	        CalculatorBrush.CreateSolidBrush(RGB(255, 255, 255));
            Initialize();
            return true; 
    }

    //--------------------------------------------------------
   afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
   {
     
	  switch (nCtlColor) 
      {
	          case CTLCOLOR_EDIT:   pDC->SetTextColor(RGB(255,0,255));
              case CTLCOLOR_STATIC: pDC->SetTextColor(RGB(255,0,255));
              case CTLCOLOR_DLG:    return CalculatorBrush;
              default:  return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
      }
	  
   }

//--------------------------------------------------------
//To Get Keyboard Messages, bypass buggy CDialog MFC Keyboard Message Handlers 
//Use ASCII values. Prevent duplicate input with if/else and WM_KEYDOWN
//IMPORTANT: Set CEdit control to read only or it will process input twice.
//Unlike +,- and /, the * key is also key for number 8 so must handle it.

BOOL PreTranslateMessage(MSG* pMsg) 
{
     int nVirtKey = (int) pMsg->wParam;
	 if(nVirtKey == 42 || nVirtKey == 43 || nVirtKey == 45 ||
		nVirtKey == 47 || nVirtKey == 61)
	 {
		 	 if(nVirtKey == 42)    
			 {   //Calls 8 too so have to shave off last character
                 pInputOutput->GetWindowText(TEMP);
				 TEMP.Delete(TEMP.GetLength()-1,1);
				 pInputOutput->SetWindowText(TEMP);
				 Calculate('m'); 
			 } // * MULTIPLY
             if(nVirtKey == 43)    { Calculate('a'); } // + PLUS
	         if(nVirtKey == 45)    { Calculate('s'); } // - MINUS
	         if(nVirtKey == 47)    { Calculate('d'); } // / DIVIDE
             if(nVirtKey == 61)    { Equals(); }       // = EQUALS
	 }
     else if(pMsg->message == WM_KEYDOWN) 
	 {       
             if(nVirtKey == 48)    { KeyNumber("0"); }
             if(nVirtKey == 49)    { KeyNumber("1"); }       
             if(nVirtKey == 50)    { KeyNumber("2"); }       
             if(nVirtKey == 51)    { KeyNumber("3"); }
             if(nVirtKey == 52)    { KeyNumber("4"); }
             if(nVirtKey == 53)    { KeyNumber("5"); }       
             if(nVirtKey == 54)    { KeyNumber("6"); }       
             if(nVirtKey == 55)    { KeyNumber("7"); }
	         if(nVirtKey == 56)    { KeyNumber("8"); }
             if(nVirtKey == 57)    { KeyNumber("9"); }       
		
	     //More examples. See ASCII Chart at Bottom for codes.
	     if(nVirtKey == 65) { MessageBox(L"The \"a\" Key Was Pressed!"); }
		 if(nVirtKey == VK_UP) { MessageBox(L"Up Key Pressed!"); }
         if(nVirtKey == VK_DOWN) { MessageBox(L"Down Key Pressed!"); }
         if(nVirtKey == '\r')  { Equals(); }
	 }
     
	 return CDialog::PreTranslateMessage(pMsg);
}

//--------------------------------------------------------
    //Message Handlers for Dialog class object
	afx_msg void key0() { KeyNumber("0"); }
	afx_msg void key1() { KeyNumber("1"); }
	afx_msg void key2() { KeyNumber("2"); }
	afx_msg void key3() { KeyNumber("3"); }
	afx_msg void key4() { KeyNumber("4"); }
	afx_msg void key5() { KeyNumber("5"); }
	afx_msg void key6() { KeyNumber("6"); }
	afx_msg void key7() { KeyNumber("7"); }
	afx_msg void key8() { KeyNumber("8"); }
	afx_msg void key9() { KeyNumber("9"); }
	afx_msg void keyPeriod() { KeyNumber("."); }
	afx_msg void keyEquals() { Equals(); }
	afx_msg void keyAdd() { Calculate('a'); }
	afx_msg void keySubtract() { Calculate('s'); }
	afx_msg void keyMultiply() { Calculate('m'); }
	afx_msg void keyDivide() { Calculate('d'); }
	afx_msg void keyPower() { Calculate('p'); }
	afx_msg void keyCube() { Cube(); }
	afx_msg void keySquare() { Square(); }
	afx_msg void keySquareRoot() { SquareRoot(); }
	afx_msg void keyMemory() { MemoryKey(); }
	afx_msg void EraseMemory() { MemoryClear(); }
	afx_msg void keyCE() { Erase(); }
	afx_msg void keyFarenheit() { CelciusToFarenheit(); }
	afx_msg void keyCelcius() { FarenheitToCelcius(); }
	afx_msg void keyMiles() { MilesToKilometers(); }
	afx_msg void keyKilometers() { KilometersToMiles(); }
	afx_msg void Quit() { EndDialog(IDOK); }
    //--------------------------------------------------------
	
	afx_msg void About() 
	{  
	        MessageBox(L"Calculator 3.0 - 2006 - C. Germany", L"Calculator 3.0 - HELP");
	}

    //--------------------------------------------------------
	afx_msg void Help() 
	{ 
             //Illustrates how to use multi-array and convert. Could just use CString.
	         char HELPTEXT[5][55] = { 
				 "This program is a fully functional calculator.\r\n",
			     "It was created as an MFC tutorial for students.\n",
				 "Its purpose is to display the logic processes\n",
				 "and progam flow between the user interface and \n",
				 "processing of input through the MFC CEdit control."
	             };
            char Message[280] = ""; 
	        for(int z = 0; z < 5; z++)
            { strncat_s(Message, HELPTEXT[z], 55); }
			CString TEMP = Message;
	        MessageBox(TEMP, L"Calculator 3.0 - HELP");
	}
	
    //--------------------------------------------------------
    //Calculator Functions

	void Initialize()
	{
         NextExpression = false;
	     NeedToClear = false;
	     ClickedEquals = false;
	     PasteMemory = false;
	     Number1 = 0.0; 
	     Number2 = 0.0; 
	     Result = 0.0;
	     Memory = 0.0;
	     oper = ' ';
	}

    //--------------------------------------------------------
    //In 2008 take in put as a CString and convert it to char array
	void KeyNumber(char digit[1])
	{
	     if(NeedToClear) 
		 { 
			 pInputOutput->SetWindowText(L""); 
			 NeedToClear = false; 
		 }
         pInputOutput->GetWindowText(TEMP);
		 char num[21] = "";
		 for(int x = 0; x < TEMP.GetLength(); x++) 
		 { num[x] = (char) TEMP[x]; }
		 strncat_s(num,digit,20);
		 TEMP = num;
	     pInputOutput->SetWindowText(TEMP);  
	}

    //--------------------------------------------------------
    void Calculate(char op)
    {
         oper = op;
         pInputOutput->GetWindowText(TEMP);
		 char num[21] = "";
		 for(int x = 0; x < TEMP.GetLength(); x++) 
		 { num[x] = (char) TEMP[x]; }
         if(NextExpression)
         {
	        if(!ClickedEquals)
	        {
                 Number2 = atof(num);
                 switch(oper)
                 {
                     case 'a' : Number1 = Number1 + Number2; break;
                     case 's' : Number1 = Number1 - Number2; break;
                     case 'm' : Number1 = Number1 * Number2; break;
					 case 'd' : if(Number2 == 0) { Number1 = 0; }
								else { Number1 = Number1 / Number2; } 
								break;
                     case 'p' : Number1 = pow(Number1,Number2); break;
                     default : break;
                 }
                  
                 char Answer[20];
			  
		         //itoa(Number1, Answer, 10); //Converts int, but truncates decimal
                 //Instead, use sprintf() to convert double or double to string
	             
				 sprintf_s(Answer,"%g",Number1);
				 TEMP = Answer;
                 pInputOutput->SetWindowText(TEMP);
		         NeedToClear = true;
	        }
	     else { ClickedEquals = false; }
       }
       else
       {
	       Number1 = atof(num);
	       NeedToClear = true;
	       NextExpression = true;
       }
    }//close Calculate()

    //--------------------------------------------------------
    void Equals() 
    { 
	     Calculate(oper);
	     NeedToClear = true;
	     ClickedEquals = true;
    }

    //--------------------------------------------------------
    void Erase()
    {  
	     pInputOutput->SetWindowText(L"");
         NextExpression = false;
	     NeedToClear = false;
	     ClickedEquals = false;
	     Number1 = 0.0; 
	     Number2 = 0.0; 
	     Result = 0.0;
	     oper = ' ';
    }

    //--------------------------------------------------------
    void Cube()
    {
         char num[20] = ""; 
	     double numtemp = 0.0;
	     pInputOutput->GetWindowText(TEMP);
         for(int x = 0; x < TEMP.GetLength(); x++) 
		 { num[x] = (char) TEMP[x]; }
	     numtemp = atof(num);
         numtemp = numtemp * numtemp * numtemp;
	     sprintf_s(num,"%g",numtemp);
		 TEMP = num;
	     pInputOutput->SetWindowText(TEMP);
    }

    //--------------------------------------------------------
    void Square()
    {
         char num[20] = ""; 
	     double numtemp = 0.0;
	     pInputOutput->GetWindowText(TEMP);
         for(int x = 0; x < TEMP.GetLength(); x++) 
		 { num[x] = (char) TEMP[x]; }
	     numtemp = atof(num);
         numtemp = numtemp * numtemp;
	     sprintf_s(num,"%g",numtemp);
		 TEMP = num;
	     pInputOutput->SetWindowText(TEMP);
    }

    //--------------------------------------------------------
    void SquareRoot()
    {
	     char num[20] = "";
	     pInputOutput->GetWindowText(TEMP);
		 for(int x = 0; x < TEMP.GetLength(); x++) 
		 { num[x] = (char) TEMP[x]; }
	     Number1 = atof(num);
		 Number1 = sqrt(Number1);
         sprintf_s(num,"%g",Number1);
		 TEMP = num;
	     pInputOutput->SetWindowText(TEMP);
    }

    //--------------------------------------------------------
    void MemoryKey()
    {
         char num[20] = "";
         if(PasteMemory)
	     {
            sprintf_s(num,"%g",Memory);
			TEMP = num;
	        pInputOutput->SetWindowText(TEMP);
	     }
	     else
	     {
            pInputOutput->GetWindowText(TEMP);
            for(int x = 0; x < TEMP.GetLength(); x++) 
		    { num[x] = (char) TEMP[x]; }
            Memory = atof(num);
	        PasteMemory = true;
	     }
    }

    //--------------------------------------------------------
    void MemoryClear() 
	{ 
		 PasteMemory = false; 
		 Memory = 0.0; 
	}

    //--------------------------------------------------------
    void CelciusToFarenheit()
    {
         char num[20];    
         pInputOutput->GetWindowText(TEMP);
         for(int x = 0; x < TEMP.GetLength(); x++) 
		 { num[x] = (char) TEMP[x]; }
	     
		 double Farenheit = atof(num);
	     Farenheit = (Farenheit * 9 / 5) + 32;
         sprintf_s(num,"%g",Farenheit); 
		 TEMP = num;
         pInputOutput->SetWindowText(TEMP);
    }

//-------------------------------------------------------------
    void FarenheitToCelcius()
    {
         char num[20];    
         pInputOutput->GetWindowText(TEMP);
         for(int x = 0; x < TEMP.GetLength(); x++) 
		 { num[x] = (char) TEMP[x]; }
	     double Celcius = atof(num);
	     Celcius = ((Celcius - 32) * 5) / 9;
         sprintf_s(num,"%g",Celcius);   
		 TEMP = num;
         pInputOutput->SetWindowText(TEMP);
    }

//-------------------------------------------------------------
    void KilometersToMiles()
    { 
	     char num[20] = "";
	     pInputOutput->GetWindowText(TEMP);
         for(int x = 0; x < TEMP.GetLength(); x++) 
		 { num[x] = (char) TEMP[x]; }
	     double x = atof(num);
	     x = x / 1.609347;
	     sprintf_s(num,"%g",x);
		 TEMP = num;
	     pInputOutput->SetWindowText(TEMP);
    }

//-------------------------------------------------------------
    void MilesToKilometers()
    { 
	     char num[20] = "";
	     pInputOutput->GetWindowText(TEMP);
         for(int x = 0; x < TEMP.GetLength(); x++) 
		 { num[x] = (char) TEMP[x]; }
		 double x = atof(num);
	     x = x * 1.609347; 
	     sprintf_s(num,"%g",x);
		 TEMP = num;
	     pInputOutput->SetWindowText(TEMP);
    }

//-------------------------------------------------------------
DECLARE_MESSAGE_MAP()
}; //closing class specification

//---------------------------------------------------------------------------------------------------------------------------

BEGIN_MESSAGE_MAP(Calculator, CDialog)
      //Listen for and map COLOR events   
      ON_WM_CTLCOLOR() 
      ON_COMMAND(IDC_Num0, key0)
      ON_COMMAND(IDC_Num1, key1)
      ON_COMMAND(IDC_Num2, key2)
      ON_COMMAND(IDC_Num3, key3)
      ON_COMMAND(IDC_Num4, key4)
      ON_COMMAND(IDC_Num5, key5)
      ON_COMMAND(IDC_Num6, key6)
      ON_COMMAND(IDC_Num7, key7)
      ON_COMMAND(IDC_Num8, key8)
      ON_COMMAND(IDC_Num9, key9)
      ON_COMMAND(IDC_Num7, key7)
      ON_COMMAND(IDC_Num8, key8)
      ON_COMMAND(IDC_Num9, key9)
      ON_COMMAND(IDC_NumPeriod, keyPeriod)
      ON_COMMAND(IDC_NumEquals, keyEquals)
      ON_COMMAND(IDC_NumAdd, keyAdd)
      ON_COMMAND(IDC_NumSubtract, keySubtract)
      ON_COMMAND(IDC_NumMultiply, keyMultiply)
      ON_COMMAND(IDC_NumDivide, keyDivide)
      ON_COMMAND(IDC_NumCube, keyCube)
      ON_COMMAND(IDC_NumSquare, keySquare)
      ON_COMMAND(IDC_NumSquareRoot, keySquareRoot)
      ON_COMMAND(IDC_POWER,keyPower)
      ON_COMMAND(IDC_NumMemory, keyMemory)
      ON_COMMAND(IDC_MemoryErase, EraseMemory)
      ON_COMMAND(IDC_NumCE, keyCE)
      ON_COMMAND(IDC_Farenheit, keyFarenheit)
      ON_COMMAND(IDC_Celcius, keyCelcius)
      ON_COMMAND(IDC_Miles, keyMiles)
      ON_COMMAND(IDC_Kilometers, keyKilometers)
      ON_COMMAND(IDC_QUIT, Quit)
      ON_COMMAND(ID_FILE_EXIT,Quit)
      ON_COMMAND(ID_OTHER_HELP,Help)
      ON_COMMAND(ID_OTHER_ABOUT,About)
END_MESSAGE_MAP()

//---------------------------------------------------------------------------------------------------------------------------

class Calc : public CWinApp
{
public:
Calc() {  }
virtual BOOL InitInstance()
{
        CWinApp::InitInstance();
        Calculator x;
        m_pMainWnd = &x;
        INT_PTR nResponse = x.DoModal();
        return FALSE;
} //close function     
};

//---------------------------------------------------------------------------------------------------------------------------

Calc SuperFun;




/*
sprintf() builds and formats a string from a number you pass into it. Arguments are:
-------------------------------------------------------------------------------------------------
c = Character a 
d  = or i Signed decimal integer 392 
e = Scientific notation (mantise/exponent) using e character 3.9265e+2 
E = Scientific notation (mantise/exponent) using E character 3.9265E+2 
f = Decimal floating point 392.65 
g = Use the shorter of %e or %f 392.65 
G = Use the shorter of %E or %f 392.65 
o = Signed octal 610 
s = String of characters sample 
u = Unsigned decimal integer 7235 
x = Unsigned hexadecimal integer 7fa 
X = Unsigned hexadecimal integer (capital letters) 7FA 
p = Pointer address B800:0000 
n = Nothing printed. The argument must be a pointer to a signed int, 
   where the number of characters written so far is stored.  
% = A % followed by another % character will write % to the string. 
EXAMPLE:
  char buffer [50];
  int n, a=5, b=3;
  n=sprintf (buffer, "%d plus %d is %d", a, b, a+b);
  printf ("[%s] is a %d char long string\n",buffer,n);
--------------------------------------------------------------------------------------------
Mouse and Keyboard Message Macros and Their Handlers:
      //ON_WM_LBUTTONDOWN( )    //Listen for LEFT mouse button click
	  //ON_WM_KEYDOWN()         //Keyboard Events
	  //ON_WM_KEYUP()           //Keyboard Events
      //ON_WM_CHAR()            //Keyboard Events
   afx_msg void OnKeyDown(UINT uChar, UINT uRepCnt, UINT uFlg)
   {
           //char x[1];
		   //x[0] = (char)uChar;
		   //MessageBox(x);
           MessageBox("MADE IT to OnChar()!");
   
           switch(uChar) 
           {
                 case '\r': Equals(); break;
                 case '\b': Erase(); break;
				 case '+' : Calculate('a'); break;
                 case '-': Calculate('s'); break;
                 case '*': Calculate('m'); break;
				 case '/' : Calculate('d'); break;
                 case '=' : Equals(); break;
				 case 'a' : MessageBox("Heard an A!"); break;
				 default : break;
		   }
   }
   afx_msg void buttonPushed()
   {
           MessageBox("MADE IT HERE in buttonPushed()!");
   }
   afx_msg void OnLButtonDown( UINT, CPoint )
   {
	       MessageBox("Mouse Clicked!", "Event Triggered");
   }
ASCII Values for PreTranslate Messages
//-----------------------------------------------------
Decimal      Character     Description 
0               NUL  
1               SOH         start of header 
2               STX         start of text 
3               ETX         end of text 
4               EOT         end of transmission 
5               ENQ         enquiry 
6               ACK         acknowledge 
7               BEL         bell 
8               BS          backspace 
9               HT          horizontal tab 
10              LF          line feed 
11              VT          vertical tab 
12              FF          form feed 
13              CR          carriage return 
14              SO          shift out 
15              SI          shift in 
16              DLE         data link escape 
17              DC1         no assignment, but usually XON 
18              DC2  
19              DC3         no assignment, but usually XOFF 
20              DC4  
21              NAK         negative acknowledge 
22              SYN         synchronous idle 
23              ETB         end of transmission block 
24              CAN         cancel 
25              EM          end of medium 
26              SUB         substitute 
27              ESC         escape 
28              FS          file seperator 
29              GS          group seperator 
30              RS          record seperator 
31              US          unit seperator 
32              SPC         space 
33  !  
34  "  
35  #  
36  $  
37  %  
38  &  
39  '  
40  (  
41  )  
42  *  
43  +  
44  ,  
45  -  
46  .  
47  /  
48  0  
49  1  
50  2  
51  3  
52  4  
53  5  
54  6  
55  7  
56  8  
57  9  
58  :  
59  ;  
60  <  
61  =  
62  >  
63  ?  
64  @  
65  A  
66  B  
67  C  
68  D  
69  E  
70  F  
71  G  
72  H  
73  I  
74  J  
75  K  
76  L  
77  M  
78  N  
79  O  
80  P  
81  Q  
82  R  
83  S  
84  T  
85  U  
86  V  
87  W  
88  X  
89  Y  
90  Z  
91  [  
92  \  
93  ]  
94  ^  
95  _  
96  `  
97   a  
98   b  
99   c  
100  d  
101  e  
102  f  
103  g  
104  h  
105  i  
106  j  
107  k  
108  l  
109  m  
110  n  
111  o  
112  p  
113  q  
114  r  
115  s  
116  t  
117  u  
118  v  
119  w  
120  x  
121  y  
122  z  
123  {  
124  |  
125  }  
126  ~  
127  DEL delete 
//-----------------------------------------------------------------------------
*/

//---------------------------------------------------------------------------------------------------------------------------


















