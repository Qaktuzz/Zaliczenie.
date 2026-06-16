#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>


void info_uzycie(char *nazwa) {
    printf("Uruchomienie: %s [liczba1] [akcja] [liczba2]\n", nazwa);
    printf("Akcje: add, sub, mul, div, mod\n");
}

int main(int argc, char* argv[]) {


    int x = 0;
    int y = 0;
    int obliczenie = 0;


    if (argc == 4) {
        x = atoi(argv[1]);
        y = atoi(argv[3]);


        if (strcmp("add", argv[2]) == 0) {
            obliczenie = x + y;
            printf("Suma: %d\n", obliczenie);
        }
        else if (strcmp("sub", argv[2]) == 0) {
            obliczenie = x - y;
            printf("Roznica: %d\n", obliczenie);
        }
        else if (strcmp("mul", argv[2]) == 0) {
            obliczenie = x * y;
            printf("Iloczyn: %d\n", obliczenie);
        }
        else if (strcmp("div", argv[2]) == 0) {

            if (y != 0) {
                obliczenie = x / y;
                printf("Iloraz: %d\n", obliczenie);
            } else {
                printf("Blad: Dzielenie przez zero!\n");
            }
        }
        else if (strcmp("mod", argv[2]) == 0) {

            if (y != 0) {
                obliczenie = x % y;
                printf("Reszta (modulo): %d\n", obliczenie);
            } else {
                printf("Blad: Modulo przez zero!\n");
            }
        }
    } else {

        info_uzycie(argv[0]);
    }

    return 0;
}
    return 0;
}
