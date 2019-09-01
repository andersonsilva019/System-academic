#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"
#include "matricula.h"
#include "funcao_arquivo.h"

ALUNO* InitA(FILE *f, ALUNO *a, int *size){
    
    ALUNO aluno;

    f = fopen("cadastroAluno.txt","r");

    if(f == 0)
        printf("Não foi possivel ler o arquivo");

    while(fscanf(f,"%d\n%[^\n]\n%[^\n]\n%f\n%f\n%f\n%f",&aluno.matricula,aluno.nome,aluno.curso,&aluno.nota[0],&aluno.nota[1],&aluno.nota[2],&aluno.nota[3]) == 7 ){
        a = insere_aluno(a,size,aluno);
    }

    fclose(f);

    return a;
}

DISCIPLINA* InitD(FILE *f, DISCIPLINA *d, int *sizeD){
    
    DISCIPLINA disciplina;

    f = fopen("cadastroDisciplina.txt","a+");

    if(f == 0)
        printf("Não foi possivel ler o arquivo");

    while(fscanf(f,"%d\n%[^\n]\n%[^\n]\n",&disciplina.id,disciplina.nome,disciplina.professor) == 3 ){
        d = insere_disciplina(d,sizeD,disciplina);
    }

    fclose(f);

    return d;
}

MATRICULA* InitM(FILE *f, MATRICULA *m, int *sizeM){
    
    MATRICULA matricula;

    f = fopen("matriculados.txt","a+");

    if(f == 0)
        printf("Não foi possivel ler o arquivo");

    while(fscanf(f,"%d\n%d\n",&matricula.mat,&matricula.id) == 2 ){
        m = insere_matricula(m,sizeM,matricula);
    }

    fclose(f);

    return m;
}

void Imprime_arquivo_aluno(FILE *f, ALUNO *a, int *size){

    
    f = fopen("cadastroAluno.txt","w");

    if(f == 0)
        printf("Não foi possivel escrever o arquivo!");
    
    for(int i = 0; i < *size;i++){
        fprintf(f,"%d\n%s\n%s\n",a[i].matricula,a[i].nome,a[i].curso);
            for(int j = 0; j < 4; j++)
                fprintf(f,"%.1f\n",a[i].nota[j]);
    }
    puts("");
    fclose(f);

}

void Imprime_arquivo_disciplina(FILE *f, DISCIPLINA *d, int *sizeD){

    f = fopen("cadastroDisciplina.txt", "w");

    if(f == 0)
        printf("Não foi possivel escrever o arquivo");
    for(int i = 0; i < *sizeD;i++)
        fprintf(f,"%d\n%s\n%s\n", d[i].id,d[i].nome,d[i].professor);
    puts("");

    fclose(f);

}

void Imprime_arquivo_matricula(FILE *f, MATRICULA *m, int *sizeM){

    f = fopen("matriculados.txt","w");

    if(f == 0)
        printf("Não foi possivel abrir o arquivo");
    for(int i = 0; i < *sizeM;i++)
        fprintf(f,"%d\n%d\n",m[i].id,m[i].mat);
    puts("");
    fclose(f);

}
