//2006 C. Germany - Network Planner GUI App
//File: 1 of 25

//---------------------------------------------------------------------------------------------------------------------------

This project will create a graphical planning tool useful for flow-charting programs and planning networks.  This project, due to its complexity, will be done in 4 separate phases, each to be covered by a separate tutorial.  This is phase I.  In this phase we will only get the bare graphic elements working and develop our class hierarchy. 

Instructions:

  1. Launch your Visual C++ compiler.
  2. Select  File->New  and then select "MFC Application Wizard" from the list of available options.
  3. In the Project Name box, type "NetProgPlanner10", then click "OK".
  4. On the next screen, select "Multiple Documents", leave the "Document/View Architecture Support" option checked, click "Next".
  5. For database support, click "None" and select "Next".
  6. For "Compound Document Support" select "None", and leave "Active X Controls" checked.  Click "Next".
  7. You will be on the "Features" screen.  Keep the defaults.  Click "Advanced", set the file extension type to "npp". Click "Next".
  8. On the next screen leave the defaults selected, "MFC Standard" and "Yes Please" for comments.  Click "Next".
  9. Click "Finish" and "Ok".  The project skeleton will be built for you.
10. We now need to add a header file for our constants.  Click File->New->"C++/C Header File" and call it "NPConstants.h".
      This will be where we place identifiers for our shapes and colors.
11. Now add another header file and call it "NPelements.h", using the same procedure you did above.  This file will hold our base class
     specification and its derived classes.
12. Finally, click File->New-> "C++ Source File" and type "NPelements.cpp" for the name, clicking "OK".  This file will be used for
      holding the class definitions.

Theory:

In thinking about how we are going to design this project, it makes sense to make use of polymorphism and use a common base class.  All of the graphical shapes and objects we will use for flow-charting: circles, squares, rectangles, lines, polygons and arcs are composed of simpler elements.  Shapes are composed of lines, and lines are composed of points, and points themselves consist of a pair of x/y coordinates.  In this sense, it makes sense to make our base class something akin to an ADT consisting of data members that will provide the scaffolding for all derived shape objects.  Then, we can dynamically call the right method on a derived class object through a pointer to the base class object.  This base class will be "like" an ADT, but it can't actually be an ADT, because a class can not contain any pure virtual methods when we are deriving it from CView and CDocument.  This allows Serialization to function properly, and this topic will be covered in a later phase.

After running the wizard and adding the extra header and source file, your project should look like this:



When the MFC App Wizard generates an application, it creates two objects with corresponding files:  the "Document" and the "View".  The Document holds the structure of a wizard-generated program.  It is where we need to place every data member and method that must persist,
be saved, serialized, and passed to the View.  The View is where we draw objects and implement OnPaint() and Update().  Here we need to
place code related to the display of objects. 

Frame window classes and the View can contain message handlers, message maps and process messages because they derive from CWnd, so
we will deal primarily with these.  The Application classes, and Document template classes do not derive form CWnd, so they
can not process messages.  We can add code to process messages to the Document object, however.  Therefore, do not place message maps, identifiers or handlers in these classes.  The Class Wizard helps you remember where to place your message handlers by not allowing you to place them in inappropriate classes. 

To gain some experience with Class Wizard, let's add items to the menu and use Class Wizard to add the message handlers.

Adding Menu Items: 

1. Click the "Resource View" tab.  Select "Menu" from under resources and "IDR_NetProgPlannerTYPE".
2. Click the blank menu box outlined in dotted lines.
3. Type &Element for the caption.  The ampersand specifies the shortcut key (alt + whatever comes after the ampersand).  There is
    no need type in a message ID, as the first root menu item in pop-up menu only serves to display the other menu items.
4. Click the "x" to close the dialog or hit "Enter".  Now repeat the same process, including adding the ampersands, for the following
    elements:  Line, Rectangle, Ellipse, Curve.  When you hit "Enter", a default message ID will be entered.  Accept this default ID.
5. Now, click the next blank menu box, call the root menu "Color", and add the following menu items:  Black, Blue, Green, and Red.
    In this way a message identifier will be generated for each menu item that you add.

Adding Message Handlers:

1. Click View->Class Wizard.  With the Document class selected, "NetProgPlannerDoc", scroll down until you find the object IDs for the
    menu items you just added.
2. Highlight them each, one at a time, under "object ids", then select "COMMAND" under the "Messages" section and double click
    "COMMAND" for each object ID that corresponds to each menu item you added.  Follow each time with "OK".  The Class Wizard will
    add an empty message handler function for each menu item and also add its identifier and handler to the message map.  You can
    begin to see how Class Wizard can be a real time saver when you know where you are going and what you want to do.
3. You will want to repeat this whole process again but select "UPDATE_COMMAND_UI" instead of "COMMAND" this time.  This is
    where we will add the code for updating the menu views so that items appear checked or unchecked when the view is updated.

Adding Code to Class Wizard Content:

1. Add the class hierarchy - that is the base class and its derived classes and their data members and methods to the NPelements
   source file ".cpp" and header file ".h", splitting the class specifications and declarations from the method definitions respectively
   between the files.  Use the code below, which is self explanatory.
2. Add the message handler code for "COMMAND" and "UPDATE_COMMAND_UI" operations.  It also is listed below.

Add Items to the Toolbar:

1. Select the "Resource View" tab.  Select "IDR_MAINFRAME" double click it to start the visual editor.
2. Select the blank gray square and dray it a little to the right.  This will start a new toolbar group.
3. Now add toolbar buttons for each shape element: Line, Rectangle, Ellipse and Curve.
4. Create another button group by dragging the blank button to the right again.
5. Now add toolbar buttons for each Color: Black, Blue, Green and Red.
6. Now double click on each  toolbar item you added to add an identifier.
7. Since these buttons simply do the same thing as our menu items, select the corresponding menu identifier for each one of the
    toolbar items you added.  In this way, both the menu selections and the toolbar selections will call the same message handlers.
8. You may now add "tooltips" for each toolbar item by double-clicking each toolbar item and filling out the "caption" section.  If you
    place a "\n" in the caption, the text after the "\n" will appear in the status bar rather than the pop-up text.

Add Mouse Behavior Code:

1. Select the View object, "NetProgPlannerView", and launch the Class Wizard as you did previously.
2. Select the "OnDraw" method from the View object.  Click on the down arrow of the Class Wizard shortcut and select "Add Windows
    Message Handler".  You will see a dialog, "New Windows Message and Event Handlers for class NetProgPlannerView".
2. With the VIew selected under "Object IDs", select the default messages "WM_LBUTTONDOWN", "WM_MOUSEMOVE", and
    "WM_LBUTTONUP", double clicking on each one to add empty message handlers.
3. Now add the code listed below to each empty message handler.

Break It Down: 

1. For three of the objects, Line, Rectangle and Ellipse, the code is pretty straightforward.  Each of these can be determined by
    a bounding rectangle and a diagonal line or radius.
2. The mouse behavior code has been added to each message handler based on what we want to happen when the user moves the
    mouse with the left mouse button held down or when the user releases the left mouse button.
3. The last element, a Curve, is not as simple as the previous three elements.  It can not be determined by a mere bounding
    rectangle and a diagonal line or a radius.  Instead, it consists of an unpredictable number of points, which themselves are x/y
    coordinates, and it uses the Arc() method to draw curves which are merely fractional pieces of ellipses between these points.
    Because of the nature of this last element, we have to create a collection to hold our list of points.  To do this, you need to add
    include# "afxtempl.h" to the "StdAfx.h" header file.  This will provide the code necessary to utilize Arrays, Lists and Maps - MFC
    collection classes.
4. In order to add text, we add entries to the toolbar and menus, message IDs and handlers, and use CEdit controls and GetDlgItem()
    to return a pointer to the CEdit control and TextOut() to display its string. 

Adding Dialogs and PopUp Menus:

For the dialogs for penwidth, scale and adding text, we add appropriate header (.h) and source ) (.cpp) files.  We then go into resource editor.  Here we right-click the Dialog folder and select "Insert Dialog" to create the pop-up forms.  We add the radio buttons, list boxes and text boxes to the forms, using class wizard to add the message IDs and message handlers.  We then code the behavior.  To create instances of the dialog objects, we can right-click on their title bars.

To add the pop-up menus, depending on whether or not and element is selected, we go to resource view and right-click the "Menu" folder and select "Insert Menu".  After adding the menu items, we use class wizard to add message IDs and message handlers, code the body of those handlers, and right-click on the menu title bars and select class wizard to add instances of the menus to the project.

Serialization:

In order to be able to save drawings and diagrams, we need to add code for serialization.  Serialization with MFC objects works almost exactly like writing an object to a binary file.  Remember from our MFC addressbook, games, and console database projects that when writing to a binary file, an entire object with all of its data members or an array of objects with all of their data members can be written to a file through static casting to a pointer to a character.  In order for serialization to work, we need a common base class.  We have one in this case, the Element class.  It derives from CObject, and all other shapes and lines derive from it. 

The Serialize() function utilizes a function, "IsStoring()", that will return true if data is being output to a file and false if not.  In this way, it can be put into a decision structure.  The MFC Serialize() function overloads the stream operator, so that writing an object to a file uses the outstream << operator and reading an object from a file involves the ifstream operator.  We can use this with the data members of our Document and base class objects like so:

Serializing the Document object:

void CNetProgPlannerDoc::Serialize(CArchive& ar)
{
   NPelementList.Serialize(ar);    // Serialize the element list
   if (ar.IsStoring())
   {
      ar << NPcolor                // Store the current color
         << NPelement              // the current element type,
         << NPpenwidth             // and the current pen width
         << NPdocsize;             // and the current document size
   }
   else
   {
      ar >> NPcolor                // Retrieve the current color
         >> NPelement              // the current element type,
         >> NPpenwidth             // and the current pen width
         >> NPdocsize;             // and the current document size
   }
}
Serializing the base class object:

void Element::Serialize(CArchive& ar)
{
   CObject::Serialize(ar);         // Call the base class function
   if (ar.IsStoring())
   {
      ar << NPcolor                // Store the color,
         << m_EnclosingRect        // and the enclosing rectangle,
         << m_Pen;                 // and the pen width
   }
   else
   {
      ar >> NPcolor                // Retrieve the color,
         >> m_EnclosingRect        // and the enclosing rectangle,
         >> m_Pen;                 // and the pen width
   }
}
We also need to add the Serialize() macro functions to our appropriate files.  These macro functions are DECLARE_DYNCREATE  and IMPLEMENT_DYNCREATE.  The arguments passed to the macro are the name of the document class and what it derives from, so in this case it would be NetProgPlanner and CDocument.  Example: IMPLEMENT_DYNCREATE(NetProgPlanner, CDocument).  The macro DECLARE_SERIAL() adds support for the serialization of objects.  The IMPLEMENT_SERIAL macro would be added to the implementation of any class that we want to serialize.  In this instance, is would be the base class of Element.  If we can serialize this class, since all the other shapes derive from it, and it itself derives from CObject, then we can use a pointer to the base class to serialize the data members of all of its derived class objects.  The macro takes three arguments: the object to serialize, its base class, and a version number.  In our case, the object would be Element, its base class would be CObject, and and its version would be "1", since this version of NetProgPlanner is only 1.0, our first draft. 

Example: IMPLEMENT_DYNCREATE(Element, CObject, 1)

Let's look at the Steps Necessary to Serialize an Object:

1. The class needs to derive at some point from CObject.
2. Add the DECLARE_SERIAL() macro to the class definition and its base class if it is not CObject.
3. Declare the Serialize() function as as a member function of your class.
4. Add the IMPLEMENT_SERIAL() macro to the file containing the class implementation.
5. Implement the Serialize() function for your class - add the code using the overloaded stream operators.
Now, where we implement serialization and its corresponding macros depends on the behavior we are trying to solicit from the user.  This has to do with the structure of our base class and derived class objects and the interface being used to interact with these objects. Whenever there is a change in the document - an Element is added, moved, or deleted, we want to be able to save and reconstruct it from within our collection.  In the case of NetProgPlanner, the occasions where we will alter objects are:

1. When we invoke AddElement() to create a new element and add it to the collection.
2. When we call DeleteElement() to delete an existing element and remove it from the collection. 
3. When we move an element to a different location.
 

Scaling and a Status Bar:

For scaling, we need to use MM_TEXT and the SetScrollsizes() method to allow scaling and resizing.  This is implemented in the View.  A status bar is added with the method SetPaneText() method using the m_wndStatusBar data member of the CMainFrame object.  We utilize the WM_CREATE message and the OnCreate() message handler to add methods to create and manipulate the statusbar.  We want to do this outside of the OnDraw() and Paint() methods to avoid unnecessary flicker. 

Printing:

In order to print, we need to calculate the largest bounding rectangle enclosing all of the elements in the object.  We are limited by paper size, let's assume that we will only use 8.5 x ll inch paper.  In this case, since we are using MM_LOENGLISH to make things scalable but then converting to MM_ANISOTROPIC, our objects have an actual physical measurement in hundreths of an inch.  With a document size of 3000, we can create documents up to 30 inches square.  Rather than worrying about paper size, we can chop each image into 6 inch by 9 inch pieces.  So we will convert the document view to pieces 600 by 900 units.  Now that we know what we want to do, how do we implement it? 

1. First we need to get the largest bounding rectangle necessary to enclose all of the elements:

CRect CNetProgPlannerDoc::GetDocExtent() const
{
   CRect DocExtent(0,0,1,1);    // Initial document extent
   CRect ElementBound(0,0,0,0); // Space for element bounding rectangle
   POSITION aPosition = NPelementList.GetHeadPosition();
   while(aPosition)      // Loop through all the elements in the list
   {
      // Get the bounding rectangle for the element
      ElementBound=(NPelementList.GetNext(aPosition))->GetBoundRect();
      // Make coordinates of document extent the outer limits
      DocExtent.UnionRect(DocExtent, ElementBound);
   }
   DocExtent.NormalizeRect();
   return DocExtent;
}
 

The UnionRect() function returns a bounding rectangle just large enough to contain both of its arguments.

2. We need to store information about our print job before we begin the print process.  To create a class for that:

class CPrintData
{
   public:
      UINT m_nWidths;                // No. of pages for the width of the document.
      UINT m_nLengths;               // No. of pages for the length of the document.
      CPoint m_DocRefPoint;        // Top left corner of the document contents.
      CString m_DocTitle;            // The name of the document.
};
3. Next we code the OnPreparePrinting() function to take care of preprocessing and the OnEndPrinting() function to delete the pointer.   We then use the IsPrinting() method in OnPrepareDC()  to determine if we are printing and further prepare the device context. 

4. Next we add the OnPrint() method to NetProgPlannerView using the class wizard.  The code for OnPrint() is:

void CNetProgPlannerView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
   CPrintData * pPrintData = static_cast<CPrintData*>(pInfo->m_lpUserData);
   // Output the document file name
   pDC->SetTextAlign(TA_CENTER);           // Center the following text
   pDC->TextOut(pInfo->m_rectDraw.right/2, -20,
                        pPrintData->m_DocTitle);
   CString PageNum;
   PageNum.Format("Page %d", pInfo->m_nCurPage);
   pDC->TextOut(pInfo->m_rectDraw.right/2, -1050, PageNum);
   pDC->SetTextAlign(TA_LEFT);             // Left justify text
   // Calculate the origin point for the current page
   int xOrg = pPrintData->m_DocRefPoint.x +
                  600 * ((pInfo->m_nCurPage - 1)%
                      (pPrintData->m_nWidths));
   int yOrg = pPrintData->m_DocRefPoint.y -
                  900 * ((pInfo->m_nCurPage - 1)/
                      (pPrintData->m_nWidths));
   // Calculate offsets to center drawing area on page as positive values
   int xOffset = (pInfo->m_rectDraw.right - 600) / 2;
   int yOffset = -(pInfo->m_rectDraw.bottom + 900) / 2;
   // Change window origin to correspond to current page & save old origin
   CPoint OldOrg = pDC->SetWindowOrg(xOrg - xOffset, yOrg + yOffset);
   // Define a clip rectangle the size of the printed area
   pDC->IntersectClipRect(xOrg, yOrg, xOrg + 600, yOrg - 900);
   OnDraw(pDC);                            // Draw the whole document
   pDC->SelectClipRgn(NULL);               // Remove the clip rectangle
   pDC->SetWindowOrg(OldOrg);              // Restore old window origin
}

//---------------------------------------------------------------------------------------------------------------------------

