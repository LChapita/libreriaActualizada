#include "estructuras.h"

void cargar_libro()
{
    stLibro libros;

    int validar;
    int bandera=1;

    int compararTitulo;
    int compararGenero;
    int compararAutor;

    char autor[50];
    char titulo[50];
    char genero[50];

    char continuar='s';

    while(continuar=='s')
    {
        CLEAN;
        menuCargar_Libro();

        libros.valida=1;
        validar=verificar_numero_libro(libros);
        libros.numLibro=validar;

        while(bandera==1)
        {
            fflush(stdin);
            gotoxy(21,7);
            gets(titulo);
            fflush(stdin);
            gotoxy(20,11);
            gets(autor);
            fflush(stdin);
            gotoxy(21,15);
            gets(genero);

            compararAutor=verificar_autor(libros,autor);
            compararTitulo=verificar_titulo(libros,titulo);
            compararGenero=verificar_genero(libros,genero);

            if(compararAutor==0 && compararTitulo==0 && compararGenero==0)
            {
                printf("Este libro ya a sido cargado.\n");
            }
            else
            {
                strcpy(libros.autor,autor);
                strcpy(libros.nombreLibro,titulo);
                strcpy(libros.genero,genero);

                bandera=0;
            }

        }



        guardar_libro(libros);

        gotoxy (8,22);
        printf("Desea continuar la carga de libros? s=Si/ n=No\n");
        fflush(stdin);
        gotoxy (8,23);
        scanf("%c",&continuar);
        if(continuar=='s')
        {
            bandera=1;
        }


    }

}
void guardar_libro(stLibro libros)
{
    FILE * archivoLibro;
    archivoLibro=fopen(archivo_Libros,"a");
    if(archivoLibro!=NULL)
    {
        fwrite(&libros,sizeof(stLibro),1,archivoLibro);
        fclose(archivoLibro);
    }
    else
    {
        printf("Error.\n");
    }
}

int verificar_autor(stLibro libros, char autor[])
{
    FILE * archivoLibros;
    archivoLibros=fopen(archivo_Libros,"r");
    int verificarAutor;

    if(archivoLibros!=NULL)
    {
        while(fread(&libros,sizeof(stLibro),1,archivoLibros)>0)
        {
            verificarAutor=strcmp(libros.autor,autor);
        }
        fclose(archivoLibros);
    }
    return verificarAutor;
}

int verificar_genero(stLibro libros, char genero[])
{
    FILE * archivoLibros;
    archivoLibros=fopen(archivo_Libros,"r");
    int verificarGenero;

    if(archivoLibros!=NULL)
    {
        while(fread(&libros,sizeof(stLibro),1,archivoLibros)>0)
        {
            verificarGenero=strcmp(libros.genero,genero);
        }
        fclose(archivoLibros);
    }
    return verificarGenero;
}

int verificar_titulo(stLibro libros, char titulo[])
{
    FILE * archivoLibros;
    archivoLibros=fopen(archivo_Libros,"r");
    int verificarTitulo;

    if(archivoLibros!=NULL)
    {
        while(fread(&libros,sizeof(stLibro),1,archivoLibros)>0)
        {
            verificarTitulo=strcmp(libros.nombreLibro,titulo);
        }
        fclose(archivoLibros);
    }
    return verificarTitulo;
}

int verificar_numero_libro(stLibro libros)
{

    FILE * archivoLibro=fopen(archivo_Libros,"r");
    int num=0;

    if(archivoLibro!=NULL)
    {
        while(fread(&libros,sizeof(stLibro),1,archivoLibro)>0)
        {
            if(libros.numLibro>num)
            {
                num=libros.numLibro;
            }
        }
        fclose(archivoLibro);
    }

    return num+1;
}
void mostrar_libro(stLibro libro)
{
    printf(" %s ",libro.nombreLibro);
    printf(" %s",libro.autor);
    printf(" %s",libro.genero);
    printf(" %d",libro.numLibro);
}
void bajalibros(stLibro libro,int idlibros)
{
    FILE * archivoLibros= fopen(archivo_Libros,"r+b");
    int flag=0;
    if(archivoLibros!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archivoLibros)>0 && flag==0)
        {
            if(libro.numLibro==idlibros && libro.valida==1 && flag==0)
            {
                libro.valida=0;
                fseek(archivoLibros,sizeof(stLibro)*-1,SEEK_CUR);
                fwrite(&libro,sizeof(stLibro),1,archivoLibros);
                printf("Se a dado de baja correctamente.\n");

                //printf("esto termina\n");
                flag=1;
                fclose(archivoLibros);
            }

        }
        fclose(archivoLibros);
    }

}
int buscarNumeroLibro(stLibro libro)
{
    int idlibro=0;

    FILE * archLibro=fopen(archivo_Libros,"rb");

    ///buscar en el archivo el numero de usuario que el usuario presione
    int numlibroBusca;
    int noExiste=0;

    printf("Ingrese el numero del Libro que desea buscar: ");
    scanf("%d",&numlibroBusca);

    if(archLibro!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archLibro)>0 && noExiste==0)
        {
            if(numlibroBusca == libro.numLibro)
            {

                printf("Este numero de Libro esta registrado.\n");
                mostrar_libro_EnlaBusqueda(libro);
                noExiste=1;
                idlibro=libro.numLibro;
                //fclose(archLibro);
            }

        }
        fclose(archLibro);
    }
    if(noExiste==0)
    {
        printf("Este numero de Libro NO se encuentra en el Archivo.\n");
    }
    return idlibro;
}


void muestraListaLibrosVal()
{
    stLibro libro;
    NodoLibro * lista;
    lista=inicListaLibro();

    lista=pasar_archivo_lista_Libros(libro,lista);
    listaLibros();
    mostrarNodos_Libros_Validos(lista);
}
void muestraListaLibros()
{
    stLibro libro;
    NodoLibro * lista;
    lista=inicListaLibro();

    lista=pasar_archivo_lista_Libros(libro,lista);
    listaLibros();
    mostrarNodos_Libros(lista);
}

///modificar libro

void modificarLibro(stLibro libro,int idlibro)///modificar para que quede bien
{

    stFavoritos fav;

    FILE * fLibro=fopen(archivo_Libros,"r+b");

    int opcion;

    char nuevoTitulo[50];
    char nuevoAutor[50];
    char nuevoGenero[50];

    int flag=0;

    if(fLibro!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,fLibro)>0 && flag ==0)
        {
            if(idlibro == libro.numLibro && flag==0)
            {
                mostrar_libro_EnlaBusqueda(libro);
                ///entra como variable la opcion
                ///la eleccion sera mediante un switch
                menu_Modificar_opcion();
                opcion=opcionModificarLibro();

                switch(opcion)
                {
                case 1:///titulo;


                    printf("Ingrese Nuevo Titulo:\n");
                    fflush(stdin);
                    gets(nuevoTitulo);

                    strcpy(libro.nombreLibro,nuevoTitulo);

                    fseek(fLibro,sizeof(stLibro)*-1,SEEK_CUR);
                    fwrite(&libro,sizeof(stLibro),1,fLibro);

                    modificar_favoritos_Titulo(fav,idlibro,nuevoTitulo);
                    fclose(fLibro);
                    flag=1;
                    PAUSE;
                    break;

                case 2:///autor
                    printf("Ingrese Nuevo Autor:\n");
                    fflush(stdin);
                    gets(nuevoAutor);

                    strcpy(libro.autor,nuevoAutor);

                    fseek(fLibro,sizeof(stLibro)*-1,SEEK_CUR);
                    fwrite(&libro,sizeof(stLibro),1,fLibro);

                    modificar_favoritos_Autor(fav,idlibro,nuevoAutor);
                    fclose(fLibro);
                    flag=1;
                    PAUSE;
                    break;

                case 3:///genero

                    printf("Ingrese Nuevo Genero:\n");
                    fflush(stdin);
                    gets(nuevoGenero);

                    strcpy(libro.genero,nuevoGenero);

                    fseek(fLibro,sizeof(stLibro)*-1,SEEK_CUR);
                    fwrite(&libro,sizeof(stLibro),1,fLibro);

                    modificar_favoritos_Genero(fav,idlibro,nuevoGenero);
                    fclose(fLibro);
                    flag=1;
                    PAUSE;
                    break;
                }
            }
        }
        fclose(fLibro);
    }

    if(flag==1)
    {
        printf("Se ha modificado con exito.\n");
        printf("Recuerde que si modifica el libro tambien se modifica en En el Archivo de Favoritos.\n");
        PAUSE;
    }
}

void invocar_modificacion_libroYfavoritos()
{
    stLibro libro;
    int idlibro=0;

    idlibro=buscarNumeroLibro(libro);

    char control='s';

    if(idlibro>0)
    {
        gotoxy(8,20);
        printf("Esta seguro que quiere Modificar este libro.s/n\n");

        fflush(stdin);
        gotoxy(8,21);
        scanf("%c",&control);

        if(control=='s')
        {
            CLEAN;
            modificarLibro(libro,idlibro);
        }
    }

}

void mostrar_libro_EnlaBusqueda(stLibro libro)
{
    ver_libro_enBusqueda();
    gotoxy (20,7);
    printf(" %s",libro.nombreLibro);
    gotoxy (20,11);
    printf(" %s",libro.autor);
    gotoxy (20,15);
    printf(" %s",libro.genero);

}


void darBaja_en_libros_comoEn_Fav(stLibro libro)
{
    stFavoritos fav;
    int idlibro=0;

    idlibro=buscarNumeroLibro(libro);

    char control='s';

    if(idlibro>0)
    {
        gotoxy(8,20);
        printf("Esta seguro que quiere Dar de Baja este libro.s/n\n");

        fflush(stdin);
        gotoxy(8,21);
        scanf("%c",&control);

        if(control=='s')
        {
            CLEAN;
            bajalibros(libro,idlibro);
            PAUSE;
            baja_de_Fav_por_libros(fav,idlibro);
        }
    }
}


