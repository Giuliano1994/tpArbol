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
extern struct Arbol* createArbol(long long value, struct Arbol* left, struct Arbol* right); 
  


void imprimirArbol(struct Arbol *nodo){
    if(nodo != 0){
        if(nodo->left != 0){
            imprimirArbol(nodo->left);
        }
        printf("%lld\n",nodo->value);
        if(nodo->right != 0){
            imprimirArbol(nodo->right);
        }
    }
}

/*
void imprimirArbol(struct Arbol* nodo) {
    if (nodo != NULL) {
        // Imprime el valor del nodo actual
        printf("%lld\n", nodo->value);

        // Llama recursivamente a la función para los subárboles izquierdo y derecho
        imprimirArbol(nodo->left);
        imprimirArbol(nodo->right);
    }
}

*/
/*
//Funcion para imprimir el arbol
void imprimirArbol2(struct Arbol* root, int nivel) {
    if (root == NULL) {
        return;
    }
    
    // Imprime espacios para la indentación
    for (int i = 0; i < nivel; i++) {
        printf("   ");
    }
    
    // Imprime el valor del nodo
    printf("%lld\n", root->value);

    // Recorre primero el subárbol izquierdo
    imprimirArbol2(root->left, nivel + 1);
    
    // Luego, recorre el subárbol derecho
    imprimirArbol2(root->right, nivel + 1);
}
*/


// Función para imprimir el árbol horizontalmente por capas
void printTreeByLevels(struct Arbol* root) {
    
    printf("Valor en decimal: %lld\n", root->value);

   
    if (root == NULL) {
        return;
    }

    // Crear una cola para almacenar los nodos del árbol
    struct Arbol** queue = (struct Arbol**)malloc(sizeof(struct Arbol*) * 1000);
    int front = 0, rear = 0;

    // Agregar el nodo raíz a la cola
    queue[rear++] = root;

     while (front < rear) {
        int currentLevelSize = rear - front;
        
        // Imprimir una línea en blanco
        printf("\n");

        // Procesar todos los nodos en el nivel actual
        for (int i = 0; i < currentLevelSize; i++) {
            // Obtener el nodo actual de la cola
            struct Arbol* current = queue[front++];

            // Imprimir el valor del nodo actual
            printf("%lld ", current->value);

            // Agregar los nodos hijos a la cola
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }
    }

    // Liberar la memoria de la cola
    free(queue);
}



// Función recursiva para liberar memoria del árbol
void liberarArbol(struct Arbol* nodo) {
    if (nodo != NULL) {
        liberarArbol(nodo->left);
        liberarArbol(nodo->right);
        free(nodo);
    }
}


// Función para insertar un nuevo nodo en el árbol
// se utiliza la funcion createArbol generada en ensamblador
struct Arbol* insertarNodo(struct Arbol* root, long long value){
    
     printf("Valor: %lld\n", value);

    // Si el árbol está vacío, crea un nuevo nodo
    if (root == NULL) {    
        return createArbol(value, NULL, NULL);
    }

      // Si el valor es menor, inserta en el subárbol izquierdo
    if (value < root->value) { 
        if(root->left != NULL){
            root->left = insertarNodo(root->left, value);
        } else {
            root->left = createArbol(value, NULL, NULL);
        }
    } 

    // Si el valor es mayor o igual, inserta en el subárbol derecho
    else {
        if(root->right != NULL){
            root->right = insertarNodo(root->right, value);
        } else {
            root->right = createArbol(value, NULL, NULL);
        }
    }

    printf("Árbol actualizado:\n");
   // imprimirArbol2(root, 0);
    imprimirArbol(root);
   // printTreeByLevels(root);
   liberarArbol(root);
    return root;
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
    
    printf("Árbol final:\n");
 //   printTreeByLevels(root);
   // imprimirArbol(root);
    // Liberar memoria del árbol
    liberarArbol(root);
    
    return 0;
}