/*
  Programa para saber si el usuario desea correr el programa en background
  autores: 
  - Alan Valderrama - 2042836
  - Estefanía Parra - 2042893
  - Isabella Bastidas - 2040127
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leerbackground.h"
#include "leercadena.h"

/*
  Metodo para saber si lo ingresado por el usuario tiene un &.
*/
int isBackground(char *cadena)
{
  int retorno=1;
  int tamaño=strlen(cadena)-1;

  cadena+=tamaño;
  
  if(strcmp("&", cadena) == 0)
  {
    retorno=0;  
  }

  return retorno;
}
