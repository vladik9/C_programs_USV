#ifndef _FILE_H_
#define _FILE_H_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct produs
{
     int product_ID;
     char *product_name;
     char *product_unit;
};

typedef struct produs PRODUS;

PRODUS *ptr_produs; //adress of firsth produs

PRODUS *CitireFisier(char *numeFisier, int *nrProduse);

char *afisareProduse(PRODUS *tab, int n);

//Functie de cautarea a unui produs dupa cod (codX).
//Functia va returna pozitia produsului gasit din tabelul de produse sau valoarea -1 daca produsul nu a fost gasit
int cautaProdus(PRODUS *tab, int n, int codX);

//adaugare produs in tabloul de produse - se va realoca spatiu pentru noul produs (transmis in functie printr-un pointer la struct produs)
PRODUS *adaugaProdus(PRODUS *tab, int *n, PRODUS *x);

//Functie de salvare a produselor intr-un fisier.
//Functia va returna TRUE daca produsele au fost salvate cu succes, respectiv FALS daca operatia a esuat.
bool salvareProduseInFisier(char *numeFisier, PRODUS *tab, int n);

#endif // !_FILE_H_
