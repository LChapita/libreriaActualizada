#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int numLibro;
    char autor[30];
    char nombreLibro[50];
    char genero[30];
    int valida;
}stLibro;
typedef struct
{
    stLibro dato;
    struct nodoArbol * izquierda;
    struct nodoArbol * derecha;

}nodoArbolLibro;



nodoArbolLibro * inicArbol();
nodoArbolLibro * crearNodoArbol(stLibro dato);
nodoArbolLibro * insertar(nodoArbolLibro * arbol,stLibro dato);
void mostrarUnLibroArbol(stLibro dato);
void preorder(nodoArbolLibro * arbol);
void inorder(nodoArbolLibro * arbol);
void postorder(nodoArbolLibro * arbol);
nodoArbolLibro* buscar(nodoArbolLibro * arbol,stLibro dato);

#endif // ARBOLES_H_INCLUDED
