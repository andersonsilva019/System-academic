#ifndef MENU_H
#define MENU_H

#include "funcao_arquivo.h"

void menu_principal(ALUNO *aluno, DISCIPLINA *turma, MATRICULA *matricula, int *size, int *sizeD, int *sizeM,FILE *f);

void chamar_menu(ALUNO *aluno, DISCIPLINA *disciplina, MATRICULA *matricula, int *size, int *sizeD, int *sizeM,FILE *f);

#endif