// Zdefiniuj wyrażenia regularne pozwalające na sprawdzenie:
//  ulicy (nazwa może składać się tylko z liter alfabetu łacińskiego i pierwsza litera jest
// dużą literą, a pozostałe liter są małe);
//  kodu pocztowego (w formacie XX-XXX, gdzie X to cyfra);
//  numeru domu (liczba lub liczba i litera, np. 28, 28B);
//  numer mieszkania
// W funkcji main należy przetestować stworzone wyrażenia regularne.

#include <iostream>
#include <regex>
#include <vector>
using namespace std;

int main() {
    string line;
    cout << "Podaj łańcuch znaków: ";
    getline(cin, line);

    vector<tuple<string, string, regex>> patterns = {
        {"nazwa ulicy", "nazwy ulicy", regex("\\b[A-Z][a-z]+(?: [A-Z][a-z]+)*\\b")},
        {"kod pocztowy", "kodu pocztowego", regex("\\b[0-9]{2}-[0-9]{3}\\b")},
        {"numer domu", "numeru domu", regex("\\b[0-9]+[A-Z]?\\b")},
        {"numer mieszkania", "numeru mieszkania", regex("\\b[0-9]+[A-Z]?\\d+\\b")}
    };

    for (const auto& element : patterns) {
        string descTrue = get<0>(element);
        string descFalse = get<1>(element);
        regex pattern = get<2>(element);
        if (regex_search(line, pattern)) {
            cout << "Znaleziono " << descTrue << ".\n";
        } else {
            cout << "Nie znaleziono " << descFalse << ".\n";
        }
    }

    return 0;
}
