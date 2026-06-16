#include <cstdio>
#include <cstring>


void male_litery(char *p) {
    while (*p != '\0') {
        if (*p >= 'A' && *p <= 'Z') {
            *p = *p + 32;
        }
        p++;
    }
}


void duze_litery(char *p) {
    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 32;
        }
        p++;
    }
}


int ile_znakow(char *p) {
    int n = 0;
    while (*(p + n)) {
        n++;
    }
    return n;
}


void pomoc(char *nazwa) {
    printf("Blad! Sprobuj tak: %s \"tekst\"\n", nazwa);
}

int main(int argc, char* argv[]) {
    char bufor[100];


    if (argc != 2) {
        pomoc(argv[0]);
        return 1;
    }


    strcpy(bufor, argv[1]);

    printf("Oryginalny tekst: %s\n", bufor);


    male_litery(bufor);
    printf("Male litery: %s\n", bufor);

    duze_litery(bufor);
    printf("WIELKIE LITERY: %s\n", bufor);


    printf("Liczba liter w tekscie: %d\n", ile_znakow(bufor));

    return 0;
}