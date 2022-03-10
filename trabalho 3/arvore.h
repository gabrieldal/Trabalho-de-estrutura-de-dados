typedef struct arvore
{
    int data;
    struct arvore *esquerda;
    struct arvore *direita;
} _arvore;

_arvore *raiz;

_arvore *criarnodo(int num);
_arvore *inserir(_arvore *node, int num);
void tab(int num);
void printfarvore(_arvore *node, int nivel);
void liberararvore(_arvore *node);
void encontrarnodo(_arvore *root, int key, _arvore *parent);