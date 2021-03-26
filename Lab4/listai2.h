#ifndef LISTAI_H_INCLUDED
#define LISTAI_H_INCLUDED

#include "data.h"
#include <stdbool.h>
//-----------------------------------
// Proprietatile TDA lista inlantuita
//
typedef struct element *ELEMENT;
typedef struct lista *LISTA;
//
//----------------------------------
// Metodele (operatiile) TDA
//
LISTA newl();
LISTA ins_in_fata(LISTA l, DATA x);
LISTA ins_la_urma(LISTA l, DATA x);
LISTA sterge_primul(LISTA l);
LISTA sterge_ultimul(LISTA l);
ELEMENT cauta(LISTA l, DATA k);
DATA primul(LISTA l);
DATA ultimul(LISTA l);
int nrElemente(LISTA l);
bool isEmptyl(LISTA l);
bool isFull(LISTA l);
char *toStringl(LISTA l,char *s);
// ...
void destroyl(LISTA l);
#endif
