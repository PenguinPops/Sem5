#ifndef DEVELOPER_H_INCLUDED
#define DEVELOPER_H_INCLUDED

#include "Employee.h"

class Developer : public Employee
{
    public:
        Developer(std::string surname1, int age1, int exp1, float salary1);
        Developer();
        ~Developer();
        virtual void calculateSalary() override;
        virtual float calculateBonus(int value) override;
};

#endif // DEVELOPER_H_INCLUDED