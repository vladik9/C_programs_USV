#include "dinamic_mem.h"
#include "dinamic_mem.c"

int main()
{
     printf("How many recods do you want? : ");
     int recods = 0;
     printf("\n");
     scanf("%d", &recods);
     int *ptr;
     //get memory for variables
     ptr = getMemoryONHeap(recods);
     //add recods
     bool ceck = addRecord(recods, ptr);
     if (ceck)
     {
          printf("\nThe records are added successfully!!\n\n");
     }
     else
     {
          printf("\nNo records were added!!\n");
     }
     ceck = printAllResults(recods, ptr);
     if (ceck)
     {
          printf("\nThe records are displayed successfully!!\n\n");
     }
     else
     {
          printf("\nNo records were printed!!\n");
     }

     freeMemoryOnHeap(ptr);
     return 0;
}
