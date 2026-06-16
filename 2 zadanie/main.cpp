#include <iostream>
#include <cstdio>


int dodaj(int *a, int *b) {
    return *a + *b;
}

int pomnoz(int *a, int *b) {
    return *a * *b;
}

int odejmij(int *a, int *b) {
    return *a - *b;
}

int podziel(int *a, int *b) {

    if (*b == 0) {
        printf("Blad: Nie mozna dzielic przez zero!\n");
        return 0;
    }
    return *a / *b;
}

int main() {
    int liczba1, liczba2;

    while (true) {
        printf("\nKalkulator\n");

        printf("Podaj pierwsza liczbe: ");

        printf("\nPodaj druga liczbe:\n");
        if (scanf("%d", &liczba2) != 1) break;

        int wynik_suma = dodaj(&liczba1, &liczba2);
        int wynik_iloczyn = pomnoz(&liczba1, &liczba2);
        int wynik_roznica = odejmij(&liczba1, &liczba2);
        int wynik_iloraz = podziel(&liczba1, &liczba2);


        printf("Wyniki:\n");
        printf("Suma: %d\n", wynik_suma);
        printf("Iloczyn: %d\n", wynik_iloczyn);
        printf("Roznica: %d\n", wynik_roznica);
        printf("Iloraz: %d\n", wynik_iloraz);
    }

    return 0;
}