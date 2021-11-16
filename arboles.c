#include "arboles.h"

nodoArbolFavoritos * inicArbol()
{
    return NULL;
}

nodoArbolFavoritos * crearNodoArbol(stFavoritos dato)
{
    nodoArbolFavoritos * aux = (nodoArbolFavoritos*) malloc(sizeof(nodoArbolFavoritos));
    aux->dato = dato;
    aux->derecha = NULL;
    aux->izquierda = NULL;

    return aux;
}

nodoArbolFavoritos * insertarEnArbol(nodoArbolFavoritos * arbol,stFavoritos dato)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if(dato.misFavoritos.numLibro > arbol->dato.misFavoritos.numLibro)
        {
            arbol->derecha = insertarEnArbol(arbol->derecha,dato);
        }
        else
        {
            arbol->izquierda = insertarEnArbol(arbol->izquierda,dato);
        }
    }
    return arbol;
}


///tipos de muestra
void preorder(nodoArbolFavoritos * arbol)
{
    if(arbol!=NULL)
    {
        mostrar_libros_favoritos_version_fea(arbol->dato);
        Sleep(150);
        preorder(arbol->izquierda);
        preorder(arbol->derecha);

    }
}

void inorder(nodoArbolFavoritos * arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izquierda);
        mostrar_libro_favoritoPrueba(arbol->dato);
        inorder(arbol->derecha);
    }
}

void postorder(nodoArbolFavoritos * arbol)
{

    if(arbol!=NULL)
    {
        postorder(arbol->izquierda);
        postorder(arbol->derecha);
        mostrar_libro_favoritoPrueba(arbol->dato);

    }
}

nodoArbolFavoritos* buscar(nodoArbolFavoritos * arbol,stFavoritos dato)
{
    nodoArbolFavoritos * respuesta = NULL;
    if(arbol!=NULL)
    {
        if(dato.misFavoritos.numLibro == arbol->dato.misFavoritos.numLibro)
        {
            respuesta = arbol;
        }
        else if(dato.misFavoritos.numLibro > arbol->dato.misFavoritos.numLibro)
        {
            respuesta = buscar(arbol->derecha, dato);
        }
        else
        {
            respuesta = buscar(arbol->izquierda,dato);
        }
    }
    return respuesta;
}

void mostrar_libro_favoritoPrueba(stFavoritos favorito,int y)
{
    gotoxy(13,y);
    printf("%s",favorito.misFavoritos.nombreLibro);
    gotoxy(13+26,y);
    printf("%s",favorito.misFavoritos.autor);
    gotoxy(13+44,y);
    printf("%s",favorito.misFavoritos.genero);
    gotoxy(13+64,y);
    printf("%d",favorito.misFavoritos.numLibro);

}

void mostrar_libros_favoritos_version_fea(stFavoritos favorito){
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    printf(" Titulo: %s\n",favorito.misFavoritos.nombreLibro);
    printf(" Autor:  %s\n",favorito.misFavoritos.autor);
    printf(" Genero: %s\n",favorito.misFavoritos.genero);
    printf(" Id:     %d\n",favorito.misFavoritos.numLibro);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);

}

nodoArbolFavoritos * pasar_archivo_Favoritos_a_arbol(stFavoritos favorit,nodoArbolFavoritos * arbol,int iduser)
{
    FILE * archFav=fopen(archivo_Favoritos,"r+b");

    if(archFav!=NULL)
    {
        while(fread(&favorit,sizeof(stFavoritos),1,archFav)>0)
        {
            if(favorit.id==iduser)
            {
                arbol=insertarEnArbol(arbol,favorit);

            }
        }
        fclose(archFav);
    }

    return arbol;
}
void invocar_arbol(int iduser)
{

    stFavoritos fav;
    nodoArbolFavoritos * arbol;
    arbol=inicArbol();
    arbol=pasar_archivo_Favoritos_a_arbol(fav,arbol,iduser);
    ///listaFavoritos();

    preorder(arbol);
    gotoxy(50,50);
//    gotoxy(20,20);
//    PAUSE;
    //inorder(arbol,x,y);
//    gotoxy(20,20);
    //PAUSE;
    //postorder(arbol,x,y);///arreglar
//    gotoxy(20,20);
//    PAUSE;


}
