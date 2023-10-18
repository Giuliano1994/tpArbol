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

  mov [eax], edx ;guardo valor
  mov ebx, 0
  mov [eax + 4], ebx;seteo nodo a cero
  mov [eax + 8], ebx;seteo nodo a cero

  jmp finalizar

finalizar:
    ;reinicio lo que apile
    ;pop ebx
    mov esp, ebp
    pop ebp
    ret