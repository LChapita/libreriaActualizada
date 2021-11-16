#ifndef TDA_LIBRO_H_INCLUDED
#define TDA_LIBRO_H_INCLUDED


typedef struct
{
    int numLibro;
    char autor[30];
    char nombreLibro[50];
    char genero[30];
    int valida;///si esta dado de alta o no
} stLibro;

void cargar_libro();

void guardar_libro(stLibro libros);

int verificar_autor(stLibro libros, char autor[]);

int verificar_genero(stLibro libros, char genero[]);

int verificar_titulo(stLibro libros, char titulo[]);

int verificar_numero_libro(stLibro libros);

void mostrar_libro(stLibro libro);

void bajalibros(stLibro libro,int idlibros);

int buscarNumeroLibro(stLibro libro);

void modificarLibro(stLibro libro,int idlibro);

void invocar_modificacion_libroYfavoritos();

void mostrar_libro_EnlaBusqueda(stLibro libro);

void darBaja_en_libros_comoEn_Fav(stLibro libro);

#endif // TDA_LIBRO_H_INCLUDED
