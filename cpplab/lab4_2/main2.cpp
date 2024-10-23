#include <iostream>
#include <random>
#include <deque>

using namespace std;

int main() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist_n(1, 100); 
    uniform_int_distribution<int> dist_values(-100, 100); 

    int n = dist_n(mt); 
    deque<int> numbers;

    for(int i = 0; i < n; ++i) {
        int num = dist_values(mt);
        if (num >= 0) {
            numbers.push_front(num);
        } else {
            numbers.push_back(num);
        }
    }

    for(deque<int>::iterator it=numbers.begin();it!=numbers.end();it++){
        cout<<*it<< " ";
    }

    return 0;
}





