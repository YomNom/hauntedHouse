// FILE: hauntedCarRide.h
// Coder: J Yong
// Purpose: Header for hauntedCarRide.cpp
#ifndef HAUNTEDCARRIDE_H_INCLUDED
#define HAUNTEDCARRIDE_H_INCLUDED

#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <deque>
using namespace std;

#define MAXPEOPLE 1000
#define BOARDTIME 78
#define MINCHANCE 1
#define MAXCHANCE 4
#define MINWEIGHT 100
#define MAXWEIGHT 300
#define IN_LINE 1


typedef struct {
  int folkCnt;
  deque<float> idle, inLine;
} CROWD;

typedef struct {
  int maxPassengers, maxWeight;
  bool go = false; //will turn true every 78 sec then turn back to false
} VEHICLE;

bool getNMtotalCrowd(char **argv, CROWD &fair, VEHICLE &car);
void crowdManagement(CROWD &fair);
void crowdGenerator(CROWD &fair);
void getInLine(CROWD &fair);

// Purpose: To convert char (specifically argv) to an int
// PRE: A const char * to change to an int to return
//      strtol doesn't like anything else
// POST: converted const char returned
int charToInt (const char *convertFrom);

// Purpose: timer for 78 seconds
//          timer will start when people start boarding and take off at 78 seconds
// PRE:
// POST: 
void timer78sec(time_t start);

// Purpose: gets time for the timer of 78 seconds
// PRE: start time to get the current status of the timer
// POST: the current time is returned
double findTime(time_t start);

#endif
