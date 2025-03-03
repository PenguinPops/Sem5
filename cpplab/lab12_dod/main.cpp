// Napisz program wykorzystujący następujący wektor krotek:
// vector< tuple<string, float, float, float, float, float, int, string> > planety
//      = { {"Merkury", 0.3825, 0.552, 0.3871, 0.2408, 58.64306, 0, "skalista"},
//          {"Wenus", 0.9489, 0.8149, 0.7233, 0.6152, 243.01875, 0, "skalista"},
//          {"Ziemia", 1.0, 1.0, 1.0, 1.0, 0.99727, 1, "skalista"},
//          {"Mars", 0.5335, 0.1074, 1.5237, 1.8808, 1.02596, 2, "skalista"},
//          {"Jowisz", 11.2092, 317.8, 5.2034, 11.8637, 0.41354, 79, "gazowa"},
//          {"Saturn", 9.494, 95.1620, 9.5371, 29.4484, 0.44400, 82, "gazowa"},
//          {"Uran", 4.0074, 14.5360, 19.1913, 84.0711, 0.71833, 27, "gazowo-lodowa"},
//          {"Neptun", 3.8827, 17.1470, 30.0690, 164.8799, 0.67125, 14, "gazowo-lodowa"} };
// (Poszczególne elementy każdej z krotek w wektorze oznaczają:
// nazwę planety, średnicę planety, masę planety, odległość od słońca, czas obiegu wokół słośca w latach, czas obrotu wokół osi w dniach, liczbę księżyców i rodzaj palnety.)
// a)
// Utwórz zwykłą funkcję show() wyświetlającą elementy krotki np.:
// cout << nazwa << "\tsrednica: " << srednica << "\tmasa: " << masa << "\todleglosc od slonca: " << odleglosc << "\tczas obiegu [lata]: " << obieg << "\tczas obrotu [dni]: " << obrot <<     "\tliczba ksiezycow: " << ksiezyce << "\trodzaj: " << rodzaj << endl;
// W funkcji main() wyświetl wszystkie elementy wektora korzystając z pętli for (...:...) dla kolekcji danych i funkcji show().
// Korzystając z algorytmu std::sort() i odpowiedniej funkcji lambda posortuj wektor planety według ich średnicy a nastepnie wyświetl ponownie elementy wektora po posortowaniu.


#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void show(string nazwa, float srednica, float masa, float odleglosc, float obieg, float obrot, int ksiezyce, string rodzaj)
{
    cout << nazwa << "\n\tsrednica: " 
        << srednica << "\n\tmasa: " 
        << masa << "\n\todleglosc od slonca: " 
        << odleglosc << "\n\tczas obiegu [lata]: " 
        << obieg << "\n\tczas obrotu [dni]: " 
        << obrot << "\n\tliczba ksiezycow: " 
        << ksiezyce << "\n\trodzaj: " 
        << rodzaj << endl;
}

void showNazwy(vector<tuple<string, float, float, float, float, float, int, string>>& planety)
{
    cout << "Planety: \n";
    for (auto& planeta : planety)
    {
        cout << get<0>(planeta) << "\t";
    }
    cout << "\n";
}

int main()
{
    vector<tuple<string, float, float, float, float, float, int, string>> planety = {
        {"Merkury", 0.3825, 0.552, 0.3871, 0.2408, 58.64306, 0, "skalista"},
        {"Wenus", 0.9489, 0.8149, 0.7233, 0.6152, 243.01875, 0, "skalista"},
        {"Ziemia", 1.0, 1.0, 1.0, 1.0, 0.99727, 1, "skalista"},
        {"Mars", 0.5335, 0.1074, 1.5237, 1.8808, 1.02596, 2, "skalista"},
        {"Jowisz", 11.2092, 317.8, 5.2034, 11.8637, 0.41354, 79, "gazowa"},
        {"Saturn", 9.494, 95.1620, 9.5371, 29.4484, 0.44400, 82, "gazowa"},
        {"Uran", 4.0074, 14.5360, 19.1913, 84.0711, 0.71833, 27, "gazowo-lodowa"},
        {"Neptun", 3.8827, 17.1470, 30.0690, 164.8799, 0.67125, 14, "gazowo-lodowa"}
    };

    for (auto& planeta : planety)
    {
        show(get<0>(planeta), get<1>(planeta), get<2>(planeta), get<3>(planeta), get<4>(planeta), get<5>(planeta), get<6>(planeta), get<7>(planeta));
    }

    showNazwy(planety);

    sort(planety.begin(), planety.end(), [](tuple<string, float, float, float, float, float, int, string>& t1, tuple<string, float, float, float, float, float, int, string>& t2) {
        return get<1>(t1) > get<1>(t2);
    });

    cout << "Po sortowaniu wg średnicy:" << endl;

    showNazwy(planety);

}            