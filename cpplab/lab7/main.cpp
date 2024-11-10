#include <boost/bind.hpp>
#include <QCoreApplication>
#include <iostream>
#include <QVector>
using namespace std;

template <typename T>
void show(QVector<T> vec)
{
    cout << "Zawartosc vec: :";
    typename QVector<T>::iterator p;
    for (p = vec.begin(); p != vec.end(); ++p)
        cout << *p << " ";
    cout << endl;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<int> vec(6);
    vec[0] = 1;
    vec[1] = 2;
    vec.append(2);
    vec.push_back(4);
    vec << 5 << 6;
    cout << "Zawartosc vec: :";
    for (int i = 0; i < vec.count(); ++i)
        cout << vec[i] << " ";
    cout << endl
         << "Zawartosc vec: :";
    for (int i = 0; i < vec.size(); ++i)
        cout << vec.at(i) << " ";
    cout << endl
         << "Zawartosc vec: :";
    QVectorIterator<int> i(vec);
    while (i.hasNext())
        cout << i.next() << " ";
    cout << endl;
    show(vec);
    cout << "Zawartosc vec: :";
    QVector<int>::iterator p;
    for (p = vec.begin(); p != vec.end(); ++p)
    {
        *p += 2;
        cout << *p << " ";
    }
    cout << endl;
    vec.insert(1, 666);
    vec.insert(vec.begin(), 777);
    show(vec);
    cout << "Ostatni indeks gdzie 2: "
         << vec.lastIndexOf(2) << endl;
    vec.move(1, vec.length() - 1);
    vec.remove(3);
    show(vec);
    return a.exec();
}