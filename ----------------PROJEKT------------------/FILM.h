#pragma once

#define RZAD 10
#define KOLUMNA 15

void ZapisDoPliku(const char* filename, int cinema[RZAD][KOLUMNA]);
void OdczytzPliku(const char* filename, int cinema[RZAD][KOLUMNA]);
void WyswietlSale(int cinema[RZAD][KOLUMNA]);
void ZarezerwujMiejsce(const char* filename, int cinema[RZAD][KOLUMNA]);
void PokazStatystyki(const char* filename, int cinema[RZAD][KOLUMNA]);
