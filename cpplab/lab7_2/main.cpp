#include <QCoreApplication>
#include <QSet>
#include <qstring.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool czyPangram(const QString& tekst) {
    // Zbiór na litery alfabetu (a-z)
    QSet<QChar> alfabet;
    // Iteracja przez znaki w tekście
    for (QChar znak : tekst.toLower()) {
        // Sprawdź, czy znak jest literą
        if (znak.isLetter()) {
            alfabet.insert(znak); // Dodaj literę do zbioru
        }
    }
    // Jeśli rozmiar zbioru to 26, oznacza to, że zawiera wszystkie litery alfabetu
    return alfabet.size() == 26;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QString tekst = "The quick brown fox jumps over the lazy dog";
    cout << tekst.toStdString() << endl;
    cout << "Czy tekst jest pangramem? " << (czyPangram(tekst) ? "Tak" : "Nie") << endl;
    tekst = "The quick brown fox jumps over the hazy dog";
    cout << tekst.toStdString() << endl;
    cout << "Czy tekst jest pangramem? " << (czyPangram(tekst) ? "Tak" : "Nie") << endl;
    return 0;
}