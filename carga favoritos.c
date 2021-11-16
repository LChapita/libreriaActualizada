#include "estructuras.h"

void cargar_favoritos(int id,stFavoritos favorito,stLibro libro)
{
    FILE * archlibro=fopen(archivo_Libros,"r+b");

    int numlibro;
    int flag=0;
    int existe;
    int fuera=0;
    printf("Ingrese Numero del libro: \n");
    scanf("%d",&numlibro);

    existe=verificar_favorito(favorito,id,numlibro);

    if(archlibro!=NULL)///arreglar
    {
        while(fread(&libro,sizeof(stLibro),1,archlibro)>0 && flag==0)
        {


            if(numlibro==libro.numLibro && libro.valida==1)///si existe el libro
            {

                if(existe==0) ///si esta dentro de favoritos sino se guarda
                {
                    favorito.id=id;
                    favorito.misFavoritos=libro;

                    guardar_favoritos(favorito);
                    flag=1;
                    fuera=1;
                }
                else
                {
                    printf("El libro ya esta cargado en favoritos.\n");
                    flag=1;
                    fuera=1;
                }
            }

        }
        fclose(archlibro);
    }
    if(fuera==0)
    {
        printf("Numero de libro no existe.\n");
    }

}

int verificar_favorito(stFavoritos favorito,int id,int numerolibro)
{
    FILE * archfavoritos;
    archfavoritos=fopen(archivo_Favoritos,"r");

    int existe=0;
    int flag=1;
    if(archfavoritos!=NULL)
    {
        while(fread(&favorito,sizeof(stFavoritos),1,archfavoritos)>0 && flag==1)
        {
            if(id==favorito.id)
            {
                if(numerolibro==favorito.misFavoritos.numLibro)
                {
                    flag=0;
                    existe=1;
                }
            }
        }

        fclose(archfavoritos);
    }

    return existe;
}

void baja_de_Fav_por_libros(stFavoritos fav,int idlibros)
{
    int conta;
    conta=contador(fav,idlibros);
    int flag=0;
    FILE * archFav= fopen(archivo_Favoritos,"r+b");

    if(archFav!=NULL)
    {
        while(fread(&fav,sizeof(stFavoritos),1,archFav)>0 && flag!=conta)
        {
            if(fav.misFavoritos.numLibro == idlibros)
            {
                fav.misFavoritos.valida=0;
                fseek(archFav,sizeof(stFavoritos)*-1,SEEK_SET);
                fwrite(&fav,sizeof(stFavoritos),1,archFav);
                flag++;

            }
        }
        fclose(archFav);
    }
    //printf("se dio de baja en fav");

}
int contador(stFavoritos fav,int idlibros)
{
    int conta=0;
    FILE * archFav= fopen(archivo_Favoritos,"rb");

    if(archFav!=NULL)
    {
        while(fread(&fav,sizeof(stFavoritos),1,archFav)>0)
        {
            if(fav.misFavoritos.numLibro == idlibros)
            {
                conta++;
            }
        }
        fclose(archFav);
    }
    //printf("se dio de baja en fav");
    return conta;
}
void guardar_favoritos(stFavoritos favoritos)
{
    FILE * archFavoritos;
    archFavoritos=fopen(archivo_Favoritos,"ab");
    if(archFavoritos!=NULL)
    {
        fwrite(&favoritos,sizeof(stFavoritos),1,archFavoritos);
        fclose(archFavoritos);
    }
    else
    {
        printf("Error.\n");
    }
}

void mostrar_mis_favoritos(stFavoritos favorito,int id)
{
    FILE * archfavoritos;
    archfavoritos=fopen(archivo_Favoritos,"r");

    //int x=13;
    //int y=8;
    //listaFavoritos();
    if(archfavoritos!=NULL)
    {

        while(fread(&favorito,sizeof(stFavoritos),1,archfavoritos)>0)
        {
            if(id==favorito.id)
            {
//                gotoxy(14,y);
//                printf("%d",favorito.numeroLibro);
//                gotoxy(17,y);
//                printf("%s",favorito.nombreLibroFav);
//                gotoxy(42,y);
//                printf("%s",favorito.autorFav);
//                gotoxy(63,y);
//                printf("%s",favorito.generoFav);
//                y=y+2;
                mostrar_libro(favorito.misFavoritos);

            }
        }
        //gotoxy(8,30);
        fclose(archfavoritos);
    }
}



void modificar_favoritos_Titulo(stFavoritos fav,int idLibro,char nuevoTitulo[])
{

    FILE * arFav=fopen(archivo_Favoritos,"r+b");

    if(arFav!=NULL)
    {
        while(fread(&fav,sizeof(stFavoritos),1,arFav)>0)
        {
            if(fav.misFavoritos.numLibro==idLibro)
            {

                strcpy(fav.misFavoritos.nombreLibro,nuevoTitulo);

                fseek(arFav,sizeof(stFavoritos)*-1,SEEK_CUR);
                fwrite(&fav,sizeof(stFavoritos),1,arFav);
                fclose(arFav);

            }
        }
        fclose(arFav);
    }
}

void modificar_favoritos_Autor(stFavoritos fav,int idLibro,char nuevoAutor[])
{

    FILE * arFav=fopen(archivo_Favoritos,"r+b");

    if(arFav!=NULL)
    {
        while(fread(&fav,sizeof(stFavoritos),1,arFav)>0)
        {
            if(fav.misFavoritos.numLibro==idLibro)
            {

                strcpy(fav.misFavoritos.autor,nuevoAutor);

                fseek(arFav,sizeof(stFavoritos)*-1,SEEK_CUR);
                fwrite(&fav,sizeof(stFavoritos),1,arFav);
                fclose(arFav);

            }
        }
        fclose(arFav);
    }
}

void modificar_favoritos_Genero(stFavoritos fav,int idLibro,char nuevoGenero[])
{

    FILE * arFav=fopen(archivo_Favoritos,"r+b");

    if(arFav!=NULL)
    {
        while(fread(&fav,sizeof(stFavoritos),1,arFav)>0)
        {
            if(fav.misFavoritos.numLibro==idLibro)
            {

                strcpy(fav.misFavoritos.genero,nuevoGenero);

                fseek(arFav,sizeof(stFavoritos)*-1,SEEK_CUR);
                fwrite(&fav,sizeof(stFavoritos),1,arFav);
                fclose(arFav);

            }
        }
        fclose(arFav);
    }
}








void mostrar_Lista_Favoritos(int id)
{
    stFavoritos fav;
    NodoFavoritos * lista;
    lista=inicListaFav();
    lista=pasar_archivo_Favoritos_a_lista(lista);
    listaFavoritos();
    mostrarNodos_Fav_Mios(lista,id);
}
