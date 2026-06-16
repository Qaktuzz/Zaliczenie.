#include <iostream>
#include <cstdio>
#define  SIZE 10
FILE * fptr;

void copy_to_file(FILE *fptr,int *numbers,int size) {
    fptr = fopen("array.txt", "r+");
    if (fptr == 0)
    {
        printf("Blad podczas otwierania pliku.\n");
        exit(1);
    }
    fseek(fptr,0,SEEK_SET);
    for (int i = 0; i < size; i++) {
        fprintf(fptr, "%d \n", numbers[i]);
    }
    fflush(fptr);
    fclose(fptr);
}
void restore_array(FILE *fptr,int *numbers,int size) {
    fptr = fopen("array.txt", "r+");
    if (fptr == 0)
    {
        printf("Blad podczas otwierania pliku.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        if (fscanf(fptr,"%d",&numbers[i]) != 1) {
            printf("Blad podczas odczytu danych.\n");
            exit(2);
        }
    }
    fseek(fptr,0,SEEK_SET);
    for (int i = 0; i < size; i++) {
        fscanf(fptr,"%d", &numbers[i]);
    }
    fclose(fptr);
}

void Array_print(int *numbers,int size) {
    for (int i = 0; i < size; i++) {
        printf("liczba[%d]=%d\n",i,*(numbers+i));
    }

}
int max_array(int *numbers,int size) {
    int max = *numbers;
    for (int i = 0; i < size; i++) {
        if  (max < *(numbers+i )) {
            max = *(numbers+i );
        }
    }return max;
}
int min_array(int *numbers,int size) {
    int min = *numbers;
    for (int i = 0; i < size; i++) {
        if (min > *(numbers+i)) {
            min = *(numbers+i);
        }
    }return min;
}
int sum(int *numbers,int size) {
    int sum=0;
    for (int i = 0; i < size; i++) {
        sum += *(numbers+i);
    }return sum;
}
float average(int *numbers,int size) {

    float avg = (float)sum(numbers,size)/size;
    return avg;

}

void sort_array(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void copy_array(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];

    }
}

double median(int *numbers, int size) {
    int temp_array[size];
    copy_array(numbers,temp_array,size);
    sort_array(temp_array,size);
    double median;
    if (size % 2 != 0) {
        median = (double)temp_array[size / 2];
        printf("mediana=%.2f\n", median);
    }else {
        median = (temp_array[size / 2 - 1] + temp_array[size / 2]) / 2.0;
        printf("mediana=%.2f\n", median);
    }
    return median;
}

void menu(){
    printf("\nMENU\n");
    printf("1. Podglad danych\n");
    printf("2. Maksimum\n");
    printf("3. Minimum\n");
    printf("4. Suma zbioru\n");
    printf("5. Srednia\n");
    printf("6. Mediana\n");
    printf("7. Zapisz do pliku\n");
    printf("8. Odczytaj z pliku\n");
    printf("0. Wyjscie\n");
    printf("Wybor: ");
}

int main() {

    int numbers[SIZE] = {1, 2, 3, 40, -5, 6, 7, 8, 9, 10};
    int option;
    do {
        menu();
        scanf("%d",&option);
        switch (option) {
            case 1:
                Array_print(numbers,SIZE);
                break;
            case 2:
                printf("max=%d\n", max_array(numbers,SIZE));
                break;
            case 3:
                printf("min=%d\n", min_array(numbers,SIZE));
                break;
            case 4:
                printf("suma=%d\n", sum(numbers,SIZE));
                break;
            case 5:
                printf("srednia=%.2f\n", average(numbers,SIZE));
                break;
            case 6:
                printf("mediana=%.2f\n", median(numbers,SIZE));
                break;
            case 7:
                copy_to_file(fptr,numbers,SIZE);
                printf("Tablica zostala skopiowana\n");
                break;
            case 8:
                printf("Przywracanie danych z pliku\n");
                restore_array(fptr,numbers,SIZE);
                break;
            case 0:
                printf("Zamykanie pliku...!\n");
                break;

        }if (option >8 || option < 0) {
            printf("Wybierz poprawny numer...\n");
        }

    }
    while (option != 0);

    return 0;
}
