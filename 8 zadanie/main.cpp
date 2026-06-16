#include <cstdio>
#include <cstdlib>
#include <cstring>


void instrukcja(char *nazwa_pliku) {
    printf("Blad! Uzycie: %s [liczba1] [operacja] [liczba2]\n", nazwa_pliku);
    printf("Dostepne operacje:\n");
    printf("\tsuma\n");
}

int main(int ilosc_arg, char* argumenty[]) {

    int val1 = 0;
    int val2 = 0;
    int suma = 0;


    if (ilosc_arg == 4) {

        val1 = atoi(argumenty[1]);
        val2 = atoi(argumenty[3]);


        if (strcmp("suma", argumenty[2]) == 0) {
            suma = val1 + val2;
            printf("Wynik dodawania: %d + %d = %d\n", val1, val2, suma);
        } else {

            instrukcja(argumenty[0]);
        }
    } else {

        instrukcja(argumenty[0]);
    }

    return 0;
}