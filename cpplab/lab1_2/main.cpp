#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

using namespace std;

void howManyProtectedAnimals(Animal *tab[], int size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (tab[i]->getStatus()) {
            counter++;
        }
    }
    cout << "Liczba chronionych zwierzat: " << counter << endl;
}


void howManyTrackerDogs(Dog *tab[], int size) {
    for (int i = 0; i < size; i++) {
        if (tab[i]->getSkillLevel(2) > tab[i]->getSkillLevel(1)) {
            tab[i]->info();
        }
    }
}

void howManyCats(Cat *tab[], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += tab[i]->getMice(j);
        }
        cout << "Kot " << tab[i]->getName() << " zlapal " << sum << " myszy" << endl;
    }
}


int main() {
    Dog d1(4, "Burek", "Owczarek");
    d1.info();
    d1.setSkillLevel(1, 5);
    d1.setSkillLevel(2, 3);
    d1.info();
    cout << "Poziom umiejetnosci przewodnika: " << d1.getSkillLevel(1) << endl;
    cout << "Poziom umiejetnosci tropiciela: " << d1.getSkillLevel(2) << endl;
    d1.giveVoice();

    Animal *tab[5];
    tab[0] = new Dog(4, "Burek", "Owczarek");
    tab[1] = new Cat(4, "Filemon");
    tab[2] = new Dog(4, "Azor", "Owczarek");
    tab[3] = new Cat(4, "Mruczek");
    tab[4] = new Animal(4, "Zwierzak");
    tab[4]->setStatus(false); 

    Cat *tabCats[5];
    tabCats[0] = new Cat(4, "Filemon");
    tabCats[1] = new Cat(4, "Mruczek");
    tabCats[2] = new Cat(4, "Kicia");
    tabCats[3] = new Cat(4, "Puszek");
    tabCats[4] = new Cat(4, "Kotek");

    Dog *tabDogs[5];
    tabDogs[0] = new Dog(4, "Burek", "Owczarek");
    tabDogs[1] = new Dog(4, "Azor", "Owczarek");
    tabDogs[2] = new Dog(4, "Reksio", "Owczarek");
    tabDogs[3] = new Dog(4, "Burek", "Owczarek");
    tabDogs[4] = new Dog(4, "Azor", "Owczarek");

    howManyProtectedAnimals(tab, 5);
    howManyTrackerDogs(tabDogs, 5);
    howManyCats(tabCats, 5);

    return 0;
}

