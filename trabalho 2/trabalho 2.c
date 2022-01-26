#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trab2.h"


int main()
{
    struct aluno *head = NULL;
    head = start(head);
    add_node(head);
    print_node(head);
    

    return 0;
}
