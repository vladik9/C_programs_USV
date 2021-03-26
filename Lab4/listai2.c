#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "listai2.h"

struct element {
    DATA info;
    struct element *urm;
};
typedef struct element Element;

struct lista {
    int nr;
    ELEMENT primul;
    ELEMENT ultimul;
};
typedef struct lista Lista;


LISTA newl(){
    LISTA header = (LISTA) malloc( sizeof(Lista) );
    if(header != NULL) {
        header->nr = 0;
        header->primul = NULL;
        header->ultimul = NULL;
    }
    return header;
}
static ELEMENT creareElement(DATA x, ELEMENT urmator)
{
    ELEMENT w= (ELEMENT) malloc( sizeof(Element) );
    if(w!=NULL) {
        w->info = x;
        w->urm  = urmator;
    }
    return w;
}
LISTA ins_in_fata(LISTA l, DATA x){
    assert(l!=NULL);

    if(isFull(l)) return l;
    ELEMENT w = creareElement(x, l->primul);
    if (w!=NULL) {
        l->primul = w;
        if(l->ultimul == NULL)
            l->ultimul = w;
        l->nr++;
    }
    return  l;
}
LISTA ins_la_urma(LISTA l, DATA x){
    assert(l!=NULL);

    if(isFull(l)) return l;
    ELEMENT w = creareElement(x, NULL);
    if(w!=NULL) {
        if(isEmptyl(l)) {
            l->primul = l->ultimul = w;
        } else {
            l->ultimul->urm = w;
            l->ultimul = w;
        }
        l->nr++;
    }
    return l;
}
LISTA sterge_ultimul(LISTA l){
    assert(l!=NULL);
    if(isEmptyl(l)) return l;
    l->nr--;
    if(l->primul == l->ultimul) { //este unicul element
        free(l->primul);
        l->primul = l->ultimul = NULL;
    } else {           // sunt cel putin 2 elemente
        ELEMENT p;
        for(p=l->primul; p->urm!=l->ultimul; p = p->urm) ;
        // p adresa penultimului element
        free(l->ultimul );  // elimina ultimul
        p->urm = NULL; // penultimul devine ultimul
        l->ultimul = p;
    }
    return l;
}
LISTA sterge_primul(LISTA l){
    assert(l!=NULL);

    if(l->primul!=NULL) {
       l->nr--;
       ELEMENT p = l->primul->urm;
       free(l->primul);
       l->primul = p;
       if(l->primul == NULL )  // lista a devenit vida
            l->primul=NULL;
    }
    return l;
}
ELEMENT cauta(LISTA l, DATA k) {
    assert(l!=NULL);

    if(!isEmptyl(l)) {
        ELEMENT p;
        for(p=l->primul; p!=NULL; p = p->urm) {
            if(p->info == k) return p;
        }
    }
    return NULL;
}


DATA primul(LISTA l) {
    assert(l!=NULL);
    return isEmptyl(l) ? ABSENT : l->primul->info;
}
DATA ultimul(LISTA l) {
    assert(l!=NULL);
    return isEmptyl(l) ? ABSENT : l->ultimul->info;
}

int nrElemente(LISTA l){
    assert(l!=NULL);
    return l->nr;
}
bool isEmptyl(LISTA l){
    return nrElemente(l)==0;
}
bool isFull(LISTA l){
    return FALS;
}
char *toStringl(LISTA l,char *s){
    char buf[100];
    char bufinfo[50];
    sprintf(s, "Lista: {", l);

    assert(l!=NULL);

    if(isEmptyl(l)) {
            strcat(s, "vida }");
    } else {
        ELEMENT p;
        for(p=l->primul; p!=NULL; p = p->urm) {
            sprintf(buf,  "%s%c", toStringDATA(p->info, bufinfo),p==l->ultimul ?'}' : ',');
            strcat(s, buf);
        }
    }
    return s;
}
// ...
void destroyl(LISTA l) {
    ELEMENT e, p;
    if(l==NULL || l->primul==NULL) return;

    e= l->primul;
    while(e!=NULL) {
        p=e;
        e = e->urm;
        free(p);
    }
}
