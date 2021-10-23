#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct
{
    stUsuario datos;
    struct Nodo*siguiente;
}Nodo;

Nodo * inicLista();

Nodo * crearNodo(stUsuario user);

void mostrarNodos(Nodo * lista);

void mostrarUnNodo(Nodo * seg);

Nodo* agregar_al_principio(Nodo *lista, Nodo *nuevoNodo);

Nodo * buscar_el_ultimo(Nodo * lista);

Nodo * agregar_al_final(Nodo * lista, Nodo * nuevoNodo);

Nodo * borrarPrimerNodo(Nodo * lista);

Nodo * borrarUltimoNodo(Nodo * lista);



#endif // LISTA_H_INCLUDED
