#ifndef COSMICVOYAGERPROJECT_STRONGSHIP_H
#define COSMICVOYAGERPROJECT_STRONGSHIP_H
#include "Ship.h"

class StrongShip : public Ship {
public:

    StrongShip() {

        damageRatio = 1;

        int randomNumber = generateRandomNumber(0, 100);
        if (randomNumber < 25) {
            escape = 1;
        }
    }
};

#endif COSMICVOYAGERPROJECT_STRONGSHIP_H
