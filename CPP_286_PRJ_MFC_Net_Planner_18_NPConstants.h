//2006 C. Germany - Network Planner GUI App
//File: 18 of 25

//---------------------------------------------------------------------------------------------------------------------------

/Definitions of constants
#ifndef NPconstants_h
#define NPconstants_h
   // Element type definitions
   // Each type value must be unique
   const WORD LINE = 101U;
   const WORD RECTANGLE = 102U;
   const WORD CIRCLE = 103U;
   const WORD CURVE = 104U;
   const WORD TEXT = 105U;
   ///////////////////////////////////
   // Color values for drawing
   const COLORREF GRAY = RGB(161,161,161);
   const COLORREF BLACK = RGB(0,0,0);
   const COLORREF RED = RGB(255,0,0);
   const COLORREF GREEN = RGB(0,255,0);
   const COLORREF BLUE = RGB(0,0,255);
   const COLORREF YELLOW = RGB(255,255,0);
   const COLORREF AQUA = RGB(0,255,255);
   const COLORREF FUSCHIA = RGB(255,0,255);



   const COLORREF SELECT_COLOR = RGB(255,0,180);
   ///////////////////////////////////
   // Program version number for use in serialization
   const UINT VERSION_NUMBER = 1;
#endif //!defined(NPconstants.h)

//---------------------------------------------------------------------------------------------------------------------------

