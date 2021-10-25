#include "estructuras.h"

/// crear tda de lista

NodoUsuario * inicListaUsuario()
{
    return NULL;
}
NodoUsuario * crearNodoUsuario(stUsuario dato)
{
    NodoUsuario * nuevoNodo=(NodoUsuario*)malloc(sizeof(NodoUsuario));
    nuevoNodo->datos=dato;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}
void mostrarUnNodo_Usuario(NodoUsuario * seg)
{
    mostrar_usuario(seg->datos);
}

void mostrarNodos_Usuario(NodoUsuario * lista)
{
    NodoUsuario *seg=lista;

    while(seg!=NULL)
    {
        mostrarUnNodo_Usuario(seg);
        seg=seg->siguiente;

    }
}
void mostrarNodos_Usuario_validos(NodoUsuario * lista)
{
    NodoUsuario * seg=lista;

    while(seg!=NULL)
    {
        if(seg->datos.validos==1){
        mostrarUnNodo_Usuario(seg);
        seg=seg->siguiente;
        }else{
        seg=seg->siguiente;
    }
    }
}
NodoUsuario* agregar_al_principio_usuario(NodoUsuario *lista, NodoUsuario *nuevoNodo)
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
NodoUsuario * buscar_el_ultimo_usuario(NodoUsuario * lista)
{
    NodoUsuario *seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}
NodoUsuario * agregar_al_final_usuario(NodoUsuario * lista, NodoUsuario * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        NodoUsuario *ultimo=buscar_el_ultimo_usuario(lista);
        ultimo->siguiente=nuevoNodo;
    }
    return lista;
}
NodoUsuario * borrarPrimerNodo(NodoUsuario * lista)
{
    NodoUsuario * seg=lista;
    lista=lista->siguiente;
    free(seg);
    return lista;
}
NodoUsuario * borrarUltimoNodo(NodoUsuario * lista)
{
    NodoUsuario * seg;
    NodoUsuario * ante;

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

///funcion lista libros
NodoLibro * inicListaLibro()
{
    return NULL;
}

NodoLibro * crearNodoLibro(stLibro dato)
{
    NodoLibro * nuevoNodo=(NodoLibro*)malloc(sizeof(NodoLibro));
    nuevoNodo->datos=dato;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}
void mostrarNodos_Libros(NodoLibro * lista)
{
    NodoLibro *seg=lista;

    while(seg!=NULL)
    {
        mostrarUnNodo_Libro(seg);
        seg=seg->siguiente;
    }
}

void mostrarUnNodo_Libro(NodoLibro * seg)
{
    mostrar_libro(seg->datos);
}

NodoLibro* agregar_al_principio_libro(NodoLibro *lista, NodoLibro *nuevoNodo)
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
NodoLibro * buscar_el_ultimo_libro(NodoLibro * lista)
{
    NodoLibro *seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}
NodoLibro * agregar_al_final_libro(NodoLibro * lista, NodoLibro * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        NodoLibro *ultimo=buscar_el_ultimo_libro(lista);
        ultimo->siguiente=nuevoNodo;
    }
    return lista;
}
NodoLibro * borrarPrimerNodo_libro(NodoLibro * lista)
{
    NodoLibro * seg=lista;
    lista=lista->siguiente;
    free(seg);
    return lista;
}
NodoLibro * borrarUltimoNodo_libro(NodoLibro * lista)
{
    NodoLibro * seg;
    NodoLibro * ante;

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










