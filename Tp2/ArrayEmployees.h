#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;

/** \brief Primer menu de opciones
*
* \
* \
* \return Devuelve la opción elegida
*/
int menu();


/** \brief Inicializa los empleados. Selecciona a los que ID habilitados.
*
* \ Incluye la estructura pricipal
* \ Incluye la medida (cantidad de empleados)
* \return 0
*/
int initEmployees(Employee* list, int len);


/** \brief Busca el primer indice libre
*
* \ Incluye la estructura pricipal
* \ Incluye la medida (cantidad de empleados)
* \return indice del empleado libre
*/
int findFreeEmployee(Employee* list, int len);


/** \brief Agrega los datos de un empleado (ID, nombre, apellido, salario y sector)
*
* \ Incluye la estructura pricipal
* \ Incluye el id (autoincremental)
* \ Incluye el nombre que va a ingresar el usuario
* \ Incluye el apellido que va a ingresar el usuario
* \ Incluye el salario que va a ingresar el usuario
* \ Incluye el numero del sector que va a ingresar el usuario
* \return 0
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Busca el ID de un empleado
*
* \ Incluye la estructura pricipal
* \ Incluye la medida (cantidad de empleados)
* \ Incluye el ID que va a ingresar el usuario para buscar
* \return indice del empleado buscado o -1 si no encontro el indice
*/
int findEmployeeById(Employee* lis, int len,int id);


/** \brief Da de baja a un empleado // cambia el valor de la variable isEmpty
*
* \ Incluye la estructura pricipal
* \ Incluye la medida (cantidad de empleados)
* \ Incluye el ID que va a ingresar el usuario para dar de baja
* \return 0 si se pudo dar la baja o -1 si no se realizo
*/
int removeEmployee(Employee* list, int len, int id);


/** \brief Ordena a los empleados por apellido
*
* \ Incluye la estructura pricipal
* \ Incluye la medida (cantidad de empleados)
* \ Incluye el criterio de ordenamiento: 1 = menor a mayor / 2 = mayor a menor
* \return 0
*/
int sortEmployees(Employee* list, int len, int order);


/** \brief Imprime en pantalla los datos de los empleados
*
* \ Incluye la estructura pricipal
* \ Incluye la medida (cantidad de empleados)
* \
* \return 0
*/
int printEmployees(Employee* list, int length);


/** \brief Imprime en pantalla los datos de un empleado
*
* \ Incluye la estructura pricipal
* \ Incluye la medida (cantidad de empleados)
* \
* \return 0
*/
int printEmployee(Employee list);


/** \brief Busca el primer indice libre de la estructura
*
* \ Incluye la estructura principal
* \ Incluye la medida (cantidad de empleados)
* \
* \return indice libre
*/
int findFreeEmployee(Employee* list, int len);


/** \brief Menu de opciones para modificar empleado
*
* \
* \
* \return Devuelve la opción elegida
*/
int menuChangeEmployee();


/** \brief Modifica los datos de un empleado (nombre, apellido, salario o sector)
*
* \ Incluye la estructura principal
* \ Incluye la medida (cantidad de empleados)
* \return 0
*/
int changeEmployee(Employee* list, int len);


/** \brief Menu de opciones para Informes
*
* \
* \
* \return Devuelve la opción elegida
*/
int menuInform();


/** \brief Informa promedio salarial y lista a los empleados que superan ese promedio
*
* \ Incluye la estructura principal
* \ Incluye la medida (cantidad de empleados)
* \return 0
*/
int informSalary(Employee* list, int len);


#endif // ARRAYEMPLOYEES_H_INCLUDED




