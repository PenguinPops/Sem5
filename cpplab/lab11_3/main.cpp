#include <iostream>
#include <memory>

using namespace std;

class Elem
{
public:
    shared_ptr<Elem> next;
    weak_ptr<Elem> prev;
    int value;
    Elem(int v) : value(v) {}
    ~Elem()
    {
        cout << "Destruktor Elem" << endl;
    }
};

class List
{
private:
    shared_ptr<Elem> head;
    shared_ptr<Elem> tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    void addFront(int v)
    {
        shared_ptr<Elem> newElem = make_shared<Elem>(v);
        if (head == nullptr)
        {
            head = newElem;
            tail = newElem;
        }
        else
        {
            newElem->next = head;
            head->prev = newElem;
            head = newElem;
        }
    }

    void addBack(int v)
    {
        shared_ptr<Elem> newElem = make_shared<Elem>(v);
        if (tail == nullptr)
        {
            head = newElem;
            tail = newElem;
        }
        else
        {
            newElem->prev = tail;
            tail->next = newElem;
            tail = newElem;
        }
    }

    void removeFront()
    {
        if (head == nullptr)
        {
            cout << "Lista jest pusta" << endl;
            return;
        }
        if (head == tail) // Jeden element w liście
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev.reset();
        }
    }

    void removeBack()
    {
        if (tail == nullptr)
        {
            cout << "Lista jest pusta" << endl;
            return;
        }
        if (head == tail) // Jeden element w liście
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev.lock();
            tail->next.reset();
        }
    }

    void showList()
    {
        shared_ptr<Elem> temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    List list;
    list.addFront(1);
    list.addFront(2);
    list.addFront(3);
    list.addBack(4);
    list.addBack(5);
    list.addBack(6);
    list.showList();
    list.removeFront();
    list.removeBack();
    list.showList();
    cout << "Czy lista jest pusta: " << list.isEmpty() << endl;
    list.removeFront();
    list.removeFront();
    list.removeFront();
    list.removeFront();
    cout << "Czy lista jest pusta: " << list.isEmpty() << endl;
    return 0;
}
