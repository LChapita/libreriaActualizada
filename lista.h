#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct
{
    stUsuario datos;
    struct Nodo*siguiente;
}NodoUsuario;

typedef struct
{
    stLibro datos;
    struct Nodo*siguiente;
}NodoLibro;

///nodos usuarios
NodoUsuario * inicListaUsuario();

NodoUsuario * crearNodoUsuario(stUsuario user);

void mostrarNodos_Usuario(NodoUsuario * lista);

void mostrarUnNodo_Usuario(NodoUsuario * seg);

NodoUsuario * agregar_al_principio_usuario(NodoUsuario *lista, NodoUsuario *nuevoNodo);

NodoUsuario * buscar_el_ultimo_libro_usuario(NodoUsuario * lista);

NodoUsuario * agregar_al_final_usuario(NodoUsuario * lista, NodoUsuario * nuevoNodo);

NodoUsuario * borrarPrimerNodo_usuario(NodoUsuario * lista);

NodoUsuario * borrarUltimoNodo_usuario(NodoUsuario * lista);

///nodo listas
NodoLibro * inicListaLibro();

NodoLibro * crearNodoLibro(stLibro libro);

void mostrarNodos_Libros(NodoLibro * lista);

void mostrarUnNodo_Libro(NodoLibro * seg);

NodoLibro * agregar_al_principio_libro(NodoLibro * lista, NodoLibro * nuevoNodo);

NodoLibro * buscar_el_ultimo_libro(NodoLibro * lista);

NodoLibro * agregar_al_final_libro(NodoLibro * lista, NodoLibro * nuevoNodo);

NodoLibro * borrarPrimerNodo_libro(NodoLibro * lista);

NodoLibro * borrarUltimoNodo_libro(NodoLibro * lista);



#endif // LISTA_H_INCLUDED
