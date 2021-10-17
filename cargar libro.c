#include "estructuras.h"
/*
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
*/
