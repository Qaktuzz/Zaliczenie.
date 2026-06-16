#pragma once
#include <string>

#define MAX_USERS 100

struct Uzytkownik {
    int id;
    std::string imie;
    std::string nazwisko;
};

extern Uzytkownik baza[MAX_USERS];
extern int iloscUzytkownikow;

void ZapiszBaze();
void WczytajBaze();
void DodajUzytkownika();