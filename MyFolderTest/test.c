#include <stdio.h>

int main()
{

     FILE *ptr_file;
     int conut = 0;
     ptr_file = fopen("num.txt", "r");

     if (ptr_file == NULL)
     {
          printf("Cant opening file\n");
     }
     for (size_t i = 0; i != feof(ptr_file); i++)
     {

          conut++;
     }

     printf("Nr of elements are: %d\n", conut);

     fclose(ptr_file);
     return 0;
}
