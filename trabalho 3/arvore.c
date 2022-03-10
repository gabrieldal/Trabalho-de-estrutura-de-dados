#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
    int data;
    struct arvore *esquerda;
    struct arvore *direita;
} _arvore;

_arvore *raiz = NULL;

_arvore *criarnodo(int numero)
{
    _arvore *node = malloc(sizeof(_arvore));
    if (node != NULL)
    {
        node->esquerda = NULL;
        node->direita = NULL;
        node->data = numero;
        return node;
    }
    else
    {
        printf("ERRO!");
        return;
    }
}

_arvore *inserir(_arvore *node, int numero)
{
    if (node == NULL)
    {
        node = criarnodo(numero);
        return node;
    }

    if (numero == node->data)
    {
        printf("\nNumero ja adicionado!\n");
        return node;
    }
    
    
    if (numero < node->data)
    {
        node->esquerda = inserir(node->esquerda, numero);
    }
    else
    {
        node->direita = inserir(node->direita, numero);
    }
    
    return node;
}

void encontrarnodo(_arvore *node, int key, _arvore *root)
{
    if (node == NULL)
    {
        printf("Key not found");
        return;
    }
 
    if (node->data == key)
    {
        if (key == root->data) {
            printf("A celula que contem %d eh a celula raiz", key);
        }
        else if (key < root->data)
        {
            printf("O valor dado e da celula esquerda da celula com o valor %d", root->data);
        }
        else  {
            printf("O valor dado e da celula direita da celula com o valor %d", root->data);
        }
 
        return;
    }
    
    if (key < node->data) {
        encontrarnodo(node->esquerda, key, node);
    } else {
        encontrarnodo(node->direita, key, node);
    }
}

void tab(int numero)
{
    for (int i = 0; i < numero; i++)
    {
        printf("\t");
    }
}

void printfarvore(_arvore *node, int nivel)
{
    if (node == NULL)
    {
        tab(nivel);
        printf("***<vazio>***\n");
        return;
    }
    tab(nivel);
    printf("O valor: %d\n", node->data);

    tab(nivel);
    printf("Para esquerda:\n");
    printfarvore(node->esquerda, nivel+1);

    tab(nivel);
    printf("Para direita:\n");
    printfarvore(node->direita, nivel+1);
    
    tab(nivel);
    printf("nivel: %d\n", nivel+1);
}

void liberararvore(_arvore *node)
{
    if (node == NULL)
        return;
    
    free(node->data);
    liberararvore(node->esquerda);
    liberararvore(node->direita);
    free(node);
}