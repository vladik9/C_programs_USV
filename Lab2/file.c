#include "file.h"
//read from file
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
     printf("\nThe current number of products are >: %d\n\n", *nrProduse);

     for (size_t i = 0; i < *nrProduse; i++)
     {
          char temp_product_buffer[50];
          char nume[30];
          char unit[10];

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

     fclose(openFile);
     return temp_ptr;
}

//print all records to screen
void afisareProduse(PRODUS *tab, int *nr_products)
{
     printf("Product ID: \tproduct name: \tmesuare unit:\n");
     for (size_t i = 0; i < *nr_products; i++)
     {
          printf("|%d| \t\t%s \t%s\n",
                 tab[i].product_ID,
                 tab[i].product_name,
                 tab[i].product_unit);
     }
}

//search for a product with
int cautaProdus(PRODUS *tab, int nr_records, int codX)
{

     for (size_t i = 0; i < nr_records; i++)
     {
          if (tab[i].product_ID == codX)
          {
               return i;
          }
     }
     return -1;
}
//add new_product to the end of list
PRODUS *adaugaProdus(PRODUS *tab, int *nr_records)
{
     PRODUS *temp_ptr;

     char temp_product_name[50];
     char temp_product_mesure_unit[5];
     printf("\nEnter product name: ");
     scanf("%s", &temp_product_name);
     printf("\nEnter product mesure units: ");
     scanf("%s", &temp_product_mesure_unit);
     ++(*nr_records);
     int position = *nr_records - 1;
     temp_ptr = (PRODUS *)realloc(tab, *nr_records * sizeof(PRODUS));
     printf("\nallocated\n");
     temp_ptr[position].product_ID = *nr_records;

     temp_ptr[position].product_name = (char *)malloc(strlen(temp_product_name) + 1);
     strcpy(temp_ptr[position].product_name, temp_product_name);

     temp_ptr[position].product_unit = (char *)malloc(strlen(temp_product_mesure_unit) + 1);
     strcpy(temp_ptr[position].product_unit, temp_product_mesure_unit);

     printf("\nThe new record are added whit id >: %d\n", *nr_records);
     return temp_ptr;
}

//save data to the file or append
bool salvareProduseInFisier(char *numeFisier, PRODUS *tab, int nr_records, char *mode)
{
     FILE *ptr_file;
     ptr_file = fopen(numeFisier, mode);
     if (ptr_file == NULL)
     {
          printf("Can't open file %s\n", numeFisier);
          return false;
     }
     printf("Nr of records are %d\n", nr_records);

     fprintf(ptr_file, "%d\n", tab[nr_records].product_ID);
     for (size_t i = 0; i < nr_records; i++)
     {
          fprintf(ptr_file, "%d %s, %s\n",
                  tab[i].product_ID,
                  tab[i].product_name,
                  tab[i].product_unit);
     }
     fclose(ptr_file);
     return true;
}