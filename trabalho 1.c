/*  
Gabriel Dalmazo Dambros
Matícula 2110103375
Trabalho 1 de Estrutura de Dados - Ponteiros e alocação dinâmica de memória
gabrieldambros.aluno@unipampa.edu.br
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct _produto{
    char descricao[80];
    long int codigo;
    float valor;

};

typedef struct _produto tipo_produto;

int main(){

    int cont=0,x;
    float y;

    tipo_produto novo[cont], *coisa;

    printf("Quantos produtos estao na lista?\n");
    scanf("%i", &cont);

    coisa = malloc(cont*sizeof(tipo_produto));

    for(x=0; x<cont; x++){
        printf("Informe o codigo do produto: ");
        scanf("%i", &novo[x].codigo);
        printf("Informe o valor do produto: ");
        scanf("%f", &novo[x].valor);
        printf("Informe a descricao do produto: ");
        scanf("%s", &novo[x].descricao);
        fflush;
    }
    
    printf("Codigo\tValor\tdescricao\n");

    for(x=0; x<cont; x++){
        printf("%i\t%.2f\t%s\n",novo[x].codigo, novo[x].valor, novo[x].descricao);
    }

    for(x=0; x<cont; x++){
        y=novo[x].valor+y;
    }
    
    printf("Valor total dos produtos: %.2f", y);

    free(coisa);

return 0;
}