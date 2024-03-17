#ifndef COSMICVOYAGERPROJECT_NORMALSHIP_H
#define COSMICVOYAGERPROJECT_NORMALSHIP_H

#include <random>
#include "Ship.h"

class NormalShip : public Ship {
public:


    NormalShip() {
        damageRatio = 2;
        int randomNumber = generateRandomNumber(0,100);
        if (randomNumber < 50) {
            escape = 1;
        }

    }
};

#endif COSMICVOYAGERPROJECT_NORMALSHIP_H
