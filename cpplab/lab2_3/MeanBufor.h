#ifndef MEANBUFOR_H_INCLUDED
#define MEANBUFOR_H_INCLUDED

#include "Bufor.h"

class MeanBufor : public Bufor
{
public:
    MeanBufor();
    MeanBufor(int size1);
    virtual ~MeanBufor();
    virtual double calculate() override;
};

#endif // MEANBUFOR_H_INCLUDED