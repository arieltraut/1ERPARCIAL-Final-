#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED
#include "pantallas.h"
#include "validar.h"


typedef struct{
    char cuit[51];
    char nombreArchivoVideo[51];
    int diasPublicacion;
    int id;
    int idPantalla;
    int flagOcupado;


}sContrataciones;
#endif // CONTRATACIONES_H_INCLUDED

int contra_init(sContrataciones arrayContratacion[], int len);
int contra_generarProximoId(void); //static
int contra_buscarPosicionLibre(sContrataciones arrayContratacion[], int len); //static
int contra_buscarIndicePorIdPantalla(sContrataciones arrayContratacion[],int len,int idPantalla); //static

int contra_alta(sPantalla arrayPantalla[],sContrataciones arrayContratacion[], int lenPantalla, int lenContratacion);
int contra_modificar(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantallas);
int contra_cancelar(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla);
void contra_baja(sContrataciones arrayContratacion[], int lenContratacion, int idPantalla);


int contra_fin(sContrataciones arrayContratacion[], int len);

void contra_printArray(sContrataciones arrayContratacion[] , int len);



