#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "student.h"
struct student
{
     char *nume;
     char *prenume;
     float medie;
     short codprogram;
};
STUDENT newStud()
{
     STUDENT s = (STUDENT)calloc(1, sizeof(struct student));
     assert(s != NULL);
     return s;
}
STUDENT newStudent(char *nume, char *prenume, float medie, int codprg)
{
     STUDENT s = newStud();
     setNume(s, nume);
     setPrenume(s, prenume);
     setMedieAdmitere(s, medie);
     setProgram(s, codprg);
}
char *getNume(STUDENT s)
{
     assert(s != NULL);
     return s->nume;
}
char *getPrenume(STUDENT s)
{
     assert(s != NULL);
     return s->prenume;
}
float getMedieAdmitere(STUDENT s)
{
     assert(s != NULL);
     return s->medie;
}
short int getProgram(STUDENT s)
{
     assert(s != NULL);
     return s->codprogram;
}
char *alocaText(char *text)
{
     char *sir = (char *)malloc(strlen(text) + 1);
     assert(sir != NULL);
     strcpy(sir, text);
     return sir;
}
void setNume(STUDENT s, char *nume)
{
     assert(s != NULL || nume != NULL);
     s->nume = alocaText(nume);
}
void setNume(STUDENT s, char *prenume)
{
     assert(s != NULL || prenume != NULL);
     s->prenume = alocaText(prenume);
}
void setMedieAdmitere(STUDENT s, float medie)
{
     assert(s != NULL);
     s->medie = medie;
}
void setProgram(STUDENT s, short int codprogram)
{
     assert(s != NULL);
     s->codprogram = codprogram;
}
bool equalsStud(STUDENT s, STUDENT t)
{
     assert(s != NULL && t != NULL);
     return strcmp(s->nume, t->nume) == 0 && strcmp(s->prenume, t->prenume) == 0 && s->medie = t->medie && s->codprogram == t->codprogram;
}
char *toString(STUDENT s, char *zona)
{
     assert(s != NULL);
     sprintf(zona, "%s\t%s\t%.2f\t%d", s->nume, s->prenume, s->medie, s->codprogram);
     return zona;
}
void deleteStud(STUDENT s)
{
     if (s != NULL)
     {
          free(s->nume);
          free(s->prenume);
          free(s);
     }
}