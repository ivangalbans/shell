Descripción
===========

Este proyecto es una implementación de un shell como los shells del sistema operativo linux.

Las funcionalidades son las siguiente:

1. Al ejecutar el programa este debe imprimir un prompt (ejemplo "$ ")
2. Ejecutar comandos e imprimir su salida
3. Poder ejecutar el comando `cd` (y que cambie de directorio)
4. Redirigir entrada y salida estandar de comandos hacia/desde ficheros con `>`, `<`, `>>`
5. Redirigir la salida estandar de un comando hacia la entrada de otro con un pipe `|`
6. Una vez terminado el comando previo, se debe mostrar el prompt nuevamente.
7. No interesa la cantidad de espacios entre cada uno de los *tokens* de la entrada
  * comandos
  * parámetros
  * operadores de redirección (`>`, `|`, etc.)

8. Implementar mas de una tubería
9. Permitir cualquier cantidad de espacios o no entre los comandos y parametros
10. Implementar un historial de comandos (un commando `history`) que permita imprimir los últimos 50 comandos ejecutados en la consola
  * NOTA: si el comando empieza con espacio, entonces no va a parar al historial.

Sistema Operativo
-----------------

Implementado en `Linux`.

Colaboración
------------

Cree un `issue` o envíeme un `pull request`.

Autores:

Iván Galbán Smith <ivan.galban.smith@gmail.com>

Raydel E. Alonso Baryolo <raydelalonsobaryolo@gmail.com>

3rd year of Computer Science

University of Havana, 2015