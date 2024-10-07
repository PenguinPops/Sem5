#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat(int limbNr1, string name1):Animal(limbNr1, name1) {
    levelOfMouseHunting = 0;
    cout << "Konstruktor klasy pochodnej - Cat" << endl;
}

Cat::Cat() {
    cout << "Konstruktor bez. klasy pochodnej - Cat" << endl;
}

void Cat::initMice() {
    for (int i = 0; i < 5; i++) {
        mice[i] = 0;
    }
}

void Cat::initCat(int limbNr1, string name1, int levelOfMouseHuntingSkills1) {
    setLimbNr(limbNr1);
    setName(name1);
    levelOfMouseHunting = levelOfMouseHuntingSkills1;
    initMice();
}

void Cat::setLevelOfMouseHunting(int value) {
    levelOfMouseHunting = value;
}

int Cat::getLevelOfMouseHunting() {
    return levelOfMouseHunting;
}

int Cat::getMice(int index) {
    return mice[index];
}

void Cat::giveVoice() {
    cout << "Miau miau" << endl;
}

void Cat::info() {
    cout << "Nazwa: " << getName() << " liczba konczyn: " << getLimbNr() << " chroniony: " << getStatus() << " poziom umiejetnosci polowania na myszy: " << levelOfMouseHunting << " liczba myszy zlapanych w roku: ";
    for (int i = 0; i < 5; i++) {
        cout << mice[i] << " ";
    }
    cout << endl;
}