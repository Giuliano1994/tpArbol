
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
  push edx
  push 12

  ; Llama a malloc para asignar memoria
  call malloc

  add esp, 4
  pop edx

  ; Configura el valor del nodo
  mov qword [rax + Arbol.value], rdi

 ; Configura el puntero izquierdo a NULL
  mov qword [rax + Arbol.left], 0

  ; Configura el puntero derecho a NULL
  mov qword [rax + Arbol.right], 0

  ret
