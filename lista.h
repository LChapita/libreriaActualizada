#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct
{
    stUsuario datos;
    struct NodoUsuario * siguiente;
}NodoUsuario;

typedef struct
{
    stLibro datos;
    struct NodoLibro * siguiente;
}NodoLibro;

typedef struct
{
    stFavoritos datos;
    struct NodoFavoritos * siguiente;
}NodoFavoritos;

///nodos usuarios
NodoUsuario * inicListaUsuario();

NodoUsuario * crearNodoUsuario(stUsuario user);

void mostrarNodos_Usuario(NodoUsuario * lista);

void mostrarUnNodo_Usuario(NodoUsuario * seg,int x, int y);

NodoUsuario * agregar_al_principio_usuario(NodoUsuario *lista, NodoUsuario *nuevoNodo);

NodoUsuario * buscar_el_ultimo_libro_usuario(NodoUsuario * lista);

NodoUsuario * agregar_al_final_usuario(NodoUsuario * lista, NodoUsuario * nuevoNodo);

NodoUsuario * borrarPrimerNodo_usuario(NodoUsuario * lista);

NodoUsuario * borrarUltimoNodo_usuario(NodoUsuario * lista);

NodoUsuario * pasar_archivo_lista_Usuarios(stUsuario usuario,NodoUsuario * lista);

///nodo libros
NodoLibro * inicListaLibro();

NodoLibro * crearNodoLibro(stLibro libro);

void mostrarNodos_Libros(NodoLibro * lista);

void mostrarUnNodo_Libro(NodoLibro * seg,int x,int y);

NodoLibro * agregar_al_principio_libro(NodoLibro * lista, NodoLibro * nuevoNodo);

NodoLibro * buscar_el_ultimo_libro(NodoLibro * lista);

NodoLibro * agregar_al_final_libro(NodoLibro * lista, NodoLibro * nuevoNodo);

NodoLibro * borrarPrimerNodo_libro(NodoLibro * lista);

NodoLibro * borrarUltimoNodo_libro(NodoLibro * lista);

NodoLibro * pasar_archivo_lista_Libros(stLibro libro,NodoLibro *lista);

///nodo favoritos

NodoFavoritos * inicListaFav();

NodoFavoritos * crearNodoFav(stFavoritos dato);

void mostrarNodos_Fav(NodoFavoritos * lista,int id);

void mostrarNodos_Fav_Mios(NodoFavoritos * lista,int id);

void mostrarTodosNodos_Fav(NodoFavoritos * lista);

void mostrarUNNodo_Fav(NodoFavoritos * lista,int x,int y);

NodoFavoritos * agregar_al_principio_fav(NodoFavoritos * lista, NodoFavoritos * nuevo);

NodoFavoritos * buscar_el_ultimo_Fav(NodoFavoritos * lista);

NodoFavoritos * agregar_al_final_Fav(NodoFavoritos * lista, NodoFavoritos * nuevoNodo);

NodoFavoritos * pasar_archivo_Favoritos_a_lista(NodoFavoritos * lista);

#endif // LISTA_H_INCLUDED
