#include <QCoreApplication>
#include <QList>
#include <qstring.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct Samochod {
    QString marka;
    QString model;
    int rokProdukcji;
    QString numerVIN;

    Samochod(const QString& m, const QString& mod, int rok, const QString& vin) : marka(m), model(mod), rokProdukcji(rok), numerVIN(vin) {}
};

class KatalogSamochodow {
    private:
        QList<Samochod> samochody;
    
    public:
        void dodajSamochod(const QString& marka, const QString& model, int rok, const QString& vin) {
            samochody.append(Samochod(marka, model, rok, vin));
            cout << "Dodano samochód: " << marka.toStdString() << " " << model.toStdString() << " (VIN: " << vin.toStdString() << ")\n";
        }

        void wyswietlSamochody() const {
            if(samochody.isEmpty()) {
                cout << "Katalog jest pusty.\n";
                return;
            }
            cout<<"Lista samochodów:"<<endl;
            for (const auto& s : samochody) {
                        cout << "- Marka: " << s.marka.toStdString()
                                << ", Model: " << s.model.toStdString()
                                << ", Rok: " << s.rokProdukcji
                                << ", VIN: " << s.numerVIN.toStdString() << "\n";
            }
        }

        int policzStarszeNiz(int rok) const {
            int count = 0;
            for (const auto& s : samochody) {
                if(s.rokProdukcji < rok) {
                    count++;
                }
            }
            return count;
        }

        void usunSamochod(const QString& vin) {
            auto it = remove_if(samochody.begin(), samochody.end(), [&](const Samochod& s) {
                return s.numerVIN == vin;
            });

            if(it != samochody.end()) {
                samochody.erase(it, samochody.end());
                cout << "Usunięto samochód o VIN: " << vin.toStdString() << endl;
            }
            else {
                cout << "Nie znaleziono takiego samochodu" << endl;
            }
        }

        void wyswietlMalejacoRok() {
            QList<Samochod> sorted = samochody;
            sort(sorted.begin(), sorted.end(), [](const Samochod& a, const Samochod& b) {
                return a.rokProdukcji > b.rokProdukcji;
            });
            cout << "Samochody malejąco względem roku produkcji: "<<endl;
            for(const auto& s : sorted) {
                cout << "- " << s.marka.toStdString() << " " << s.model.toStdString()
                      << " (" << s.rokProdukcji << ")\n";
            }
        }

        void wyswietlRosnacoMarka() {
            QList<Samochod> sorted = samochody;
            sort(sorted.begin(), sorted.end(), [](const Samochod& a, const Samochod& b) {
                return a.marka < b.marka;
            });
            cout << "Samochody rosnąco względem marki:\n";
            for (const auto& s : sorted) {
                cout << "- " << s.marka.toStdString() << " " << s.model.toStdString()
                      << " (" << s.rokProdukcji << ")\n";
            }
        }
};

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    KatalogSamochodow katalog;

    // Dodanie kilku samochodów do katalogu
    katalog.dodajSamochod("Toyota", "Corolla", 2015, "VIN123456");
    katalog.dodajSamochod("Ford", "Focus", 2018, "VIN654321");
    katalog.dodajSamochod("BMW", "X5", 2010, "VIN111111");
    katalog.dodajSamochod("Audi", "A4", 2020, "VIN222222");

    // Wyświetlenie wszystkich samochodów
    katalog.wyswietlSamochody();

    // Liczenie samochodów starszych niż 2016
    int starsze = katalog.policzStarszeNiz(2016);
    std::cout << "Liczba samochodów starszych niż 2016: " << starsze << "\n";

    // Usunięcie samochodu o danym VIN
    katalog.usunSamochod("VIN123456");

    // Wyświetlenie samochodów w kolejności malejącej względem roku produkcji
    katalog.wyswietlMalejacoRok();

    // Wyświetlenie samochodów w kolejności rosnącej względem marki
    katalog.wyswietlRosnacoMarka();

    return 0;
}