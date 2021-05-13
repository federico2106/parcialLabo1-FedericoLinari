/*
Se necesita gestionar una bicicletería y para eso se deberá desarrollar lo siguiente:
ENTIDADES:
Servicio:
● id (comienza en 20000, autoincremental)
● descripción (máximo 25 caracteres)
● precio
Trabajo:
● id (autoincremental)
● marcaBicicleta (Cadena) Validar
● rodadoBicicleta
● idServicio (debe existir) Validar
● fecha (Validar día, mes y año)
DATOS PREVIOS:
El array de servicios deberá ser hardcodeado.
Servicios (Limpieza: $250, Parche: $300, Centrado: $400, Cadena: $350)
MENU DE OPCIONES:
A. ALTA TRABAJO
B. MODIFICAR TRABAJO: Se ingresará el id, permitiendo en un submenú modificar:
● La marca de la bicicleta
● El servicio
C. BAJA TRABAJO: Se ingresará el id del trabajo y se realizará una baja lógica.
D. LISTAR TRABAJOS: Hacer un único listado de todos los trabajos ordenados por año y ante igualdad
de año por marca de la bicicleta.
E. LISTAR SERVICIOS
F. TOTAL en pesos por los servicios prestados.
*/

#include <stdio.h>
#include <stdlib.h>
#include "bicileteria.h"
#define TAM 3


typedef struct
{
    int idServicio;
    char descripcion[25];
    float precio;
    int isEmpty;
}eServicio;

int main()
{

    int seguir='s';
    int id=2000;

    eTrabajo miTrabajo[TAM];


   do
    {
      switch (Menu ())
        {
            case 1:
                altaTrabajo(miTrabajo,TAM,id);
                 system("pause");
            break;
            case 2:
               ModificarTrabajo(miTrabajo,TAM);
               system("pause");
            break;
            case 3:
                bajaTrabajo(miTrabajo,TAM);
                system("pause");
            break;
            case 4:

            break;
            case 5:
            printf ("Hasta Pronto\n");
            seguir = 'n';
            break;
            default:
            printf ("\nOpcion invalida.\n");

        }

    }while (seguir == 's');

    return 0;
}

void harcodearServicio(eServicio listaServicio[])
{

            int codigoServicio[5]= {0,1,2,2,4};


    int idServicio[5]= {100,200,300,400,500};
    char descripcion[5][20]= {"Limpieza","Parche","Centrado","Cadena"};

    float precio[5]={250,300,400,350};


    for(int i=0; i<5; i++)
    {
        listaServicio[i].idServicio= idServicio[i];
        strcpy(listaServicio[i].descripcion,descripcion[i]);

        listaServicio[i].precio=precio[i];
        listaServicio[i].isEmpty=0;

    }


}
