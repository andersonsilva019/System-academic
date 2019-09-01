
#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "funcao_arquivo.h"

DISCIPLINA* Cadastrar_disciplina(DISCIPLINA *p ,int *sizeD);

DISCIPLINA ler_disciplina();

DISCIPLINA* insere_disciplina(DISCIPLINA *v, int *n, DISCIPLINA novo);

void ImprimeM(DISCIPLINA *p, int sizeD);

void ImprimeD(DISCIPLINA *p, int *sizeD);

#endif
