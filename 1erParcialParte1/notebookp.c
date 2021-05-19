#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebookp.h"
#include "datawarehousep.h"

void inicializarNotebook(eNotebook pc[], int tam)
{

    if( pc != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            pc[i].isEmpty = 1;
        }
    }
}

int buscarLibre(eNotebook pc[], int tam)
{

    int estado = -1;

    if( pc != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(pc[i].isEmpty)
            {

                estado = i;
                break;
            }
        }
    }
    return estado;
}

int altaNotebook(eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT, int* pId){

    int todoOk = 0;
    int i;
    int idMarca;
    int idTipo;

    eNotebook auxNotebook;

    system("cls");
    printf("    Alta Notebook\n\n");
    printf("ID: %d\n", *pId);

    if( pc != NULL && tamN > 0 && pId != NULL && marcas != NULL && tamM > 0 && tipos != NULL && tamT > 0)
    {
        i = buscarLibre(pc, tamN);

        if(i == -1)
        {

            printf("No hay lugar en el sistema\n");
        }

        else
        {
            printf("\nIngrese Modelo: ");
            fflush(stdin);
            gets(auxNotebook.modelo);


            mostrarMarcas(marcas, tamM);
            printf("\nIngrese el id de la marca: ");
            scanf("%d", &idMarca);


            auxNotebook.idMarca = idMarca;

            mostrarTipos(tipos, tamT);
            printf("\nIngrese el id del tipo: ");
            scanf("%d", &idTipo);


            auxNotebook.idTipo = idTipo;

            printf("\nIngrese Precio: ");
            scanf("%d", &auxNotebook.precio);

            auxNotebook.isEmpty = 0;

            auxNotebook.id = *pId;
            (*pId)++;
            pc[i] = auxNotebook;
            todoOk = 1;
        }
    }
    return todoOk;
}

int mostrarNotebooks(eNotebook pc[],int tamn, eMarca marcas[],int tamm, eTipo tipos[],int tamt){

    int estado = 1;
    if(pc != NULL && marcas != NULL && tipos != NULL && tamn > 0 && tamm > 0 && tamt > 0)
    {
        printf("\t         *** Listado de Notebooks ***\n\n");
        printf("ID        Modelo     Marca     Tipo   Precio  \n\n");
        for(int i=0; i < tamn; i++)
        {
            if( !pc[i].isEmpty )
            {
                mostrarNotebook(pc[i], marcas, tamm, tipos, tamt);
                estado = 0;
            }
        }
        if(estado)
        {
            printf("    No hay Notebooks que mostrar.\n");
        }

        printf("\n\n");
    }
    return estado;
}

void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], int tamm, eTipo tipos[], int tamt){

    char descripcionM[20];
    char descripcionT[20];

    if(marcas != NULL && tipos != NULL && tamm > 0 && tamt > 0)
    {


    if(cargarDescripcionMarca(unaNotebook.idMarca, marcas, tamm, descripcionM)
       && cargarDescripcionTipo(unaNotebook.idTipo, tipos, tamt, descripcionT))
    {



        printf("%d    %10s     %s    %s   %d\n"
               , unaNotebook.id
               , unaNotebook.modelo
               , descripcionM
               , descripcionT
               , unaNotebook.precio
              );
    }
    }
}


int buscarNotebook(eNotebook pc[], int tam, int id)
{


    int indice = -1;
    if(pc != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(pc[i].id == id && pc[i].isEmpty == 0)
            {

                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaNotebook(eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT)
{

    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    if(pc != NULL && marcas != NULL && tipos != NULL && tamN > 0 && tamM> 0 && tamT > 0)
    {
        system("cls");
        printf("    Baja de Notebook\n\n");
        mostrarNotebooks(pc, tamN, marcas, tamM, tipos, tamT);
        printf("Ingrese ID de la Notebook que desea dar de baja: ");
        scanf("%d", &id);
        printf("\n");

        indice = buscarNotebook(pc, tamN, id);

        if( indice == -1)
        {
            printf("No hay ninguna notebook registrada con ese id %d\n", id);
        }
        else
        {
            mostrarNotebook(pc[indice], marcas, tamM, tipos, tamT);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                pc[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }

        }
    }
    return todoOk;
}
