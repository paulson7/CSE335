#include <iostream>
#include <string>

using namespace std;

#include "internationalTrip.h"

//Trip constructor
InternationalTrip::InternationalTrip()
{
  cout << "***In InternationalTrip Constructor***" << endl;

  From = rt.From;
  To = rt.To;
  Date[0] = rt.Date[0];
  Date[1] = rt.Date[1];
  Date[2] = rt.Date[2];

  Country = "";
}

//Trip destructor
InternationalTrip::~InternationalTrip()
{
cout << "***In InternationalTrip Destructor***" << endl;

  From = "";
  To = "";
  Date[0] = 0;
  Date[1] = 0;
  Date[2] = 0;
  Country = "";
}

//copy constructor
InternationalTrip::InternationalTrip( const InternationalTrip& existing )
{
  cout << "***In InternationalTrip Copy Constructor***" << endl;
  
  From = existing.From;
  To = existing.To;
  Date[0] = existing.Date[0];
  Date[1] = existing.Date[1];
  Date[2] = existing.Date[2];
  Country = existing.Country;
}

////create a InternationalTrip from an existing Trip
InternationalTrip::InternationalTrip( Trip& t ) : rt(t)
{
  cout << "***In Trip to InternationalTrip Constructor***" << endl;
  
  From = t.From;
  To = t.To;
  Date[0] = t.Date[0];
  Date[1] = t.Date[1];
  Date[2] = t.Date[2];
  
  Country = "";
}

//assignment operator
InternationalTrip& InternationalTrip::operator=(const InternationalTrip& exist)
{
  cout << "***In InternationalTrip Assignment Operator***" << endl;

  From = exist.From;
  To = exist.To;
  Date[0] = exist.Date[0];
  Date[1] = exist.Date[1];
  Date[2] = exist.Date[2];
  Country = exist.Country;

  return *this;
}

void InternationalTrip::report() const
{
  cout << "\nInternational ";
  Trip::print();
  cout << " Country: " << Country;
  cout << endl;
}