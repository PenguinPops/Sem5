#ifndef TEAMLEADER_H_INCLUDED
#define TEAMLEADER_H_INCLUDED

#include "Employee.h"

class TeamLeader : public Employee
{
    public:
        TeamLeader(std::string surname1, int age1, int exp1, float salary1);
        TeamLeader();
        ~TeamLeader();
        virtual void show() override;
        virtual void calculateSalary() override;
        virtual float calculateBonus(int value) override;
};

#endif // TEAMLEADER_H_INCLUDED