#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void skaiciuotiBilietus() {
    ifstream inFile("bilietai.txt");
    ofstream outFile("rezultatai_bilietai.txt");

    if (!inFile) {
        cout << "Nepavyko atidaryti failo 'bilietai.txt'." << endl;
        return;
    }

    string tipas;
    double kaina;
    int kiekis;
    double bendraSuma = 0;
    int bendrasKiekis = 0;

    cout << fixed << setprecision(2);
    outFile << fixed << setprecision(2);

    cout << "Bilietu pardavimu duomenys:" << endl;
    outFile << "Bilietu pardavimu duomenys:" << endl;

    while (inFile >> tipas >> kaina >> kiekis) {
        double suma = kaina * kiekis;
        bendraSuma += suma;
        bendrasKiekis += kiekis;

        cout << tipas << " bilietai: "
             << kiekis << " vnt, "
             << "kaina: " << kaina << " EUR, "
             << "suma: " << suma << " EUR" << endl;

        outFile << tipas << " bilietai: "
                << kiekis << " vnt, "
                << "kaina: " << kaina << " EUR, "
                << "suma: " << suma << " EUR" << endl;
    }

    cout << "Bendras parduotu bilietu kiekis: " << bendrasKiekis << endl;
    cout << "Bendra pardavimu suma: " << bendraSuma << " EUR" << endl;

    outFile << "Bendras parduotu bilietu kiekis: " << bendrasKiekis << endl;
    outFile << "Bendra pardavimu suma: " << bendraSuma << " EUR" << endl;

    inFile.close();
    outFile.close();
}

void atnaujintiAtlyginimus() {
    ifstream inFile("salary.txt");
    ofstream outFile("newSalary.txt");

    if (!inFile) {
        cout << "Nepavyko atidaryti failo 'salary.txt'." << endl;
        return;
    }

    string pavarde, vardas;
    double atlyginimas, procentas;

    cout << fixed << setprecision(2);
    outFile << fixed << setprecision(2);

    cout << "Atnaujinti atlyginimai:" << endl;

    while (inFile >> pavarde >> vardas >> atlyginimas >> procentas) {
        double naujas = atlyginimas + (atlyginimas * procentas / 100);
        cout << pavarde << " " << vardas << " " << naujas << endl;
        outFile << pavarde << " " << vardas << " " << naujas << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    int pasirinkimas;

    do {
        cout << " 1 - Skaiciuoti bilietu pardavimus" << endl;
        cout << " 2 - Atnaujinti darbuotoju atlyginimus" << endl;
        cout << " 0 - Baigti programa" << endl;
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                skaiciuotiBilietus();
                break;
            case 2:
                atnaujintiAtlyginimus();
                break;
            case 0:
                cout << "Programa baigta." << endl;
                break;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        }
    } while (pasirinkimas != 0);

    return 0;
}
