// Zadanie 3
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class GrupaDziekanska {
private:
    map<string, int> grupa;

public:
    void dodajStudenta(const string& email, int indeks) {
        grupa[email] = indeks;
    }

    // alternatywa dla dodajStudenta ale bez const i używając this->

    // void dodajStudenta(string email, int indeks) {
    //      this->grupa[email] = indeks;
    // }


    void wyswietlGrupe() const {
        for (const auto& [email, indeks] : grupa) {
            cout << "Email: " << email << ", Indeks: " << indeks << endl;
        }
    }
    // for ocena in oceny
    // odpowiednik w c++:
    // for (const auto& ocena : oceny) {
    //     cout<<ocena<<endl;
    // }

    void findKlucz(const string& email) const {
        auto it = grupa.find(email);
        //odpowiednik w pętli for
        // funkcja znajdz() {
        //     for(find email in grupa) {
        //         if(found) {
        //             return indeks
        //         }
        //     }
        //     return indeks
        // }
        if (it != grupa.end()) {
            cout << "Znaleziono: Email: " << it->first << ", Indeks: " << it->second << endl;
        } else {
            cout << "Nie znaleziono klucza." << endl;
        }
    }

    void szukajWartosc(int indeks) const {
        vector<string> wyniki;
        for (const auto& [email, id] : grupa) {
            if (id == indeks) {
                wyniki.push_back(email);
            }
        }

        if (!wyniki.empty()) {
            cout << "Znaleziono adresy o indeksie " << indeks << ":\n";
            for (const auto& email : wyniki) {
                cout << email << endl;
            }
        } else {
            cout << "Nie znaleziono adresów o podanym indeksie." << endl;
        }
    }
};

int main() {
    GrupaDziekanska grupa;

    grupa.dodajStudenta("anna.nowak@gmail.com", 1100);
    grupa.dodajStudenta("s54321@pollub.edu.pl", 1101);
    grupa.dodajStudenta("s99999@pollub.edu.pl", 1100);
    grupa.dodajStudenta("s12345@pollub.edu.pl", 1001);
    grupa.dodajStudenta("s55555@pollub.edu.pl", 1002);
    grupa.dodajStudenta("jan.kowalski@gmail.com", 1010);
    grupa.dodajStudenta("s11111@pollub.edu.pl", 1010);

    cout << "Wszyscy członkowie grupy dziekańskiej:" << endl;
    grupa.wyswietlGrupe();

    cout << "\nWyszukiwanie adresu jan.kowalski@gmail.com:" << endl;
    grupa.findKlucz("jan.kowalski@gmail.com");

    cout << "\nWyszukiwanie wszystkich elementów o numerze indeksu 1100:" << endl;
    grupa.szukajWartosc(1100);

    return 0;
}