#ifndef COSMICVOYAGERPROJECT_SPEEDYSHIP_H
#define COSMICVOYAGERPROJECT_SPEEDYSHIP_H

#include "Ship.h"

class SpeedyShip : public Ship {
public:

    SpeedyShip() {

        damageRatio = 3;

        int randomNumber = generateRandomNumber(0,100);
        if (randomNumber < 75) { //%75 olasılıkla geminin kaçabileceği ihtimalini belirleriz.
            escape = 1;
        }

    }
};

#endif COSMICVOYAGERPROJECT_SPEEDYSHIP_H
