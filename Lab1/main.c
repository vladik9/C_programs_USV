#include "dinamic_mem.h"
#include "dinamic_mem.c"

int main()
{
     int *head_mem_aloc = NULL;
     head_mem_aloc = getMemoryONHeap();

     printf("Enter your variable here:>  ");
     scanf("%d", head_mem_aloc);

     printf("Your variable is %d", *head_mem_aloc);
     bool choice = 0;
     printf("\nDo you want to release the memory? : 1-yes 0-no \n");
     scanf("%d", &choice);
     if (choice == 1)
     {
          //choice = freeMemoryOnHeap(head_mem_aloc);
          free(head_mem_aloc);
          if (choice)
          {
               printf("\nMemory released successfully!\n");
          }
          else
          {
               printf("\nCan't release memory!\n");
          }
     }
     else
     {
          printf("\nWe leave memory without be relesed!\n");
     }

     return 0;
}
