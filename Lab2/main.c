#include "file.h"
#include "file.c"

int main()
{
     int nr_products_in_file;
     bool file_flag = false;
     int user_choice = 0;
     do
     {
          sleep(2); // sleep for 3 seconds
          system("clear");
          printf("################################\n");
          printf("1 - Read from a file.\n");
          printf("2 - Print all products.\n");
          printf("3 - Search an produs via ID.\n");
          printf("4 - Add a product to the struct.\n");
          printf("5 - Save the struct in a file.\n");
          printf("6 - Exit from this program.\n");
          printf("Your option here:> ");
          scanf("%d", &user_choice);
          printf("################################\n\n");

          switch (user_choice)
          {
          case 1:
               /* code */
               printf("Enter the name of file to be opened: ");
               char filename[25];
               scanf("%s", filename);
               ptr_produs = CitireFisier(filename, &nr_products_in_file);

               break;
          case 2:
               /* code */
               break;
          case 3:
               /* code */
               break;
          case 4:
               /* code */
               break;
          case 5:
               /* code */
               break;
          case 6:
               /* code */
               break;

          default:
               printf("This is not a valid option.\n");
               break;
          }

     } while (user_choice != 6);

     return 0;
}
