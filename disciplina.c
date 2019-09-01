#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"


DISCIPLINA* Cadastrar_disciplina(DISCIPLINA *p , int *sizeD){
    system("clear");
    int op = 0;

    do{
        p = insere_disciplina(p,sizeD,ler_disciplina());// insere uma posição para cadastrar um turma

        system("clear");

        printf("-Digite 1 para fazer um novo cadastro. \n-Digite 2 para voltar ao menu.\n");
        printf(">> ");
        scanf("%d",&op);
        if(op == 2)
            return p;
    }while(op == 1);

    return p;
}

DISCIPLINA ler_disciplina(){
    
    DISCIPLINA disciplina;

    printf("DIGITE O ID DA DISCIPLINA: \n");
    scanf("%d",&disciplina.id);
    getchar();
    printf("DIGITE A DISCIPLINA: \n");
    scanf("%[^\n]", disciplina.nome);
    getchar();
    printf("DIGITE O PROFESSOR DA DISCIPLINA: \n");
    scanf("%[^\n]", disciplina.professor);
    getchar();

    return disciplina;
}


DISCIPLINA* insere_disciplina(DISCIPLINA *v, int *n, DISCIPLINA novo){

    v = (DISCIPLINA*) realloc(v,(*n+1) * sizeof(DISCIPLINA));

    if(v == 0){
        printf("Memoria insuficiente");
        return 0;
    }
    v[*n] = novo;
    (*n)++; // adicionando uma posição 

    return v;
}

void ImprimeM(DISCIPLINA *p, int sizeD){
    system("clear");
        printf("======= DISCIPLINAS CADASTRADAS ===========\n");
    for(int i = 0; i < sizeD; i++){
        printf("%d - %s\n",p[i].id,p[i].nome);
        puts("");
    }
        printf("===========================================\n");
    getchar();
    getchar();
    return;
}

void ImprimeD(DISCIPLINA *p, int *sizeD){
    system("clear");
    for(int i = 0; i < *sizeD; i++){
        printf("IDENTIFICADOR: %d\n",p[i].id);
        printf("DISCIPLINA %s\n",p[i].nome);
        printf("PROFESSOR DA DISCIPLINA: %s\n",p[i].professor);
        puts("");
        printf("=======================================\n");
    }
    getchar();
    getchar();
    return;
}