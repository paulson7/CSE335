
/******************************************************************************
  MiniProject 1 -- driver file for MiniProject 1
******************************************************************************/

/*******************************************************************************
  This is the driver module for Project 10. It consists of the function "main"
  and any auxiliary functions that directly support it. This driver module is
  the main component of a program that utilizes a collection of simple travel
  classes about trips taken for a company. The trips data is stored in a
  simple text file with each line representing a trip. Domestic trips are 
  denoted with a "D" preceding a line in a text file and include the desti-
  nation state and the travel time in minutes at the end of the line. Inter-
  national trips are denoted with an "I" preceding a line in a text file and in-
  clude the destination country in lieu of the state and time at the end of the 
  line. Other data included on each line includes the origin and destination
  aiports and the date of the flight. Formatting for the given variables is as
  follows:
   
   * Airport Names (both FROM and TO): 3-letter strings (e.g. DTW, LAN, FNT, LHR)
   * DATE format: M/D/Y where M and D are 2-digit strings and Y is a 4-digit string
	(although the handout says 2-digits, the examples show 4 digits
	and it was deemed acceptable by a TA (e.g. 01/01/2011); also, although the
	handout text refers to the M,D, and Y variables as strings, they are being
	treated as integers and as such the leading zeros that are present in the 
	input will not likely be present in the output (as shown in the handout)
	despite what may have been noted in class
   * STATE Name: 2-letter strings based on the postal system (e.g. MI for Michigan)
   * FLIGHTTIME: a positive integer representing the number of minutes
   
  The items in a line are space-delimited and are in the following format
  examples (for domestic and international, respectively):
  
  D LAN STL 04/01/2010 MO 302
  I DTW LHR 12/31/2011 GBR
  
  or in a generic sense
  
  D <From> <To> <Date> <State> <FlightTime>
  or
  I <From> <To> <Date> <Country>
   
  It is assumed that the data files to be processed by the program have the
  correct format. As such, there is no need to validate the format of items 
  within a data file (and only other very simple error checking procedures
  have been included as this has been verified to be acceptable according
  to a course teaching assistant). There can be any amount of whitespace 
  between tokens.
 
  The program is compiled from this main.cc file, trip.h and trip.cc files,
  DomesticTrip.h and DomesticTrip.cc files, and InternationalTrip.h and
  TnternationalTrip.cc files using the makefile located at:
  
  "http://www.cse.msu.edu/~alexliu/courses/335Spring2012/lectures/makefile"
  
  The program is operated via a single command-line reference to the text 
  file to be processed, for example:
  
  <prompt> a.out < sample_text_file
  
  Execution of the file involves the following:
  
  A. Reading the text file referenced from the command line and assign the data
     into appropriate vectors (specifically store FROM and TO and DATE)
  B. Sort the vector data by date
  C. Output a report in the following format (in the defined date-sorted order)
     entirely on stdout by calling the report() virtual function (in the DomesticTrip
     and InternationalTrip classes) which calls the print() member function in
     the Trip class (and which prints only the FROM, TO, and DATE elements) 
  
  The output appears as follows:
  
  "Domestic Flight From:LAN To:STL Date:4/1/2010 State:MO Flight Time:302"
  "International Flight From:FNT To:LGW Date:8/14/2011 Country:GBR"
  
******************************************************************************/  
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "trip.h"
#include "domesticTrip.h"
#include "internationalTrip.h"

struct date_compare
{
  inline bool operator() (const Trip* t, const Trip* u)
  {
    //comparison function returns true if t's date is before u's date
    //t and u are pointers to trips so you need to change the code below
    if( t->Date[2] < u->Date[2] ) return true;
    else if ( t->Date[2] == u->Date[2] && 
              t->Date[0] <  u->Date[0] ) return true;
    else if ( t->Date[2] == u->Date[2] && 
              t->Date[0] == u->Date[0] && 
              t->Date[1] <  u->Date[1] ) return true;
    else return false;
  }
};

int main()
{
    // declarations
     
	vector<Trip*> Master; 		// master list of trips
	vector<Trip>::iterator It; 	// iterator (needed?)
	string X; 			// placeholder for reading I or D for flight type
	string Origin; 			// placeholder for reading 'from' airport
	string Dest; 			// placeholder for reading 'to' airport
	int Month; 			// placeholder for reading flight 'month'
	int Day; 			// placeholder for reading flight 'day'
	int Year; 			// placeholder for reading flight 'year'
	string St;			// placeholder for reading 'state' of destination
	string Ct;			// placeholder for reading 'country' of destination
	int Dist;			// placeholder for reading 'distance' of flight
	string JUNK;			// to remove unwanted characters from input stream

	unsigned count = 0;		// (for future implementation)
	bool errorbit = 0;		// (for possible error checking)
      
	
    while (!cin.eof()) // possible to do a 'for(;;)' with a 'break if' statement
    {
        cout << endl << endl;
	cout << "*** Processing input file. ***";
	cout << endl << endl;
	
        // read line 1 into placeholders, create vector(s), repeat for additional lines until eof
	cin >> X;		
	cin >> Origin; 		
	cin >> Dest; 		
	cin >> Month; 		
	JUNK = getchar();	
	cin >> Day; 		
	JUNK = getchar();	
	cin >> Year;		
	
	/*cout << X << " ";
	cout << Origin << " ";
	cout << Dest << " ";
	cout << Month << " ";
	cout << JUNK << " ";
	cout << Day << " ";
	cout << JUNK << " ";
	cout << Year << " ";*/
	
	if(cin.eof()) break;
	
	if (X == "D")
	{
		cin >> St;	
		cin >> Dist; 	
		/*cout << "St:" << St << " ";
		cout << Dist;*/
		
		// (then write to vector once eof is encountered)
		
		cout << endl << endl << "Domestic flight data successfully created!" << endl;
		
		count++;
	}
	else if (X == "I")
   	{
		cin >> Ct;	cout << Ct;
		//getline(cin, JUNK); // this should remove the '/n' and get to the next line
		// (then write to vector once eof is encountered
		
		cout << endl << endl << "Internationl flight data successfully created!" << endl;
		
		count++;
	}
	else
	{
		cerr << endl << endl << "*** Improper flight designation! Data ignored. ***";
		errorbit = 1;
		getline(cin, JUNK); // this should remove the '/n' and get to the next line
	}
    }
    
};
    // (how to deal with InternationalTrip and DomesticTrip? do these live 'inside'
    // the Trip vector or does the Trip vector reference them for the additional
    // information, and if so, what is the indexing method)


    // insert date evaluation and vector re-ordering code


    // call print() (which subsequently calls report() to fill in pertinent information)
//    {

//    }








/* ERROR CHECKING TYPE READ-IN CODE
		for (;;)
		{
			cin >> CHAR;
			if (cin.eof() || (CHAR != '(' && CHAR != ',' 
					&& CHAR!= ')' && CHAR != ' ' && CHAR != '\n' && CHAR != '\t')) 
			{
				for(;;)
				{
					cin >> JUNK;
					if( JUNK == '\n')
					{
						break;
					}
				}
				break;
		  	}	
			else if (CHAR == '(' || CHAR == ',')
			{
				cin >> INT[COUNT];
				COUNT++;
			}
			else if (CHAR == ')')
			{
				SETINDEX++;
				break;
			}
		}			
			for(int I=0; I<COUNT; I++)
			{
				Test6.insert(INT[I]);	
			}
*/


/* CHRONOLOGICAL DISPLAY CODE

void MasterPrint( vector<Trip>& );

void MasterPrint( vector<Trip>& ReadIn )
{
	cout << endl << " # |   Date   | Name" << endl
	       <<       "---------------------------------------------------"
       		<< endl;
	One.sort(less_date);
	for_each( ReadIn.begin(), ReadIn.end(), print );
	cout << endl << "Done!" << endl;
	return;	 
}
*/
