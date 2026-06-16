#include <iostream>

// void copy_text(char * text, char * destination) {
//     while (*text) {
//         *destination = *text;
//         destination++;
//         text++;
//     }
// }


void to_lowercase(char *str) {

    while (*str) {
        if ('A' <= *str && *str <= 'Z') {
            *str += ('a' - 'A');


        }*str++;
    }
}
void to_uppercase(char *str) {
    while (*str) {
        if ('a' <= *str && *str <= 'z') {
            *str += ('A' - 'a');

        }*str++;
    }
}
int size_text(char *str) {
    int size = 0;
    while (*str) {
        size++;
        str++;

    }return size;
}
// char lower(char *str) {
//    char c[size_text(str)];
//     copy_text(str,c);
//     while (c) {
//         if ('A' <= c && c <= 'Z') {
//             c += ('a' - 'A');
//         }
//     }return c;
// }
void change(char *str) {
    str[size_text(str) - 1]=0;
}
int main() {

    char str[80];

    while (true) {
        printf("Enter a text: ");
        fgets(str, 80, stdin);

        if (str[0] == '\n') {
            break;

        }
        change(str);
        printf("%s\n", str);
        to_lowercase(str);
        printf("%s\n", str);
        to_uppercase(str);
        printf("%s\n", str);
        printf("text size=%d\n", size_text(str));

    }





    return 0;
}

