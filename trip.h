#include <string>

using namespace std;

class Trip
{
  public:
   // Initialize the Trip to empty
    //
    Trip();

    // De-initialize the Trip
    //
    ~Trip();

    // Initialize the Trip using an existing Trip
    //
    Trip( const Trip& );

    // Assign into the Trip from another Trip
    //
    Trip& operator=( const Trip& );
    
    //print
    void print() const;

    //report
    virtual void report() const;
    
    string From;
    string To;
    int Date[3];
  
};