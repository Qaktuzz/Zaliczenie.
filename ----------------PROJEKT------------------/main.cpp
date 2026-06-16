#include <iostream>
#include "FILM.h"
#include "BAZA.h"

int main() {
    int cinema[RZAD][KOLUMNA];
    char filename[100];
    int option;

    WczytajBaze();

    printf("Podaj nazwe filmu (Prosimy nie uzywac spacji): ");
    scanf("%s", filename);
    OdczytzPliku(filename, cinema);

    do {
        printf("\n--System rezerwacji miejsc w kinie--\n");
        printf("Aktualna sala filmu: %s\n", filename);
        printf("1. Wyswietl sale kinowa\n");
        printf("2. Wybierz i zarezerwuj miejsce dla uzytkownika\n");
        printf("3. Sprawdz liczbe miejsc (Statystyki)\n");
        printf("4. Zmien sale kinowa\n");
        printf("5. Dodaj nowego uzytkownika do bazy\n");
        printf("0. Wyjscie\n");
        printf("LEGENDA: 0 - WOLNE, INNA CYFRA - ID UZYTKOWNIKA\n");
        printf("Wybor:");
        scanf("%d", &option);

        switch (option) {
            case 1:
                WyswietlSale(cinema);
                break;

            case 2:
                ZarezerwujMiejsce(filename, cinema);
                break;

            case 3:
                PokazStatystyki(filename, cinema);
                break;

            case 4:
                printf("Podaj nazwe pliku nowego filmu: ");
                scanf("%s", filename);
                OdczytzPliku(filename, cinema);
                break;

            case 5:
                DodajUzytkownika();
                break;

            case 0:
                printf("Koniec programu.\n");
                break;

            default:
                printf("Wybierz opcje sposrod menu!\n");
                break;
        }
    } while (option != 0);
    return 0;
}