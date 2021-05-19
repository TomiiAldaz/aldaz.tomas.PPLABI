#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marcap.h"



void mostrarMarcas(eMarca marcas[], int tam){

   printf("    Lista de Marcas\n\n");
   printf("    Id   Descripcion\n");
   if( marcas !=  NULL && tam > 0)
   {
        for(int i=0; i < tam; i++)
        {
            mostrarMarca(marcas[i]);

        }
   }
}


void mostrarMarca(eMarca unaMarca){


    printf("   %d    %10s\n", unaMarca.id , unaMarca.descripcion);

}

int cargarDescripcionMarca(int id, eMarca marcas[], int tam, char desc[]){

    int todoOk = 0;

    if(id>= 1000 && id<= 1003 && marcas != NULL && tam > 0 && desc != NULL)
    {

        for(int i=0; i < tam; i++)
        {
            if(marcas[i].id == id)
            {
                strcpy(desc, marcas[i].descripcion);
                todoOk = 1;
                break;
            }

        }
    }
    return todoOk;
}
