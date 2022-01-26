#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    int matricula;
    char nome[40];
    float nota;
    struct aluno *link;
};



    struct aluno *ordem_alfab(struct aluno *head) {
    
    struct aluno *pont1 = malloc(sizeof(struct aluno));
    if (pont1 == NULL) {
        abort();
    }
     printf("Digite o nome do aluno: \n");
        scanf("%s", &pont1->nome);
        printf("Digite a matricula do aluno: \n");
        scanf("%i", &pont1->matricula);
        printf("Digite a nota do aluno: \n");
        scanf("%f", &pont1->nota);

    if (head == NULL || strcmp(pont1->nome, head->nome) < 0) {
        pont1->link = head;
        return pont1;
    } else {
        struct aluno *pont2 = head;
        while (pont2->link != NULL && strcmp(pont1->nome, pont2->link->nome) >= 0) {
            pont2 = pont2->link;
        }
        pont1->link = pont2->link;
        pont2->link = pont1;
        return head;
    }
}

void print_node(struct aluno *head)
{
    if (head == NULL)
    {
        printf("A lista está vazia");
    }
    struct aluno *pont1 = NULL;
    pont1 = head;
   
    while (pont1 != NULL)
    {
        printf("Nome: %s \n", pont1->nome);
        printf("Matricula: %i\n", pont1->matricula);
        printf("Nota: %.2f\n", pont1->nota);
        printf("*******************\n");
        pont1 = pont1->link;
    }
}
