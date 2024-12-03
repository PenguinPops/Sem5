#include <QCoreApplication>
#include <QMap>
#include <qstring.h>
#include <iostream>
#include <algorithm>

using namespace std;

string skrocLiczbe(long liczba) {
    string wynik;
    if(liczba >= 1000000000) {
        wynik = to_string(liczba / 1000000000) + " mld";
    }
    else if(liczba >= 1000000) {
        wynik = to_string(liczba / 1000000) + " mln";
    }
    else if(liczba >= 1000) {
        wynik = to_string(liczba / 1000) + " tys.";
    }
    else {
        wynik = to_string(liczba);
    }
    return wynik;
}

class KatalogKrajow {
    private:
        QMap<QString, long> kraje;

    public:
        void dodajKrajZLudnoscia(const QString& kraj, long ludnosc) {
            kraje.insert(kraj, ludnosc);
            cout << "Dodano kraj: " << kraj.toStdString() << " (ludność: " << skrocLiczbe(ludnosc) << ")\n";
        }

        void wyswietlKrajeZLudnoscia() const {
            if(kraje.isEmpty()) {
                cout << "Katalog jest pusty.\n";
                return;
            }
            cout << "Lista krajów:\n";
            for (auto it = kraje.constBegin(); it != kraje.constEnd(); ++it) {
                cout << "- Kraj: " << it.key().toStdString()
                     << ", Ludność: " << skrocLiczbe(it.value()) << "\n";
            }
        }

        void wyswietlKraje() const {
            if(kraje.isEmpty()) {
                cout << "Katalog jest pusty.\n";
                return;
            }
            cout << "Lista krajów:\n";
            for (auto it = kraje.constBegin(); it != kraje.constEnd(); ++it) {
                cout << "- Kraj: " << it.key().toStdString() << "\n";
            }
        }

        void wyswietlZakresKrajow(long min, long max) const {
            if(kraje.isEmpty()) {
                cout << "Katalog jest pusty.\n";
                return;
            }
            cout << "Lista krajów z ludnością w zakresie " << min << " - " << max << ":\n";
            for (auto it = kraje.constBegin(); it != kraje.constEnd(); ++it) {
                if(it.value() >= min && it.value() <= max) {
                    cout << "- Kraj: " << it.key().toStdString()
                         << ", Ludność: " << skrocLiczbe(it.value()) << "\n";
                }
            }
        }

        void usunKraj(const QString& kraj) {
            auto it = kraje.find(kraj);
            if(it != kraje.end()) {
                kraje.erase(it);
                cout << "Usunięto kraj: " << kraj.toStdString() << endl;
            }
        }

        void posortujKrajeWgLudnosci(string wybor) {
            if(wybor == "rosnaco") {
                QMap<QString, long> krajePosortowane = kraje;
                QMapIterator<QString, long> i(krajePosortowane);
                i.toFront();
                cout << "Lista krajów posortowana rosnąco wg ludności:\n";
                while (i.hasNext()) {
                    i.next();
                    cout << "- Kraj: " << i.key().toStdString()
                         << ", Ludność: " << skrocLiczbe(i.value()) << "\n";
                }
            }
            else if(wybor == "malejaco") {
                QMap<QString, long> krajePosortowane = kraje;
                QMapIterator<QString, long> i(krajePosortowane);
                i.toBack();
                cout << "Lista krajów posortowana malejąco wg ludności:\n";
                while (i.hasPrevious()) {
                    i.previous();
                    cout << "- Kraj: " << i.key().toStdString()
                         << ", Ludność: " << skrocLiczbe(i.value()) << "\n";
                }
            }
            return;
        }

};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    KatalogKrajow katalog;
    katalog.dodajKrajZLudnoscia("Polska", 38000000);
    katalog.dodajKrajZLudnoscia("Niemcy", 83000000);
    katalog.dodajKrajZLudnoscia("Francja", 67000000);
    katalog.dodajKrajZLudnoscia("Włochy", 60000000);
    katalog.dodajKrajZLudnoscia("Hiszpania", 47000000);
    katalog.wyswietlKrajeZLudnoscia();
    katalog.wyswietlKraje();
    katalog.wyswietlZakresKrajow(60000000, 80000000);
    katalog.usunKraj("Włochy");
    katalog.wyswietlKrajeZLudnoscia();
    katalog.posortujKrajeWgLudnosci("rosnaco");
    katalog.posortujKrajeWgLudnosci("malejaco");
    return 0;
}