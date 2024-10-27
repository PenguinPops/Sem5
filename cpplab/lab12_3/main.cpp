#include <iostream>
#include <string>
#include <vector>

using namespace std;

tuple<int, float, string> stringTuple(vector<string> str) {
    int min = str[0].length();
    int max = str[0].length();
    float avg = str[0].length();
    string longest = str[0];
    for (auto& s : str) {
        if (s.length() < min) {
            min = s.length();
        }
        if (s.length() > max) {
            max = s.length();
            longest = s;
        }
        avg += s.length();
    }
    avg /= 4;
    return make_tuple(min, avg, longest);
}



int main() {
    vector<string> str = {"Ala", "ma", "kota", "a", "kot", "ma", "Ale"};
    tuple<int, float, string> s = stringTuple(str);
    cout << "Length of shortest string: " << get<0>(s)<< " Avg string length: " << get<1>(s) <<" Longest string: "<< get<2>(s) << endl;
}