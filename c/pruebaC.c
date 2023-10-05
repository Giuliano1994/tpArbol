#include <stdio.h>
#include <stdlib.h>

// Declaración de la función en ensamblador para crear un nodo del árbol
// Al llamar al metodo createArbol utulizamos la funcion creada en ensamblador que crea la estructura de arbol 
extern struct Arbol* createArbol(long long value, struct Arbol* left, struct Arbol* right);

// Estructura del nodo del árbol binario
struct Arbol {
    long long value;
    struct Arbol* left;
    struct Arbol* right;
};

//Funcion para imprimir el arbol
void imprimirArbol(struct Arbol* root, int nivel) {
    if (root == NULL) {
        return;
    }

    // Recorre el subárbol derecho primero
    imprimirArbol(root->right, nivel + 1);

    // Indenta según el nivel
    for (int i = 0; i < nivel; i++) {
        printf("   ");
    }

    // Imprime el valor del nodo
    printf("%lld\n", root->value);

    // Recorre el subárbol izquierdo
    imprimirArbol(root->left, nivel + 1);
}

// Función para insertar un nuevo nodo en el árbol
// se utiliza la funcion createArbol generada en ensamblador
struct Arbol* insertarNodo(struct Arbol* root, long long value){
    
    // Si el árbol está vacío, crea un nuevo nodo
    if (root == NULL) {    
        return createArbol(value, NULL, NULL);
    }

    // Si el valor es menor, inserta en el subárbol izquierdo
    if (value < root->value) { 
        root->left = insertarNodo(root->left, value);
    } 

    // Si el valor es mayor o igual, inserta en el subárbol derecho
    else {
        root->right = insertarNodo(root->right, value);
    }

    printf("Árbol actualizado:\n");
    imprimirArbol(root, 0);
    return root;
}

int main() {
    
    struct Arbol* root = NULL;
    
    while (1) {
        long long value;
        printf("Ingrese un valor para el nodo: ");
        scanf("%lld", &value);
        
        root = insertarNodo(root, value);
        
        char continuar;
        printf("¿Desea ingresar otro valor? (s/n): ");
        scanf(" %c", &continuar);
        
        if (continuar != 's') {
            break;
        }
    }
    
    // Liberar memoria dinámica utilizada por los nodos del árbol
    free(root);
    
    return 0;
}