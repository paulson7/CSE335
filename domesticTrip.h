#include <string>
#include "trip.h"

using namespace std;

class DomesticTrip : public Trip
{
  public:
  
    string State;
    int FTime;
  
    // Initialize the DomesticTrip to empty
    DomesticTrip();
    
    //create a DomesticTrip from an existing Trip
    DomesticTrip( Trip& t );

    // De-initialize the DomesticTrip
    //
    ~DomesticTrip();

    // Initialize the DomesticTrip using an existing DomesticTrip
    //
    DomesticTrip( const DomesticTrip& );

    // Assign into the DomesticTrip from another DomesticTrip
    //
    DomesticTrip& operator=( const DomesticTrip& );
    
    //report
    virtual void report() const;
    
  private:
  
    Trip rt;
    
};