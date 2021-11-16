#ifndef CELDAS_H_INCLUDED
#define CELDAS_H_INCLUDED
#include "estructuras.h"
typedef struct{

    stUsuario usuario;
    NodoFavoritos * listaFavoritos;
}stCelda;

int buscarUsuarioEnCelda(stCelda adl[], stUsuario user,int validos);

int agregarCelda(stCelda adl[], stUsuario user,int validos);

int alta(stCelda adl[], stUsuario user,int validos);

int archivo2adl(stCelda adl[], int val, int dim);

void mostrarADL(stCelda adl[], int validos);

void lista_UsuariosEC(stCelda adl[], int validos);

void buscarEnCelda_y_MuestaListaFav(stCelda adl[], int validos);

int verificar_Celdas(stCelda adl[], int validos,int user);

int retorna_posicion_enElArreglo(stCelda adl[], int validos,int user);

void mostrarListaFavortiosEC();

void mostrandoLista_Users();

#endif // CELDAS_H_INCLUDED
