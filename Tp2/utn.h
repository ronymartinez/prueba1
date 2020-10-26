#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


int esNumerica(char* cadena);
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int getFloat(float* pResultado);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int esFlotante(char* cadena);
void strlwrLinux(char* cadena);
int getNombre(char* pResultado, int longitud);
int esNombre(char* cadena,int longitud);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int getString(char* cadena, int longitud);


#endif // UTN_H_INCLUDED
