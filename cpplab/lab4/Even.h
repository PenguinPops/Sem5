#ifndef EVEN_H_INCLUDED
#define EVEN_H_INCLUDED

class Even {
    private:
        int divider;
    public:
        Even(int divider);
        bool operator()(int x);
};

Even:: Even(int divider) {
    this -> divider = divider;
}

bool Even::operator()(int x) {
    return (x % divider == 0) ? true : false;
}

#endif // EVEN_H_INCLUDED