#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100 // Maksymalny rozmiar stosu

// Deklaracje funkcji
void Push(int value);
int Pop(void);
int Top(void);
bool isStackEmpty(void);
bool isStackFull(void);

#endif