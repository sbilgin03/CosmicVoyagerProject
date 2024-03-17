#include <iostream>

#include "Ship.h"
#include "EventsAndFunctions.h"



using namespace std;

void asteroidEvent(Ship* ptr) { // Asteroid Çarpması Durumu

    cout << "You are passing through the asteroid belt!" << endl;
    if (ptr->escape == 1)
    {
        cout << "The asteroid didn't hit.You're in luck :)" << endl;
        ptr->escape = ptr->generateRandomNumber(0, 1);
    }
    else if (ptr->health > ((ptr->asteroidDamageCoefficient) * ptr->damageRatio)) { // Sağlık 0'dan küçük olmasın diye kontrol ediliyor.
        cout << "Asteroid hit! The ship was damaged." << endl;
        ptr->health = ptr->health - ((ptr->asteroidDamageCoefficient) * ptr->damageRatio);
        ptr->escape = ptr->generateRandomNumber(0, 1);
    }
}

void spacePiratesEvent(Ship* ptr) { // Uzay Korsanları çıkması Durumu

    int spaceChoice;
    cout << "Space pirates appeared!" << endl;
    cout
            << "If you choose 1, you will flight, if you choose 2, you will fight and if you choose 3, you will bargain."
            << endl;
    cin >> spaceChoice;
    // Uzay Korsanları Eventinde Kaçma durumu
    if (spaceChoice == 1 && ptr->fuel >= ptr->fuelControl) { // Kaçmak için Yeterli Yakıt olup Olmadığı Kontrol ediliyor.
        if (ptr->escape == 1) {
            cout << "Escape successful!" << endl;
            ptr->fuel -= ptr->fuelControl ;
            ptr->escape = ptr->generateRandomNumber(0, 1);
        }
        else if (ptr->escape == 0 && ptr->fuel >= ptr->fuelControl) {
            cout << "You couldn't escape, you're back to square one!" << endl;
            ptr->escape = ptr->generateRandomNumber(0, 1);
            ptr->fuel -= ptr->fuelControl;
            spacePiratesEvent(ptr);
        }
        else {
            cout <<  "Game over!" << endl;
            pointCalculator(ptr);
        }

    }
    if (spaceChoice == 2) { // Uzay Korsanları Eventinde Savaşma durumu
        cout << "You chose to fight!" << endl;
        int randomNumber = ptr->generateRandomNumber(0, 100);
        if (randomNumber < 50) {
            cout << "You won the war!" << endl;
        }
            //Her gemi içim sağlık durumunun 0'ın altına inmesini engelledik.
        else if (ptr->health > ((ptr->spaceDamageCoefficient) * ptr->damageRatio)) {
            cout << "You lost the war!" << endl;
            ptr->health = ptr->health - ((ptr->spaceDamageCoefficient) * ptr->damageRatio);
        }
    }
    if (spaceChoice == 3) { // Uzay Korsanları Eventinde Pazarlık seçeneği

        cout << "You chose to bargain!" << endl;
        int randomNumber = ptr->generateRandomNumber(1, 3);

        if (randomNumber == 1 && ptr->coin >= 10) {
            cout << "Space pirates want 10 coin!" << endl;
            ptr->coin -= 10;
        }
        else if (randomNumber == 2 && ptr->coin >= 20) {
            cout << "Space pirates want 20 coin!" << endl;
            ptr->coin -= 20;
        }
        else if (randomNumber == 3 && ptr->coin >= 30) {
            cout << "Space pirates want 30 coin!" << endl;
            ptr->coin -= 30;
        }
        else {
            cout << "Bargain is failed!" << endl;
            cout << "You have to fight!" << endl;
            randomNumber = ptr->generateRandomNumber(0, 100);

            if (randomNumber < 50) {
                cout << "You won the war!" << endl;
            }
            if (randomNumber >= 50 && ptr->health > ((ptr->spaceDamageCoefficient) * ptr->damageRatio)) {
                cout << "You lost the war!" << endl;
                ptr->health = ptr->health - ((ptr->spaceDamageCoefficient) * ptr->damageRatio);
            }
        }
    }
}
void abandonedPlanetEvent(Ship* ptr) { // Terkedilmiş Gezegen Eventi

    cout << "You crashed on an abandoned planet!" << endl;
    int randomNumber = ptr->generateRandomNumber(0,100);
    if (randomNumber < 50) {
        cout << "You did not suffer any damage, you will get coin!" << endl;
        ptr->coin += ptr->coinIncreasing;
    }
    else {
        spacePiratesEvent(ptr);
    }
}