#ifndef TDA_FAVORITOS_H_INCLUDED
#define TDA_FAVORITOS_H_INCLUDED
#include "estructuras.h"

typedef struct
{
    int id;///id user
    stLibro misFavoritos;
} stFavoritos;


void cargar_favoritos(int id,stFavoritos favorito,stLibro libro);

int verificar_favorito(stFavoritos favorito,int id,int numerolibro);

void baja_de_Fav_por_libros(stFavoritos fav,int idlibros);

void guardar_favoritos(stFavoritos favoritos);

void mostrar_mis_favoritos(stFavoritos favorito,int id);

int contador(stFavoritos fav,int idlibros);

void mostrar_Lista_Favoritos(int id);

void modificar_favoritos_Titulo(stFavoritos fav,int idLibro,char nuevoTitulo[]);

void modificar_favoritos_Autor(stFavoritos fav,int idLibro,char nuevoAutor[]);

void modificar_favoritos_Genero(stFavoritos fav,int idLibro,char nuevoGenero[]);

#endif // TDA_FAVORITOS_H_INCLUDED
