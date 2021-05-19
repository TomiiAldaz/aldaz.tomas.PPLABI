#ifndef MARCAP_H_INCLUDED
#define MARCAP_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCAP_H_INCLUDED

/** \brief Muestra el array de Marcas
 *
 * \param marcas[] eMarca array de Marcas
 * \param tam int Tamanio del array
 * \return void
 *
 */
void mostrarMarcas(eMarca marcas[], int tam);

/** \brief Muestra una Marca
 *
 * \param unaMarca eMarca
 * \return void
 *
 */
void mostrarMarca(eMarca unaMarca);

/** \brief Toma el id de la marca  y carga su descripcion
 *
 * \param id int id de la marca
 * \param marcas[] eMarca array de Marcas
 * \param tam int tamanio del array
 * \param desc[] char guarda la descripcion a carga
 * \return int
 *
 */
int cargarDescripcionMarca(int id, eMarca marcas[], int tam, char desc[]);
