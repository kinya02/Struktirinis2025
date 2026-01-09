#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

const int klausimuKiekis = 20;
const double maxTasku = 40.0;

char teisingiAts[klausimuKiekis];

struct strukturaStudento {
    string id;
    char atsakymai[klausimuKiekis];
    int taskai;
    double procentas;
    int pazymys;
};

// procentai -> pazymys (pagal uzduoti)
int priskirtiPazymi(double procentas) {
    if (procentas >= 95) return 10;
    if (procentas >= 85) return 9;
    if (procentas >= 75) return 8;
    if (procentas >= 65) return 7;
    if (procentas >= 55) return 6;
    if (procentas >= 50) return 5;  //teigiamas nuo 50%
    if (procentas >= 35) return 4;
    if (procentas >= 25) return 3;
    if (procentas >= 15) return 2;
    return 1;
}

// duomenu nuskaitymas is testData.txt
void duomenysIsFailo(vector<strukturaStudento>& studentai) {
    ifstream infile("testData.txt");
    if (!infile) {
        cout << "Nepavyko atidaryti failo testData.txt\n";
        return;
    }

    // 1 eilute: teisingi atsakymai
    for (int i = 0; i < klausimuKiekis; i++) {
        infile >> teisingiAts[i];
        if (teisingiAts[i] == 't') teisingiAts[i] = 'T';
        if (teisingiAts[i] == 'f') teisingiAts[i] = 'F';
    }

    // kitos eilutes: studentai
    strukturaStudento s;
    while (infile >> s.id) {
        // studento atsakymai
        for (int i = 0; i < klausimuKiekis; i++) {
            char c;
            infile >> c;

            if (c == 'T' || c == 't') s.atsakymai[i] = 'T';
            else if (c == 'F' || c == 'f') s.atsakymai[i] = 'F';
            else s.atsakymai[i] = '-';
        }

        // tasku skaiciavimas
        s.taskai = 0;
        for (int i = 0; i < klausimuKiekis; i++) {
            if (s.atsakymai[i] == '-') {
                // 0
            } else if (s.atsakymai[i] == teisingiAts[i]) {
                s.taskai += 2;
            } else {
                s.taskai -= 1;
            }
        }

        // procentai
        s.procentas = (s.taskai / maxTasku) * 100.0;
        if (s.procentas < 0) s.procentas = 0;

        // pazymys
        s.pazymys = priskirtiPazymi(s.procentas);

        studentai.push_back(s);
    }

    infile.close();
}

// isvedimas i faila results.txt (tas pats formatas)
void saugojimas(const vector<strukturaStudento>& studentai) {
    ofstream out("results.txt");
    if (!out) {
        cout << "Nepavyko sukurti results.txt\n";
        return;
    }

    out << "ID\tTaskai\tProcent\tPazymys\n";
    for (const auto& s : studentai) {
        out << s.id << "\t"
            << s.taskai << "\t"
            << fixed << setprecision(2) << s.procentas << "%\t"
            << s.pazymys << "\n";
    }

    out.close();
}
3
void klasesStatistika(const vector<strukturaStudento>& studentai) {
    if (studentai.empty()) {
        cout << "Nera studentu.\n\n";
        return;
    }

    int studentuSk = (int)studentai.size();
    int maxTaskai = studentai[0].taskai;
    int minTaskai = studentai[0].taskai;

    double sumTaskai = 0;
    double sumProc = 0;
    int pazymiuPasiskirstymas[11] = {0}; // 1..10

    for (const auto& s : studentai) {
        if (s.taskai > maxTaskai) maxTaskai = s.taskai;
        if (s.taskai < minTaskai) minTaskai = s.taskai;

        sumTaskai += s.taskai;
        sumProc += s.procentas;

        pazymiuPasiskirstymas[s.pazymys]++;
    }

    double vidTaskai = sumTaskai / studentuSk;
    double vidProc = sumProc / studentuSk;

    cout << "Studentu skaicius: " << studentuSk << endl;
    cout << "Didziausias balas: " << maxTaskai << endl;
    cout << "Maziausias balas: " << minTaskai << endl;
    cout << "Vidutinis balas: " << fixed << setprecision(2) << vidTaskai << endl;
    cout << "Vidutinis procentas: " << fixed << setprecision(2) << vidProc << "%" << endl << endl;

    cout << "Pazymiu pasiskirstymas:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << ": " << pazymiuPasiskirstymas[i];
        if (i != 10) cout << " | ";
    }
    cout << endl << endl;
}

void studentoPaieska(const vector<strukturaStudento>& studentai) {
    string ID;

    while (true) {
        cout << "Iveskite studento ID\n0: nutraukti paieska: " << endl;
        cin >> ID;

        if (ID == "0") break;

        bool rastas = false;
        for (const auto& s : studentai) {
            if (s.id == ID) {
                cout << "ID\tTaskai\tProcent\tPazymys" << endl;
                cout << s.id << "\t" << s.taskai << "\t"
                     << fixed << setprecision(2) << s.procentas << "%\t"
                     << s.pazymys << endl << endl;
                rastas = true;
                break;
            }
        }

        if (!rastas) {
            cout << "Studentas su ID '" << ID << "' nerastas." << endl << endl;
        }
    }
}

void klausimuStatistika(const vector<strukturaStudento>& studentai) {
    int teisingi[klausimuKiekis] = {0};
    int neteisingi[klausimuKiekis] = {0};
    int neatsakyti[klausimuKiekis] = {0};

    for (const auto& s : studentai) {
        for (int i = 0; i < klausimuKiekis; i++) {
            if (s.atsakymai[i] == '-') neatsakyti[i]++;
            else if (s.atsakymai[i] == teisingiAts[i]) teisingi[i]++;
            else neteisingi[i]++;
        }
    }

    cout << "Kl:\tT:\tF:\t-:" << endl;
    for (int i = 0; i < klausimuKiekis; i++) {
        cout << (i + 1) << "\t"
             << teisingi[i] << "\t"
             << neteisingi[i] << "\t"
             << neatsakyti[i] << endl << endl;
    }
}

void sunkiausiasKlausimas(const vector<strukturaStudento>& studentai) {
    if (studentai.empty()) {
        cout << "Nera studentu.\n\n";
        return;
    }

    int teisingi[klausimuKiekis] = {0};

    for (const auto& s : studentai) {
        for (int i = 0; i < klausimuKiekis; i++) {
            if (s.atsakymai[i] != '-' && s.atsakymai[i] == teisingiAts[i]) {
                teisingi[i]++;
            }
        }
    }

    double minProcentas = 101.0;
    vector<int> sunkiausi;

    for (int i = 0; i < klausimuKiekis; i++) {
        double p = (double)teisingi[i] / studentai.size() * 100.0;

        if (p < minProcentas) {
            minProcentas = p;
            sunkiausi.clear();
            sunkiausi.push_back(i + 1);
        } else if (p == minProcentas) {
            sunkiausi.push_back(i + 1);
        }
    }

    cout << "Klausimas: ";
    for (int nr : sunkiausi) cout << nr << " ";
    cout << "Teisingai atsake: " << fixed << setprecision(2) << minProcentas << "%" << endl << endl;
}

int main() {
    vector<strukturaStudento> studentas;
    duomenysIsFailo(studentas);

    bool veikimas = true;
    int pasirinkimas;

    while (veikimas == true) {
        cout << "Pasirinkite funkcija:\n"
             << "0: Nutraukti programa\n"
             << "1: Klases statistika\n"
             << "2: Studento paieska pagal ID\n"
             << "3: Rezultatu issaugojimas i faila\n"
             << "4: Kiekvieno klausimo statistika\n"
             << "5: Sunkiausio klausimo nustatymas" << endl;

        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 0: veikimas = false; break;
            case 1: klasesStatistika(studentas); break;
            case 2: studentoPaieska(studentas); break;
            case 3: saugojimas(studentas); break;
            case 4: klausimuStatistika(studentas); break;
            case 5: sunkiausiasKlausimas(studentas); break;
        }
    }

    return 0;
}
