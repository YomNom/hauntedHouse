// FILE: hauntedHouse.cpp
// Coder: J Yong
// Purpose: Pthreads program simulating...
//          The Transy Haunted House this year is an amusement park style ride.
//          A car, capable of holding n people with no more than m weight takes
//          students through an incredible scare-fest.
//          It waits until n people have boarded, with the added restriction that
//          the total weight can be no more than m (people will have random weights between 100 and 300 pounds).
//          Cars start out every 78 seconds.
//
// SOURCES:
// converting strings to ints https://www.geeksforgeeks.org/strol-function-in-c/
#include "hauntedCarRide.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv) {
  time_t start = time(NULL);
  CROWD fair; //haunted house is assumed to be a fair
  VEHICLE car;

  bool isOpen = getNMtotalCrowd(argv, fair, car);

  if (isOpen == true) {
    cout << "max: " << car.maxPassengers << " weight:  " << car.maxWeight << " cnt: " << fair.folkCnt << endl;
    crowdManagement(fair);
  }
  /*
  if (argv[1] != NULL && argv[2] != NULL) {
    car.maxPassengers = charToInt(argv[1]);
    car.maxWeight = charToInt(argv[2]);

    //Gives a specific message for if the fair population is left off
    if (argv[3] != NULL) {
      fair.folkCnt = charToInt(argv[3]);
    }
    else {
      cout << endl << "Closing because no one has entered the park within the time for admittance\n\n";
    }
    cout << endl << "Welcome to the Haunted Car Ride at the exclusive Transy Fair!"
         << endl << "\tOur cars can hold " << car.maxPassengers << " passengers and a max weight of " << car.maxWeight << endl << endl;
    timer78sec(start);
  }
  else {
    cout << endl << "Apologies, the haunted house is not open right now.\n\n";
  }
  */
  
  return 0;
}
