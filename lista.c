#include "estructuras.h"

/// crear tda de lista

Nodo * inicLista()
{
    return NULL;
}
Nodo * crearNodo(stUsuario user)
{
    Nodo * nuevoNodo=(Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->datos=user;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

void mostrarNodos(Nodo * lista)
{
    Nodo *seg=lista;

    while(seg!=NULL)
    {
        mostrarUnNodo(seg);
        seg=seg->siguiente;
    }
}

void mostrarUnNodo(Nodo * seg)
{
    mostrar_mi_perfil(seg->datos,seg->datos.id);
}

Nodo* agregar_al_principio(Nodo *lista, Nodo *nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }
    return lista;
}
Nodo * buscar_el_ultimo(Nodo * lista)
{
    Nodo *seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}
Nodo * agregar_al_final(Nodo * lista, Nodo * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        Nodo *ultimo=buscar_el_ultimo(lista);
        ultimo->siguiente=nuevoNodo;
    }
    return lista;
}
Nodo * borrarPrimerNodo(Nodo * lista)
{
    Nodo * seg=lista;
    lista=lista->siguiente;
    free(seg);
    return lista;
}
Nodo * borrarUltimoNodo(Nodo * lista)
{
    Nodo * seg;
    Nodo * ante;

    if(lista!=NULL)
    {
        if(lista->siguiente ==NULL)
        {
            seg=lista;
            lista=lista->siguiente;
            free(seg);
        }
        else
        {
            seg=lista;
            while(seg->siguiente!=NULL)
            {
                ante=seg;
                seg=seg->siguiente;

            }
            free(seg);
            ante->siguiente=NULL;
        }

    }
    return lista;
}










