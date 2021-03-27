#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "listai2.h"

//struct whit elements
//### element ###
struct element
{
    DATA info;
    struct element *urm;
};
//###     ###

//redefintion of element struct in ELEMENT
typedef struct element Element;

//struct whit list of elements called list
//### lista ###

struct lista
{
    int nr;
    ELEMENT primul;
    ELEMENT ultimul;
};
//###     ###

//redefintion of element struct list in LIST
typedef struct lista Lista;

//list initialization
LISTA newl()
{
    LISTA header = (LISTA)malloc(sizeof(Lista)); //get memroy for list
    if (header != NULL)                          // whit 3 filds
    {
        header->nr = 0;         // nr of elements
        header->primul = NULL;  //first_element in  list
        header->ultimul = NULL; //second element in list
    }
    return header; // a pointer whit value of list
}

// function static to create a element in list
static ELEMENT creareElement(DATA x, ELEMENT urmator)
{
    ELEMENT w = (ELEMENT)malloc(sizeof(Element)); // get memory for 2 records
    if (w != NULL)
    {
        w->info = x;      // record info (data int)
        w->urm = urmator; // record pointer to next element via ptr
    }
    return w; //return the address of the element
}

LISTA ins_in_fata(LISTA l, DATA x) // Data is an alias for a int type
{
    assert(l != NULL); // check_condition if list have allocated memory

    if (isFull(l))                           // call function for check if list is full
        return l;                            //return list if is full
                                             //else
    ELEMENT w = creareElement(x, l->primul); //call function for creating a new element
    if (w != NULL)                           // check if allocated memory is available
    {
        l->primul = w;          //access memory in list and write first element
        if (l->ultimul == NULL) //check if is only one record
            l->ultimul = w;     // if true set the last element the single element in list
        l->nr++;                // increment the number of elements in list from 0 to 1
        printf("\nElementul %d a fost adaugat cu succes in lista!\n ", x);
    }

    return l; //return ptr to list
}

LISTA ins_la_urma(LISTA l, DATA x) // function for adding an element at the end of the list
{
    assert(l != NULL); //check if the list have memory

    if (isFull(l))                      // check if the list is full
        return l;                       //return ptr to list full
    ELEMENT w = creareElement(x, NULL); //create a new element whit an int data and a NULL terminator
    if (w != NULL)                      //check if the element get memory
    {
        if (isEmptyl(l)) // check if the list is full
        {
            l->primul = l->ultimul = w; //acces list and update the first record
                                        //and second to  have same data
        }
        else // if in the list exit elements updating diferrent value for first and last element
        {
            l->ultimul->urm = w; // give the addres of the current object to the last record
            l->ultimul = w;      //
        }
        l->nr++; //increment the number of elements
    }
    return l; //return the list ptr
}

LISTA sterge_ultimul(LISTA l) // delete the last element int the list
{
    assert(l != NULL);                 // check if the list is available
    if (isEmptyl(l))                   // check if the list is not empty(no records)
        return l;                      // if true return the list
    l->nr--;                           //else decrement one item from nr of elements
    if (l->primul == l->ultimul)       //check if the first element si equal to the last element
    {                                  //este unicul element
        free(l->primul);               //if true the free first the single element in list
        l->primul = l->ultimul = NULL; // and NULL the ptr pointing to that memory location
        printf("\nElementul a fost sters cu succes.\n");
    }
    else // else we hava more that one record
    {
        ELEMENT p;
        for (p = l->primul; p->urm != l->ultimul; p = p->urm)
            ; // get p(adress) at the (n-1) positon in list

        free(l->ultimul); // delete the last element memory location
        p->urm = NULL;    // NULL the conection to the last element
        l->ultimul = p;   //update the postion in list to be able to use the list ahead
        printf("\nElementul a fost sters cu succes.\n");
    }
    return l; //return a ptr whit list
}

LISTA sterge_primul(LISTA l) // delete the first element in list
{
    assert(l != NULL); //check if list have memeory

    if (l->primul != NULL) //check if the first element is present (have memeory allocated)
    {
        l->nr--;                    // decrement one element in list
        ELEMENT p = l->primul->urm; // a pointer to store the second element after the first
        free(l->primul);            //free the memeory alocated to the first element
        l->primul = p;              // update the info for list whit new first element
        if (l->primul == NULL)      //check if the list is empty (no more elements)
            l->primul = NULL;       //if true NULL the pointer
        printf("\nElementul a fost sters cu succes.\n");
    }
    return l; //return the list ptr
}

ELEMENT cauta(LISTA l, DATA k) // search the data in the list
{
    assert(l != NULL); // check if the list have memory allocated

    if (!isEmptyl(l)) //check if the list is empty (no more elements)
    {
        ELEMENT p;                                 //temp ptr
        for (p = l->primul; p != NULL; p = p->urm) // a loop to search the element in the list
        {
            if (p->info == k) // if the element matches
                return p;     //return it
        }
    }
    return NULL; //NULL; // else no one matche return NULL
}

DATA primul(LISTA l) //return a int whit num of first elements or ABSENT if list empty
{
    assert(l != NULL);                             // check if the list have memory allocated
    return isEmptyl(l) ? ABSENT : l->primul->info; // ternary operator true: ABSENT false: int
}

DATA ultimul(LISTA l) //return a int whit num of first elements or ABSENT if list empty
{
    assert(l != NULL);                              // check if the list have memory allocated
    return isEmptyl(l) ? ABSENT : l->ultimul->info; // ternary operator true: ABSENT false: int
}

int nrElemente(LISTA l) // function for  return number of elements in list
{
    assert(l != NULL); // check if the list have memory allocated
    return l->nr;      // return the number of elements
}

bool isEmptyl(LISTA l) // function for check the list is empty
{
    return nrElemente(l) == 0; //return nr pf elements equal to 0
}

bool isFull(LISTA l) // check if the list is full
{
    return FALS; // this list never can be full, it can be extended to the posibility of OP
}

char *toStringl(LISTA l, char *s) // funciton that transform all elements in a string
{
    char buf[100];             // a buf var
    char bufinfo[50];          // a buf info var
    sprintf(s, "Lista: {", l); // atach this message in the list

    assert(l != NULL); // if the list have memory

    if (isEmptyl(l)) // and it's empty
    {
        strcat(s, "vida }"); // atach word vida, for emptinees
    }
    else // else if not empty
    {
        ELEMENT p;
        for (p = l->primul; p != NULL; p = p->urm) // go from first to the last element
        {                                          // and attache in buf one element folowed by a comma
            sprintf(buf, "%s%c", toStringDATA(p->info, bufinfo), p == l->ultimul ? '}' : ',');
            strcat(s, buf); // concatenate the data into existing buffer
        }
    }
    return s; //return the buffer to the user via *ptr char
}

void destroyl(LISTA l) // destroy list
{
    ELEMENT e, p;                       // use 2 ptr
    if (l == NULL || l->primul == NULL) //check if the list is exist and if the first element exist
        return;
    //e is for auxiliar variable
    e = l->primul;    //ptr is equal to the first element
    while (e != NULL) // while this is not null
    {
        p = e; // go from one address element to another and
        e = e->urm;
        free(p); // free the memeory
    }
}

// ... for new function added by me
LISTA delete_X_element(LISTA l, DATA x)
{
    assert(l != NULL); // check_condition if list have allocated memory

    if (isEmptyl(l))
    {
        return l; // return list if is empty
    }
    if (l->primul->info == x)
    {
        l = sterge_primul(l);
    }
    else if (l->ultimul->info == x)
    {
        l = sterge_ultimul(l);
    }
    else
    {
        ELEMENT p, anteriorX, posteriorX;             //temp ptr
        for (p = l->primul; p->info != x; p = p->urm) // a loop to search the element in the list
        {
            anteriorX = p->urm;
            for (p = l->primul; p != NULL; p = p->urm)
            {
                if (p->info == x)
                { // if the element matches
                    free(p);
                    posteriorX = p->urm; // get the addres of the next element

                    posteriorX = anteriorX;
                    printf("\nElementul a fost sters cu succes.\n");
                }
            }
        }
    }

    return l;
}

bool saveListToFile(LISTA l)
{

    FILE *ptr;
    ELEMENT p;

    assert(l != NULL); // check_condition if list have allocated memory

    if (isEmptyl(l))
    {
        return false; // return list if is empty
    }
    printf("Enter name for new file: ");
    char filename[25];
    scanf("%s", filename);
    ptr = fopen(filename, "w");
    if (ptr == NULL)
    {
        printf("Can't create new file %s", filename);
    }

    for (p = l->primul; p != NULL; p = p->urm) // a loop to search the element in the list
    {
        fprintf(ptr, "%d ", p->info);
    }
    fclose(ptr);
    return true;
}

bool creareListeNoiPozitivaNegativa(LISTA initiala, LISTA pozitiva, LISTA negativa)
{
}