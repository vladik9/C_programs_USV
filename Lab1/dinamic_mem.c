#include "dinamic_mem.h"
//get from user value of memory
int *getMemoryONHeap(int nr_records)
{
     int *temp_ptr = (int *)malloc(nr_records * sizeof(int));
     if (temp_ptr == NULL)
     {
          printf("Can't alloc the memeory!!!\n");
          exit(1);
     }
     return temp_ptr;
}
// add records in arr
bool addRecord(int nr_records, int *first_record)
{
     for (size_t i = 0; i < nr_records; i++)
     {
          printf("Enter record nr. %d :> ", i + 1);
          scanf("%d", &first_record[i]);
     }
     if (first_record[nr_records - 1] != 0)
     {
          return true;
     }
     else
     {
          return false;
     }
}
//print all records in arr
bool printAllResults(int nr_records, int *first_record)
{
     for (size_t i = 0; i < nr_records; i++)
     {
          printf("Record %d is :> ", i + 1);
          printf("%d\n", first_record[i]);
          if (i == nr_records)
          {
               return true;
          }
     }
}

//free memory on heap
void freeMemoryOnHeap(int *ptr_whit_memory_adress)
{
     free(ptr_whit_memory_adress);
     ptr_whit_memory_adress = NULL;
}