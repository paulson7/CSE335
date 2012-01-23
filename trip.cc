using namespace std;

#include <iostream>
#include <stdlib.h>
#include <string>

#include "trip.h"

//Trip constructor
Trip::Trip()
{
  cout << "***In Trip Constructor***" << endl;
  
  From = "";
  To = "";
  Date[0] = 0;
  Date[1] = 0;
  Date[2] = 0;
}

//Trip destructor
Trip::~Trip()
{
  cout << "***In Trip Destructor***" << endl;
  
  From = "";
  To = "";
  Date[0] = 0;
  Date[1] = 0;
  Date[2] = 0;
}

//copy constructor
Trip::Trip( const Trip& existing )
{
  cout << "***In Trip Copy Constructor***" << endl;
  
  From = existing.From;
  To = existing.To;
  Date[0] = existing.Date[0];
  Date[1] = existing.Date[1];
  Date[2] = existing.Date[2];
}

//assignment operator
Trip& Trip::operator=( const Trip& existing )
{
  cout << "***In Trip Assignment Operator***" << endl;
  
  From = existing.From;
  To = existing.To;
  Date[0] = existing.Date[0];
  Date[1] = existing.Date[1];
  Date[2] = existing.Date[2];
  
  return *this;
}

//print that can be used for I & D
void Trip::print() const
{
  cout << "Flight From: " << From;
  cout << " To: " << To;
  cout << " Date: " << Date[0] << "/" << Date[1] << "/" << Date[2];
  
}

//virtual report
void Trip::report() const { cout<<"xxx"<<endl;}






