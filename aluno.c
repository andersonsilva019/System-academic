#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"
#include "matricula.h"


ALUNO* Cadastrar_aluno(ALUNO *p , int *size){
    system("clear");
    int op = 0;

    do{
        p = insere_aluno(p,size,ler_aluno());// insere uma posição para cadastrar um aluno

        system("clear");

        printf("-Digite 1 para fazer um novo cadastro. \n-Digite 2 para voltar ao menu.\n");
        printf(">> ");
        scanf("%d",&op);
        if(op == 2)
            return p;
    }while(op == 1);

    return p;
}

ALUNO ler_aluno(){

    ALUNO aluno;

    printf("Digite a matricula: \n");
    scanf("%d",&aluno.matricula);
    getchar();
    printf("Digite o nome completo: \n");
    scanf("%[^\n]", aluno.nome);
    getchar();
    printf("Digite o curso: \n");
    scanf("%[^\n]", aluno.curso);
    getchar();

        for(int j = 0; j < 4; j++)
            aluno.nota[j] = 0;

    return aluno;
}

ALUNO* insere_aluno(ALUNO *v, int *n, ALUNO novo){

    v = (ALUNO*) realloc(v,(*n+1) * sizeof(ALUNO));

    if(v == 0){
        printf("Memoria insuficiente");
        return 0;
    }
    v[*n] = novo;
    (*n)++; // adicionando uma posição

    return v;
}

void Imprime(ALUNO *p, int *size){
    system("clear");
    for(int i = 0; i < *size; i++){
        printf("MATRICULA: %d\n",p[i].matricula);
        printf("NOME: %s\n",p[i].nome);
        printf("CURSO %s\n",p[i].curso);
        //printf("DISCIPLINA: %s\n",p[i].disciplina);
            for(int j = 0; j < 4; j++)
                printf("%.1f | ",p[i].nota[j]);
        puts("");
        printf("=======================================\n");

    }
    getchar();
    getchar();
    return;
}

void remove_aluno(ALUNO *v, int *n){

    system("clear");

    int index = 0;
    int op = 0;
    int encontrou = 0; // variavel booleana
    int matricula = 0;

    do{
        printf("DIGITE A MATRÍCULA DO ALUNO PARA FAZER A REMOÇÃO: \n");
        scanf("%d",&matricula);
        getchar();

        for(int i = 0; i < *n; i++){

            if(matricula == v[i].matricula){
                encontrou = 1;
                index = i;
                break;
            }
        }
        if(encontrou){
            v[index] = v[*n-1];
                if(*n == 1)
                    v = (ALUNO*) realloc(v,sizeof(ALUNO));
                else
                    v = (ALUNO*) realloc(v,(*n-1) * sizeof(ALUNO));
        if(v == 0){
            printf("Memória insuficiente");
            return;
        }
        (*n)--;

        }else
            printf("Matricula inexistentes!");

        getchar();
        printf("DIGITE 1 PARA FAZER EXCLUIR NOVAMENTE.\nDIGITE 2 PARA VOLTAR AO MENU\n");
        printf(">> ");
        scanf("%d",&op);

        if(op == 2)
            return;

        system("clear");
    }while(op == 1);

}

void Buscar_aluno(ALUNO *p,MATRICULA *m, DISCIPLINA *d, int *size, int *sizeM,int *sizeD){

    system("clear");
    int encontrou = 0;
    int op = 0;
    int matricula = 0;
    int index = 0;
    int id0 = 0;

    do{
        printf("DIGITE A MATRÍCULA DO ALUNO PARA FAZER A BUSCA: \n");
        scanf("%d",&matricula);
        getchar();

        for(int i = 0; i < *size; i++){

            if(matricula == p[i].matricula){
                encontrou = 1;
                index = i;
                break;
            }
        }
        if(encontrou){
            printf("MATRICULA: %d\n",p[index].matricula);
            printf("NOME: %s\n",p[index].nome);
            printf("CURSO %s\n",p[index].curso);
            for(int i = 0; i < *sizeM;i++){
                if(matricula == m[i].mat){
                    id0=m[i].id;
                    for(int j=0;j<*sizeD;j++){
                        if(id0 == d[j].id)
                            printf("DISCIPLINA: %s ", d[j].nome);
                    }

                }
            }
            puts("");
            //printf("DISCIPLINA: %s\n",p[index].disciplina);
                for(int j = 0; j < 4; j++)
                    printf("%.1f | ",p[index].nota[j]);
        puts("");
        printf("=======================================\n");
        }else
            printf("Matricula inexistentes!");
        getchar();
        printf("DIGITE 1 PARA FAZER NOVA BUSCA.\nDIGITE 2 PARA VOLTAR AO MENU\n");
        printf(">> ");
        scanf("%d",&op);

        if(op == 2)
            return;

        system("clear");
    }while(op == 1);

}

// Atualiza

void ATUALIZA(ALUNO *a, int *size){
    system("clear");

        int op = 0;
    do{

        int mat;
        int p;   
        float nota = 0; 
        printf("Digite a matrícula do aluno: ");
        scanf("%d", &mat);
        getchar();
        for(int i=0;i<*size;i++){
            if(mat==a[i].matricula);{
                p=i;
                break;
            }
        }
        printf("Digite a nota que precisa alterar:\n");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            
            printf("Digite a nota: \n");
            scanf("%f",&nota);
            a[p].nota[0]=nota;
            break;
        
        case 2:
            
            printf("Digite a nota: \n");
            scanf("%f",&nota);
            a[p].nota[1]=nota;
            break;

        case 3:
            
            printf("Digite a nota: \n");
            scanf("%f",&nota);
            a[p].nota[2]=nota;
            break;

        case 4:
            
            printf("Digite a nota: \n");
            scanf("%f",&nota);
            a[p].nota[3]=nota;
            break;
        default:
            printf("Opção invalida");
        break;
        }

        printf("DIGITE 1 PARA FAZER OUTRA ALTERAÇÂO.\nDIGITE 2 PARA VOLTAR AO MENU\n");
        printf(">> ");
        scanf("%d",&op);

        if(op == 2)
            return;

    }while(op == 1);
}
