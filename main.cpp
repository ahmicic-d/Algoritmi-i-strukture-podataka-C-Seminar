#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include<windows.h> 
using namespace std;

//--------GLAVNA STRUKTURA----------
struct Sudari {
    int ident;
    string adresa;
    double latituda;
    double longituda;
    int dob;
    string vijece;
    string cpdSusjedstvo;
    string datumSudara;
    string lokacijaSudara;
    string ozbiljnostSudara;
    int ozbiljnostSudaraID;
    string datumPrijaveSudara;
    string dan;
    string spol;
    string ozljede;
    string instancaID;
    string svjetlostDana;
    string brojLokalnogIzvjestaja;
    string opisSudara;
    string stanjeCeste;
    string konturaCeste;
    string povrsinaCeste;
    string snaSusjedstvo;
    string tipOsobe;
    string vrijeme;
    string postanskiBroj;
    string tipVozila;

};
/*
void ispisDobi(const vector<Sudari>& data) {
    set<int> age;
    for (const Sudari& item : data) {
        age.insert(item.dob);
    }

    cout << "Popis dobi sudionika prometnih nesreca:\n";
    for (const int& dobi : age) {
        cout << dobi <<"  ";
    }
    cout << endl;
}*/

int ruksak_bez_dijeljenja(set<int>& vrijednosti, set<int>& tezine, int kapacitet) {

    //VEKTOR VRIJEDNOSTI
    vector<int> vrijednost(vrijednosti.begin(), vrijednosti.end());
    //VEKTOR TEZINA
    vector<int> tezina(tezine.begin(), tezine.end());
    int n = vrijednost.size();

    //2D TABLICA UNUTAR KOJE SPREMAMO REZULTATE POTPROBLEMA
    vector<vector<int>> dp(n + 1, vector<int>(kapacitet + 1, 0));

    //IZRADA TABLICE
    for (int i = 1; i <= n; ++i) {
        for (int t = 1; t <= kapacitet; ++t) {
            // AKO STAVKE MOŽE STATI U RUKSAK
            if (tezina[i - 1] <= t) {
                dp[i][t] = max(dp[i - 1][t], dp[i - 1][t - tezina[i - 1]] + vrijednost[i - 1]);
            } else {
                //AKO STAVKA NEMOŽE UCI U RUKSAK - KAPACITET PREMASEN
                dp[i][t] = dp[i - 1][t];
            }
        }
    }

    //SPREMANJE REZULTATA
    return dp[n][kapacitet];
}


//---------------------------GLAVNI PROGRAM-----------------------------------
int main()
{
    //U VEKTOR TIPA SUDARI SE SPREMAJU PODACI
    vector<Sudari> data;

    //UCITAVANJE PODATAKA
    ifstream file("Data.csv");
    if (file) {
        string line;
        getline(file, line);

        while (getline(file, line)) {
            istringstream iss(line);

            string podatak;
            Sudari sudari;
            int index = 0;
            //INDEX PREDSTAVLJA SVAKI STUPAC

            while (getline(iss, podatak, ',')) {
                switch (index) {
                    //UNOS PODATAKA U VEKTOR STRUKTURE
                    //STOI SLUZI ZA STRING-TO-INTEGER PRETVORBU
                    //STOD SLUZI ZA STRING-TO-DOUBLE PRETVORBU
                    case 0: sudari.ident = stoi(podatak.substr(1)); break;
                    case 1: sudari.adresa = podatak; break;
                    case 2: sudari.latituda = stod(podatak); break;
                    case 3: sudari.longituda = stod(podatak); break;
                    case 4: sudari.dob = stoi(podatak);break;
                    case 5: sudari.vijece = podatak; break;
                    case 6: sudari.cpdSusjedstvo = podatak; break;
                    case 7: sudari.datumSudara = podatak; break;
                    case 8: sudari.lokacijaSudara = podatak; break;
                    case 9: sudari.ozbiljnostSudara = podatak; break;
                    case 10: sudari.ozbiljnostSudaraID = stoi(podatak); break;
                    case 11: sudari.datumPrijaveSudara = podatak; break;
                    case 12: sudari.dan = podatak; break;
                    case 13: sudari.spol = podatak; break;
                    case 14: sudari.ozljede = podatak; break;
                    case 15: sudari.instancaID = podatak; break;
                    case 16: sudari.svjetlostDana = podatak; break;
                    case 17: sudari.brojLokalnogIzvjestaja = podatak; break;
                    case 18: sudari.opisSudara = podatak; break;
                    case 19: sudari.stanjeCeste = podatak; break;
                    case 20: sudari.konturaCeste = podatak; break;
                    case 21: sudari.povrsinaCeste = podatak; break;
                    case 22: sudari.snaSusjedstvo = podatak; break;
                    case 23: sudari.tipOsobe = podatak; break;
                    case 24: sudari.vrijeme = podatak; break;
                    case 25: sudari.postanskiBroj = podatak; break;
                    case 26: sudari.opisSudara = podatak; break;
                    default: break;
                }
                index++;
            }

            data.push_back(sudari);
        }
    }

    file.close();

    cout<<"Ucitavanje podataka ... ";
    Sleep(1);
    cout<<" ... ";
    Sleep(1);
    cout<<" ... ";
    Sleep(1);
    cout<<" ... ";
    Sleep(1);
    cout<<" ... "<<endl;
    Sleep(1);




    //PRETVORBA VEKTORA U SET - TEZINE VRIJEDNOSTI ZA ALGORITAM - LAKSA MANIPULACIJA ALGORITMOM
    set<int> tezine;
    for (const Sudari& tezina : data) {
        tezine.insert(tezina.dob+1);
    }

    //PRETVORBA VEKTORA U SET - VRIJEDNOSTI ZA ALGORITAM - LAKSA MANIPULACIJA ALGORITMOM
    set<int> vrijednosti;
    for (const Sudari& vrijednost : data) {
        vrijednosti.insert(vrijednost.dob);
    }


    int izbor;
    do{

            cout<<"\n\n_______________________________"<<endl;
            cout<<"1 - Ispis vrijednosti dobi stradalih osoba u prometnim nesrecama"<<endl;
            cout<<"2 - Ispis vrijednosti tezina za algoritam ruksaka bez dijeljenja"<<endl;
            cout<<"3 - Unos kapaciteta ruksaka, te izvodjenje glavnog programa"<<endl;
            cout<<"Bilo koja druga tipka - Izlaz iz programa"<<endl<<endl;
            cin>>izbor;

            switch(izbor){
                case 1:
                    cout<<"Vrijednosti: ";
                    for (const int& values : vrijednosti) {
                        cout << values<<"  ";
                    }
                    cout << endl;
                    break;
                case 2:
                    cout<<"Vrijednosti: ";
                    for (const int& weights : tezine) {
                        cout << weights<<"  ";
                    }
                    cout << endl;
                    break;
                case 3:
                    int kapacitet_naprtnjace;
                    cout<<"\nUnesite vrijednost koja ce reprezentirati kapacitet naprtnjace: ";
                    cin>>kapacitet_naprtnjace;

                    //ISPIS REZULTATA ALGORITMA RUKSAKA BEZ DIJELJENJA
                    int maksimalna_vrijednost = ruksak_bez_dijeljenja(vrijednosti, tezine, kapacitet_naprtnjace);
                    cout<<"\nIznos algoritma ruksaka bez dijeljenja: "<<maksimalna_vrijednost;
                    break;
            }
    }while(izbor == 1 || izbor == 2 || izbor == 3);




    return 0;
}



