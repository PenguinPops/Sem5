#ifndef MAXBUFOR_H_INCLUDED
#define MAXBUFOR_H_INCLUDED

#include "Bufor.h"

class MaxBufor : public Bufor
{
public:
    MaxBufor();
    MaxBufor(int size1);
    virtual ~MaxBufor();
    virtual double calculate() override;
    virtual void add(int value) override;
};

#endif // MAXBUFOR_H_INCLUDED