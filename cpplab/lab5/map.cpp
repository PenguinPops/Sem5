#include <iostream>
#include <map>
using namespace std;
map<string, int>::iterator searchByValue(map<string, int> &m, int val)
{
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
        if (it->second == val)
            break;
    return it;
}
void showMap(map<string, int> m)
{
    cout << endl
         << "m: " << endl;
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}
int main()
{
    map<string, int> m;
    m.insert(pair<string, int>("Kowalski", 4500));
    m.insert(make_pair("Nowak", 2000));
    m["Adamek"] = 3000;
    showMap(m);
    int salary = m.find("Kowalski")->second;
    cout << "Zarobki Kowalskiego: " << salary << endl;
    m.erase("Adamek");
    showMap(m);
    cout << "Czy jest Kowalski? " << m.count("Kowalski") << endl;
    pair<string, int> el = *m.begin();
    cout << "Klucz: " << el.first << " " << "war: " << el.second << endl;

    map<string, int>::iterator it = searchByValue(m, 2000);
    if (it != m.end())
        cout << "Element znaleziony: " << it->first << " " << it->second << endl;
    else
        cout << "Brak elementu" << endl;
    return 0;
}
