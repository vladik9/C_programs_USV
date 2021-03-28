#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
     char buff_of_int[50];
     FILE *ptr_file = fopen("num.txt", "r");
     if (ptr_file == NULL)
     {
          printf("No such file\n");
     }

     int size = 0;

     fscanf(ptr_file, "%[^\n]", buff_of_int);
     int len = strlen(buff_of_int);

     printf("elemets are %s\n", buff_of_int);
     printf("nr elements are %d", len);
     return 0;
}
