#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void show(set<int> s)
{
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(3);
    show(s);
    s.erase(s.begin(), s.find(2));
    show(s);
    s.erase(2);
    show(s);
    cout << s.count(2) << endl;

    set<int> s1 = {1, 2, 3, 7};
    set<int> s2 = {-2, 4, 1, 7, 6};
    cout << "s1: ";
    show(s1);
    cout << "s2: ";
    show(s2);
    set<int> sUnion, sIntersec, sDiffer;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator(sUnion, sUnion.begin()));
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator(sIntersec, sIntersec.begin()));
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator(sDiffer, sDiffer.begin()));
    cout << "sUnion: ";
    show(sUnion);
    cout << "sIntersec: ";
    show(sIntersec);
    cout << "sDiffer: ";
    show(sDiffer);

    set<int> s3 = {3, 8};
    pair<set<int>::iterator, bool> res;
    res = s3.insert(6);
    cout << "Dodany element: " << *(res.first) << endl;
    cout << "Czy element dodany? " << res.second << endl;
    show(s3);
    return 0;
}