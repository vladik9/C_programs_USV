#include <stdio.h>
struct element
{
     int info;
     struct element *urm;
};
//###     ###

//redefintion of element struct in ELEMENT
typedef struct element Element;

//struct whit list of elements called list
//### lista ###
typedef struct element *ELEMENT;
typedef struct lista *LISTA;
struct lista
{
     int nr;
     ELEMENT primul;
     ELEMENT ultimul;
};

int main()
{

     ELEMENT ptr;
     LISTA l;
     l->primul->info;
     ptr->info;

     return 0;
}
