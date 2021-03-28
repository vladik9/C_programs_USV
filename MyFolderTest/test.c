#include <stdio.h>
#include <stdlib.h>

int main()
{
     FILE *fp = fopen("num.txt", "r");
     int array[100];
     int i_ = 0, retval;

     if (fp == NULL)
     {
          printf("error in opening file\n");
          // handle it
     }

     // note the null statement in the body of the loop
     while (i_ < 100 && (retval = fscanf(fp, "%d", &array[i_++])) == 1)
          ;

     if (i_ == 100)
     {
          // array full
     }

     if (retval == 0)
     {
          // read value not an integer. matching failure
     }

     if (retval == EOF)
     {
          // end of file reached or a read error occurred
          if (ferror(fp))
          {
               // read error occurred in the stream fp
               // clear it
               clearerr(fp);
          }
     }

     printf("retval is %d\n", retval);
     printf("i_ is %d\n", i_);
     for (size_t i = 0; i < i_; i++)
     {
          printf("The val is |%d|\n", array[i]);
     }

     // after being done with fp
     fclose(fp);

     return 0;
}
