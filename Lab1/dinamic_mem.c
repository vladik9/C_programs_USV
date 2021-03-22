#include "dinamic_mem.h"
//get from user value of memory
int *getMemoryONHeap()
{

     printf("Do you want to get memory on heap ? 1-yes 0-no\n");
     int choice = 0;
     scanf("%d", &choice);
     if (choice == 1)
     {
          int *mem_ptr = NULL;
          mem_ptr = (int *)malloc(sizeof(int));
          if (mem_ptr == NULL)
          {
               printf("Can't allocate memory!!!\n");
               exit(1);
          }

          return mem_ptr;
     }
     else if (choice == 0)
     {
          printf("Ok no memory provided!!!\n");
          return NULL;
     }
     else
     {
          printf("It's not a valid option!!!\n");
          return NULL;
     }
}
//free memory on heap
bool freeMemoryOnHeap(int *ptr_whit_memory_adress)
{
     free(ptr_whit_memory_adress);

     ptr_whit_memory_adress == NULL;

     if (ptr_whit_memory_adress == NULL)
     {
          return 1;
     }
     else
     {
          return 0;
     }
}