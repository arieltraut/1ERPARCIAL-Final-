#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "pantallas.h"
#include "contrataciones.h"
#include "validar.h"

int info_listarFacturacion(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla);
int info_listarContrataciones(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla);
int info_printArrayPantalla(sPantalla arrayPantalla[] , int len);
int info_listarClientes(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla);
int info_listarClienteConImporteMasAlto(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla);



void prueba(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla);



#endif // INFORMES_H_INCLUDED
