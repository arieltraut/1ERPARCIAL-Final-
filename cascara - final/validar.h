#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

void myFgets(char* buffer, int limite ,FILE* archivo);

int val_getUnsignedInt(int* destino, char* mensaje,char* mensajeError,int intentos,int lowLimit, int hiLimit);
int val_validarUnsignedInt(char* buffer);

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esSoloLetras(char* buffer);

int val_getPrecio(float* destino, char* mensaje,char* mensajeError,int intentos,float lowLimit, float hiLimit);
int val_soloNumeros(char* buffer);

int val_getCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);

int val_getAlfanumerico(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esAlfaNumerico(char str[]);
int val_esNumericoFlotante(char str[]);



#endif // VALIDAR_H_INCLUDED
