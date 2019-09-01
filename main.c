#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"
#include "matricula.h"
#include "funcao_arquivo.h"
#include "menu.h"


int main(){

    FILE *f;

    // Alocando uma única posição
    int *size = (int*) malloc(sizeof(int));
    int *sizeD = (int*) malloc(sizeof(int));
    int *sizeM = (int*) malloc(sizeof(int));

    if(size == 0){
        printf("Erro: Memória insufuciente");
        return 0;
    }
    if(sizeD == 0){
        printf("Erro: Memória insufuciente");
        return 0;
    }
    if(sizeM == 0){
        printf("Erro: Memória insufuciente");
        return 0;
    }
    *size = 0;
    *sizeD = 0; // iniciando a variável
    *sizeM = 0;

    ALUNO *aluno;
    aluno = (ALUNO*) malloc(sizeof(ALUNO));
    if(aluno == 0){
        printf("Erro: Memória insuficiente - Aluno");
        return 0;
    }

    DISCIPLINA *turma;
    turma = (DISCIPLINA*) malloc(sizeof(DISCIPLINA));
    if(turma == 0){
        printf("Erro: Memória insuficiente - Professor");
        return 0;
    }

    MATRICULA *matricular;
    matricular = (MATRICULA*) malloc(sizeof(MATRICULA));
    if(matricular == 0){
        printf("Erro: Memória insuficiente - Professor");
        return 0;
    }

    printf("======================================\n");
    printf("=                                    =\n");
    printf("=               UPSIPPA              =\n");
    printf("=                                    =\n");
    printf("=                                    =\n");
    printf("=  SEJA BEM VINDO AO NOSSO SISTEMA   =\n");
    printf("=                                    =\n");
    printf("=                                    =\n");
    printf("=   APERTE ENTER PARA CONTINUAR      =\n");
    printf("======================================\n");
    getchar();

    //Funções para carregar os dados dos arquivos para os vetores
    aluno = InitA(f,aluno,size); // carrega os dados de aluno
    turma = InitD(f,turma,sizeD); // carrega os dados de turma(as diciplinas)
    matricular = InitM(f,matricular,sizeM); // carrega as matriculas

    menu_principal(aluno,turma,matricular,size,sizeD,sizeM,f);



    free(aluno); // Liberando memória de aluno
    free(turma);
    free(matricular);// Liberando memória do turma
    free(size);
    free(sizeD);
    free(sizeM); // Liberando memória do tamanho do vetor

}


