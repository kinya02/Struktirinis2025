#include <iostream>
#include <string>
using namespace std;

string Vardas[100];
int pazimiai[100][10];
int mokKiekis = 0;

int main() {
    int pasirinkimas;
    bool veiksmas = true;

    while (veiksmas) {
        cout << "Mokiniu pazymiu sistema" << endl;
        cout << "1 Ivesti mokinius ir ju pazymius" << endl;
        cout << "2 Perziureti visu mokiniu pazymius" << endl;
        cout << "3 Atnaujinti pazymi (pagal varda)" << endl;
        cout << "4 Pasalinti mokini (pagal varda)" << endl;
        cout << "0 Baigti darba" << endl;
        cout << "Pasirinkite: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {

        //prideti mok
        case 1: {
            int n;
            cout << "Kiek mokiniu norite ivesti? ";
            cin >> n;
            if (n <= 0 || n > 100) {
                cout << "Klaida! Netinkamas skaicius." << endl;
                break; //grisi i meniu
            }

            for (int i = 0; i < n; i++) {
                cout << "Iveskite " << i + 1 << " mokinio varda: ";
                cin >> Vardas[mokKiekis];
                cout << "Iveskite 10 pazymiu (nuo 1 iki 10):" << endl;
                bool klaida = false;
                for (int j = 0; j < 10; j++) {
                    cin >> pazimiai[mokKiekis][j];
                    if (pazimiai[mokKiekis][j] < 1 || pazimiai[mokKiekis][j] > 10) {
                        cout << "Klaida! Pazymys turi buti nuo 1 iki 10!" << endl;
                        klaida = true;
                        break;
                    }
                }
                if (klaida) break; //jeigu buvo klaida, ne papildis
                mokKiekis++;
            }
            break;
        }

        //sarasas
        case 2: {
            if (mokKiekis == 0) {
                cout << "Dar nera ivestu mokiniu!" << endl;
                break;
            }

            cout << "Mokiniu sarasas" << endl;
            for (int i = 0; i < mokKiekis; i++) {
                cout << Vardas[i] << " | Pazymiai: ";
                for (int j = 0; j < 10; j++) {
                    cout << pazimiai[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }

        //pakeisti pazymi
        case 3: {
            if (mokKiekis == 0) {
                cout << "Sistemoje nera mokiniu!" << endl;
                break;
            }

            string vardas;
            cout << "Iveskite mokinio varda, kurio pazymi norite pakeisti: ";
            cin >> vardas;

            bool rastas = false;
            for (int i = 0; i < mokKiekis; i++) {
                if (Vardas[i] == vardas) {
                    rastas = true;
                    cout << "Mokinys rastas: " << vardas[i] << endl;
                    cout << "Jo pazymiai: ";
                    for (int j = 0; j < 10; j++) {
                        cout << pazimiai[i][j] << " ";
                    }
                    cout << endl;

                    int numer, naujaOcena;
                    cout << "Kuria pazymi norite pakeisti? (1-10): ";
                    cin >> numer;
                    if (numer < 1 || numer > 10) {
                        cout << "Klaida! Netinkamas numeris!" << endl;
                        break;
                    }

                    cout << "Iveskite nauja pazymi: ";
                    cin >> naujaOcena;
                    if (naujaOcena < 1 || naujaOcena > 10) {
                        cout << "Klaida! Pazymys turi buti nuo 1 iki 10!" << endl;
                        break;
                    }

                    pazimiai[i][numer - 1] = naujaOcena;
                    cout << "Pazymys pakeistas sekmingai!" << endl;
                }
            }
            if (!rastas) {
                cout << "Klaida! Mokinio su tokiu vardu nera." << endl;
            }
            break;
        }

        //pasalinti mokini
        case 4: {
            if (mokKiekis == 0) {
                cout << "Sistemoje nera mokiniu!" << endl;
                break;
            }

            string vardas;
            cout << "Iveskite mokinio varda, kuri norite pasalinti: ";
            cin >> vardas;

            bool rastas = false;
            for (int i = 0; i < mokKiekis; i++) {
                if (Vardas[i] == vardas) {
                    rastas = true;
                    cout << "Mokinys " << vardas[i] << " buvo pasalintas!" << endl;
                    for (int k = i; k < mokKiekis - 1; k++) {
                        vardas[k] = vardas[k + 1];
                        for (int j = 0; j < 10; j++) {
                            pazimiai[k][j] = pazimiai[k + 1][j];
                        }
                    }
                    mokKiekis--;
                    break;
                }
            }
            if (!rastas) {
                cout << "Klaida! Toks mokinys nerastas." << endl;
            }
            break;
        }

        //programa baigta
        case 0:
            veiksmas = false;
            cout << "Programa baigta!" << endl;
            break;
        default:
            cout << "Klaida! Tokio pasirinkimo nera." << endl;
        }
    }
    return 0;
}
