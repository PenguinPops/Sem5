#include <QCoreApplication>
#include <QString>
#include <QSet>
#include <iostream>

// Funkcja sprawdzająca, czy napis jest pangramem
bool isPangram(const QString &text) {
    QSet<QChar> letters; // Zbiór unikalnych liter

    // Iteracja po wszystkich znakach w napisie
    for (const QChar &ch : text) {
        if (ch.isLetter()) { // Sprawdzenie, czy znak jest literą
            letters.insert(ch.toLower()); // Dodanie litery w formacie małych liter
        }
    }

    // liczba liter alfabetu
    return letters.size() == 26;
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    std::cout << "Podaj napis do sprawdzenia: ";
    std::string input;
    std::getline(std::cin, input); // Wczytanie całego wiersza z konsoli

    // Sprawdzenie, czy napis jest pangramem
    if (isPangram(QString::fromStdString(input))) {
        std::cout << "Podany napis jest pangramem.\n";
    } else {
        std::cout << "Podany napis nie jest pangramem.\n";
    }

    return 0;
}
