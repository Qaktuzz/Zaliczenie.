#include "FILM.h"
#include "BAZA.h"
#include <iostream>

void ZapisDoPliku(const char* filename, int cinema[RZAD][KOLUMNA]) {
    FILE *fptr = fopen(filename, "w");
    if (fptr != NULL) {
        for (int i = 0; i < RZAD; i++) {
            for (int j = 0; j < KOLUMNA; j++) {
                fprintf(fptr, "%d ", cinema[i][j]);
            }
            fprintf(fptr, "\n");
        }
        fclose(fptr);
    }
}

void OdczytzPliku(const char* filename, int cinema[RZAD][KOLUMNA]) {
    FILE *fptr = fopen(filename, "r");
    if (fptr != NULL) {
        for (int i = 0; i < RZAD; i++) {
            for (int j = 0; j < KOLUMNA; j++) {
                fscanf(fptr, "%d", &cinema[i][j]);
            }
        }
        fclose(fptr);
        printf("Dane sali [%s] zostaly wczytane!\n", filename);
    } else {
        for (int i = 0; i < RZAD; i++) {
            for (int j = 0; j < KOLUMNA; j++) cinema[i][j] = 0;
        }
        ZapisDoPliku(filename, cinema);
        printf("Utworzono nowy plik sali [%s] z wolnymi miejscami!\n", filename);
    }
}

void WyswietlSale(int cinema[RZAD][KOLUMNA]) {
    printf("KOLUMNA     ");
    for (int j = 0; j < KOLUMNA; j++) {
        if (j < 10) printf("[%d] ", j);
        else        printf("[%d]", j);
    }
    printf("\n");

    printf("\nRZAD\n");

    for (int i = 0; i < RZAD; i++) {
        if (i < 10) printf("  [%d]       ", i);
        else        printf(" [%d]       ", i);

        for (int j = 0; j < KOLUMNA; j++) {
            printf("|%-3d", cinema[i][j]);
        }
        printf("|\n");
    }
}

void ZarezerwujMiejsce(const char* filename, int cinema[RZAD][KOLUMNA]) {
    if (iloscUzytkownikow == 0) {
        printf("Baza uzytkownikow jest pusta.\n");
        return;
    }

    int rzad, kolumna, wybraneId;

    printf("\n--- DOSTEPNI UZYTKOWNICY W BAZIE ---\n");
    for (int u = 0; u < iloscUzytkownikow; u++) {
        std::cout << "ID: " << baza[u].id << " -> " << baza[u].imie << " " << baza[u].nazwisko << "\n";
    }

    printf("Wpisz ID uzytkownika, ktory rezerwuje miejsce: ");
    scanf("%d", &wybraneId);

    bool istnieje = false;
    for (int u = 0; u < iloscUzytkownikow; u++) {
        if (baza[u].id == wybraneId) istnieje = true;
    }
    if (!istnieje) {
        printf("Blad: Nie ma uzytkownika o takim ID w bazie danych!\n");
        return;
    }

    printf("Podaj numer KOLUMNY (0-%d): ", KOLUMNA -1);
    scanf("%d", &kolumna);
    printf("Podaj numer RZEDU (0-%d): ", RZAD - 1);
    scanf("%d", &rzad);
    rzad = rzad - 1;
    kolumna = kolumna - 1;

    if (rzad < 0 or rzad >= RZAD or kolumna < 0 or kolumna >= KOLUMNA) {
        printf("Blad: Niepoprawny numer kolumny lub rzedu!\n");
        return;
    }

    if (cinema[rzad][kolumna] == 0) {
        cinema[rzad][kolumna] = wybraneId;
        ZapisDoPliku(filename, cinema);
        printf("Miejsce zostalo zarezerwowane dla ID %d i zapisane.\n", wybraneId);
    } else {
        printf("To miejsce jest juz zajete przez uzytkownika o ID %d!\n", cinema[rzad][kolumna]);
    }
}

void PokazStatystyki(const char* filename, int cinema[RZAD][KOLUMNA]) {
    int zajete = 0;
    for (int i = 0; i < RZAD; i++) {
        for (int j = 0; j < KOLUMNA; j++) {
            if (cinema[i][j] != 0) zajete++;
        }
    }
    int wszystkie = RZAD * KOLUMNA;
    printf("\n---STATYSTYKI MIEJSC z filmu (%s)---\n", filename);
    printf("Miejsca WOLNE (0): %d\n", wszystkie - zajete);
    printf("Miejsca ZAJETE: %d\n", zajete);
    printf("Ilosc wszystkich miejsc: %d\n", wszystkie);
}
