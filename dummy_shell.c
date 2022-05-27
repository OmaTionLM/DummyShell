#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include "leercadena.h"
#include <sys/types.h>
#include <signal.h>
#include "leerbackground.h"

#define MAX 100

int main(int argc, char* argv[]) 
{
  char **vector_cadenas;
  char cadena[MAX];
  char **lista;
  int i=0;
  
  while (1) 
  {
    pid_t pid;
    pid_t otroPid;
	  printf("> ");
	  leer_de_teclado(MAX, cadena);
    
    //Funcion para saber si quiere correr en BG el proceso.
    if(isBackground(cadena)==0)
    {
      /*lista=de_cadena_a_vector(cadena);
      execvp(lista[0], lista);
      lista[i]=cadena;
      i++;*/
    }
    
	  vector_cadenas = de_cadena_a_vector(cadena);
    
    pid = fork();
    assert(pid >= 0);
    if (pid == 0) 
    {
	    execvp(vector_cadenas[0], vector_cadenas);
    } 
    else 
    {
      wait(NULL);
    }
    
    //Sale del programa.
    if (strcmp("salir",vector_cadenas[0]) == 0) break;

    //Lista las tareas que están corriendo en background.
    if(strcmp("tareas", vector_cadenas[0]) == 0)
    {
      for (int i=0; i < sizeof(lista); i++)
      {
        printf ("Tareas ejecutadas en BG: %s\n", lista[i]);
      }
    }
    
    //Detiene un proceso.
    if(strcmp("detener",vector_cadenas[0]) == 0)
    {
      printf("Ingrese el PID correspondiente: ");
      scanf("%d", &otroPid);
      kill(otroPid, SIGKILL);
    }
  }
  
  printf("Gracias por usar mi dummy shell ;-)\n");

  return 0;
}