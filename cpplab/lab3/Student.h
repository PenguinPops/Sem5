#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
using namespace std;
#include <iostream>

template<typename T>
class Student {
    private:
        string name;
        int mark;
    public:
        Student(int mark, string name) {
            this->mark = mark;
            this->name = name;
        }
        Student();
        void showMark() {
            cout << "Imie: " << name << ", ocena: " << mark << endl;
        }
};

template<>
void Student<int>::showMark() {
    cout<< "Twoja ocena to: " << mark << endl;
}

template<>
class Student<string> {
    private:
        string name;
        int mark;
    public:
        Student(int mark, string name) {
            this->mark = mark;
            this->name = name;
        }
        Student();
        void show() {
            cout << "imie: "<< name << ", ocena: " << mark << endl;
        }
        int showMark() {
            string word [6]= {"jedynka","dwojka","trojka","czworka","piatka","szostka"};
            cout << "Twoja ocena to: "<<word[mark-1]<<endl;
            return mark;
        }
};

#endif // STUDENT_H_INCLUDED