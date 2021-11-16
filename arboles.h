#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

#include "estructuras.h"

typedef struct
{
    stFavoritos dato;
    struct nodoArbolFavoritos * izquierda;
    struct nodoArbolFavoritos * derecha;

}nodoArbolFavoritos;



nodoArbolFavoritos * inicArbol();
nodoArbolFavoritos * crearNodoArbol(stFavoritos dato);
nodoArbolFavoritos * insertarEnArbol(nodoArbolFavoritos * arbol,stFavoritos dato);
void mostrarUnLibroArbol(stFavoritos dato);

void preorder(nodoArbolFavoritos * arbol);
void inorder(nodoArbolFavoritos * arbol);
void postorder(nodoArbolFavoritos * arbol);

nodoArbolFavoritos* buscar(nodoArbolFavoritos * arbol,stFavoritos dato);
void mostrar_libro_favorito(stFavoritos favorito,int y);

nodoArbolFavoritos * pasar_archivo_Favoritos_a_arbol(stFavoritos favorit,nodoArbolFavoritos * arbol,int iduser);

#endif // ARBOLES_H_INCLUDED
