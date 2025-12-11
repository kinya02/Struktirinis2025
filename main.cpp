#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct menuItemType {
    string name;
    double price;
};

int main() {

    menuItemType menu[20]; //sukuriame masyva is 20 elementu, kur kiekvienas elementas yra struktura su name ir price
    int count = 0;
    int qty[20] = {0};

    ifstream fin("menu.txt");

    if (!fin.is_open()) { //jeigu failas neatidarytas
        cout << "Nepavyko atidaryti menu failo\n";
        return 0;
    }


    while (fin >> menu[count].name >> menu[count].price) { //fin - skaityk
        count++;
    }

    fin.close();

    // Parodome meniu
    cout << "Sveiki atvyke i restorana Kinga!\n\n";
    cout << "Pusryciu meniu:\n";

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". "
             << menu[i].name << " - "
             << fixed << setprecision(2)
             << menu[i].price << " EUR\n";
    }

    // Pasirinkimai
    while (true) {

        int choice;
        cout << "\nPasirinkite patiekalo numeri (0 - baigti): ";
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Neteisingas ivestis! Bandykite dar karta.\n";
            continue;
        }

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > count) {
            cout << "Tokio patiekalo nera!\n";
            continue;
        }

        int porsijos;
        cout << "Kiek porciju norite: ";
        cin >> porsijos;

        if (!cin || porsijos < 1) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Neteisingas porciju kiekis!\n";
            continue;
        }

        qty[choice - 1] += porsijos;
        cout << "Prideta!\n";
    }

    // Skaiciavimai
    double suma = 0;

    ofstream fout("receipt.txt");

    cout << "\nJusu uzsakymas:\n\n";
    fout << "Jusu uzsakymas:\n\n";

    for (int i = 0; i < count; i++) {
        if (qty[i] > 0) {

            double tarpine = qty[i] * menu[i].price;
            suma += tarpine;

            cout << qty[i] << " x " << menu[i].name
                 << " = " << fixed << setprecision(2)
                 << tarpine << " EUR\n";

            fout << qty[i] << " x " << menu[i].name
                 << " = " << fixed << setprecision(2)
                 << tarpine << " EUR\n";
        }
    }

    double pvm = suma * 0.21;
    double galutine = suma + pvm;

    cout << "\nMokesciai (21%): " << fixed << setprecision(2) << pvm << " EUR\n";
    cout << "Galutine suma: " << galutine << " EUR\n";

    fout << "\nMokesciai (21%): " << pvm << " EUR\n";
    fout << "Galutine suma: " << galutine << " EUR\n";

    fout.close();

    cout << "\nSaskaita irasyta i receipt.txt\n";

    return 0;
}
