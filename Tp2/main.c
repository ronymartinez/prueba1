#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"


#define TAM 2000 //TRABAJO SOLO CON IDS QUE VAN DEL 1000 A 2000

int main()
{
    char seguir = 's';
    char confirma;
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int sector;
    int orden;
    int triggerAdd = 0; //LLAVE PARA NO SALTEARSE OPCIONES

    Employee emp[TAM];
    initEmployees(emp, TAM);

    do
    {
        switch(menu())
        {
        case 1: //AGREGAR EMPLEADO
            if (0 == addEmployee(emp, TAM, legajo, nombre, apellido, sueldo, sector))
            {
            triggerAdd = 1; // HABILITO EL USO DE LAS SIGUIENTES OPCIONES DEL MENU
            }
            break;
        case 2: // MODIFICAR EMPLEADO
            if (triggerAdd == 1) // SOLO ENTRAMOS SI YA SE AGREDO UN EMPLEADO
            {
            changeEmployee(emp, TAM);
            }
            else
            {
                system("clear");
                printf("\nNo puede modificar si no ingresó un empleado.");
                printf("\n\nPresione ENTER para volver. ");
            }
            break;
        case 3: // MODIFICAR EMPLEADO
        if (triggerAdd == 1)
            {
            removeEmployee(emp, TAM, legajo);
            }
            else
            {
                system("clear");
                printf("\nNo puede eliminar si no ingresó un empleado.");
                printf("\n\nPresione ENTER para volver. ");
            }
            break;
        case 4://DAR DE BAJA UN EMPLEADO
        if (triggerAdd == 1)
            {
            menuInform(emp, TAM, orden);
            }
            else
            {
                system("clear");
                printf("\nNo puede ver informes si no ingresó un empleado.");
                printf("\n\nPresione ENTER para volver. ");
            }
            break;
        case 5: //SALIR DEL MENU
            printf("\nIngrese 's' para confirmar salida: ");
            __fpurge(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
        getchar();
    }
    while(seguir == 's');

    printf("\n\n");

    return 0;
}




