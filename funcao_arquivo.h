
#ifndef FUNCAO_ARQUIVO_H
#define FUNCAO_ARQUIVO_H

#include <stdio.h>

typedef struct{

    int matricula;
    char nome[50];
    char curso[20];
    float nota[4];
    
    
}ALUNO;

typedef struct {
    int id;
    char nome[50];
    char professor[50];
}DISCIPLINA;

typedef struct{
    int mat;
    int id;
}MATRICULA;


ALUNO* InitA(FILE *f, ALUNO *a, int *size);
DISCIPLINA* InitD(FILE *f, DISCIPLINA *d, int *sizeD);
MATRICULA* InitM(FILE *f, MATRICULA *m, int *sizeM);
void Imprime_arquivo_aluno(FILE *f, ALUNO *a, int *size);
void Imprime_arquivo_disciplina(FILE *f, DISCIPLINA *d, int *sizeD);
void Imprime_arquivo_matricula(FILE *f, MATRICULA *m, int *sizeM);


#endif