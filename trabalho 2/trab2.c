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

struct aluno *ordem_alfab(struct aluno *head)
{

    struct aluno *pont1 = malloc(sizeof(struct aluno));
    if (pont1 == NULL)
    {
        abort();
    }
    fflush(stdin);
    printf("Digite o nome do aluno: \n");
    gets(pont1->nome);
    fflush(stdin);
    printf("Digite a matricula do aluno: \n");
    scanf("%i", &pont1->matricula);
    printf("Digite a nota do aluno: \n");
    scanf("%f", &pont1->nota);

    if (head == NULL || strcmp(pont1->nome, head->nome) < 0)
    {
        pont1->link = head;
        return pont1;
    }
    else
    {
        struct aluno *pont2 = head;
        while (pont2->link != NULL && strcmp(pont1->nome, pont2->link->nome) >= 0)
        {
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
struct aluno *deletar(struct aluno *head)
{
    if (head == NULL)
    {
        printf("A lista esta vazia!\n");
    }
    else
    {
        struct aluno *pont2 = head;
        struct aluno *pont1 = head;
        char nome[40];
        fflush(stdin);
        printf("Digite o nome do aluno que deseja deletar: ");
        gets(nome);
        fflush(stdin);
        if (strcmp(nome, head->nome) == 0)
        {
            head = head->link;
            free(pont2);
            free(pont1);
            pont2 = NULL;
            pont1 = NULL;
            printf("\nDeletado!");
        }
        else
        {
            while (strcmp(nome, pont2->nome) != 0 && pont2->link != NULL)
            {
                pont1 = pont2;
                pont2 = pont2->link;
            }
            if (strcmp(nome, pont2->nome) == 0)
            {
                pont1->link = pont2->link;
                free(pont2);
                pont2 = NULL;
                printf("\nDeletado!\n");
            }
            else
            {
                printf("\nAluno inexistente.");
            }
        }
    }
    return head;
}
