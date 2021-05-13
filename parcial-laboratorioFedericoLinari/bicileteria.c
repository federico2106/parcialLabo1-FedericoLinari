
#include <stdio.h>
#include <stdlib.h>
#include "bicileteria.h"




int Menu()
{
  int opcion;
  system("cls");
  printf("\n\tElija una opcion:\n\t1. ALTA TRABAJO\n\t2. BAJA TRABAJO\n\t3. MODIFICAR TRABAJO\n\t4. LISTAR\n\t5. SALIR\n");
  scanf("%d", &opcion);
  system("cls");

  return opcion;
}

int inicializarTrabajo (eTrabajo listaTrabajo[], int tam)
{
  int error = 1;

  if (listaTrabajo != NULL && tam > 0)
    {
          for (int i = 0; i < tam; i++)
        {
          listaTrabajo[i].isEmpty = 1;
        }

      error = 0;
    }
  return error;
}
int buscarLIbre (eTrabajo listaTrabajo[], int cant)
{

  int indice = -1;
  int i;
  for (i = 0; i < cant; i++)
    {
          if (listaTrabajo[i].isEmpty == 1)
    	{
    	  indice = i;

    	  break;
    	}
    }
	  return indice;
}

int altaTrabajo(eTrabajo listaTrabajo[],int tam,int id)
{
    int error= 1;
    int indice;
    eTrabajo nuevoTrabajo;

    if(listaTrabajo!=NULL && tam >0 && id >0)
    {
        indice=buscarLIbre(listaTrabajo,tam);
        if(indice==-1 )
        {
            printf("Sistema COMPLETO\n");
        }
        else
        {
            nuevoTrabajo.idTrabajo=id;
            nuevoTrabajo.isEmpty=0;
            printf("Ingrese nombre:\n:");
            fflush(stdin);
            gets(nuevoTrabajo.marcaBicicleta);
            fflush(stdin);
            nuevoTrabajo.rodadoBicicleta= getInt(nuevoTrabajo.rodadoBicicleta,"Ingrese el rodado de la bicicleta","Error, reingrese el rodado.\n");


            listaTrabajo[indice]=nuevoTrabajo;
            listaTrabajo[indice].idTrabajo=indice+1;
        }
    }
    return error;
}

int getInt(eTrabajo listaTrabajo[],char mensaje[],char mensajeError[])
{
    int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxiliar);
    while(auxiliar<0)
    {
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%d",&auxiliar);

    }
    return auxiliar;
}



