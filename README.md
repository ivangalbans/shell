Orientacion del Proyecto
========================

El objetivo del proyecto es hacer un shell que simule los shells del sistema operativo linux.

Las funcionalidades son las siguiente:

1. Al ejecutar el programa este debe imprimir un prompt (ejemplo "$ ")
2. Ejecutar comandos e imprimir su salida
3. Poder ejecutar el comando `cd` (y que cambie de directorio)
4. Redirigir entrada y salida estandar de comandos hacia/desde ficheros con `>`, `<`, `>>` 
5. Redirigir la salida estandar de un comando hacia la entrada de otro con un pipe `|`
6. Una vez terminado el comando previo, se debe mostrar el prompt nuevamente.
7. Solamente habrá un espacio entre cada uno de los *tokens* de la entrada
  * comandos
  * parámetros
  * operadores de redirección (`>`, `|`, etc.)

y hasta aqui tienen 3 puntos en el proyecto

8. Implementar mas de una tubería (1pt adicional)
9. Implementar el operador `&` y tener procesos en el background (1pt adicional)
  * jobs => listar todos los procesos que estan correiendo en el background
  * fg <pid> => envia el proceso <pid> hacia el foreground
  * NOTA: aqui tiene que funcionar algo como `command1 < file1 | command2 > file2 &`
9. Permitir cualquier cantidad de espacios o no entre los comandos y parametros (0.5pt adicional)
10. Implementar un historial de comandos (un commando `history`) que permita imprimir los últimos 50 comandos ejecutados en la consola (0.5pt adicional)
  * NOTA: si el comando empieza con espacio, entonces no va a parar al historial.

El proyecto se hará en un repositorio de git que esta en 
[http://gitlab.matcom.uh.cu/pm2/shell.git]

Instrucciones
=============

1. Si usted esta leyendo esta documentación en el sitio de gitlab entonces debe estar en la dirección 
http://gitlab.matcom.uh.cu/2/shell/tree/master

2. Vaya al **Home** del proyecto. (dar click en la casita que esta en la parte superior izquierda)
http://gitlab.matcom.uh.cu/pm2/shell

3. Hagale **fork** al proyecto. (dar click en el boton [Fork Repositoty] en la parte derecha de la página)
http://gitlab.matcom.uh.cu/pm2/shell/fork

4. En la página nueva que le salió (que debe ser http://gitlab.matcom.uh.cu/((tu-usuario-de-matcom))/shell) fíjese
en la parte superior derecha que aparece la dirección se su nuevo repo. 

5. Deben aparecerle dos opciones [SSH] y **[HTTP]**, le recomendamos que use la variante HTTP. 
La URL debe ser algo como http://gitlab.matcom.uh.cu/(((tu-usuario-de-matcom))/shell.git

6. Abran una consola y ejecuten el siguiente código

~~~bash
    $ git clone http://gitlab.matcom.uh.cu/((tu-usuario-de-matcom))/shell.git
~~~ 

7. La tarea la deben hacer en ese directorio [shell.git] que se les acaba de crear con el comando
`git clone`. A ese directorio le pueden cambiar el nombre y lo pueden mover de lugar sin ningun
problema.

8. Le recomendamos que cada cierto tiempo usted ejecute los siguientes commandos

~~~bash
    $ cd /camino/hasta/el/directorio/shell.git # ir al directorio del proyecto
    $ git add .                                # adicionar todos los ficheros modificados y nuevos
    $ git commit -v                            # hacer un commit con todos los cambios hechos
    # NOTA: se les abrirá un editor de texto para que pongan un comentario relacionado con el commit
~~~

Sobre la Entrega
================

Fecha de entrega: Lunes 7 de noviembre
-------------------------------

9. Al finalizar el proyecto. deben hacer lo siguiente:

~~~bash
    $ cd /camino/hasta/el/directorio/shell.git
    $ git add .
    $ git commit -v
    $ git push origin master # con esto suben los cambios hacia gitlab
    $ # NOTA: puede hacer git push no solo al final, sino tambien en otros momentos
~~~

10. Vaya a gitlab a la direccion http://gitlab.matcom.uh.cu/((tu-usuario-de-matcom))/shell

11. De click en el boton [Merge Requests] que esta en la parte superior de la pagina
http://gitlab.matcom.uh.cu/((tu-usuario-de-matcom))/shell/merge_requests

12. Dele click al boton [New Merge Request] que es un boton verte que esta en la parte derecha

13. En la nueva pagina que sale aparecen 4 combos (dos en la derecha y dos en la izquierda) y un formula

  * seleccione [((tu-usuario-de-matcom))/shell] en el primer combo de la izquierda
  * seleccione [master] donde dice [select branch] en el segundo combo de la izquierda
  * seleccione [programacion-de-maquinas-ii/shell] en el tercer combo
  * seleccione [master] en el ultimo combo
  * en [title] pongan algo como [tarea de fulano y mengano]
  * los demas campos no son obligatorios

