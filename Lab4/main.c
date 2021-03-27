#include <stdio.h>
#include "data.h"
#include "listai2.h"
#include "listai2.c"
//#include <unistd.h>  // for sleap linux
#include <Windows.h> // for sleap windows

int main()
{
     int check_condition = 0;
     LISTA my_list, lista_negativa, lista_pozitiva;
     ELEMENT my_element;
     FILE *ptr_file;
     char *string_whit_elements;
     bool flag_inserare = 0;
     int user_element = 0;
     my_list = newl();        //list initialization
     lista_pozitiva = newl(); // positiv list initialization
     lista_negativa = newl(); //negativ list initialization
     bool save_to_file = false;
     bool list_devided_condion = false;
     do
     {
          sleep(2); // sleep for 3 seconds
          system("clear");
          printf("\n################################\n");
          printf("Bine ai venit in programul meu!!!\n");
          sleep(1);
          printf("1 - citeste un numar intreg si - l introduce la inceputul listei.\n");
          sleep(1);
          printf("?2 - citeste un fisier text ce contine numere intregi separate prin spatii\nsi le introduce in lista (la sfarsitul listei)\n");
          sleep(1);
          printf("3 - afiseaza lista.\n");
          sleep(1);
          printf("?4 |adauga functie| - insereaza un element  in lista dupa un element cu informatia data.\n");
          sleep(1);
          printf("5 - cauta un element in lista.\n");
          sleep(1);
          printf("6 - elimina primul element din lista.\n");
          sleep(1);
          printf("7 - elimina ultimul element din lista.\n");
          sleep(1);
          printf("?8 - elimina din lista elementul cu informatia x.\n");
          sleep(1);
          printf("9 - salveaza lista intr-un fisier text.\n");
          sleep(1);
          printf("10 - din lista L se formeaza doua noi liste, una ce contine elementele\nnegative si una continând elementele pozitive.\n");
          sleep(1);
          printf("11 - afiseaza lista continand elementele pozitive.\n");
          sleep(1);
          printf("12 - afiseaza lista continand elementele negative.\n");
          sleep(1);
          printf("13 - informatii despre autor.\n");
          sleep(1);
          printf("14 - terminare program.\n");
          sleep(1);
          printf("Optiunea ta aici :> ");
          sleep(1);
          scanf("%d", &check_condition);
          printf("\n################################\n");

          switch (check_condition)
          {
          case 1:
               printf("\nIntroduceti un numar pentru a fi adaugat la inceputul listei: ");
               scanf("%d", &user_element);
               my_list = ins_in_fata(my_list, user_element);

               break;
          case 2: // to solve this program

               break;
          case 3:
               string_whit_elements = toStringl(my_list, string_whit_elements);
               printf("%s\n", string_whit_elements);
               break;
          case 4:

               break;
          case 5:
               printf("Introduceti numarul pe care doriti sa-l cautati in lista! : ");
               scanf("%d", &user_element);
               my_element = cauta(my_list, user_element);
               if (my_element != 0)
               {
                    printf("Elementul %d a fost gasit!\n", user_element);
               }
               else
               {
                    printf("Elementul %d nu a fost gasit!\n", user_element);
               }

               break;
          case 6:
               my_list = sterge_primul(my_list); // delete last element
               break;
          case 7:
               my_list = sterge_primul(my_list); //delete first element
               break;
          case 8:
               printf("Introduceti numarul x pentru a fi sters: ");
               scanf("%d", &user_element);
               my_list = delete_X_element(my_list, user_element);
               break;
          case 9:
               save_to_file = saveListToFile(my_list);
               if (save_to_file == false)
               {
                    printf("The list don't exist!\n");
               }
               else if (save_to_file = true)
               {
                    printf("The list writed succesufuly!\n");
               }

               break;
          case 10:
               list_devided_condion = creareListeNoiPozitivaNegativa(my_list, lista_pozitiva, lista_negativa);
               if (list_devided_condion == true)
               {
                    printf("List are devided in 2 parts!\n");
               }
               else
               {
                    printf("List are not devided!\n");
               }

               break;
          case 11:
               string_whit_elements = toStringl(lista_pozitiva, string_whit_elements);
               printf("%s", string_whit_elements);
               break;
          case 12:
               string_whit_elements = toStringl(lista_negativa, string_whit_elements);
               printf("%s", string_whit_elements);
               break;
          case 13:
               userInfo();
               break;
          case 14:
               destroyl(my_list);
               break;
          default:
               printf("Ai introdus o optiune invalida.\n");
               break;
          }

     } while (check_condition != 14);

     return 0;
}
