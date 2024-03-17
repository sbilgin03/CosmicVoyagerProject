#include <iostream>
#include "Ship.h"
#include "EventsAndFunctions.h"

using namespace std;

int Ship::generateRandomNumber(int min, int max) { // Verilen aralıkta integer sayı üretir
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void pointCalculator(Ship* ptr) //Puanı yazdıran fonksiyon
{
    int Point; Point = (ptr->fuel*5) + (ptr->health*10) + (ptr->coin*10); // puan hesaplanması
    cout << "Game over!" << endl;
    cout << "Your point:" << Point << endl;
}

void eventGenerator(Ship* ptr) {
    for (int i = 0; i < 5; i++) { // 5 event oluşturmak için loop
        int random_event = ptr->generateRandomNumber(0,2); // 3 eventten birini oluşturmak için
        if (random_event == 0) {
            cout << "AsteroidEvent()**" << endl; //PROJE TESLİMİNDE SİL
            asteroidEvent(ptr);
        }
        else if (random_event == 1) {
            cout << "AbandonedPlanetEvent()***" <<endl;//PROJE TESLİMİNDE SİL
            abandonedPlanetEvent(ptr);

        }
        else {
            cout << "SpacePiratesEvent()**" << endl;//PROJE TESLİMİNDE SİL
            spacePiratesEvent(ptr);

        }
    }
}