#include <string>
#include "trip.h"

using namespace std;

class InternationalTrip : public Trip
{
  public:
    // Initialize the InternationalTrip to empty
    //
    InternationalTrip();

    // De-initialize the InternationalTrip
    //
    ~InternationalTrip();

    //create a InternationalTrip from an existing Trip
    InternationalTrip( Trip& t );

    // Initialize the InternationalTrip using an existing InternationalTrip
    //
    InternationalTrip( const InternationalTrip& );

    // Assign into the InternationalTrip from another InternationalTrip
    //
    InternationalTrip& operator=( const InternationalTrip& );
    
    //report
    void report() const;
    
    string Country;

  private:
  
    Trip rt;
};