section .data

section .text
global createArbol_asm

createArbol_asm:
  push ebp
  mov ebp, esp

  ; Argumento de la estructura ArbolCreationData
  mov eax, [ebp+8]  ; Accede al puntero a la estructura Arbol
  mov ecx, [eax]  ; Accede al valor
  mov esi, [eax + 4]  ; Accede al puntero izquierdo
  mov edx, [eax + 8]  ; Accede al puntero derecho

  ; Lógica para crear el nodo usando los argumentos
  mov [eax], ecx  ; Guarda el valor
  mov [eax + 4], esi  ; Guarda el puntero izquierdo
  mov [eax + 8], edx  ; Guarda el puntero derecho

  pop ebp
  ret

