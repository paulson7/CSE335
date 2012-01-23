#include <iostream>
#include <string>

using namespace std;

#include "domesticTrip.h"

//DomesticTrip constructor
DomesticTrip::DomesticTrip()
{
  cout << "***In DomesticTrip Constructor***" << endl;

  From = rt.From;
  To = rt.To;
  Date[0] = rt.Date[0];
  Date[1] = rt.Date[1];
  Date[2] = rt.Date[2];

  State = "";
  FTime = 0;
}

////create a DomesticTrip from an existing Trip
DomesticTrip::DomesticTrip( Trip& t ) : rt(t)
{
  cout << "***In Trip to DomesticTrip Constructor***" << endl;
  
  From = t.From;
  To = t.To;
  Date[0] = t.Date[0];
  Date[1] = t.Date[1];
  Date[2] = t.Date[2];
  
  State = "";
  FTime = 0;
}

//DomesticTrip destructor
DomesticTrip::~DomesticTrip()
{
  cout << "***In DomesticTrip Destructor***" << endl;

  From = "";
  To = "";
  Date[0] = 0;
  Date[1] = 0;
  Date[2] = 0;
  State = "";
  FTime = 0;
}

//copy constructor
DomesticTrip::DomesticTrip( const DomesticTrip& existing )
{
  cout << "***In DomesticTrip Copy Constructor***" << endl;
  
  From = existing.From;
  To = existing.To;
  Date[0] = existing.Date[0];
  Date[1] = existing.Date[1];
  Date[2] = existing.Date[2];
  State = existing.State;
  FTime = existing.FTime;
}

//assignment operator
DomesticTrip& DomesticTrip::operator=( const DomesticTrip& existing )
{
  cout << "***In DomesticTrip Assignment Operator***" << endl;

  From = existing.From;
  To = existing.To;
  Date[0] = existing.Date[0];
  Date[1] = existing.Date[1];
  Date[2] = existing.Date[2];
  State = existing.State;
  FTime = existing.FTime;

  return *this;
}

void DomesticTrip::report() const
{
  cout << "\nDomestic ";
  Trip::print();
  cout << " State: " << State;
  cout << " Flight Time: " << FTime;
  cout << endl;
}