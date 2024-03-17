#ifndef COSMICVOYAGERPROJECT_SHIP_H
#define COSMICVOYAGERPROJECT_SHIP_H
#include <random>
using namespace std;

class Ship {
public:
    int fuel;
    int coin;
    int health;
    const int fuelControl = 33; // Kaçmak için gerekli olan yakıt miktarı.Oyunda yakıt kaçılamayacak kadar azsa oyunu bitirir.
    const int asteroidDamageCoefficient = 5; // Asteroid eventinde hasar katsayısı
    const int spaceDamageCoefficient = 15; // Uzay Korsanları eventinde hasar katsayısı
    const int coinIncreasing = 10; // Terkedilmiş gezegen eventinde coin artışını belirleyen değişken
    int damageRatio; //Gemi türüne göre hasar oranı
    bool escape = 0; // Geminin asteroidden veya uzaydan kaçıp kaçmadığı bilgisini verir. 1 ise gemi kaçabilmiştir.

    virtual int generateRandomNumber(int min, int max);

    Ship() { // Ship constructor'ı
        fuel = 100;
        coin = 0;
        health = 100;
    }
};

#endif COSMICVOYAGERPROJECT_SHIP_H
