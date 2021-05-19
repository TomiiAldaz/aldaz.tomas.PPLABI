#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipop.h"



void mostrarTipos(eTipo tipos[], int tam){

   printf("    Lista de Tipos\n\n");
   printf("    Id   Descripcion\n");
   if( tipos !=  NULL && tam > 0)
   {
        for(int i=0; i < tam; i++)
        {
            mostrarTipo(tipos[i]);

        }
   }
}


void mostrarTipo(eTipo unTipo){


    printf("   %d    %10s\n", unTipo.id , unTipo.descripcion);

}

int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[]){

    int todoOk = 0;

    if(id>= 5000 && id<=5003 && tipos != NULL && tam > 0 && desc != NULL)
    {

        for(int i=0; i < tam; i++)
        {
            if(tipos[i].id == id)
            {
                strcpy(desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }

        }
    }
    return todoOk;
}
