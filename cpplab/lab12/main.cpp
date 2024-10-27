#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


bool fn(int l, int r)
{
    return l > r;
}

void fun(function<int(int)> f, int n)
{
    for (int i = 0; i < n; ++i)
        cout << "f(" << i << ") = " << f(i) << endl;
}

void printVec(vector<int> num)
{
    cout << endl
         << "Zawartosc num: ";
    for (auto it = num.begin(); it != num.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    tuple<char, int, float> t1;
    t1 = make_tuple('a', 8, 21.5);
    cout << "Liczba elementow: "
         << tuple_size<decltype(t1)>::value << endl;
    cout << "get<0>: " << get<0>(t1) << endl;
    cout << "get<1>: " << get<1>(t1) << endl;
    cout << "get<2>: " << get<2>(t1) << endl;
    tuple_element<0, decltype(t1)>::type
        first = get<0>(t1);
    tuple_element<1, decltype(t1)>::type
        second = get<1>(t1);
    cout << "Pierwszy element t1: " << first << endl;
    cout << "drugi element t1: " << second << endl;
    cout << "Przed modyfikacja: get<1>: "
         << get<1>(t1) << endl;
    get<1>(t1) = 2;
    cout << "Po modyfikacji: get<1>: " << get<1>(t1) << endl;
    tuple<char, int, float> t2('p', 45, 7.5);
    cout << "Przed swap t2" << endl;
    cout << "get<0>: " << get<0>(t2) << endl;
    cout << "get<1>: " << get<1>(t2) << endl;
    cout << "get<2>: " << get<2>(t2) << endl;
    t2.swap(t1);
    cout << "Po swap t2" << endl;
    cout << "get<0>: " << get<0>(t2) << endl;
    cout << "get<1>: " << get<1>(t2) << endl;
    cout << "get<2>: " << get<2>(t2) << endl;
    tuple<int, char> t3(2, 'a');
    auto t4 = make_tuple(3, 'b');
    auto t5 = tuple_cat(t3, t4);
    cout << "Zawartosc t5: " << endl;
    cout << get<0>(t5) << " " << get<1>(t5) << " " << get<2>(t5)
         << " " << get<3>(t5) << endl;
    int i_val;
    char ch_val;
    float f_val;
    tuple<int, char, float> t6(2, 'R', 3.5);
    tie(i_val, ch_val, f_val) = t6;
    cout << "Pobranie wszystkich zmiennych z tupli: ";
    cout << i_val << " " << ch_val << " " << f_val << endl;
    tie(i_val, ignore, f_val) = t6;
    cout << "Pobranie wybranych zmiennych z tupli: ";
    cout << i_val << " " << f_val << endl;

    vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort(num.begin(), num.end(), fn);
    sort(num.begin(), num.end(),
         [](int l, int r) -> bool
         { return l > r; });
    sort(num.begin(), num.end(),
         [](int l, int r)
         { return l > r; });
    printVec(num);
    transform(num.begin(), num.end(), num.begin(),
              [](int el)
              { return el * 2; });
    cout << "Zawartosc num: ";
    for_each(num.begin(), num.end(),
             [](int el)
             { cout << "**" << el; });
    for_each(num.begin(), num.end(), [](int &el)
             { el = el * 2; });
    printVec(num);

    cout << "Suma a+b: "
         << [](int a, int b)
    { return a + b; }(1, 8) << endl;
    auto lam = [](int a) -> float
    { if( a > 0 ) return 1;
return -1.0; };

    fun([]( int x ) { return x+2; }, 5);
    cout << lam(2) << endl;
    return 0;
}