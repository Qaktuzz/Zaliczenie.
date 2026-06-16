#include <iostream>
#define  size 10

int main() {
    printf("Arrays\n");
    int numbers[size] = {1, 2, 3, 40, -5, 6, 7, 8, 9, 10};

    // for (int i = 0; i < size; i++) {
    //     printf("number[%d]=%d\n", i, numbers[i]);
    // }
    for (int i = 0; i < size; i++) {
        printf("number[%d]=%d\n", i, *(numbers+i));
    }
    // int max = numbers[0];
    // for (int i = 0; i < size; i++) {
    //     if  (max < numbers[i] ) {
    //         max = numbers[i];
    //     }
    // }
    int max = *numbers;
    for (int i = 0; i < size; i++) {
        if  (max < *(numbers+i )) {
            max = *(numbers+i );
        }
    }
    // printf("max=%d\n", max);
    // int min = *numbers;
    // for (int i = 0; i < size; i++) {
    //     if (min > *(numbers+i) {
    //         min = *(numbers+i);
    //     }
    // }
    // printf("min=%d\n", min);

    printf("max=%d\n", max);
    int min = *numbers;
    for (int i = 0; i < size; i++) {
        if (min > *(numbers+i)) {
            min = *(numbers+i);
        }
    }
    printf("min=%d\n", min);

    // int sum=0;
    // for (int i = 0; i < size; i++) {
    //     sum += numbers[i];
    // }
    // printf("sum=%d\n", sum);
    // float average =(float) sum/size;
    // printf("average=%.2f\n", average);
    int sum=0;
    for (int i = 0; i < size; i++) {
        sum += *(numbers+i);
    }
    printf("sum=%d\n", sum);
    float average =(float) sum/size;
    printf("average=%.2f\n", average);
    int copy[size];

    // int *ptr=&numbers[0];

    for (int i = 0; i < size; i++) {
        *(copy+i) = *(numbers+i);

    }


    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(copy+j) > *(copy+j+1)) {
                int temp = *(copy+j);
                *(copy+j) = *(copy+j + 1);
                *(copy+j + 1) = temp;
            }
        }
    }
    double median;
    if (size % 2 != 0) {
        median = numbers[size / 2];
        printf("median=%.2f\n", median);
    } else {

        median = (copy[size / 2 - 1] + copy[size / 2]) / 2.0;
        printf("median=%.2f\n", median);
    }
    for (int i = 0; i < size; i++) {
        printf("number[%d]=%d\n", i, *(numbers+i));
    }


    return 0;
    //obliczyc mediane jako prace domowa!!!!
    // #include <iostream>
// #define  size 10
//
// int main() {
//     while (true){
//
//         printf("Simple calculator\n");
//         int num1=0;
//         int *ptr1=&num1;
//         int num2=0;
//         int *ptr2=&num2;
//         printf("Enter number no.1\n");
//         scanf("%d",ptr1);
//         if (*ptr1==0) {
//             break;
//         }
//         printf("Enter number no.2\n");
//         scanf("%d",ptr2);
//         if (*ptr2==0) {
//             break;
//         }
//         printf(" %d+%d=%d\n",*ptr1 ,*ptr2 ,*ptr1+ *ptr2);
//         printf(" %d-%d=%d\n",*ptr1 ,*ptr2 ,*ptr1 - *ptr2);
//         printf(" %d*%d=%d\n",*ptr1 ,*ptr2 ,*ptr1 * *ptr2);
//         printf(" %d/%d=%d\n",*ptr1 ,*ptr2 ,*ptr1 / *ptr2);
//         printf("%d %% %d =%d\n",*ptr1 ,*ptr2 ,*ptr1 % *ptr2);
//
//
//     }return 0;
// }
}
