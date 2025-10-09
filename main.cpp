#include <iostream>
#include <string>
using namespace std;

int main() {
    double GBP_Bendras = 0.8729, GBP_Pirkti = 0.86, GBP_Parduoti = 0.922;
    double USD_Bendras = 1.1793, USD_Pirkti = 1.146, USD_Parduoti = 1.234;
    double INR_Bendras = 104.6918, INR_Pirkti = 101.3862, INR_Parduoti = 107.8546;

    int pasirinkimas;
    string valiuta;
    double kiekis, rezultatas;

    while (true) {
        cout << "Pasirinkite veiksma:" << endl;
        cout << "0 - nutraukti programa" << endl;
        cout << "1 - Palyginti valiutos kursa" << endl;
        cout << "2 - Pirkti valiuta (EUR -> valiuta)" << endl;
        cout << "3 - Parduoti valiuta (EUR -> valiuta)" << endl;
        cout << "Iveskite savo pasirinkima: ";
        cin >> pasirinkimas;
        cout << endl;

        if (pasirinkimas == 0) {
            cout << "Viso gero!" << endl;
            break;
        }

        cout << "Iveskite valiuta (EUR, GBP, USD, INR): ";
        cin >> valiuta;

        if (pasirinkimas == 2 || pasirinkimas == 3) {
            cout << "Iveskite kieki EUR: ";
            cin >> kiekis;
        }

        // 1 - palyginti kursa
        if (pasirinkimas == 1) {
            if (valiuta == "GBP") cout << "1 EUR = " << GBP_Bendras << " GBP" << endl;
            else if (valiuta == "USD") cout << "1 EUR = " << USD_Bendras << " USD" << endl;
            else if (valiuta == "INR") cout << "1 EUR = " << INR_Bendras << " INR" << endl;
            else if (valiuta == "EUR") cout << "1 EUR = 1 EUR" << endl;
            else cout << "Netinkama valiuta" << endl;
        }

        // 2 - pirkti valiuta
        else if (pasirinkimas == 2) {
            if (valiuta == "GBP") rezultatas = kiekis * GBP_Pirkti;
            else if (valiuta == "USD") rezultatas = kiekis * USD_Pirkti;
            else if (valiuta == "INR") rezultatas = kiekis * INR_Pirkti;
            else if (valiuta == "EUR") rezultatas = kiekis;
            else { cout << "Netinkama valiuta" << endl; continue; }

            cout << "Uz " << kiekis << " EUR gausite " << rezultatas << " " << valiuta << endl;
        }

        // 3 - parduoti valiuta
        else if (pasirinkimas == 3) {
            if (valiuta == "GBP") rezultatas = kiekis * GBP_Parduoti;
            else if (valiuta == "USD") rezultatas = kiekis * USD_Parduoti;
            else if (valiuta == "INR") rezultatas = kiekis * INR_Parduoti;
            else if (valiuta == "EUR") rezultatas = kiekis;
            else { cout << "Netinkama valiuta" << endl; continue; }

            cout << "Uz " << kiekis << " EUR gausite " << rezultatas << " " << valiuta << endl;
        }

        cout << endl;
    }

    return 0;
}
