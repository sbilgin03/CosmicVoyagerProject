#ifndef COSMICVOYAGERPROJECT_EVENTSANDFUNCTIONS_H
#define COSMICVOYAGERPROJECT_EVENTSANDFUNCTIONS_H

#include <iostream>
#include <random>
#include "Ship.h"

using namespace std;

void pointCalculator(Ship* ptr);
void asteroidEvent(Ship* ptr);
void spacePiratesEvent(Ship* ptr) ;
void abandonedPlanetEvent(Ship* ptr);
void eventGenerator(Ship* ptr);

#endif COSMICVOYAGERPROJECT_EVENTSANDFUNCTIONS_H

