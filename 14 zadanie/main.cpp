#include <stdio.h>
#include <stdlib.h>
#include "Stack.h" 

void menu(void)
{
    printf("\n--- OPERACJE NA STOSIE ---");
    printf("\n1 - Push (poloz liczbe)");
    printf("\n2 - Top (odczytaj szczyt)");
    printf("\n3 - Pop (zdejmij liczbe)");
    printf("\n4 - Sprawdz czy pusty");
    printf("\n5 - Sprawdz czy pelny");
    printf("\n6 - Koniec programu");
    printf("\nWybor: ");
}

int main()
{
    int temp = 0;
    int option = 0;

    printf("STOS - implementacja w tablicy statycznej\n");

    while (1)
    {
        menu();

        // Zabezpieczenie przed wpisaniem znaku zamiast liczby
        if (scanf("%d", &option) != 1) {
            printf("Blad! Podaj liczbe.\n");
            while(getchar() != '\n'); // czyszczenie bufora
            continue;
        }

        switch (option)
        {
            case 1:
                if (!isStackFull()) {
                    printf("Podaj wartosc: ");
                    scanf("%d", &temp);
                    Push(temp);
                    printf("Wartosc %d polozona na stosie.\n", temp);
                } else {
                    printf("Operacja niedozwolona: STOS pelny!!!\n");
                }
                break;

            case 2:
                if (!isStackEmpty()) {
                    temp = Top();
                    printf("Wartosc na szczycie: %d\n", temp);
                } else {
                    printf("Operacja niedozwolona: STOS pusty!!!\n");
                }
                break;

            case 3:
                if (!isStackEmpty()) {
                    temp = Pop();
                    printf("Zdjeto wartosc: %d\n", temp);
                } else {
                    printf("Operacja niedozwolona: STOS pusty!!!\n");
                }
                break;

            case 4:
                if (isStackEmpty()) printf("Status: STOS jest pusty.\n");
                else printf("Status: STOS nie jest pusty.\n");
                break;

            case 5:
                if (isStackFull()) printf("Status: STOS jest pelny.\n");
                else printf("Status: STOS nie jest pelny.\n");
                break;

            case 6:
                printf("Zamykanie programu...\n");
                return 0;

            default:
                printf("Bledna opcja! Wybierz 1-6.\n");
                break;
        }
    }
    return 0;
}