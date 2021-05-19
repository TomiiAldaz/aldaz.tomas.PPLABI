#ifndef TIPOP_H_INCLUDED
#define TIPOP_H_INCLUDED

typedef struct {
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPOP_H_INCLUDED

void mostrarTipos(eTipo tipos[], int tam);
void mostrarTipo(eTipo unTipo);
int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[]);
