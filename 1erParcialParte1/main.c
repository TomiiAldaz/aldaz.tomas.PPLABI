#include <stdio.h>
#include <stdlib.h>
#include "datawarehousep.h"
#include "marcap.h"
#include "tipop.h"
#include "serviciop.h"
#include "trabajop.h"
#include "notebookp.h"

#define TAMM 4
#define TAMT 4
#define TAMN 10
#define TAMS 4

char menu();

int main()
{

    char salir = 'n';
    char salir2 = 'n';
    int flagAlta = 0;

    int nextIdNotebook = 700;
    eMarca marcas[TAMM] = {
        {1000,"Compaq"},
        {1001,"Asus"},
        {1002,"Acer"},
        {1003,"HP"}
    };
    eTipo tipos[TAMT] = {
        {5000,"Gamer"},
        {5001,"Disenio"},
        {5002,"Ultrabook"},
        {5003,"Normalita"}
    };
    eServicio servicios[TAMT] = {
        {20000, "Bateria",250},
        {20001, "Antivirus",300},
        {20002, "Actualizacion",400},
        {20003, "Fuente",600}
    };

    eNotebook notebooks[TAMN];
    //eTrabajo trabajos[TAMA];
    inicializarNotebook(notebooks, TAMN);
    //inicializarAlmuerzos(almuerzos, TAMA);
    do
    {
        switch(menu())
        {

        case 'A':
            if( altaNotebook(notebooks, TAMN, marcas, TAMM, tipos, TAMT, &nextIdNotebook) )
            {
                printf("Alta exitosa.\n");
            }else
            {
                printf("Hubo un problema al realizar el alta.\n");
            }
            flagAlta = 1;
            break;
        case 'B':
           if(flagAlta = 1)
           {/* if( modificarEmpleado(nomina, TAM, sectores, TAMSEC))
            {
                printf("Baja exitosa.\n");
            }else
            {
                printf("Hubo un problema al realizar la baja.\n");
            }*/

            }
            else
            {
                printf("Antes de modificar una notebook, primero debes dar de alta una notebook");
            }
            break;
        case 'C':
            if(flagAlta = 1)
            {
                if(bajaNotebook(notebooks, TAMN, marcas, TAMM, tipos, TAMT))
                {
                    printf("Baja exitosa.\n");
                }
                else
                {
                    printf("Hubo un problema al realizar la baja.\n");
                }
            }
            else
            {
                printf("Antes de dar de baja una notebook, primero debes dar de alta una notebook");
            }
            break;
        case 'D':
            system("cls");
            if(flagAlta = 1)
            {

                mostrarNotebooks(notebooks, TAMN, marcas, TAMM, tipos, TAMT);
            }
            else
            {
                printf("Antes de dar listar una notebook, primero debes dar de alta una notebook");
            }
            break;
        case 'E':
            system("cls");
            mostrarMarcas(marcas, TAMM);
            break;
        case 'F':
            system("cls");
            mostrarTipos(tipos, TAMT);
            break;
        case 'G':
            system("cls");
            if(mostrarServicios(servicios, TAMS))
            {
                printf("\n\n Listado exitoso\n");
            }
            else
            {
                printf("\n\n Hubo un problema al realizar el listado\n");
            }
            break;
        case 'H':
          /*  system("cls");
            mostrarAlmuerzos(almuerzos, TAMA, comidas, TAMC, nomina, TAM);*/
            break;
        case 'I':
          /*  system("cls");
            if( altaAlmuerzo(almuerzos, TAMA, comidas, TAMC, nomina, TAM, sectores, TAMSEC, &nextIdAlmuerzo) )
            {
                printf("Alta almuerzo exitosa.\n");
            }else
            {
                printf("Hubo un problema al realizar el alta del almuerzo.\n");
            }*/
            break;
        case 'J':
            printf("\n   Confirma salida?: ");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("\n   Opcion Invalida!\n");
            fflush(stdin);
            printf("\n");
            system("pause");

        }
        system("pause");

    }
    while(salir == 'n');

    return 0;
}

char menu(){

    char opcion;
    system("cls");
    printf("      Menu de Opciones\n\n");
    printf("   A. Alta Notebook.\n");
    printf("   B. Modificar Notebook.\n");
    printf("   C. Baja Notebook.\n");
    printf("   D. Listar Notebook.\n");
    printf("   E. Listar Marcas.\n");
    printf("   F. Listar Tipos.\n");
    printf("   G. Listar Servicios.\n");
    printf("   H. Alta Trabajo.\n");
    printf("   I. Listar Trabajos.\n");
    printf("   J. Salir.\n\n");
    printf("   Introduzca opcion (A-J): ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
