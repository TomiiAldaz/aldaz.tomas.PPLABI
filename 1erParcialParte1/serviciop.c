#include <stdlib.h>
#include <string.h>
#include "serviciop.h"



int mostrarServicios(eServicio servicios[], int tam){

   int todoOk = 0;

   printf("    Lista de Servicios\n\n");
   printf("    Id   Descripcion   Precio\n");
   if( servicios !=  NULL && tam > 0)
   {
        for(int i=0; i < tam; i++)
        {
            mostrarServicio(servicios[i]);
            todoOk = 1;

        }
   }
   return todoOk;
}


void mostrarServicio(eServicio unServicio){


    printf("  %d    %10s   %d\n", unServicio.id , unServicio.descripcion, unServicio.precio);

}
