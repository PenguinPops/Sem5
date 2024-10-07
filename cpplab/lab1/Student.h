#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "Person.h"
using namespace std;

class Student : public Person {
    private:
        string index;
    public:
        Student(string name1, string surname1, int age1, string index1);
        Student();
        void setIndex(string index1);
        string getIndex();
        void showInfoStudent();

};

#endif // STUDENT_H_INCLUDED