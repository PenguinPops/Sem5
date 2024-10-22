#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

void sort_wg_sumy_cyfr(vector<int> &v) {
    sort(v.begin(), v.end(), [](int a, int b) {
        int sum_a = 0;
        int sum_b = 0;
        while(a) {
            sum_a += a % 10;
            a /= 10;
        }
        while(b) {
            sum_b += b % 10;
            b /= 10;
        }
        return sum_a < sum_b;
    });
}

void sort_wg_liczby_cyfr(vector<int> &v) {
    sort(v.begin(), v.end(), [](int a, int b){
        int licz_a = 0, licz_b = 0;
        while(a) {
            a /= 10;
            licz_a++;
        }
        while(b) {
            b /= 10;
            licz_b++;
        }
        return licz_a > licz_b;
    });
}

void print_vector(vector<int> v) {
    string s = "[ ";
    for(auto &e : v) {
        s +=  to_string(e) + ", ";
    }
    if(!v.empty()) {
        s.pop_back();
        s.pop_back();
    }
    s += " ]";
    cout << s << endl;
}

int main() {
    vector<int> v;
    srand(time(0));
    for(int i = 0; i < 10; i++) {
        v.push_back(rand() % 20000);
    }
    cout << "Wektor nie posortowany: ";
    print_vector(v);
    sort_wg_sumy_cyfr(v);
    cout << "Wektor posortowany wg sumy cyfr: ";
    print_vector(v);
    sort_wg_liczby_cyfr(v);
    cout << "Wektor posortowany wg liczby cyfr: ";
    print_vector(v);
}