#include "file.h"
#include "file.c"

int main()
{
     int nr_products_in_file = 0;
     bool file_flag = false;
     int user_choice = 0;
     do
     {
          //sleep(2); // sleep for 3 seconds
          // system("clear");
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
               file_flag = true;
               break;
          case 2:
               /* code */
               if (!file_flag)
               {
                    printf("Enter the name of file to be opened: ");
                    char filename[25];
                    scanf("%s", filename);
                    ptr_produs = CitireFisier(filename, &nr_products_in_file);
                    file_flag = true;
               }
               afisareProduse(ptr_produs, &nr_products_in_file);

               break;
          case 3:
               /* code */
               if (!file_flag)
               {
                    printf("Enter the name of file to be opened: ");
                    char filename[25];
                    scanf("%s", filename);
                    ptr_produs = CitireFisier(filename, &nr_products_in_file);
                    file_flag = true;
               }
               int ID_to_search = 0;
               printf("Enter the ID of the product to search: ");
               scanf("%d", &ID_to_search);

               int search_status = cautaProdus(ptr_produs,
                                               nr_products_in_file,
                                               ID_to_search);
               if (search_status != -1)
               {
                    printf("Produs founded whit ID %d\n", ID_to_search);
                    printf("\nDo you want to print it:?");
                    printf("\n 1-Yes 2-No\n");
                    scanf("%d", &user_choice);
                    if (user_choice == 1)
                    {
                         printf("Product ID: \tproduct name: \tmesuare unit:\n");
                         printf("|%d| \t\t%s \t%s\n",
                                ptr_produs[ID_to_search - 1].product_ID,
                                ptr_produs[ID_to_search - 1].product_name,
                                ptr_produs[ID_to_search - 1].product_unit);
                    }
                    else
                    {
                         printf("\nOk quiting!!!\n");
                    }
               }
               else
               {
                    printf("\nNo product found!!!\n");
               }

               break;
          case 4:
               /* code */
               if (!file_flag)
               {
                    printf("Enter the name of file to be opened: ");
                    char filename[25];
                    scanf("%s", filename);
                    ptr_produs = CitireFisier(filename, &nr_products_in_file);
                    file_flag = true;
               }
               ptr_produs = adaugaProdus(ptr_produs, &nr_products_in_file);
               break;
          case 5:
               /* code */
               break;
          case 6:
               /* code */
               exit(0); //exit code successe
               break;

          default:
               printf("This is not a valid option.\n");
               break;
          }

     } while (user_choice != 6);

     return 0;
}
