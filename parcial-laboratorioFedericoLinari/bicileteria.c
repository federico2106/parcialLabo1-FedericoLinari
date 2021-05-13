
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
int buscarLibre (eTrabajo listaTrabajo[], int cant)
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
    int error= -1;
    int indice;
    eTrabajo nuevoTrabajo;

    if(listaTrabajo!=NULL && tam >0 && id >0)
    {
        indice=buscarLibre(listaTrabajo,tam);
        if(indice==1 )
        {
            printf("Sistema COMPLETO\n");
        }
        else
        {
            nuevoTrabajo.idTrabajo=id;
            nuevoTrabajo.isEmpty=0;
            printf("Ingrese marca:\n:");
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

void mostararUnTrabajo(eTrabajo miTrabajo)
{
    printf("%d %s %d %s %s %f\n",miTrabajo.idTrabajo,miTrabajo.marcaBicicleta,miTrabajo.rodadoBicicleta);
}

int mostrarTrabajo(eTrabajo listaTrabajo[],int tam)
{
    int error=1;
    int flag=0;
    if(listaTrabajo!=NULL && tam>0)
    {
        printf("MARCA*****RODADO \n");
        for(int i=0; i<tam; i++)
        {
            if( listaTrabajo[i].isEmpty==0)
            {
                mostararUnTrabajo(listaTrabajo[i]);
                flag=1;
            }
        }

        if(flag==0)
        {
            printf("No hay trabajos en la lista...");
        }
        else
        {
            printf("\n\n");
        }

        error=0;
    }

    return error;

}

int bajaTrabajo(eTrabajo listaTrabajo[],int tam)
{
    int error=-1;

    int indice;
    int idTrabajo;
    char confirma;
    printf("Sistema de bajas.");
    mostrarTrabajo(listaTrabajo,tam);
    printf("ingrese idTrabajo");
    scanf("%d",&idTrabajo);
    if(listaTrabajo!=NULL && tam>0 && idTrabajo>0)
    {



        indice=buscarLibre(listaTrabajo,tam);

        if(indice==1)
        {
            printf("No hay ningun trabajo con ese codigo.");
        }
        else
        {
            mostararUnTrabajo(listaTrabajo[indice]);
            printf("Confirma baja?");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                listaTrabajo[indice].isEmpty=1;
                error=0;
            }
            else
            {
                error=2;
            }


        }

        return error;

    }
}

int ModificarTrabajo(eTrabajo listaTrabajo[],int tam)
{
    int error = -1;
    int indice;
    int idTRabajo;
    int opcion;
    eTrabajo nuevaModificacion;
    char confirma;
    printf("\n\n\t\t\t\t\t**Sistema de bajas**\n\n");
    mostrarTrabajo(listaTrabajo,tam);

    printf("Ingrese ID \n");
    scanf("%d",&idTRabajo);
    if(listaTrabajo !=NULL && tam > 0 && idTRabajo > 0)
    {


        indice=buscarLibre(listaTrabajo,tam);


        if(indice == 1)
        {
            printf("No existe en nuestro sistema el ID\n");
        }
        else
        {
            mostrarTrabajo(listaTrabajo,tam);

            nuevaModificacion=listaTrabajo[indice];
            printf("Que desea modificar?\n");
            printf("1)NOMBRE\n2)EDAD\n3)RAZA\n\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese marca a modificar ");
                fflush(stdin);
                gets(nuevaModificacion.marcaBicicleta);
                break;

            case 2:
                printf("\nIngrese rodado a modificar:\n ");
                scanf("%d",&nuevaModificacion.rodadoBicicleta);
                break;




            }
            printf("\nDesea efectuar el cambio? s/n?\n");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                strcpy(listaTrabajo [indice].marcaBicicleta,nuevaModificacion.marcaBicicleta);
                listaTrabajo[indice].rodadoBicicleta=nuevaModificacion.rodadoBicicleta;
                error=0;
            }
            else
            {
                error =2;
            }
        }
    }
    return error;
}
