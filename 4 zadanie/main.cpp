#include <iostream>
#include <cstdio>

#define tablica 10


void PokazDane(int *tab, int n) {
    for (int k = 0; k < n; k++) {
        printf("Liczba[%d] ma wartosc: %d\n", k, *(tab + k));
    }
}


int FunkcjaMax(int *tab, int n) {
    int gora = *tab;
    for (int x = 0; x < n; x++) {
        if (gora < *(tab + x)) {
            gora = *(tab + x);
        }
    }
    return gora;
}


int FunkcjaMin(int *tab, int n) {
    int dol = *tab;
    for (int x = 0; x < n; x++) {
        if (dol > *(tab + x)) {
            dol = *(tab + x);
        }
    }
    return dol;
}


int ObliczSume(int *tab, int n) {
    int lacznie = 0;
    for (int i = 0; i < n; i++) {
        lacznie += *(tab + i);
    }
    return lacznie;
}


float WyliczSrednia(int *tab, int n) {
    float wynik = (float)ObliczSume(tab, n) / n;
    return wynik;
}


void Sortowanie(int *t, int n) {
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - a - 1; b++) {
            if (t[b] > t[b + 1]) {
                int zamiana = t[b];
                t[b] = t[b + 1];
                t[b + 1] = zamiana;
            }
        }
    }
}


void Kopiowanie(int wej[], int wyj[], int n) {
    for (int i = 0; i < n; i++) {
        wyj[i] = wej[i];
    }
}


double ObliczMediane(int *tab, int n) {
    int kopia[n];
    Kopiowanie(tab, kopia, n);
    Sortowanie(kopia, n);

    double m;
    if (n % 2 != 0) {
        m = (double)kopia[n / 2];
    } else {
        m = (kopia[n / 2 - 1] + kopia[n / 2]) / 2.0;
    }
    return m;
}


void WyswietlOpcje() {
    printf("\nMenu\n");
    printf("[1] Lista elementow\n");
    printf("[2] Wartosc maksymalna\n");
    printf("[3] Wartosc minimalna\n");
    printf("[4] Suma zbioru\n");
    printf("[5] Srednia\n");
    printf("[6] Mediana\n");
    printf("[0] Zakoncz program\n");
    printf("Wybor: ");
}

int main() {

    int dane[tablica] = {12, 5, 88, 3, 11, 42, 7, 19, 60, 2};
    int wybor;

    do {
        WyswietlOpcje();
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                printf("Zawartosc tablicy:\n");
                PokazDane(dane, tablica);
                break;
            case 2:
                printf("Najwiekszy element: %d\n", FunkcjaMax(dane, tablica));
                break;
            case 3:
                printf("Najmniejszy element: %d\n", FunkcjaMin(dane, tablica));
                break;
            case 4:
                printf("Suma elementow: %d\n", ObliczSume(dane, tablica));
                break;
            case 5:
                printf("Srednia wartosc: %.2f\n", WyliczSrednia(dane, tablica));
                break;
            case 6:
                printf("Mediana zbioru: %.2f\n", ObliczMediane(dane, tablica));
                break;
            case 0:
                printf("Zamykanie programu...\n");
                break;
            default:
                printf("Bledny wybor! Sprobuj ponownie.\n");
                break;
        }
    } while (wybor != 0);

    return 0;
}
