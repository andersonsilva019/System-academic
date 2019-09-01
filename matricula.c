#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"
#include "matricula.h"



MATRICULA* matricular(ALUNO *a, MATRICULA *p , DISCIPLINA *d ,int *size, int *sizeM, int *sizeD){
    system("clear");
    int op = 0;

    do{
        p = insere_matricula(p,sizeM,ler_matriculados(a,p,d,size,sizeM,sizeD));// insere uma posição para cadastrar um turma

        puts("");
        printf("-Digite 1 para fazer um nova matricula. \n-Digite 2 para voltar ao menu.\n");
        printf(">> ");
        scanf("%d",&op);
        if(op == 2)
            return p;
    }while(op == 1);

    return p;
}


MATRICULA ler_matriculados(ALUNO *a, MATRICULA *p , DISCIPLINA *d,int *size, int *sizeM, int *sizeD){

    int encontrou = 0;
    // Falta fazer a verificação se exite na função aluno
    printf("DIGITE A MATRICULA: \n");
    scanf("%d",&(*p).mat);
    for(int i = 0; i < *size;i++){
        if(a[i].matricula == (*p).mat){
            encontrou = 1;
            break;
        }else
            printf("Matricula inexistente\n");
    }
    if(encontrou){
        ImprimeM(d,*sizeD);
        printf("DIGITE O ID DA DISCIPLINA: \n");
        scanf("%d",&(*p).id);
        getchar();
    }

    return *p;

}

MATRICULA* insere_matricula(MATRICULA *v, int *n, MATRICULA novo){

    v = (MATRICULA*) realloc(v,(*n+1) * sizeof(MATRICULA));

    if(v == 0){
        printf("Memoria insuficiente");
        return 0;
    }
    v[*n] = novo;
    (*n)++; // adicionando uma posição

    return v;
}
