
section .data
struc Arbol
  .value resq 1
  .left resq 1
  .right resq 1
endstruc

section .text
extern malloc, free
global createArbol

createArbol_asm:
  ; Argumentos:
  ; rdi: Valor del nodo
  ; rsi: Puntero al nodo izquierdo
  ; rdx: Puntero al nodo derecho

  ; Calcula el tamaño necesario para la estructura Arbol
  mov rax, 24

  ; Llama a malloc para asignar memoria
  call malloc

  ; Comprueba si malloc tuvo éxito (rax contiene el puntero si es exitoso)
  test rax, rax
  jz .malloc_failed

  ; Configura el valor del nodo
  mov qword [rax + Arbol.value], rdi

 ; Configura el puntero izquierdo a NULL
  mov qword [rax + Arbol.left], 0

  ; Configura el puntero derecho a NULL
  mov qword [rax + Arbol.right], 0

  ret

.malloc_failed:
  ; Maneja la falla de malloc, puedes agregar código aquí para manejar errores
