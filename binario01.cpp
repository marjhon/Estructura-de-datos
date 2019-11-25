#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Tipo_elemento;

struct nodo
{
	Tipo_elemento el;
	struct nodo *izq, *der;
};

typedef struct nodo NODO;

NODO* Crear_nodo(Tipo_elemento el);
NODO* Construir(Tipo_elemento el, NODO *izq, NODO *der);

//recibe como parametro un arbol y retorna su hijo izquierdo
NODO* Hijo_izq(NODO *a);

//recibe como parametro un arbol y retorna su hijo derecho
	NODO* Hijo_der(NODO *a);

/*------------------- Recoridos del arbol binario ---------------------*/
void Inorden(NODO *a);


/*---------------------------------------------------------------------*/

NODO* Crear_nodo(Tipo_elemento el)
{
	NODO *nuevo;
	nuevo=(NODO*)malloc(sizeof(NODO));
	nuevo->el=el;
	nuevo->izq = nuevo->der = NULL;
	return nuevo;
}
NODO* Construir(Tipo_elemento el, NODO *izq, NODO *der)
{
	NODO *nn;
	nn=Crear_nodo(el);
	nn->izq=izq;
	nn->der=der;
	return (nn);
}
NODO* Hijo_izq(NODO *a)
{
	if(a)
		return (a->izq);
	else
	{
		return (NULL);
	}
}
NODO* Hijo_der(NODO *a)
{
	if(a)
		return (a->der);
	else
	{
		return (NULL);
	}
}

void main()
{
	NODO *raiz=NULL;
	Construir(1,izq,der); Construir(6,NULL,NULL);  Construir(4,NULL,NULL);
	Construir(10,izq,der); Construir(12,NULL,NULL);  Construir(8,NULL,NULL);
	
	printf("El recorrido en inorden sera:");
	Inorden(raiz);
	getchar();
}

void Inorden(NODO *a)
{
	if(a)
	{
		Inorden(a->izq);
		printf("%d", a->el);
		Inorden(a->der);
	}
}

