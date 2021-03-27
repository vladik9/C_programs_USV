#include <stdio.h>
#include "data.h"
#include "listai2.h"
#include "listai2.c"

int main()
{
     int check_condition = 0;
     LISTA my_list;
     ELEMENT my_element;
     FILE *ptr_file;
     char *list = NULL;
     bool flag_inserare = 0;
     do

     {
          printf("\n################################\n");
          printf("Bine ai venit in programul meu!!!\n");

          printf("1 - citeşte un număr întreg şi - l introduce la inceputul listei.\n");
          printf("2 - citeşte un fişier text ce contine numere intregi separate prin spatii\nsi le introduce in lista (la sfarsitul listei)\n");
          printf("3 - afişeaza lista.\n");
          printf("4 |adauga functie| - insereaza un element  in lista dupa un element cu informatia data.\n");
          printf("5 - cauta un element în lista.\n");
          printf("6 - elimină primul element din lista.\n");
          printf("7 - elimină ultimul element din lista.\n");
          printf("8 - elimina din lista elementul cu informatia x.\n");
          printf("9 - salvează lista într-un fişier text.\n");
          printf("10 - din lista L se formează două noi liste, una ce contine elementele\nnegative şi una conţinând elementele pozitive.\n");
          printf("11 - afişeaza lista conţinând elementele pozitive.\n");
          printf("12 - afişează lista conţinând elementele negative.\n");
          printf("13 - informatii despre autor.\n");
          printf("14 - terminare program.\n");
          printf("Optiunea ta aici :> ");
          scanf("%d", &check_condition);
          printf("\n################################\n");

          switch (check_condition)
          {
          case 1:

               my_list = newl();
               int num = 0;

               printf("\nIntroduce numarul dorit: ");
               if (flag_inserare == 0)
               {
                    scanf("%d", &num);
                    my_list = ins_in_fata(my_list, num);
                    flag_inserare = 1;
               }
               else if (flag_inserare == 1)
               {
                    scanf("%d", &num);
                    my_list = ins_la_urma(my_list, num);
               }

               break;
          case 2: // to solve this program

               ptr_file = fopen("in.txt", "r");
               if (ptr_file == NULL)
               {
                    printf("Error opening file num.txt\n");
               }
               int nume_file = 0;
               break;
          case 3:
               list = (char *)malloc(my_list->nr * sizeof(char));
               list = toStringl(my_list, list);
               printf("%s\n", list);
               break;
          case 4:
               break;
          case 5:
               break;
          case 6:
               break;
          case 7:
               break;
          case 8:
               break;
          case 9:
               break;
          case 10:
               break;
          case 11:
               break;
          case 12:
               break;
          case 14:
               break;
          default:
               printf("Ai introdus o optiune invalida.\n");
               break;
          }

     } while (check_condition != 14);

     return 0;
}
