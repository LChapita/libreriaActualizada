#ifndef TDA_FAVORITOS_H_INCLUDED
#define TDA_FAVORITOS_H_INCLUDED


typedef struct
{
    int id;
    stLibro misFavoritos;
} stFavoritos;


void favorito_archivo(int id,stFavoritos favorito,stLibro libro);

int verificar_favorito(stFavoritos favorito,int id,int numerolibro);

void guardar_favoritos(stFavoritos favoritos);

void mostrar_mis_favoritos(stFavoritos favorito,int id);

#endif // TDA_FAVORITOS_H_INCLUDED
