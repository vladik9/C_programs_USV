#include "dinamic_mem.h"
//get from user value of memory
int *getMemoryONHeap()
{
     int amount_memory = 0;
     printf("Enter the amount of memory that will be allocated: ");
     scanf("%d", &amount_memory);
     int *mem_ptr = NULL;
     mem_ptr = (int *)malloc(amount_memory * sizeof(int));
     return mem_ptr;
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