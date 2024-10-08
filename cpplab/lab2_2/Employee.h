#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <string>

class Employee {
    private:
        std::string surname;
        int age;
        int exp;
        float salary;
    public:
        Employee(std::string surname1, int age1, int exp1, float salary1);
        Employee();
        virtual ~Employee();
        virtual void show();
        virtual void calculateSalary() = 0;
        virtual float calculateBonus(int value) = 0;
        int ageEmployment();
        std::string getSurname();
        int getAge();
        int getExp();
        float getSalary();
};

#endif // EMPLOYEE_H_INCLUDED