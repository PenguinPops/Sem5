#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog(int limbNr1, string name1, string breed1):Animal(limbNr1, name1) {
    breed = breed1;
    levelOfGuideSkills = 0;
    levelOfTrackerSkills = 0;
    cout << "Konstruktor klasy pochodnej - Dog" << endl;
}

Dog::Dog(int limbNr1, string name1, string breed1, int levelOfGuideSkills1, int levelOfTrackerSkills1):Animal(limbNr1, name1) {
    breed = breed1;
    levelOfGuideSkills = levelOfGuideSkills1;
    levelOfTrackerSkills = levelOfTrackerSkills1;
    cout << "Konstruktor klasy pochodnej - Dog" << endl;
}

Dog::Dog() {
    cout << "Konstruktor bez. klasy pochodnej - Dog" << endl;
}

void Dog::setSkillLevel(int type, int value) {
    if (type == 1) {
        levelOfGuideSkills = value;
    } else if (type == 2) {
        levelOfTrackerSkills = value;
    }
}

int Dog::getSkillLevel(int type) {
    if (type == 1) {
        return levelOfGuideSkills;
    } else if (type == 2) {
        return levelOfTrackerSkills;
    } else {return -100;}
}

void Dog::giveVoice() {
    cout << "Hau hau" << endl;
}

void Dog::info() {
    cout << "Nazwa: " << getName() << " liczba konczyn: " << getLimbNr() << " chroniony: " << getStatus() << " rasa: " << breed << " poziom umiejetnosci przewodnika: " << levelOfGuideSkills << " poziom umiejetnosci tropiciela: " << levelOfTrackerSkills << endl;
}

