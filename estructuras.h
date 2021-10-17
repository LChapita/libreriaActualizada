#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <windows.h>
#include "utiles.h"


#define PAUSE system("pause");
#define CLEAN system("cls");
typedef struct
{
    char nombreYapellido[60];//mas de 1
    char nombreUsuario[50];//verificar
    int id;///
    char contrasenia[10];///
    int validos;
}stUsuario;

typedef struct
{
    int numLibro;
    char autor[30];
    char nombreLibro[50];
    char genero[30];
    int valida;///si esta dado de alta o no
} stLibro;

typedef struct
{
    int dni;
    int numeroLibro;
    char nombreLibroFav[50];
} stFavoritos;


#define archivo_Usuarios "Usuarios.txt"
#define archivo_Libros "Libros.txt"
#define archivo_Favoritos "Favoritos.txt"


#endif // ESTRUCTURAS_H_INCLUDED
