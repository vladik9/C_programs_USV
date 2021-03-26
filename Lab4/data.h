#ifndef _DATA_H_
#define _DATA_H_
typedef unsigned char LOGIC;
#define FALS 0
#define ADEVARAT 1
//
//-----------------------------------------
// Rezervat modificarilor utilizatorului
// care va preciza tipul informatiei din
// elementele TDA, precum si numarul maxim
// de elemente ale TDA (NMAX)
//-----------------------------------------
//
typedef int DATA;
#define FORMAT "%d"
#define ABSENT 0
//
//-----------------------------------------
// functia care converteste intr-un sir informatia
// structurata de tip DATA
//
static char *toStringDATA(DATA x, char *zona){
    sprintf(zona, FORMAT, x);
    return zona;
}
#endif
