#ifndef BUFOR_H_INCLUDED
#define BUFOR_H_INCLUDED

class Bufor{
    private:
        //wskaźnik, który będzie reprezentować dynamiczną tablicę przechowującą liczby całkowite
        int *tab;
        //rozmiar tablicy
        int size;
        //indeks pierwszego wolnego miejsca w tablicy, zakładamy że są dodawane po kolei
        int index;
    public:
        //bezargumentowy konstruktor w którym zostanie stworzona tablica o rozmiarze 10, a indeks pierwszej wolnej komórki w tablicy zostanie ustawiony na 0
        Bufor();
        //konstruktor argumentowy, który jako argument dostanie rozmiar tablicy, w konstruktorze powinna zostać stworzona tablica oraz wartość pierwszego wolnego miejsca w tablicy ustawiona na 0
        Bufor(int size1);
        //wirtualny destruktor, w którym zostanie usunięta przydzielona pamięć
        virtual ~Bufor();
        //wirtualna metoda void add(int value) która umożliwia dodanie liczby w pierwsze wolne miejsce w tablicy
        virtual void add(int value);
        //czysto wirtualna metoda double calculate()
        virtual double calculate() = 0;
        //metoda int getIndex() która zwraca indeks pierwszej wolnej komórki w tablicy
        int getIndex();
        //metoda int getSize() która zwraca rozmiar tablicy
        int getSize();
        //metoda int getTab(int i) która zwraca wartość z tablicy pod indeksem i
        int getTab(int i);
        //metoda int getFirst(value) która zwraca pierwszy dostępny indeks
        int getFirst(int value);
        //metoda void setFirst(value), która ustawia wartość pola przechowującego pierwszy dostępny indeks w tablicy
        void setFirst(int value);
        //metoda void setTab(int pos, int value) która będzie ustawiała wartość znajdująca się pod indeksem pos na wartość value
        void setTab(int pos, int value);
        //metoda show
        void show();
};

#endif // BUFOR_H_INCLUDED
