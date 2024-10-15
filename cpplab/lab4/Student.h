#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
using namespace std;

class Student {
    private:
        int mark;
        string name;
    public:
        Student(int mark, string name);
        int getMark();
};

Student::Student(int mark, string name) : mark(mark), name(name) {}
int Student::getMark() { return mark; }

#endif //STUDENT_H_INCLUDED