/*
Gabriel Dalmazo Dambros
Matícula 2110103375
Trabalho 3 - Árvores Binárias de Pesquisa
gabrieldambros.aluno@unipampa.edu.br
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    int opcao = 0;
    int numero;
    while (opcao != 4)
    {
        
        printf("1. Inserir\n");
        printf("2. Printar\n");
        printf("3. Buscar\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 1:

            printf("Informe um numero para adicionar na arvore: ");
            scanf("%d", &numero);
            raiz = inserir(raiz, numero);

            break;

        case 2:

            printfarvore(raiz, 0);

            break;

        case 3:

            printf("Informe um numero para buscar: ");
            scanf("%d", &numero);

            encontrarnodo(raiz, numero, raiz);

            break;

        case 4:
            liberararvore(raiz);
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }

    return 0;
}