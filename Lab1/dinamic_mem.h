#ifndef _DINAMIC_MEM_H_
#define _DINAMIC_MEM_H_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *getMemoryONHeap(int nr_records);                    //get from user value of memory
bool addRecord(int nr_records, int *first_record);       // add records in arr
bool printAllResults(int nr_records, int *first_record); //print all records in arr
void freeMemoryOnHeap();                                 //free memory on heap

#endif // !_DINAMIC_MEM_H_
