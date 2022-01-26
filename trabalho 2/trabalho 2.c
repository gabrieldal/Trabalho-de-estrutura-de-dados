#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trab2.h"

int main()
{
    int opc = 0;
    struct aluno *head = NULL;
    while (opc != 4)
    {

        printf("***MENU***\n ");
        printf("1. Cadastrar alunos\n ");
        printf("2. Consultar alunos\n ");
        printf("3. Deletar alunos\n ");
        printf("4. Sair\n ");
        printf("Opção: \n ");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            for (int x = 0; x < 3; x++)
            {
                head = ordem_alfab(head);
            }
            break;
        case 2:

            print_node(head);
            break;
        case 3:
            break;
        case 4:
            printf("\n ***SAINDO DO SISTEMA*** \n");
            break;
        default:
            printf("Opção Inválida!");
        }
    }

    return 0;
}
