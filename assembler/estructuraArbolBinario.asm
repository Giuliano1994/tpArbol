; defino la estructura de arbol, tiene 3 campos de 8 bytes

section .data
struc Arbol
  .value resq 1
  .left resq 1
  .right resq 1
endstruc



; funcion para crear arbol, toma 3 argumentos de rdi, rsi y rdx

section .text
global createArbol

createArbol:
  ; Argumentos:
  ; rdi: Valor del nodo
  ; rsi: Puntero al nodo izquierdo
  ; rdx: Puntero al nodo derecho
  
  ; Reserva espacio para la estructura Arbol en la pila
  push rdi
  push rsi
  push rdx

 
  ; Configura el valor del nodo
  mov rax, rdi  ; rax = valor

  ; HAGO VIOLACIONES DE SEGMENTO AL AGREGAR UN SEGUNDO NODO AL ARBOL, AL ESTABLECER ARBOL.RIGHT Y LEFT EN 0 ESTOY INICIALIZANDOLOS
  mov qword [rsp + Arbol.left], 0
  mov qword [rsp + Arbol.right], 0

  ; el regustro rsp es un puntero a la pila, apunta al tope de la pila (stack pointer) 
  ; Configura el puntero izquierdo
  mov qword [rsp + Arbol.left], rsi

  ; Configura el puntero derecho
  mov qword [rsp + Arbol.right], rdx

  ; Retorna la dirección del nodo creado (en rsp)
  
  ; Restaura la pila
  pop rdx
  pop rsi
  pop rdi
  ret
