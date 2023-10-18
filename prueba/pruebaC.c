#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo del árbol binario
struct Arbol {
    long long value;
    struct Arbol* left;
    struct Arbol* right;
};


// Declaración de la función en ensamblador para crear un nodo del árbol
// Al llamar al metodo createArbol utulizamos la funcion creada en ensamblador que crea la estructura de arbol 
extern struct Arbol* createArbol_asm(struct Arbol* nodo);

  
// Función para insertar un nuevo nodo en el árbol
struct Arbol* insertarNodo(struct Arbol* root, long long value) {
    if (root == NULL) {    
        struct Arbol* nodo = malloc(sizeof(struct Arbol));
        nodo->value = value;
        nodo->left = NULL;
        nodo->right = NULL;
        return createArbol_asm(nodo);
    }

    if (value < root->value) {
        root->left = insertarNodo(root->left, value);
    } else {
        root->right = insertarNodo(root->right, value);
    }

    return root;
}

// Función para imprimir el árbol
void imprimirArbol(struct Arbol* root, int espacio) {
    // Si el árbol está vacío, retornar
    if (root == NULL)
        return;

    // Incrementar la distancia entre niveles
    espacio += 10;

    // Procesar el nodo derecho primero
    imprimirArbol(root->right, espacio);

    // Imprimir el nodo actual después de dar espacio
    printf("\n");
    for (int i = 10; i < espacio; i++)
        printf(" ");
    printf("%lld\n", root->value);

    // Procesar el nodo izquierdo
    imprimirArbol(root->left, espacio);
}

// Función auxiliar para imprimir el árbol
void imprimir(struct Arbol* root) {
   // Pasar el número inicial de espacios como 0
   imprimirArbol(root, 0);
}


int main() {
    
    struct Arbol* root = NULL;
    int c;

    while (1) {
        long long value;
        printf("Ingrese un valor para el nodo: ");
        scanf("%lld", &value);
        while ((c = getchar()) != '\n' && c != EOF) { }  // Limpia el buffer de entrada

        root = insertarNodo(root, value);

        char continuar;
        printf("¿Desea ingresar otro valor? (s/n): ");
        scanf(" %c", &continuar);
        while ((c = getchar()) != '\n' && c != EOF) { }  // Limpia el buffer de entrada

        if (continuar != 's') {
            break;
        }
    }

    printf("El árbol es: \n");
    imprimir(root);
    
    return 0;
}