section .data
struc Arbol
  .value resq 1
  .left resq 1
  .right resq 1
endstruc

section .text
extern malloc, free
global createArbol_asm

createArbol_asm:
  push rbp
  mov rbp, rsp

  ; Argumento de la estructura ArbolCreationData
  mov rax, [rdi]  ; Accede al valor
  mov rsi, [rdi + 8]  ; Accede al puntero izquierdo
  mov rdx, [rdi + 16]  ; Accede al puntero derecho

  ; Lógica para crear el nodo usando los argumentos
  push rdx
  push 24
  call malloc
  add rsp, 8  ; Borro el parámetro para pedir memoria
  pop rdx

  mov [rax], rdi  ; Guarda el valor
  mov [rax + 8], rsi  ; Guarda el puntero izquierdo
  mov [rax + 16], rdx  ; Guarda el puntero derecho

  pop rbp
  ret
   