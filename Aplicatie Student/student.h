#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include <stdbool.h>
typedef struct student *STUDENT;

STUDENT newStud();
STUDENT newStudent(char *name, char *prenume, float medie, int codprg);
char *getNume(STUDENT s);
char *getPrenume(STUDENT s);
float getMedieAdmitere(STUDENT s);
short int getProgram(STUDENT s);
void setNume(STUDENT s, char *prenume);
void setPrenume(STUDENT s, char *prenume);
void setMedieAdmitere(STUDENT s, float medie);
void setProgram(STUDENT s, short int codprg);

bool equalsStud(STUDENT s, STUDENT t);
char *toString(STUDENT s, char *zona);
void deleteStud(STUDENT s);


#endif // !_STUDENT_H_INCLUDED