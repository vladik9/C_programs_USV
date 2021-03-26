#include <stdio.h>

int main()
{

     FILE *ptr_file;

     ptr_file = fopen("num.txt", "r");
     if (ptr_file == NULL)
     {
          printf("Cant opening file\n");
     }
     int ch = getc(ptr_file);
     printf("End od file have value: %d\n", ch);
     return 0;
}
