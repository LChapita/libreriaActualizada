#include "estructuras.h"

int opcionModificar()///menu modificar usuario nombre apellido mail
{
    int op;
    scanf("%d",&op);
    int flag=1;
    while(op>0 && flag==1)
    {
        if(op>3)
        {
            printf("La opcion es incorrecta.\n");
            printf("Ingrese su opcion:\n");
            scanf("%d",&op);
        }
        else
        {
            flag=0;
        }
    }
    return op;
}
int opcionModificarLibro()///menu modificar usuario nombre autor genero
{
    int op;
    printf("Ingrese su opcion:\n");
    scanf("%d",&op);
    int flag=1;
    while(op>0 && flag==1)
    {
        if(op>3)
        {
            printf("La opcion es incorrecta.\n");
            printf("Ingrese su opcion:\n");
            scanf("%d",&op);
        }
        else
        {
            flag=0;
        }
    }
    return op;
}
void menuInicio()
{
    stUsuario usuario;
    stLibro libro;
    stFavoritos favorito;

    int opcion;
    int id;

    do
    {
        CLEAN;
        menu1();

        gotoxy(8,4);
        printf ("%c ingrese 1 para registrarse, 2 para iniciar, 0 para salir: %c",186,186);
        gotoxy(8,5);
        printf ("%c                                                           %c",186,186);
        gotoxy(10,10);
        scanf ("%d", &opcion);

        switch (opcion)
        {
        case 1:///registrarce
            gotoxy (27,7);
            printf ("<-\n\n\n\n\n");
            PAUSE;
            CLEAN;
            cargar_usuario();
            break;
        case 2:///igresar
            gotoxy (46,7);
            printf ("<-\n\n\n\n\n");
            PAUSE;
            id=login(usuario);
            break;
        case 0:///cerrando programa
            gotoxy (65,7);
            printf ("<-\n\n\n\n\n");
            PAUSE;
            opcion=0;
            break;

        }
    }
    while (opcion != 0);
}

void menu_Administrador()
{
    stUsuario usuario;
    stLibro libro;
    stFavoritos favorito;

    char control='s';

    int idUsuario;
    int opcion;

    CLEAN;
    do
    {
        CLEAN;
        menuAdmin();
        gotoxy (10,27);
        scanf ("%d", &opcion);
        switch (opcion)
        {
        case 4:///menu libros
            gotoxy(37,19);
            printf("<-");
            CLEAN;
            menu_AdmiLibros();
            break;

        case 3:///dar baja usuario buscar
            gotoxy(37,15);
            printf("<-");
            CLEAN;
            idUsuario=buscarNumeroUsuario(usuario);
            PAUSE;
            CLEAN;
            printf("Esta seguro que quiere dar de baja este usuario.\n");
            fflush(stdin);
            scanf("%c",&control);
            if(control=='s')
            {
                darseBaja(usuario,idUsuario);
                PAUSE;
                CLEAN;
                bajaCorrecta();
                PAUSE;
                CLEAN;

            }
            gotoxy(8,28);
            PAUSE;
            CLEAN;
            break;

        case 2:///modificiar usuario
            gotoxy(37,11);
            printf("<-");
            CLEAN;
            idUsuario=buscarNumeroUsuario(usuario);
            PAUSE;
            CLEAN;
            printf("Esta seguro que quiere modificar este usuario.\n");
            fflush(stdin);
            scanf("%c",&control);
            if(control=='s')
            {
                CLEAN;
                modificarUsuario(usuario,idUsuario);
            }
            gotoxy(8,28);
            PAUSE;
            break;

        case 1:///lista usuarios
            gotoxy(37,7);
            printf("<-");
            CLEAN;
            mostrar_lista_usuarios(usuario);
            gotoxy(8,62);
            PAUSE;
            break;

        case 0:///salir
            gotoxy (25,23);
            printf("<-");
            gotoxy(8,30);
            PAUSE;
            CLEAN;
            saliendo();
            gotoxy (30,15);
            PAUSE;
            opcion=0;
            break;
        }
    }
    while (opcion != 0);

}
void menu_AdmiLibros()
{
    stUsuario usuario;
    stLibro libro;
    stFavoritos favorito;

    char control='s';

    int idlibro;

    int idusuario;

    int opcion;

    do
    {
        CLEAN;
        menuAdmin_Libros();

        gotoxy (10,31);
        scanf ("%d", &opcion);

        switch (opcion)
        {
        case 5:///cargar libro
            gotoxy(37,23);
            printf("<-");
            CLEAN;
            cargar_libro();
            gotoxy(8,32);
            PAUSE;
            break;
        case 4:///lista favoritos
            gotoxy(37,19);
            printf("<-");
            CLEAN;
            idusuario=buscarNumeroUsuario(usuario);
            PAUSE;
            CLEAN;
            mostrar_mis_favoritos(favorito,idusuario);
            gotoxy(8,32);
            PAUSE;

            break;

        case 3:///dar baja libro
            gotoxy(37,15);
            printf("<-");
            CLEAN;

            idlibro=buscarNumeroLibro(libro);
            printf("Esta seguro que quiere dar de baja este libro.\n");
            fflush(stdin);
            scanf("%c",&control);

            if(control=='s')
            {
                bajalibros(libro,idlibro);
            }
            gotoxy(8,32);
            PAUSE;
            break;

        case 2:///modificar libro
            gotoxy(37,11);
            printf("<-");
            CLEAN;

            idlibro=buscarNumeroLibro(libro);
            printf("Esta seguro que quiere modificar este libro.\n");
            fflush(stdin);
            scanf("%c",&control);

            if(control=='s')
            {
                modificarLibro(libro,idlibro);
            }
            gotoxy(8,32);
            PAUSE;
            break;

        case 1:///lista de libros
            gotoxy(37,7);
            printf("<-");
            CLEAN;
            printf("Se mostraran todos los libros dados de alta o baja.\n");
            PAUSE;
            ///mostrar_lista(libro);
            gotoxy(8,60);
            PAUSE;
            break;

        case 0:///salir
            gotoxy (25,27);
            printf("<-");
            CLEAN;
            saliendo();
            gotoxy(30,15);
            PAUSE;

            opcion=0;
            break;
        }
    }
    while (opcion != 0);

}
void menu_login(int id)
{
    stUsuario usuario;
    stLibro libro;
    stFavoritos favorito;

    int opcion;

    do
    {
        CLEAN;
        menuPrincipal_Ingresado();
        gotoxy (10,23);
        scanf ("%d", &opcion);

        switch (opcion)
        {
        case 1:///darbaja
            gotoxy(33,7);
            printf("<-");
            gotoxy(8,24);
            PAUSE;
            CLEAN;
            darseBaja(usuario,id);
            PAUSE;
            CLEAN;
            bajaCorrecta();
            PAUSE;
            CLEAN;
            opcion=0;
            break;
        case 2:///menu libro usuario favoritos
            gotoxy(33,11);
            printf("<-");
            gotoxy(8,24);
            PAUSE;
            CLEAN;
            menu_favoritos(id);
            PAUSE;
            CLEAN;
            break;
        case 3:///ver perfil
            gotoxy(33,15);
            printf("<-");
            gotoxy(8,24);
            PAUSE;
            CLEAN;
            mostrar_mi_perfil(usuario,id);
            PAUSE;
            CLEAN;
            break;
        case 0:///desloguear/salir
            gotoxy (25,19);
            printf("<-");
            gotoxy(8,24);
            PAUSE;
            CLEAN;
            saliendo();
            gotoxy (30,15);
            PAUSE;
            CLEAN;
            opcion=0;
            break;
        }
    }
    while (opcion != 0);
}

void menu_favoritos(int id)
{
    stUsuario usuario;
    stLibro libro;
    stFavoritos favorito;

    int opcion;

    do
    {
        CLEAN;
        opcionesUsuario();
        gotoxy (10,25);
        scanf ("%d", &opcion);

        switch (opcion)
        {
        case 1:///lista libros en alta
            gotoxy(33,7);
            printf("<-");
            PAUSE;
            CLEAN;
            ///mostrar_lista_validos(libro);
            PAUSE;
            CLEAN;
            break;
        case 2:///favoritos
            gotoxy(33,11);
            printf("<-");
            PAUSE;
            CLEAN;
            mostrar_mis_favoritos(favorito,id);
            PAUSE;
            CLEAN;
            break;

        case 3:///marcar favoritos
            gotoxy(33,15);
            printf("<-");
            PAUSE;
            CLEAN;
            favorito_archivo(id,favorito,libro);
            PAUSE;
            CLEAN;
            break;

        case 0:///salir
            gotoxy (25,19);
            printf("<-");
            PAUSE;
            CLEAN;
            saliendo();
            gotoxy(8,25);
            PAUSE;
            CLEAN;
            opcion=0;
            break;
        }
    }
    while (opcion != 0);
}

