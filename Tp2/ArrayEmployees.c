#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"

int menu()
{
    int opcion; // MENU DE OPCIONES

    system("clear");
    printf("****** EMPLEADOS *****\n\n");
    printf("1. Alta\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Salir\n\n");
    utn_getNumero(&opcion, "\nIngrese opcion: ","\nError: no es una opcion valida.\n", 1,5, 3);
    __fpurge(stdin);

    return opcion;
}

int initEmployees(Employee* list, int len)
{
    //HABILITA TRABAJAR SOLO CON LOS IDS DE EMPLEADOS HABILITADOS, IGNORA LOS DADOS DE BAJA
    for(int i = 0; i < len; i++)
    {
        list[i].isEmpty = 1;
    }

    return 0;
}

int findFreeEmployee(Employee* list, int len)
{
    //BUSCA EL PRIMER INDICE LIBRE PARA ASIGNARSELO A UN NUEVO EMPLEADO
    //SI EL USUARIO INGRESO UN ID INCORRECTO ESTA FUNCION GUARDA UN -1 QUE SERVIRA PARA OTRAS FUNCIONES
    int indice = -1;

    for (int i = 0; i < len; i++)
    {
        if (list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    //AGREGA A UN EMPLEADO Y ASIGNA IDS DEL 1000 AL 2000
    int todoOk = -1;
    id = findFreeEmployee(list, len); // USA EL ID LIBRE QUE ME DIO LA FUNCION findFreeEmployee

    Employee auxEmpleado; // DECLARO UN EMPLEADO AUXILIAR PARA AGREGARLE INFORMACION

    system("clear");
    printf("*** Alta del empleado ***\n\n");

    if( id == -1) // Hay lugar?
    {
        printf("Sistema Completo\n\n");
    }
    else
    {

        utn_getNombre(auxEmpleado.name, 20, "\nIngrese nombre: ","\nError: No es un dato valido.",3);
        strlwrLinux(auxEmpleado.name); // CONVIERTE EN MINUSCULA LO INGRESADO POR EL USUARIO
        auxEmpleado.name[0] = toupper(auxEmpleado.name[0]);// CONVIERTE EN MAYUSCULA LA PRIMERA LETRA DEL NOMBRE

        utn_getNombre(auxEmpleado.lastName, 20, "\nIngrese apellido: ","\nError: No es un dato valido.",3);
        strlwrLinux(auxEmpleado.lastName);//CONVIERTE EN MINUSCULA LO INGRESADO POR EL USUARIO
        auxEmpleado.lastName[0] = toupper(auxEmpleado.lastName[0]);//CONVIERTE EN MAYUSCULA LA PRIMERA LETRA DEL APELLIDO

        utn_getNumeroFlotante(&auxEmpleado.salary,"\nIngrese sueldo: ","\nError: no es un numero valido",0, 9999999, 3);
        printf("\n**** Sectores ****"); //MENU DE SECTORES
        printf("\n1. Sistemas.\n2. RR.HH.\n3. Ventas.\n4. Mantenimiento.\n5. Contable.\n");

        utn_getNumero(&auxEmpleado.sector,"\nIngrese sector: ","Error: no es un sector valido.",1,5, 3);
        printf("\n\nSe ha incluido un empleado correctamente");

        auxEmpleado.isEmpty = 0;
        auxEmpleado.id = id + 1000; // SUMO 1000 PARA INICIAR LOS IDS EN 1000

        list[id] = auxEmpleado; // COPIO LOS DATOS INGRESADOS EN LA ESTRUCTURA PRINCIPAL

        todoOk = 0;
    }

    return todoOk;
}

int findEmployeeById(Employee* list, int len,int id)
{
    //BUSCA A UN EMPLEADO HABILITADO, NO RECONOCE A LOS IDS DADOS DE BAJA
    int indice = -1;

    for (int i = 0; i < len; i++)
    {
        if (list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menuChangeEmployee()
{
    //MENU PARA MODIFICAR EMPLEADO
    int opcion;

    printf("\n\n\n\n****** MODIFICAR EMPLEADO *****\n\n");
    printf("1. Modificar nombre.\n");
    printf("2. Modificar apellido.\n");
    printf("3. Modificar sueldo.\n");
    printf("4. Modificar sector.\n");
    printf("5. Salir.\n\n");
    __fpurge(stdin);
    utn_getNumero(&opcion, "Ingrese opcion: ","\nError: no es una opcion valida.\n", 1,5, 3);

    return opcion;
}

int changeEmployee(Employee* list, int len)
{
    //MODIFICA DATOS DE UN EMPLEADO
    int id;
    int indice;
    char confirma;

    system("clear");
    printf("*** MODIFICAR EMPLEADO***");
    utn_getNumero(&id,"\n\nIngrese ID del empleado: ", "\nError: No es un dato valido.",1000, 2000, 3);
    indice = findEmployeeById(list, len, id); // LLAMO A LA FUNCION QUE BUSCA EMPLEADO Y LO GUARDO EN EL LA VARIABLE INDICE

    if(indice == -1) // SI LA FUNCION DE BUSCAR EMPLEADO NO PUDO ENCONTRAR EL ID NO SE PODRA EJECUTAR LA MODIFICACION
    {
        system("clear");
        printf("\n\nNo hay registro de empleado con el ID %d\n\n", id);
        getchar();
    }
    else
    { //SI LA FUNCION DE BUSCAR EMPLEADO ENCONTRO UN ID VALIDO ENTRAMOS AL ELSE
        do
        {
        system("clear");
        printf("Empleado a modificar: \n\n");
        printf("    ID      Apellido       Nombre       Sueldo    Sector\n");
        printEmployee(list[indice]);

            switch(menuChangeEmployee())
            {
            case 1:
                system("clear");
                utn_getNombre(list[indice].name, 20, "\nIngrese nuevo nombre: ","\nError: No es un dato valido.",3);
                strlwrLinux(list[indice].name); // CONVIERTO LOS DATOS A MINUSCULA
                list[indice].name[0] = toupper(list[indice].name[0]); //CONVIERTO LA PRIMERA LETRA EN MAYUSCULA
                printf("\n\nSe ha modificado el nombre.");
                break;

            case 2:
                system("clear");
                utn_getNombre(list[indice].lastName, 20, "\nIngrese nuevo apellido: ","\nError: No es un dato valido.",3);
                strlwrLinux(list[indice].lastName);// CONVIERTO LOS DATOS A MINUSCULA
                list[indice].lastName[0] = toupper(list[indice].lastName[0]);//CONVIERTO LA PRIMERA LETRA EN MAYUSCULA
                printf("\n\nSe ha modificado el apellido.");
                break;

            case 3:
                system("clear");
                utn_getNumeroFlotante(&list[indice].salary,"Ingrese nuevo sueldo: ","\nError: no es un sueldo valido.\n",0,999999, 3);
                printf("\n\nSe ha modificado el sueldo.");
                break;

            case 4:
                system("clear");
                utn_getNumero(&list[indice].sector,"\nIngrese nuevo sector: ","Error: no es un sector valido.",1,5, 3);
                printf("\n\nSe ha modificado el sector.");
                getchar();
                break;

            case 5:
                printf("\nIngrese 's' para confirmar salida: ");
                __fpurge(stdin);
                scanf("%c", &confirma);
                if(confirma == 's')
                {
                    confirma = 'n';
                }
                break;
            }
        }while(confirma == 's');
    }
    return 0;
}

int printEmployee(Employee list)
{
    //IMPRIME UN EMPLEADO EN LA PANTALLA
    printf("\n  %d    %10s   %10s   %10.2f        %2.d  ",
            list.id, list.lastName, list.name, list.salary, list.sector);
    return 0;
}

int printEmployees(Employee* list, int length)
{
    int flag = 0;//BANDERA PARA DETENER O INICIAR EL FOR
    system("clear");
    printf("\n\n            ******** LISTADO DE EMPLEADOS ********\n\n\n\n");
    printf("    ID        Apellido     Nombre       Sueldo     Sector\n");

    for(int i = 0; i < length; i++)
    {
        if( list[i].isEmpty == 0)
        {
            printEmployee(list[i]); //SELECCIONA SOLO A LOS EMPLEADOS HABILITADOS
            flag = 1;//SALE DEL FOR CUANDO ENCUENTRA UN ID VACIO
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay empleados para listar");
    }
    return 0;
}


int removeEmployee(Employee* list, int len, int id)
{
    //DAR DE BAJA UN EMPLEADO
    char confirmar;
    int indice;
    int todoOk = -1;

    system("clear");
    utn_getNumero(&id,"\n\nIngrese ID del empleado a eliminar: ", "\nError: No es un dato valido.",1000, 2000, 3);
    indice = findEmployeeById(list, len, id); //LLAMO A LA FUNCION QUE BUSCA EMPLEADO POR ID

    if(indice == -1) // SI EL USUARIO INGRESO UN ID NO HABILITADO NO ACEPTA HACER CAMBIOS
    {
        system("clear");
        printf("\nNo hay registro de empleado con el ID %d\n\n", id);
        getchar();
    }
    else
    {
        system("clear");
        printf("    ID        Apellido     Nombre       Sueldo     Sector\n");

        printEmployee(list[indice]); //HACE UNA VISTA PREVIA DEL EMPLEADO A MODIFICAR

        printf("\n\nIngrese 's' para confirmar baja: ");
        __fpurge(stdin);
        scanf("%c", &confirmar);

        if (confirmar == 's')
        {
        list[indice].isEmpty = 1;
        printf("\nSe ha eliminado el empleado");
        }
        else
        {
            printf("\nSe ha cancelado la operación");
        }
        getchar();
        todoOk = 0;
    }
    return todoOk;
}

int menuInform(Employee* list, int len, int order)
{
    //MENU DE INFORMES
    char confirma;


    int opcion;

    system("clear");
    printf("\n       ***** INFORMES *****\n");
    printf("\n1. Mostrar lista de empleados.");
    printf("\n2. Mostrar sueldos totales y promedios.");
    printf("\n3. Salir.");
    utn_getNumero(&opcion, "\nIngrese opcion: ","\nError: no es una opcion valida.\n", 1,3, 3);
    __fpurge(stdin);

    switch (opcion)
    {
        case 1: //ENTRA A LAS FUNCIONES PARA ORDENAR LA LISTA
        sortEmployees(list, len, order);
        break;

        case 2: //IMPRIME PROMEDIO SALARIAL Y EMPLEADOS QUE SUPERAN EL PROMEDIO
        informSalary(list, len);
        break;

        case 3:
        printf("Ingrese 's' para confirmar salida: ");
        __fpurge(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            break;
        }
    }
    return opcion;
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee auxEmp; //CREO UN EMPLEADO AUXILIAR PARA EL BURBUJEO

    system("clear");
    printf("\n1. Ordenar de menor a mayor.");
    printf("\n2. Ordenar de mayor a menor.");
    printf("\n3. Salir.");
    utn_getNumero(&order, "\n\nIngrese opcion: ","\nError: no es una opcion valida.\n", 1,3, 3);
    __fpurge(stdin);

    if (order == 1)
    {
    for(int i = 0; i < len; i++) // ORDENA DE MENOR A MAYOR LOS APELLIDOS (A - Z)
        {
            for(int j = i +1; j < len; j++)
            {
                if(strcmp(list[i].lastName, list[j].lastName) > 0)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }//AGREGO EL SECTOR EN EL BURBUJEO (1-5)
                else if(strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list [j].sector)
                    {
                        auxEmp = list[i];
                        list[i] = list[j];
                        list[j] = auxEmp;
                    }
            }
        }
    }
    else if(order == 2) // ORDENA DE MAYOR A MENOR LOS APELLIDOS (Z-A)
        for(int i = 0; i < len; i++)
        {
            for(int j = i +1; j < len; j++)
            {
                if(strcmp(list[i].lastName, list[j].lastName) < 0)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }//AGREGO EL SECTOR EN EL BURBUJEO (5 A 1)
                else if(strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list [j].sector)
                    {
                        auxEmp = list[i];
                        list[i] = list[j];
                        list[j] = auxEmp;
                    }
            }
        }

    printEmployees(list, len); //IMPRIME A LOS EMPLEADOS LUEGO DEL ORDENAMIENTO
    return 0;
}

int informSalary(Employee* list, int len)
{
    //IMPRIME EMPLEADOS Y SACA PROMEDIOS
    float acum = 0;
    float prom;
    int contIsEmpty = 0;
    int contSueldoMayor = 0;

    for(int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0)
            {
                acum = acum + list[i].salary; //SUMA EL SUELDO DE LOS EMPLEADOS
                contIsEmpty++; //CONTADOR DE EMPLEADOS HABILITADOS (SE IGNORAN LOS DADOS DE BAJA)
            }

            prom = (float) acum / contIsEmpty; // SACA EL PROMEDIO DE TODOS LOS SUELDOS HABILITADOS
        }
    for(int i = 0; i < len; i++)
    {
        if (list[i].salary > prom)
            {
            contSueldoMayor++; //CUENTA LA CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO
            }
    }
    system("clear");
    //IMPRIME EL SALARIO TOTAL, EL PROMEDIO Y LOS EMPLEADOS QUE SUPERAN EL PROMEDIO
    printf("\n           **** INFORME DE SALARIOS ****\n\n");
    printf("\n-El salario total es %.2f", acum);
    printf("\n-El promedio es %.2f", prom);
    printf("\n-Son %d los empleados que superan el promedio:", contSueldoMayor);

    printf("\n\n    ID        Apellido     Nombre       Sueldo     Sector\n");

    for(int i = 0; i < len; i++)
    {
        if (list[i].salary > prom)
        {
        printEmployee(list[i]) > prom;
        }
    }

    return 0;
}
