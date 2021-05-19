#include "marcap.h"
#include "tipop.h"

#ifndef NOTEBOOKP_H_INCLUDED
#define NOTEBOOKP_H_INCLUDED
typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int precio;
    int isEmpty;
}eNotebook;


#endif // NOTEBOOKP_H_INCLUDED

/** \brief Coloca todos los isEmpty en 1
 *
 * \param pc[] eNotebook array de Notebooks
 * \param tam int tamanio del array
 * \return void
 *
 */
void inicializarNotebook(eNotebook pc[], int tam);

/** \brief Genera el alta de una Notebook
 *
 * \param pc[] eNotebook array de Notebooks
 * \param tamN int tamanio del array
 * \param marcas[] eMarca array de Marcas
 * \param tamM int tamanio del array
 * \param tipos[] eTipo array de Tipos
 * \param tamT int tamanio del array
 * \param pId int* puntero del id de notebooks
 * \return int
 *
 */
int altaNotebook(eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT, int* pId);

/** \brief Muestra el array de Notebooks
 *
 * \param pc[] eNotebook
 * \param tamn int
 * \param marcas[] eMarca
 * \param tamm int
 * \param tipos[] eTipo
 * \param tamt int
 * \return int
 *
 */
int mostrarNotebooks(eNotebook pc[],int tamn, eMarca marcas[],int tamm, eTipo tipos[],int tamt);

/** \brief Muestra una Notebook
 *
 * \param unaNotebook eNotebook
 * \param marcas[] eMarca
 * \param tamm int
 * \param tipos[] eTipo
 * \param tamt int
 * \return void
 *
 */
void mostrarNotebook(eNotebook unaNotebook, eMarca marcas[], int tamm, eTipo tipos[], int tamt);

/** \brief Busca la posicion de una Notebook en el array de Notebooks en base a su id
 *
 * \param pc[] eNotebook
 * \param tam int
 * \param id int id de la notebook a buscar
 * \return int
 *
 */
int buscarNotebook(eNotebook pc[], int tam, int id);

/** \brief Genera la baja de una Notebook previamente dada de alta
 *
 * \param pc[] eNotebook
 * \param tamN int
 * \param marcas[] eMarca
 * \param tamM int
 * \param tipos[] eTipo
 * \param tamT int
 * \return int
 *
 */
int bajaNotebook(eNotebook pc[], int tamN, eMarca marcas[], int tamM, eTipo tipos[], int tamT);

/** \brief Busca la primer posicion libre en el array de Notebooks
 *
 * \param pc[] eNotebook
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eNotebook pc[], int tam);
