
#ifndef MATRICULA_H
#define MATRICULA_H

#include "funcao_arquivo.h"



MATRICULA* matricular(ALUNO *a, MATRICULA *p , DISCIPLINA *d ,int *size, int *sizeM, int *sizeD);

MATRICULA ler_matriculados(ALUNO *a, MATRICULA *p , DISCIPLINA *d,int *size, int *sizeM, int *sizeD);

MATRICULA* insere_matricula(MATRICULA *v, int *n, MATRICULA novo);

#endif
