#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"


/** \brief Pide al usuario el CUIT y muestra las contrataciones asignadas a este con el importe a pagar
 * \param sContrataciones arrayContratacion[] Puntero al array de contrataciones
 * \param sPantalla arrayPantalla[] Puntero al array de pantallas
 * \param lenContrataciones int Longitud del array
 * \param lenPantalla int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida, puntero NULL o no se encontro el CUIT].
 *                    (0) si Ok
 */
int info_listarFacturacion(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, indexPan, idPan, flagCuitEncontrado = 0;
    char bCuit[51];

    if (arrayPantalla != NULL && arrayContratacion != NULL && lenContrataciones > 0 && lenPantalla > 0)
    {
        if (val_getCuit(bCuit,"\nIngrese CUIT\n","\nCUIT invalido, ingrese nuevamente\n",2,51)==0)
        {
            for(indexContra=0; indexContra<lenContrataciones; indexContra++)
            {
                if((strcmp(arrayContratacion[indexContra].cuit,bCuit) == 0) && arrayContratacion[indexContra].flagOcupado == 1)
                {
                    flagCuitEncontrado = 1;
                    idPan = arrayContratacion[indexContra].idPantalla;
                    indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                    float importeContra = arrayPantalla[indexPan].precio * arrayContratacion[indexContra].diasPublicacion;
                    printf("ID Contratacion: %d  Precio contratacion: %.2f\n\n",arrayContratacion[indexContra].id, importeContra);
                    retorno = 0;
                }
            }
            if (flagCuitEncontrado == 0)
            {
                printf("No hay contrataciones asignadas al CUIT ingresado\n");
            }
        }
    }
    return retorno;
}


/** \brief Muestra las contrataciones cargadas
 * \param sContrataciones arrayContratacion[] Puntero al array de contrataciones
 * \param sPantalla arrayPantalla[] Puntero al array de pantallas
 * \param lenContrataciones int Longitud del array
 * \param lenPantalla int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida, puntero NULL].
 *                    (0) si Ok
 */
int info_listarContrataciones(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, indexPan, idPan, flagCuitEncontrado = 0;

    if (arrayPantalla != NULL && arrayContratacion != NULL && lenContrataciones > 0 && lenPantalla > 0)
    {
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if(arrayContratacion[indexContra].flagOcupado == 1)
            {
                flagCuitEncontrado = 1;
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                printf("Nombre pantalla: %s,  Nombre video: %s, Cantidad dias: %d, CUIT Cliente: %s\n\n",arrayPantalla[indexPan].nombre, arrayContratacion[indexContra].nombreArchivoVideo,arrayContratacion[indexContra].diasPublicacion,arrayContratacion[indexContra].cuit);
                retorno = 0;
            }
        }
        if (flagCuitEncontrado == 0)
        {
            printf("No se han cargado contrataciones\n");
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Muestra las Pantallas cargadas
 * \param sPantalla arrayPantalla[] Puntero al array de pantallas
 * \param lenPantalla int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida, puntero NULL].
 *                    (0) si Ok
 */
int info_printArrayPantalla(sPantalla arrayPantalla[] , int len)
{
    int i, retorno = -1;
    if (arrayPantalla != NULL && len > 0)
    {
        for (i=0;i<len;i++)
        {
            if(arrayPantalla[i].flagOcupado == 1)
            {
                printf("ID: %d, Tipo: %d, Nombre: %s, Direccion: %s, precio: %.2f\n\n\n",arrayPantalla[i].id,arrayPantalla[i].tipoPantalla,arrayPantalla[i].nombre,arrayPantalla[i].direccion,arrayPantalla[i].precio);
                retorno = 0;
            }
        }
        if (retorno == -1)
        {
            printf("No hay ninguna pantalla cargada en el sistema\n");
            retorno = 0;
            system("pause");
        }
    }
    return retorno;
}

/** \brief Muestra cada cliente con cantidad de contrataciones e importe a pagar por cada una
 * \param sContrataciones arrayContratacion[] Puntero al array de contrataciones
 * \param sPantalla arrayPantalla[] Puntero al array de pantallas
 * \param lenContrataciones int Longitud del array
 * \param lenPantalla int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida, puntero NULL].
 *                    (0) si Ok
 */
int info_listarClientes(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, i;
    int iArrayClientes=0, indiceCuit=0,arrayContador[lenContrataciones];
    char bCuit[51],arrayClientes[lenContrataciones][51];

    for(i=0; i<lenContrataciones; i++)
    {
        strcpy(arrayClientes[i],"0");
        arrayContador[i] = 0;
    }

    int j;
    for(indexContra=0; indexContra<lenContrataciones; indexContra++)
    {
        if(arrayContratacion[indexContra].flagOcupado == 1)
        {
            strncpy(bCuit, arrayContratacion[indexContra].cuit,50);
            j=indexContra-1;

            while(j>=0)
            {
                if (strcmp(bCuit,arrayContratacion[j].cuit)==0 && arrayContratacion[j].flagOcupado==1)
                    break;
                else
                    j--;
            }
            if(j==-1)
            {
                strcpy(arrayClientes[iArrayClientes],bCuit);
                iArrayClientes++;
            }
        }
    }

    char bCuit2[51];
    for (indiceCuit=0; indiceCuit<lenContrataciones; indiceCuit++)
    {
        strncpy(bCuit2, arrayClientes[indiceCuit],50);
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(bCuit2,arrayContratacion[indexContra].cuit))==0 && arrayContratacion[indexContra].flagOcupado == 1)
                arrayContador[indiceCuit]++;
        }
    }

    for (indiceCuit=0; indiceCuit<lenContrataciones; indiceCuit++)
    {
        if ( arrayContador[indiceCuit] != 0)
             printf("La cantidad de contrataciones del CUIT: %s es %d\n\n",arrayClientes[indiceCuit],arrayContador[indiceCuit]);

        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(arrayContratacion[indexContra].cuit,arrayClientes[indiceCuit]))==0 && arrayContratacion[indexContra].flagOcupado == 1)
            {
                //flagCuitEncontrado = 1;
                int idPan = arrayContratacion[indexContra].idPantalla;
                int indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                float importeContra = arrayPantalla[indexPan].precio * arrayContratacion[indexContra].diasPublicacion;

                printf("   > ID Contratacion: %d  Precio contratacion: %.2f\n\n",arrayContratacion[indexContra].id, importeContra);
            }

        }
    }
    return retorno;
}




/** \brief Muestra cada cliente con cantidad de contrataciones e importe a pagar por cada una
 * \param sContrataciones arrayContratacion[] Puntero al array de contrataciones
 * \param sPantalla arrayPantalla[] Puntero al array de pantallas
 * \param lenContrataciones int Longitud del array
 * \param lenPantalla int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida, puntero NULL].
 *                    (0) si Ok
 */
int info_listarClienteConImporteMasAlto(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{
    int retorno = -1, indexContra, i, idPan, indexPan, iArrayClientes=0,arrayIdClientes[lenContrataciones];
    char arrayClientes[lenContrataciones][51];
    float importeContra, acumulador, arrayFacturacion[lenContrataciones];


    for(i=0; i<lenContrataciones; i++)
    {
        strcpy(arrayClientes[i],"0");
        arrayFacturacion[i]=0;
        arrayIdClientes[i]=0;
    }
    //arrayClientes[lenContrataciones-1] = '\0';

    int j;
    for(indexContra=0; indexContra<lenContrataciones; indexContra++)
    {
        if(arrayContratacion[indexContra].flagOcupado == 1)
        {
            j=indexContra-1;

            while(j>=0)
            {
                if (strcmp(arrayContratacion[indexContra].cuit,arrayContratacion[j].cuit)==0 && arrayContratacion[j].flagOcupado==1)
                    break;
                else
                    j--;
            }
            if(j==-1 && arrayContratacion[indexContra].flagOcupado == 1)
            {
                strcpy(arrayClientes[iArrayClientes],arrayContratacion[indexContra].cuit);
                arrayIdClientes[iArrayClientes]=arrayContratacion[indexContra].id;
                iArrayClientes++;
            }
        }
    }


    for (iArrayClientes=0; iArrayClientes<lenContrataciones; iArrayClientes++)
    {
        if(strcmp(arrayClientes[iArrayClientes],"0")==0)
            break;

        acumulador = 0;
        for(indexContra=0; indexContra<lenContrataciones; indexContra++)
        {
            if((strcmp(arrayContratacion[indexContra].cuit,arrayClientes[iArrayClientes]) == 0) && arrayContratacion[indexContra].flagOcupado == 1)
            {
                idPan = arrayContratacion[indexContra].idPantalla;
                indexPan = pantalla_buscarIndicePorId(arrayPantalla,lenPantalla,idPan);
                importeContra = arrayPantalla[indexPan].precio * arrayContratacion[indexContra].diasPublicacion;
                acumulador+=importeContra;
            }
        }
        arrayFacturacion[iArrayClientes]=acumulador;

    }

    float max = arrayFacturacion[0];
    int indexMax = 0;
    for (iArrayClientes=1; iArrayClientes<lenContrataciones; iArrayClientes++)
    {
        if (arrayFacturacion[iArrayClientes]>max)
        {
            max = arrayFacturacion[iArrayClientes];
            indexMax = iArrayClientes;
        }

    }
    printf("\n\n\nEl cliente con importe mas alto a facturar es: %s\n\n",arrayClientes[indexMax]);

    return retorno;
}










void prueba(sContrataciones arrayContratacion[], sPantalla arrayPantalla[], int lenContrataciones, int lenPantalla)
{

        int indexVacio = pantalla_buscarPosicionLibre(arrayPantalla, lenPantalla);
        int indexVacio2;
        int idNuevo;
        int idNuevo2;

        if (arrayPantalla != NULL && indexVacio >=0 && indexVacio < lenPantalla)
        {
            idNuevo = pantalla_generarProximoId();


            strncpy(arrayPantalla[indexVacio].nombre,"Pantalla Uno",51);
            strncpy(arrayPantalla[indexVacio].direccion,"Del Signo 4077",51);
            arrayPantalla[indexVacio].tipoPantalla = 0;
            arrayPantalla[indexVacio].precio = 25;
            arrayPantalla[indexVacio].flagOcupado = 1;
            arrayPantalla[indexVacio].id = idNuevo;
        }

        indexVacio = pantalla_buscarPosicionLibre(arrayPantalla, lenPantalla);

        if (arrayPantalla != NULL && indexVacio >=0 && indexVacio < lenPantalla)
        {
            idNuevo = pantalla_generarProximoId();


            strncpy(arrayPantalla[indexVacio].nombre,"Pantalla Dos",51);
            strncpy(arrayPantalla[indexVacio].direccion,"Av. Mitre 750",51);
            arrayPantalla[indexVacio].tipoPantalla = 0;
            arrayPantalla[indexVacio].precio = 50;
            arrayPantalla[indexVacio].flagOcupado = 1;
            arrayPantalla[indexVacio].id = idNuevo;
        }



        indexVacio2 = contra_buscarPosicionLibre(arrayContratacion, lenContrataciones);

        if (arrayContratacion != NULL && indexVacio2 >=0 && indexVacio2 < lenContrataciones)
        {
            idNuevo2 = contra_generarProximoId();


            strncpy(arrayContratacion[indexVacio2].nombreArchivoVideo,"Primer Archivo",51);
            arrayContratacion[indexVacio2].diasPublicacion = 4;
            strncpy(arrayContratacion[indexVacio2].cuit,"20308596673",51);
            //arrayContratacion[indexVacio2].cuit = atoi(bCuit);
            arrayContratacion[indexVacio2].idPantalla = 0;
            arrayContratacion[indexVacio2].id = idNuevo2;
            arrayContratacion[indexVacio2].flagOcupado = 1;
        }

        indexVacio2 = contra_buscarPosicionLibre(arrayContratacion, lenContrataciones);

        if (arrayContratacion != NULL && indexVacio2 >=0 && indexVacio2 < lenContrataciones)
        {
            idNuevo2 = contra_generarProximoId();


            strncpy(arrayContratacion[indexVacio2].nombreArchivoVideo,"Segundo Archivo",51);
            arrayContratacion[indexVacio2].diasPublicacion = 2;
            strncpy(arrayContratacion[indexVacio2].cuit,"20308596673",51);
            //arrayContratacion[indexVacio2].cuit = atoi(bCuit);
            arrayContratacion[indexVacio2].idPantalla = 1;
            arrayContratacion[indexVacio2].id = idNuevo2;
            arrayContratacion[indexVacio2].flagOcupado = 1;
        }

        indexVacio2 = contra_buscarPosicionLibre(arrayContratacion, lenContrataciones);

         if (arrayContratacion != NULL && indexVacio2 >=0 && indexVacio2 < lenContrataciones)
        {
            idNuevo2 = contra_generarProximoId();


            strncpy(arrayContratacion[indexVacio2].nombreArchivoVideo,"Tercer Archivo",51);
            arrayContratacion[indexVacio2].diasPublicacion = 1;
            strncpy(arrayContratacion[indexVacio2].cuit,"20306667777",51);
            //arrayContratacion[indexVacio2].cuit = atoi(bCuit);
            arrayContratacion[indexVacio2].idPantalla = 1;
            arrayContratacion[indexVacio2].id = idNuevo2;
            arrayContratacion[indexVacio2].flagOcupado = 1;
        }
}

