# tpArbol

Pasos para compilar:
1)
Compilar Assembler: Compilamos el archivo assembler para crear un objeto el cual utilizaremos a la hora de compilar el proyecto en C.
                    Reemplazamos nombre_del_archivo por el nombre que tiene nuestro archivo assembler

nasm -f elf64 nombre_del_archivo.asm -o nombre_del_archivo.o



2)
Compilar C: el archuvo en C junto con el codigo generado al compilar el codigo assembler lo utilizamos para crear un ejecutable.
            Reemplazamos mi_codigo_c por el nombre del archivo de codigo en C.
            Reemplazamos mi_codigo_asm por el nombre del archivo objeto de assembler compilado en el paso 1.
            Reemplazamos programa por el nombre del archivo ejecutable que querramos.

gcc mi_codigo_c.c mi_codigo_asm.o -o programa


3)
Ejecutar el codigo

./ programa
