#include "estructuras.h"

void favorito_archivo(int id,stFavoritos favorito,stLibro libro)
{
    FILE * archlibro=fopen(archivo_Libros,"r+b");

    int numlibro;
    int flag=0;
    int existe;
    int fuera=0;
    printf("Ingrese Numero del libro: \n");
    scanf("%d",&numlibro);

    existe=verificar_favorito(favorito,id,numlibro);

    if(archlibro!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archlibro)>0 && flag==0)
        {


            if(numlibro==libro.numLibro)///si existe el libro
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
                if(numerolibro==favorito.id)
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

///funcion guardar
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

//void mostrar_libro_favorito(stFavoritos favorito)
//{
//    printf("Nombre del Libro : %s\n",favoritomisFavoritos);
//    printf("Nombre de Autor  : %s\n",favorito.autorFav);
//    printf("Genero del Libro : %s\n",favorito.generoFav);
//    printf("Numero del Libro : %d\n",favorito.numeroLibro);
//}
void mostrar_mis_favoritos(stFavoritos favorito,int id)
{
    FILE * archfavoritos;
    archfavoritos=fopen(archivo_Favoritos,"r");

    int x=13;
    int y=8;
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
        gotoxy(8,30);
        fclose(archfavoritos);
    }
}

int funcion(){///funcion de prueba
    stFavoritos fav;
    stLibro lib;
    favorito_archivo(1,fav,lib);
    mostrar_mis_favoritos(fav,1);

return 0;}
