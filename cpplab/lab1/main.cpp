#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;
int main()
{
    // cout << endl
    //      << "Obiekty klasy Person" << endl;
    // Person o1("Grazyna", "Nowak", 45);
    // o1.showInfoPerson();
    // cout << "Czy pelnoletnia?: " << o1.is_18() << endl;
    // o1.setAge(16);
    // cout << endl
    //      << "Obiekty klasy Teacher" << endl;
    // Teacher n1("Barbara", "Kowalska", 56, 30, "Phd");
    // n1.showInfoTeacher();
    // cout << "Czy ma Phd?: " << n1.is_Phd() << endl;
    // n1.setAge(34);

    // Person p1[3];
    // Person *p2;
    // Person *p3[3];
    // Person **p4;
    // for (int i = 0; i < 3; i++) {
    //     p1[i].init("Anna", "Nowak", 20 + i);
    //     p1[i].showInfoPerson();
    // }
    // p2 = new Person[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     p2[i].init("Ola", "Adamek", 20 + i);
    //     p2[i].showInfoPerson();
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     p3[i] = new Person("Kasia", "Kowalska", 20 + i);
    //     p3[i]->showInfoPerson();
    // }
    // p4 = new Person *[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     p4[i] = new Person("Pawel", "Wojcik", 20 + i);
    //     p4[i]->showInfoPerson();
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     delete p3[i];
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     delete p4[i];
    // }
    // delete[] p4;

    Student s1[3]; //statyczna tablica statycznych obiektow
    Student *s2; //dynamiczna tablica statycznych obiektow
    Student *s3[3]; //statyczna tablica dynamicznych obiektow
    Student **s4; //dynamiczna tablica dynamicznych obiektow

    //statyczna tablica statycznych obiektow
    for (int i = 0; i < 3; i++)
    {
        s1[i].init("Anna", "Nowak", 20 + i);
        s1[i].setIndex("1234" + to_string(i));
        s1[i].showInfoStudent();
    }

    //dynamiczna tablica statycznych obiektow
    s2 = new Student[3];
    for(int i = 0; i < 3; i++) {
        s2[i].init("Ola", "Adamek", 20 + i);
        s2[i].setIndex("1234" + to_string(i));
        s2[i].showInfoStudent();
    }

    //statyczna tablica dynamicznych obiektow
    for(int i = 0; i < 3; i++) {
        s3[i] = new Student("Kasia", "Kowalska", 20 + i, "1234" + to_string(i));
        s3[i]->showInfoStudent();
    }

    //dynamiczna tablica dynamicznych obiektow
    s4 = new Student *[3];
    for(int i = 0; i < 3; i++) {
        s4[i] = new Student("Pawel", "Wojcik", 20 + i, "1234" + to_string(i));
        s4[i]->showInfoStudent();
    }
    


    return 0;
}