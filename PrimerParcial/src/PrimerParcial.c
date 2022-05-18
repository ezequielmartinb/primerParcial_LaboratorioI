#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "censista.h"
#include "localidades.h"
#include "zona.h"
#include "cargarDatos.h"

#define VACIO 1
#define CARGADO 0

#define ACTIVO 1
#define INACTIVO 2
#define LIBERADO 3

#define TAM_CENSISTA 5
#define TAM_ZONA 5
#define TAM_LOCALIDADES 8
#define TAM_CARGAR_DATOS 5

int main(void)
{
	Censista listaCensista[TAM_CENSISTA]={
										  {1001, "Ezequiel", "Bra�anova", {26,02,1993, 29},{"Mendoza", 328}, LIBERADO, 0, CARGADO},
										  {1002, "German", "Perez", {10,03,1963, 59},{"Alsina", 152}, LIBERADO, 0, CARGADO},
										  {1003, "Gaston", "Hernandez", {21,02,1983, 39},{"Palaa", 300}, LIBERADO, 0, CARGADO},
										  {1004, "Julieta", "Gonzalez", {30,04,1973, 49},{"Belgrano", 370}, LIBERADO, 0, CARGADO},
										  {1005, "Alberto", "Alcaraz", {14,12,1975, 47},{"Mitre", 1500}, LIBERADO, 0, CARGADO}};
	Zona listaZona[TAM_ZONA];
	Localidad listaLocalidades[TAM_LOCALIDADES]= {{1, "Avellaneda"},
												    {2, "Sarandi"},
												    {3, "Dock Sud"},
												    {4, "Pineyro"},
												    {5, "Villa Dominico"},
												    {6, "Gerli"},
												    {7, "Wilde"},
												    {8, "Crucecita"}};
	CargaDatos listaCargarDatos[TAM_CENSISTA];
	int banderaCargaCensista=1;
	int opcionIngresada;
	int idIngresado;

	setbuf(stdout, NULL);
	//inicializarCensistas(listaCensista, TAM_CENSISTA);
	inicializarZona(listaZona, TAM_ZONA);
	inicializarCargarDatos(listaCargarDatos, TAM_CARGAR_DATOS);
	while(opcionIngresada!=9)
	{
		printf("\t***MENU DE OPCIONES***\n\n");
		printf("1- CARGAR CENSISTA\n"
			   "2- MODIFICAR CENSISTA\n"
			   "3- DAR LA BAJA CENSISTA\n"
			   "4- CARGAR ZONA\n"
			   "5- ASIGNAR ZONA A CENSISTA\n"
			   "6- CARGA DE DATOS\n"
			   "7- MOSTRAR CENSISTA\n"
			   "8- MOSTRAR ZONAS\n"
			   "9- SALIR\n");
		if(utn_getNumeroEntero(&opcionIngresada, "Ingrese una opcion: ", "ERROR. OPCION INVALIDA. ", 0, 8, 3)==0)
		{
			switch(opcionIngresada)
			{
				case 1:
					if(cargarCensista(listaCensista, TAM_CENSISTA)==0)
					{
						printf("\n\n\n\tLA CARGA DEL CENSISTA FUE EXITOSA\n\n\n");
						banderaCargaCensista=1;
					}
					else
					{
						printf("\n\n\n\tLA CARGA DEL CENSISTA NO FUE EXITOSA\n\n\n");
					}
					break;
				case 2:
					imprimirCensista(listaCensista, TAM_CENSISTA);
					if(banderaCargaCensista==0)
					{
						printf("\n\n\n\tANTES DE MODIFICAR, PRIMERO HAY QUE CARGAR DE FORMA EXITOSA LOS/EL CENSISTA/S\n\n\n");
					}
					else
					{
						if(utn_getNumeroEntero(&idIngresado, "Ingrese el ID que desea modificar: ", "ERROR. ID ERRONEO", 1001, 1005, 3)==-1)
						{
							printf("\tMODIFICACION DENEGADA\n");
						}
						if(modificarCensista(listaCensista, TAM_CENSISTA, idIngresado)==0)
						{
							printf("\tLa MODIFICACION fue realizada con EXITO\n\n");
						}
					}

					break;
				case 3:
					//printf("ACA VA LA BAJA CENSISTA\n");
					if(bajaCensista(listaCensista, TAM_CENSISTA, idIngresado)==0)
					{
						printf("\n\n\n\tLA BAJA DEL CENSISTA FUE EXITOSA\n\n\n");
					}
					break;
				case 4:
					//printf("ACA VA LA CARGA DE LA ZONA\n");
					if(cargarZona(listaZona, TAM_ZONA, listaCensista, TAM_CENSISTA, listaLocalidades, TAM_LOCALIDADES)==0)
					{
						printf("\n\n\n\tLA CARGA DE LA ZONA FUE EXITOSA\n\n\n");
					}
					break;
				case 5:
					//printf("ACA VA LA ASIGNACION DE LA ZONA AL CENSISTA\n");
					if(asignarZona(listaZona, TAM_ZONA, listaCensista, TAM_CENSISTA, listaLocalidades, TAM_LOCALIDADES)==0)
					{
						printf("La asignacion fue exitosa\n");
					}
					break;
				case 6:
					cargarDatos(listaCensista, TAM_CENSISTA, listaZona, TAM_ZONA, listaLocalidades, TAM_LOCALIDADES, listaCargarDatos, TAM_CARGAR_DATOS);
					break;
				case 7:
					if(banderaCargaCensista==0)
					{
						printf("\n\n\n\tANTES DE IMPRIMIR, PRIMERO HAY QUE CARGAR DE FORMA EXITOSA LOS/EL CENSISTA/S\n\n\n");
					}
					else
					{
						imprimirCensista(listaCensista, TAM_CENSISTA);
					}
					break;
				case 8:
					//printf("ACA VA EL MOSTRAR ZONAS\n");
					imprimirZona(listaZona, TAM_ZONA, listaLocalidades, TAM_LOCALIDADES, listaCensista, TAM_CENSISTA);
					break;
				case 0:
					printf("SALIR\n");
					break;

			}
		}
	}
	return EXIT_SUCCESS;
}
