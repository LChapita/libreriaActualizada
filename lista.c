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
void mostrarUnNodo_Usuario(NodoUsuario * seg,int x,int y)
{
    gotoxy(x,y);
    printf("%s",seg->datos.nombreYapellido);
    gotoxy(x+26,y);
    printf("%s",seg->datos.nombreUsuario);
    gotoxy(x+44,y);
    printf("%d",seg->datos.id);
    gotoxy(x+53,y);
    printf("%s",seg->datos.contrasenia);
    gotoxy(x+64,y);
    printf("%d",seg->datos.validos);

}

void mostrarNodos_Usuario(NodoUsuario * lista)///lista
{
    NodoUsuario *seg=lista;
    int x=13;
    int y=8;
    while(seg!=NULL)
    {
        gotoxy(x,y);
        Sleep(700);
        mostrarUnNodo_Usuario(seg,x,y);
        y=y+2;
        seg=seg->siguiente;

    }
}
void mostrarNodos_Usuario_validos(NodoUsuario * lista)
{
    NodoUsuario * seg=lista;
    int x=13;
    int y=8;
    while(seg!=NULL)
    {
        if(seg->datos.validos==1)
        {
            gotoxy(x,y);
            mostrarUnNodo_Usuario(seg,x,y);
            y=y+2;
            seg=seg->siguiente;
        }
        else
        {
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

NodoUsuario * pasar_archivo_lista_Usuarios(stUsuario usuario,NodoUsuario * lista)
{
    FILE * archUsuario=fopen(archivo_Usuarios,"r");
    NodoUsuario *aux;
    if(archUsuario!=NULL)
    {
        while(fread(&usuario,sizeof(stUsuario),1,archUsuario)>0)
        {
            aux=crearNodoUsuario(usuario);
            lista=agregar_al_principio_usuario(lista,aux);

        }
        fclose(archUsuario);
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
    int x=13;
    int y=8;
    while(seg!=NULL)
    {
        gotoxy(x,y);
        mostrarUnNodo_Libro(seg,x,y);
        y=y+2;
        seg=seg->siguiente;
    }
    gotoxy(84,60);
}
void mostrarNodos_Libros_Validos(NodoLibro * lista)
{
    NodoLibro *seg=lista;
    int x=13;
    int y=8;
    while(seg!=NULL)
    {
        if(seg->datos.valida==1)
        {
            gotoxy(x,y);
            mostrarUnNodo_Libro(seg,x,y);
            y=y+2;
            seg=seg->siguiente;

        }
        else
        {
            seg=seg->siguiente;
        }

    }
}

void mostrarUnNodo_Libro(NodoLibro * seg, int x, int y)
{
    gotoxy(x,y);
    printf(" %s ",seg->datos.nombreLibro);
    gotoxy(x+26,y);
    printf(" %s",seg->datos.autor);
    gotoxy(x+44,y);
    printf(" %s",seg->datos.genero);
    gotoxy(x+62,y);
    printf(" %d",seg->datos.numLibro);
    gotoxy(x+64,y);
    printf(" %d",seg->datos.valida);
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

NodoLibro * pasar_archivo_lista_Libros(stLibro libro,NodoLibro *lista)
{
    FILE * archLibro=fopen(archivo_Libros,"r");

    if(archLibro!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archLibro)>0)
        {
            lista=agregar_al_principio_libro(lista,crearNodoLibro(libro));
        }
        fclose(archLibro);
    }

    return lista;
}

///funciones lista de favoritos

NodoFavoritos * inicListaFav()
{
    return NULL;
}

NodoFavoritos * crearNodoFav(stFavoritos dato)
{
    NodoFavoritos *nuevoNodo=(NodoFavoritos*)malloc(sizeof(NodoFavoritos));
    nuevoNodo->datos=dato;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

void mostrarNodos_Fav(NodoFavoritos * lista,int id)
{
    NodoFavoritos * seg=lista;
    int x=13;
    int y=8;
    while(seg!=NULL)
    {
        if(seg->datos.id==id)
        {
            gotoxy(x,y);
            mostrarUNNodo_Fav(seg,x,y);
            y=y+2;
            seg=seg->siguiente;
        }
        else
        {
            seg=seg->siguiente;
        }
    }
}
void mostrarNodos_Fav_Mios(NodoFavoritos * lista,int id)
{
    NodoFavoritos * seg=lista;
    int x=13;
    int y=8;
    while(seg!=NULL)
    {
        if(seg->datos.id==id && seg->datos.misFavoritos.valida==1)
        {
            gotoxy(x,y);
            mostrarUNNodo_Fav(seg,x,y);
            y=y+2;
            seg=seg->siguiente;
        }
        else
        {
            seg=seg->siguiente;
        }
    }
}
void mostrarTodosNodos_Fav(NodoFavoritos * lista)
{
    NodoFavoritos * seg=lista;
    int x=13;
    int y=8;
    while(seg!=NULL)
    {
        gotoxy(x,y);
        mostrarUNNodo_Fav(seg,x,y);
        y=y+2;
        seg=seg->siguiente;

    }
}
void mostrarUNNodo_Fav(NodoFavoritos * lista,int x,int y)
{
    gotoxy(x,y);
    printf("%s",lista->datos.misFavoritos.nombreLibro);
    gotoxy(x+26,y);
    printf("%s",lista->datos.misFavoritos.autor);
    gotoxy(x+44,y);
    printf("%s",lista->datos.misFavoritos.genero);
    gotoxy(x+64,y);
    printf("%d",lista->datos.misFavoritos.numLibro);
}

NodoFavoritos * agregar_al_principio_fav(NodoFavoritos * lista, NodoFavoritos * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}

NodoFavoritos * buscar_el_ultimo_Fav(NodoFavoritos * lista)
{
    NodoFavoritos *seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}
NodoFavoritos * agregar_al_final_Fav(NodoFavoritos * lista, NodoFavoritos * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        NodoFavoritos *ultimo=buscar_el_ultimo_Fav(lista);
        ultimo->siguiente=nuevoNodo;
    }
    return lista;
}
NodoFavoritos * pasar_archivo_Favoritos_a_lista(NodoFavoritos * lista)
{
    stFavoritos fav;
    FILE * archFav=fopen(archivo_Favoritos,"r");
    NodoFavoritos * aux=inicListaFav();
    if(archFav!=NULL)
    {
        while(fread(&fav,sizeof(stFavoritos),1,archFav)>0)
        {
            if(fav.misFavoritos.valida==1){
                aux=crearNodoFav(fav);
                lista=agregar_al_final_Fav(lista,aux);
            }
        }
        fclose(archFav);
    }
    return lista;
}

