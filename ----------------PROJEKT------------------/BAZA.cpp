#include "BAZA.h"
#include <iostream>
#include <fstream>

Uzytkownik baza[MAX_USERS];
int iloscUzytkownikow = 0;

void ZapiszBaze() {
    std::ofstream plik("BAZA.txt");
    if (plik.is_open()) {
        plik << iloscUzytkownikow << "\n";
        for (int i = 0; i < iloscUzytkownikow; i++) {
            plik << baza[i].id << " " << baza[i].imie << " " << baza[i].nazwisko << "\n";
        }
        plik.close();
    }
}

void WczytajBaze() {
    std::ifstream plik("BAZA.txt");
    if (plik.is_open()) {
        if (plik >> iloscUzytkownikow) {
            for (int i = 0; i < iloscUzytkownikow; i++) {
                plik >> baza[i].id >> baza[i].imie >> baza[i].nazwisko;
            }
        }
        plik.close();
    } else {
        iloscUzytkownikow = 0;
    }
}

void DodajUzytkownika() {
    if (iloscUzytkownikow >= MAX_USERS) {
        printf("Blad: Osiagnieto maksymalny limit bazy danych!\n");
        return;
    }

    Uzytkownik nowy;
    printf("Podaj imie: ");
    std::cin >> nowy.imie;
    printf("Podaj nazwisko: ");
    std::cin >> nowy.nazwisko;

    bool istnieje = false;
    int znalezioneId = -1;

    for (int u = 0; u < iloscUzytkownikow; u++) {
        if (baza[u].imie == nowy.imie && baza[u].nazwisko == nowy.nazwisko) {
            istnieje = true;
            znalezioneId = baza[u].id;
            break;
        }
    }

    if (istnieje) {
        std::cout << "Uwaga: Uzytkownik " << nowy.imie << " " << nowy.nazwisko
                  << " juz istnieje w bazie pod ID: " << znalezioneId << "\n";
    } else {
        nowy.id = iloscUzytkownikow + 1;
        baza[iloscUzytkownikow] = nowy;
        iloscUzytkownikow++;

        ZapiszBaze();
        printf("Uzytkownik dodany pomyslnie! Przypisane ID: %d\n", nowy.id);
    }
}
