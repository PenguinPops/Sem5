#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

//use algorithm and lambda

void eraseNegative(vector<int>& v) {
    v.erase(remove_if(v.begin(), v.end(), [](int i) {
        return i < 0;
    }), v.end());
}

void invert(vector<int>& v) {
    transform(v.begin(), v.end(), v.begin(), [](int i) {
        return -i;
    });
}

int countLess(vector<int>& v, int n) {
    return count_if(v.begin(), v.end(), [n](int i) {
        return i < n;
    });
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -2, -3, -4, -5};

    string p = "";
    for_each(v.begin(), v.end(), [&](int i) {
        p += to_string(i) + "|";
    });
    p.pop_back();
    cout << p << endl;

    float avg = accumulate(v.begin(), v.end(), 0.0) / v.size();
    cout << "Average: " << avg << endl;

    int count = count_if(v.begin(), v.end(), [](int i) {
        return i % 2 == 0;
    });
    cout << "Even numbers: " << count << endl;

    eraseNegative(v);

    invert(v);

    count = countLess(v, 5);
    cout << "Numbers less than 5: " << count << endl;

    

    
}