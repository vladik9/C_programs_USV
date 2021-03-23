#include "file.h"

PRODUS *CitireFisier(char *numeFisier, int *nrProduse)
{
     PRODUS *temp_ptr = NULL;
     FILE *openFile = fopen(numeFisier, "r");
     if (openFile == NULL)
     {
          printf("This file cannot be opened!!!\n");
     }

     fscanf(openFile, "%d", nrProduse);
     temp_ptr = (PRODUS *)malloc(*nrProduse * sizeof(PRODUS));
     printf("\nThe number of products are %d\n", *nrProduse);

     for (size_t i = 0; i < *nrProduse; i++)
     {
          char temp_product_buffer[50];
          char nume[25];
          char unit[5];

          //citesc din fisier codul produsului[i]
          fscanf(openFile, "%d", &temp_ptr[i].product_ID);
          //citesc o linie din fisier (den+un)
          fgets(temp_product_buffer, 255, openFile); //linie[]="mere rosii,kg"
          //extrag din linie denumirea si um a produsului
          strcpy(nume, strtok(temp_product_buffer + 1, ","));
          strcpy(unit, strtok(NULL, ","));
          //aloc spatiu pentru pp[i].dem si pp[i].um, apoi
          //copiez informatiile din _den si _um in zonele

          temp_ptr[i].product_name = (char *)malloc(strlen(nume) + 1);
          strcpy(temp_ptr[i].product_name, nume);

          temp_ptr[i].product_unit = (char *)malloc(strlen(unit) + 1);
          strcpy(temp_ptr[i].product_unit, unit);
     }

     char *afisareProduse(PRODUS * tab, int n)
     {
     }

     fclose(openFile);
     return temp_ptr;
}