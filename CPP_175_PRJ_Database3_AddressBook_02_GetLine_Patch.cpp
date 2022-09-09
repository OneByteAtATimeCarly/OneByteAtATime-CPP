//AddressBook 2 - GetLine file patch - 2004 C. S. Germany

//---------------------------------------------------------------------------------------------------------------------------

// File Name:	GetLinePatch.h
// Description:	Patch code for Visual C++ 5-6 getline(cin, string);
// Revision: 	B
// Created: 	January 10, 1998
// Author:		Garth B. Santor
// Mail: 		gsantor@email.com
//
// Language:	Visual C++ 6.0 (ANSI/Win32)
//
// Copyright Garth B. Santor
//
// The copyright to the computer program(s) herein
// is the property of Garth B. Santor, Canada.
// The program(s) may be used and/or copied only with
// the written permission of Garth B. Santor
// or in accordance with the terms and conditions
// stipulated in the agreement/contract under which
// the program(s) have been supplied.
#ifndef __GETLINEPATCH_H__
#define __GETLINEPATCH_H__
// STL string::getline patch
#ifdef _STRING_
#if _MSC_VER >= 1100
namespace gbs 
{
//==================================================================
	template<class E, class T, class A>    
	std::basic_istream<E, T>& getline( std::basic_istream <E, T>& is, 
        std::basic_string<E, T, A>& str )


	// PURPOSE:	Extracts elements from the stream 'is' and stores them 
        //in string 'str'.  Extraction stops
	//on end-of-file or on an elements that compares 
        // equally to '\n' which is extracted.
	// REQUIRE:	INITIAL( is.good() )
	// PROMISE:	Terminating character is removed from the stream 'is'.
	// PROMISE: RESULT = reference to 'is'
	// PROMISE: 'str' will not contain previous values.
	{
		str.erase();
		for(;;)
		{
			T::int_type ch = is.get();
			if( ch == is.widen('\n') || ch == T::eof() )
				break;
			str += T::to_char_type( ch );
		}
		return is;
	}
	
//==================================================================
} // End: namespace gbs

#define FIXGETLINE using gbs::getline
#endif
#else
#pragma message("Warning: string header not included before GetlinePatch.h")
#endif

// nullified patch MACROS
#ifndef FIXGETLINE
#define FIXGETLINE
#endif
	
#endif // __GETLINEPATCH_H__

//---------------------------------------------------------------------------------------------------------------------------





