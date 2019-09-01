#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"
#include "funcao_arquivo.h"
#include "matricula.h"
#include "menu.h"

void menu_principal(ALUNO *aluno, DISCIPLINA *turma, MATRICULA *matricula, int *size, int *sizeD, int *sizeM,FILE *f){
        int op = 0;
    do{
        system("clear");
        //Imprime(aluno,size);
        printf("=========================================\n");
        printf("=                                       =\n");
        printf("=          MENU DE OPÇÕES               =\n");
        printf("=                                       =\n");
        printf("=                                       =\n");
        printf("=     1-  SECRETARIA ACADEMICA          =\n");
        printf("=                                       =\n");
        printf("=========================================\n");

        scanf(" %d",&op);


        switch(op){
            //case 1:
            //    menu_aluno(aluno,turma,matricula,size,sizeD,sizeM); //chama minha função de cadastrar o cliente
            //break;
            case 1:
                chamar_menu(aluno,turma,matricula,size,sizeD,sizeM,f);
            break;
        }

    }while(1);
}

void chamar_menu(ALUNO *aluno, DISCIPLINA *disciplina, MATRICULA *matricula, int *size, int *sizeD, int *sizeM,FILE *f){

        int op = 0;
    do{
        system("clear");
        printf("==============================================\n");
        printf("=                                            =\n");
        printf("=          MENU DE OPÇÕES                    =\n");
        printf("=                                            =\n");
        printf("=                                            =\n");
        printf("=     1-  NOVO ALUNO                         =\n");
        printf("=     2-  BUSCAR ALUNO                       =\n");
        printf("=     3-  ATUALIZAR DADOS ALUNO              =\n");
        printf("=     4-  EXCLUIR ALUNO                      =\n");
        printf("=     5   VER ALUNOS CADASTRADOS             =\n");
        printf("=     6-  CADASTRAR DISCIPLINA               =\n");
        printf("=     7-  VER DISCIPLINA                     =\n");
        printf("=     8-  MATRICULAR ALUNO                   =\n");
        printf("=     9-  SAIR                               =\n");
        printf("=                                            =\n");
        printf("==============================================\n");

        scanf(" %d",&op);


        switch(op){
            case 1:
                aluno = Cadastrar_aluno(aluno,size); //chama minha função de cadastrar o cliente
            break;
            case 2:
                Buscar_aluno(aluno, matricula, disciplina, size, sizeM, sizeD); //chama minha função de buscar cliente
            break;
            case 3:
                ATUALIZA(aluno,size);
            break;
            case 4:
                remove_aluno(aluno,size);
            break;
            case 5:
                Imprime(aluno,size);
            break;
            case 6:
                disciplina = Cadastrar_disciplina(disciplina,sizeD); //chama minha função de buscar cliente
            break;
            case 7:
                ImprimeD(disciplina,sizeD); //Imprime os dados da estrutura disciplina
            break;
            case 8:
                matricula = matricular(aluno,matricula,disciplina,size,sizeM,sizeD); //chama minha função para matricular o aluno
            break;
            case 9:
                // Escrevendo em arquivo
                Imprime_arquivo_aluno(f,aluno,size);
                Imprime_arquivo_disciplina(f,disciplina,sizeD);
                Imprime_arquivo_matricula(f,matricula,sizeM);
                exit(1);
            break;
        }

    }while(1);
}