#include <iostream>
#include <memory>

#include "cmake-build-debug/Ship.h"
#include "cmake-build-debug/SpeedyShip.h"
#include "cmake-build-debug/NormalShip.h"
#include "cmake-build-debug/StrongShip.h"
#include "cmake-build-debug/EventsAndFunctions.h"


using namespace std;

int main() {
    int shipChoice;
    cout << "Hello! You will start by choosing your ship for a unique space journey." << endl;
    cout << "If you choose 1, you will play with the Fast Ship, if you choose 2, you will play with the Strong Ship, and if you choose 3, you will play with the Normal Ship."<< endl;
    cin >> shipChoice;
    Ship* ptr= new Ship();
    std::unique_ptr<Ship> uniquePtr(ptr);
    if (shipChoice == 1)
    {
        SpeedyShip ship;
        eventGenerator(&ship);
        // Gemi hakkında oyun sonundaki bilgileri print ettirir
        cout << "Your coin: " << ship.coin << endl;
        cout << "Health: " << ship.health << endl;
        cout << "Fuel: " << ship.fuel << endl;
        pointCalculator(&ship);
    }
    else if (shipChoice == 2) {
        StrongShip ship;
        eventGenerator(&ship);
        cout << "Your coin: " << ship.coin << endl;
        cout << "Health: " << ship.health << endl;
        cout << "Fuel: " << ship.fuel << endl;
        pointCalculator(&ship);
    }
    else if (shipChoice == 3) {
        NormalShip ship;
        eventGenerator(&ship);
        cout << "Your coin: " << ship.coin << endl;
        cout << "Health: " << ship.health << endl;
        cout << "Fuel: " << ship.fuel << endl;
        pointCalculator(&ship);
    }
    return 0;
}
