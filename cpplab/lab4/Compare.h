#ifndef COMPARE_H_INCLUDED
#define COMPARE_H_INCLUDED
#include "Student.h"
class Compare {
    public:
        bool operator() (Student &s1, Student &s2);
};

bool Compare::operator() (Student &s1, Student &s2) {
    return s1.getMark()<s2.getMark();
}
#endif //COMPARE_H_INCLUDED