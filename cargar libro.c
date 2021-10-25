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
    printf("Nombre del Libro : %s\n",libro.nombreLibro);
    printf("Nombre de Autor  : %s\n",libro.autor);
    printf("Genero del Libro : %s\n",libro.genero);
    printf("Numero del Libro : %d\n",libro.numLibro);
}
////void mostrar_todos_los_libros()
////{
////    stLibro libro;
////    FILE * archivoLibros;
////    archivoLibros=fopen(archivo_Libros,"r");
////
////    if(archivoLibros!=NULL)
////    {
////        while(fread(&libro,sizeof(stLibro),1,archivoLibros)>0)
////        {
////            mostrar_libro(libro);
////            printf("\n");
////        }
////    }
////    fclose(archivoLibros);
////}
void bajalibros(stLibro libro,int idlibros)
{
    FILE * archivoLibros= fopen(archivo_Libros,"r+b");

    if(archivoLibros!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archivoLibros)>0)
        {
            if(idlibros==libro.numLibro && libro.valida==1)
            {
                libro.valida=0;
                fseek(archivoLibros,sizeof(stLibro)*-1,SEEK_CUR);
                fwrite(&libro,sizeof(stLibro),1,archivoLibros);
                printf("Se a dado de baja correctamente.\n");

                fclose(archivoLibros);

            }
            else
            {
                printf("\nEl libro no existe.\n");
            }
        }
        fclose(archivoLibros);
    }

}
void modificarLibro(stLibro libro,int idlibro)
{

    FILE * fLibro=fopen(archivo_Libros,"r+b");

    int opcion;

    char nuevoNombre[50];
    char nuevoAutor[50];
    char nuevoGenero[50];

    int flag=0;

    if(fLibro!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,fLibro)>0)
        {
            if(idlibro == libro.numLibro && flag==0)
            {
                ///entra como variable la opcion
                ///la eleccion sera mediante un switch
                opcion=opcionModificarLibro();

                switch(opcion)
                {
                case 1:///titulo;


                    printf("Ingrese Nuevo Nombre:\n");
                    fflush(stdin);
                    gets(nuevoNombre);

                    strcpy(libro.nombreLibro,nuevoNombre);

                    fseek(fLibro,sizeof(stLibro)*-1,SEEK_CUR);
                    fwrite(&libro,sizeof(stLibro),1,fLibro);


                    flag=1;
                    PAUSE;
                    break;

                case 2:///autor
                    printf("Ingrese Nuevo Apellido:\n");
                    fflush(stdin);
                    gets(nuevoAutor);

                    strcpy(libro.autor,nuevoAutor);

                    fseek(fLibro,sizeof(stLibro)*-1,SEEK_CUR);
                    fwrite(&libro,sizeof(stLibro),1,fLibro);

                    flag=1;
                    PAUSE;
                    break;

                case 3:///genero

                    printf("Ingrese Nuevo mail:\n");
                    fflush(stdin);
                    gets(nuevoGenero);

                    strcpy(libro.genero,nuevoGenero);

                    fseek(fLibro,sizeof(stLibro)*-1,SEEK_CUR);
                    fwrite(&libro,sizeof(stLibro),1,fLibro);

                    flag=1;
                    PAUSE;
                    break;
                }
            }
        }
    }
    fclose(fLibro);
}
int buscarNumeroLibro(stLibro libro)
{
    int idlibro;

    FILE * archLibro=fopen(archivo_Libros,"r");

    ///buscar en el archivo el numero de usuario que el usuario presione
    int numlibroBusca;
    int noExiste=0;

    printf("Ingrese el numero del Libro que desea buscar: ");
    scanf("%d",&numlibroBusca);

    if(archLibro!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archLibro)>0)
        {
            if(numlibroBusca == libro.numLibro)
            {

                printf("Este numero de Libro esta registrado.\n");
                mostrar_libro(libro);
                noExiste=1;
                idlibro=libro.numLibro;
                fclose(archLibro);
            }

        }
        fclose(archLibro);
    }
    if(noExiste==0)
    {
        printf("Este numero de Usuario NO se encuentra en el Archivo.\n");
    }
    return idlibro;
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

int pruebalibro()
{
    stLibro libro;
    NodoLibro * lista;
    lista=inicListaLibro();

    lista=pasar_archivo_lista_Libros(libro,lista);
    mostrarNodos_Libros(lista);

    return 0;
}

