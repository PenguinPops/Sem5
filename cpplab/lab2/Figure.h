#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
class Figure
{
private:
    float area;

public:
    Figure();
    virtual ~Figure();
    float getArea();
    void setArea(float area1);
    virtual void calculateArea() = 0;
    virtual void show();
    virtual void calculateCircumference() = 0;
};
#endif // FIGURE_H_INCLUDED