// W zadaniu wykorzystaj inteligentne wskaźniki i pamiętaj, aby wszystkie zasoby zostały
// poprawnie zwolnione. Zdefiniuj klasę abstrakcyjną Buffer. Klasa posiada:
//  funkcję czysto wirtualną void add(int a);
//  funkcję czysto wirtualną void write();
//  konstruktor bezparametrowy wypisujący na ekranie napis "Konstruktor Buffer"
//  destruktor wypisujący na ekranie napis "Destruktor Buffer"
// Stwórz dwie klasy dziedziczące publicznie po tej klasie: BufferArr oraz BufferFile.
// Klasa BufferArr posiada:
//  prywatne pola do reprezentowania jednowymiarowej tablicy elementów o rozmiarze
// podanym w parametrze;
//  konstruktor jednoargumentowy alokujący tablicę o rozmiarze podanym w parametrze;
//  odpowiednie gettery oraz settery do pól;
//  metodę add(int a), która dodaje przekazany w parametrze element na kolejną pozycję
// w tablicy, w przypadku gdy tablica jest pełna i nie można dodać do niej elementu, na
// ekranie powinien pojawić się odpowiedni komunikat;
//  napisz metodę write(), która wyświetla wszystkie dodane elementy na ekranie;
// Konstruktory oraz destruktor dodatkowo wypisują na ekranie napis identyfikujący je:
//  konstruktor jednoargumentowy otwierający plik o ścieżce podanej w parametrze;
//  metodę add(int a), która dopisuje do pliku kolejną liczbę. W jednej linijce znajduje się
// jedna liczba;
//  metodę write(), która wyświetla wszystkie liczby z pliku na konsolę;
// Konstruktor oraz destruktor dodatkowo powinny wypisywać na ekranie napis
// identyfikujący je: „Konstruktor klasy BufferFile” oraz „Destruktor klasy BufferFile”.
// Uchwyty pozwalające na otworzenie pliku powinny być wskaźnikami.
// Napisz program, w którym przetestujesz polimorficzne wywołanie metod wirtualnych.
// Napisz funkcję main(), która posiada 6 „buforów” umieszczonych w kontenerze lub tablicy
#include <iostream>
#include <memory>

using namespace std;

class Buffer
{
public:
    Buffer()
    {
        cout << "Konstruktor Buffer" << endl;
    }
    virtual ~Buffer()
    {
        cout << "Destruktor Buffer" << endl;
    }
    virtual void add(int a) = 0;
    virtual void write() = 0;
};

class BufferArr : public Buffer
{
private:
    unique_ptr<int[]> tab;
    int size;
    int index;

public:
    BufferArr(int s) : size(s)
    {
        tab = make_unique<int[]>(size);
        index = 0;
    }
    ~BufferArr()
    {
        tab.reset();
    }
    void add(int a)
    {
        if (index < size)
        {
            tab[index] = a;
            index++;
        }
        else
        {
            cout << "Tablica jest pelna" << endl;
        }
    }
    void write()
    {
        for (int i = 0; i < index; i++)
        {
            cout << tab[i] << " ";
        }
        cout << endl;
    }
};

class BufferFile : public Buffer
{
private:
    FILE *file;

public:
    BufferFile(string path)
    {
        file = fopen(path.c_str(), "w");
    }
    ~BufferFile()
    {
        fclose(file);
    }
    void add(int a)
    {
        fprintf(file, "%d\n", a);
    }
    void write()
    {
        fseek(file, 0, SEEK_SET); // ustawienie wskaźnika na początek pliku
        char line[256]; // bufor na linie
        while (fgets(line, sizeof(line), file))
        {
            cout << line; // wypisanie linii
        }
    }
};

int main()
{
    unique_ptr<Buffer> buffers[6];
    buffers[0] = make_unique<BufferArr>(5);
    buffers[1] = make_unique<BufferArr>(3);
    buffers[2] = make_unique<BufferArr>(4);
    buffers[3] = make_unique<BufferFile>("file.txt");
    buffers[4] = make_unique<BufferFile>("file2.txt");
    buffers[5] = make_unique<BufferFile>("file3.txt");

    for (int i = 0; i < 6; i++)
    {
        buffers[i]->add(i);
        buffers[i]->add(i + 1);
        buffers[i]->add(i + 2);
        buffers[i]->write();
    }

    return 0;
}