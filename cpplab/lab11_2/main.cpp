// W zadaniu wykorzystaj inteligentne wskaźniki. Zdefiniuj klasę Warehouse, która będzie
// reprezentować magazyn. Klasa będzie posiadać:
//  prywatne pola przechowujące nazwę towaru, który jest przechowywany w magazynie
// (dla uproszczenia na przykład: książki, komputery, łóżka, itd.) oraz liczbę sztuk;
//  odpowiednie setery oraz gettery do pól;
//  metodę wyświetlającą informację o magazynie (nazwa towaru oraz liczba sztuk
// towaru).
// Następnie stwórz klasę Shop, która będzie reprezentować sklep i posiadać:
//  listę magazynów, z których korzysta;
//  metodę, która umożliwi sprzedaż towaru, którego nazwa i liczba sztuk została podana
// w argumencie (zakładamy, że nazwa artykułu jest taka sama jak nazwa towaru
// w magazynie). Jeśli w danym magazynie znajduje się odpowiednia liczba sztuk
// danego towaru, to towar powinien zostać sprzedany;
//  metodę wyświetlającą z jakich magazynów korzysta sklep;
// W funkcji main stwórz listę unikatowych sklepów. Sklepy mogą korzystać z tych samych
// magazynów. Przetestuj stworzone klasy.

#include <iostream>
#include <memory>

using namespace std;

class Warehouse
{
private:
    string name;
    int quantity;

public:
    Warehouse(string n, int q) : name(n), quantity(q) {}
    void setName(string n) { name = n; }
    void setQuantity(int q) { quantity = q; }
    string getName() { return name; }
    int getQuantity() { return quantity; }
    void showInfo()
    {
        cout << "Nazwa towaru: " << name << ", ilosc sztuk: " << quantity << endl;
    }
};

class Shop
{
private:
    unique_ptr<Warehouse> warehouse;

public:
    Shop(unique_ptr<Warehouse> w) : warehouse(std::move(w)) {} // Przenoszenie zasobu z obiektu wskazywanego przez w do obiektu wskazywanego przez warehouse
    void sell(string name, int quantity)
    {
        if (warehouse->getName() == name && warehouse->getQuantity() >= quantity)
        {
            warehouse->setQuantity(warehouse->getQuantity() - quantity);
        }
    }
    void showWarehouses()
    {
        warehouse->showInfo();
    }
};

int main()
{
    unique_ptr<Warehouse> w1 = make_unique<Warehouse>("komputery", 10);
    unique_ptr<Warehouse> w2 = make_unique<Warehouse>("ksiazki", 20);
    unique_ptr<Warehouse> w3 = make_unique<Warehouse>("lozka", 30);

    unique_ptr<Shop> s1 = make_unique<Shop>(std::move(w1));
    unique_ptr<Shop> s2 = make_unique<Shop>(std::move(w2));
    unique_ptr<Shop> s3 = make_unique<Shop>(std::move(w3));

    s1->sell("komputery", 5);
    s1->showWarehouses();
    s2->sell("ksiazki", 10);
    s2->showWarehouses();
    s3->sell("lozka", 15);
    s3->showWarehouses();

    return 0;
}