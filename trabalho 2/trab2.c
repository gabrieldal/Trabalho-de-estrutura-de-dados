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

struct aluno *start(struct aluno *head)
{

    head = malloc(sizeof(struct aluno));
    printf("Digite o nome do aluno: \n");
    scanf("%s", &head->nome);
    printf("Digite a matricula do aluno: \n");
    scanf("%i", &head->matricula);
    printf("Digite a nota do aluno: \n");
    scanf("%f", &head->nota);
    head->link = NULL;
    return head;
}

void add_node(struct aluno *head)
{
    struct aluno *pont1, *pont2;
    pont1 = head;
    pont2 = malloc(sizeof(struct aluno));
    printf("Digite o nome do aluno: \n");
    scanf("%s", &pont2->nome);
    printf("Digite a matricula do aluno: \n");
    scanf("%i", &pont2->matricula);
    printf("Digite a nota do aluno: \n");
    scanf("%f", &pont2->nota);
    while (pont1->link != NULL)
    {
        pont1 = pont1->link;
    }
    pont1->link = pont2;
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