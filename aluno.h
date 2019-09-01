
#ifndef ALUNO_H
#define ALUNO_H
#include "funcao_arquivo.h"

ALUNO* Cadastrar_aluno(ALUNO *p , int *size);

ALUNO ler_aluno();

ALUNO* insere_aluno(ALUNO *v, int *n, ALUNO novo);

void Imprime(ALUNO *p, int *size);

void remove_aluno(ALUNO *v, int *n);

void Buscar_aluno(ALUNO *p,MATRICULA *m, DISCIPLINA *d, int *size, int *sizeM,int *sizeD);

void ATUALIZA(ALUNO *a, int *size);

#endif
