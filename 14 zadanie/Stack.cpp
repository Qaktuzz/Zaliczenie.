#include "Stack.h"
#include <stdio.h>

static int stack[MAX_SIZE]; // Nasza tablica statyczna
static int topIndex = -1;   // Indeks szczytu stosu (-1 oznacza pusty stos)

void Push(int value) {
    if (!isStackFull()) {
        stack[++topIndex] = value;
    }
}

int Pop(void) {
    if (!isStackEmpty()) {
        return stack[topIndex--];
    }
    return -1; // Zwraca błąd, jeśli stos pusty
}

int Top(void) {
    if (!isStackEmpty()) {
        return stack[topIndex];
    }
    return -1;
}

bool isStackEmpty(void) {
    return topIndex == -1;
}

bool isStackFull(void) {
    return topIndex == MAX_SIZE - 1;
}
