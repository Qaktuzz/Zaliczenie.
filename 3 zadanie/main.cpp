#include <iostream>
#include <cstdio>

#define tablica 10


void PokazTablice(int *ptr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Liczba[%d] -> %d\n", i, *(ptr + i));
    }
}


int ZnajdzMax(int *dane, int n) {
    int najwyzsza = *dane;
    for (int k = 0; k < n; k++) {
        if (*(dane + k) > najwyzsza) {
            najwyzsza = *(dane + k);
        }
    }
    return najwyzsza;
}


int ZnajdzMin(int *dane, int n) {
    int najnizsza = *dane;
    for (int k = 0; k < n; k++) {
        if (*(dane + k) < najnizsza) {
            najnizsza = *(dane + k);
        }
    }
    return najnizsza;
}


int ObliczSume(int *tab, int n) {
    int wynik = 0;
    for (int j = 0; j < n; j++) {
        wynik += *(tab + j);
    }
    return wynik;
}


float ObliczSrednia(int *tab, int n) {
    float sr = (float)ObliczSume(tab, n) / n;
    return sr;
}


void Sortuj(int *zbior, int n) {
    for (int x = 0; x < n - 1; x++) {
        for (int y = 0; y < n - x - 1; y++) {
            if (zbior[y] > zbior[y + 1]) {
                int bufor = zbior[y];
                zbior[y] = zbior[y + 1];
                zbior[y + 1] = bufor;
            }
        }
    }
}


void KopiujDane(int wejscie[], int wyjscie[], int n) {
    for (int i = 0; i < n; i++) {
        wyjscie[i] = wejscie[i];
    }
}


double WyznaczMediane(int *liczby, int n) {
    int tablica_robocza[n];
    KopiujDane(liczby, tablica_robocza, n);
    Sortuj(tablica_robocza, n);

    double wynik_mediana;
    if (n % 2 != 0) {
        wynik_mediana = (double)tablica_robocza[n / 2];
    } else {
        wynik_mediana = (tablica_robocza[n / 2 - 1] + tablica_robocza[n / 2]) / 2.0;
    }
    printf("Obliczona mediana: %.2f\n", wynik_mediana);
    return wynik_mediana;
}

int main() {
    printf("Wyniki:\n");


    int zestaw[tablica] = {15, 22, 5, 100, -12, 0, 33, 8, 19, 45};

    PokazTablice(zestaw, tablica);

    printf("Najwieksza: %d\n", ZnajdzMax(zestaw, tablica));
    printf("Najmniejsza: %d\n", ZnajdzMin(zestaw, tablica));
    printf("Suma wszystkich: %d\n", ObliczSume(zestaw, tablica));
    printf("Srednia wartosc: %.2f\n", ObliczSrednia(zestaw, tablica));

    WyznaczMediane(zestaw, tablica);

    return 0;
}