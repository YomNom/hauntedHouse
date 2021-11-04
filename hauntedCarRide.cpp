// FILE: hauntedCarRide.cpp
// Coder: J Yong
// Purpose: Functions for a simulated amusement park style ride at the Transy Haunted House

#include "hauntedCarRide.h"

bool getNMtotalCrowd(char **argv, CROWD &fair, VEHICLE &car) {
  if (argv[1] != NULL && argv[2] != NULL) {
    car.maxPassengers = charToInt(argv[1]);
    car.maxWeight = charToInt(argv[2]);

    //Gives a specific message for if the fair population is left off
    if (argv[3] != NULL) {
      fair.folkCnt = charToInt(argv[3]);
      
      cout << endl << "Welcome to the Haunted Car Ride at the exclusive Transy Fair!"
         << endl << "\tOur car can hold " << car.maxPassengers << " passengers and a max weight of " << car.maxWeight << ".\n\n";
      
      return true;
    }
    else {
      cout << endl << "Closing because no one has entered the park within the admittance time.\n\n";
      return false;
    }
  }
  else {
    cout << endl << "Apologies, the haunted house is not open right now.\n\n";
    return false;
  }
}

void crowdManagement(CROWD &fair) {
  crowdGenerator(fair);
  getInLine(fair);

  cout << "\nIDLE\n";
  for (int i = 0; i < fair.idle.size(); i++) {
    cout << fair.idle[i] << endl;
  }

  cout << "\nLINE\n";
  for (int x = 0; x < fair.inLine.size(); x++) {
    cout << fair.inLine[x] << endl;
  }
}

void crowdGenerator(CROWD &fair) {
  random_device rd;
  default_random_engine eng(rd());
  uniform_real_distribution<> distr(MINWEIGHT, MAXWEIGHT);

  float newPerson;
  for (int i = 0; i < fair.folkCnt; ++i) {
    fair.idle.push_back(distr(eng));
  }
    
  for (int x = 0; x < fair.idle.size(); x++) {
    cout << x << ": " << fair.idle[x] << endl;
  }
}

void getInLine(CROWD &fair) {
  random_device rd;
  default_random_engine eng(rd());
  uniform_int_distribution<int> distr(MINCHANCE, MAXCHANCE);
  
  //25% chance of getting in line                                                            
  int status;
  for (int i = 0; i < fair.idle.size(); i++) {
    status = distr(eng);
    if (status == IN_LINE) {
      fair.inLine.push_back(fair.idle[i]);
    }
  }

  //removes things inLine from idle
  for (int i = 0; i < fair.inLine.size(); i++) {
    cout << "Clone " << i << ": " << fair.inLine[i];
    cout << "\nIDLE\n";
    //looks for float in inLine in idle to delete it
    for (int x = 0; x < fair.idle.size(); x++) {
      if (fair.inLine[i] == fair.idle[x]) {
	cout << "idle: " << fair.idle[x] << endl;
	fair.idle.erase(fair.idle.begin() + x);
      }
    }
    
  }
}

int charToInt (const char *convertFrom) {
  int base = 10;
  char* strGarbage; //not going to use at all
 
  int convertTo = strtol(convertFrom, &strGarbage, base);

  return convertTo;
}

void timer78sec(time_t start) {
  double time = findTime(start);
  while (time < BOARDTIME) {
    //cout << endl << "TIME: " << time << endl;
    time = findTime(start);
  }
  cout << endl << "FINAL TIME: " << time << endl;
}

double findTime(time_t start) {
  double sec;
  time_t currentTime = time(NULL);

  sec = difftime(currentTime, start);

  return sec;
}
