#include "arboles.h"

nodoArbolLibro * inicArbol()
{
    return NULL;
}

nodoArbolLibro * crearNodoArbol(stLibro dato)
{
    nodoArbolLibro * arbol = (nodoArbolLibro*) malloc(sizeof(nodoArbolLibro));
    arbol->dato = dato;
    arbol->derecha = NULL;
    arbol->izquierda = NULL;

    return arbol;
}

nodoArbolLibro * insertar(nodoArbolLibro * arbol,stLibro dato)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if(dato.numLibro > arbol->dato.numLibro)
        {
            arbol->derecha = insertar(arbol->derecha,dato);
        }
        else
        {
            arbol->izquierda = insertar(arbol->izquierda,dato);
        }
    }
    return arbol;
}

void mostrarUnLibroArbol(stLibro dato)
{
    printf("Autor:  %s",dato.autor);
    printf("Genero: %s",dato.genero);
    printf("Nombre del Libro:  %s",dato.nombreLibro);
    printf("Numero del Libro:  %d",dato.numLibro);
}

void preorder(nodoArbolLibro * arbol)
{
    if(arbol!=NULL)
    {
        mostrarUnLibroArbol(arbol->dato);
        preorder(arbol->izquierda);
        preorder(arbol->derecha);
    }
}

void inorder(nodoArbolLibro * arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izquierda);
        mostrarUnLibroArbol(arbol->dato);
        inorder(arbol->derecha);
    }
}

void postorder(nodoArbolLibro * arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izquierda);
        postorder(arbol->derecha);
        mostrarUnLibroArbol(arbol->dato);
    }
}

nodoArbolLibro* buscar(nodoArbolLibro * arbol,stLibro dato)
{
    nodoArbolLibro * respuesta = NULL;
    if(arbol!=NULL)
    {
        if(dato.numLibro == arbol->dato.numLibro)
        {
            respuesta = arbol;
        }
        else if(dato.numLibro > arbol->dato.numLibro)
        {
            respuesta = buscar(arbol->derecha, dato);
        }
        else
        {
            respuesta = buscar(arbol->izquierda,dato);
        }
    }
    return respuesta;
}
