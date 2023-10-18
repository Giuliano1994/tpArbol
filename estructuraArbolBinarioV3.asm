section .data
struc Arbol
  .value resq 1
  .left resq 1
  .right resq 1
endstruc

section .text
extern malloc, free
global createArbol

createArbol:
  push edx
  push 12
  call malloc
  add esp, 4 ;borro el parametro para pedir memoria
  pop edx
    
  mov [eax], edx ;guardo valor
  mov ebx, 0
  mov [eax + 4], ebx;seteo nodo a cero
  mov [eax + 8], ebx;seteo nodo a cero

  jmp finalizar

_agregar_abb:
    push ebp ; guardo base point
    mov ebp, esp ; mi nuevo base point es stack point
    ;push ebx ;guardo el registro que voy a usar para el puntero
    
    mov edx, [ebp + 12];valor parametro
    mov ebx, [ebp + 8];puntero nodo
    cmp ebx, 0 ;si es cero, es porque no hay nodo
    je agregoNodo;pedir memoria para nuevo nodo y guardar valor
    ;ebx valor nodo
    ;ebx + 4 puntero nodo izq
    ;ebx + 8 puntero nodo der
    cmp edx, [ebx];comparo valor parametro con valor nodo
    JE finalizar
    JG mover_der;IF greater
    jmp mover_izq

finalizar:
    ;reinicio lo que apile
    ;pop ebx
    mov esp, ebp
    pop ebp
    ret