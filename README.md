# tpArbol

## Pasos para compilar:

1. **Compilar Assembler:** Compilamos el archivo assembler para crear un objeto que utilizaremos al compilar el proyecto en C. Reemplaza `nombre_del_archivo` por el nombre de tu archivo assembler.

    ```bash
    nasm -f elf32 estructuraArbolBinarioV3.asm -o estructuraArbolBinario.o
    ```

2. **Compilar C:** El archivo en C, junto con el código generado al compilar el código assembler, se utiliza para crear un ejecutable. Reemplaza `mi_codigo_c` por el nombre de tu archivo de código en C, `mi_codigo_asm` por el nombre del archivo objeto de assembler compilado en el paso 1, y `programa` por el nombre que desees para el archivo ejecutable.

    ```bash
   gcc -m32 pruebaC.c estructuraArbolBinario.o -o programa
    ```

3. **Ejecutar el código:**

    ```bash
    ./programa
    ```
