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
int opcionModificarLibro()///menu modificar libro nombre autor genero
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
    system("color 0E");
    stUsuario usuario;
    stLibro libro;
    stFavoritos favorito;

    int op;
    int id;

    do
    {
        CLEAN;
        menu1();
        fflush(stdin);
        scanf ("%d", &op);

        if(op>=0 && op<=2)
        {


            switch (op)
            {
            case 1:///registrarce
                gotoxy (27,7);
                printf ("<-\n\n\n\n\n");
                PAUSE;
                CLEAN;
                menuRegistro();
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
                op=0;
                break;

            }
        }
        else
        {
            gotoxy(24,24);
            printf("Ingreso un Caracter o una Letra o una Opcion incorrecta\n\n");
            PAUSE;
        }
    }
    while (op != 0);
}

void menu_Administrador()
{
    stUsuario usuario;
    stLibro libro;
    stFavoritos favorito;

    stCelda adl[20];
    int validos=0;
    int dim = 20;


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
        case 1:///lista usuarios
            gotoxy(37,7);
            printf("<-");
            CLEAN;
            mostrandoLista_Users();
            gotoxy(8,62);
            PAUSE;
            break;

        case 2:///modificiar usuario
            gotoxy(37,11);
            printf("<-");
            gotoxy (35,29);
            CLEAN;
            modificar_admi();
            gotoxy(8,28);
            PAUSE;
            break;

        case 3:///dar baja usuario buscar
            gotoxy(37,15);
            printf("<-");
            gotoxy (35,29);
            CLEAN;
            dar_baja_admi();
            gotoxy(8,28);
            PAUSE;
            CLEAN;
            break;


        case 4:///menu libros
            gotoxy(37,19);
            printf("<-");
            gotoxy (35,29);
            PAUSE;
            CLEAN;
            menu_AdmiLibros();
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

        gotoxy (8,33);
        scanf ("%d", &opcion);

        switch (opcion)
        {
        case 1:///lista de libros
            gotoxy(37,7);
            printf("<-");
            gotoxy (39,33);
            CLEAN;
            printf("Se mostraran todos los libros dados de alta o baja.\n");
            PAUSE;
            muestraListaLibros();
            gotoxy(8,60);
            PAUSE;
            break;

        case 2:///cargar libro
            gotoxy(37,11);
            printf("<-");
            gotoxy (39,33);
            CLEAN;
            cargar_libro();
            gotoxy(8,32);
            PAUSE;
            break;

        case 3:///lista favoritos de usuarios dados de baja o esten en alta
            gotoxy(37,15);
            printf("<-");
            gotoxy (39,33);
            PAUSE;
            CLEAN;
            mostrarListaFavortiosEC();
            gotoxy(3,40);
            ///preorden posorden o inorder
            PAUSE;
            CLEAN;
            break;
        case 4:///modificar libro
            gotoxy (37,19);
            printf("<-");
            gotoxy (8,33);
            PAUSE;
            CLEAN;
            invocar_modificacion_libroYfavoritos();
            gotoxy(3,40);
            PAUSE;
            CLEAN;
            break;
        case 0:///salir
            gotoxy (25,27);
            printf("<-");
            gotoxy (39,33);
            PAUSE;
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
        gotoxy (10,27);
        scanf ("%d", &opcion);

        switch (opcion)
        {
        case 1:///darbaja
            gotoxy(33,7);
            printf("<-");
            gotoxy (35,29);
            PAUSE;
            CLEAN;
            darseBaja(usuario,id);
            bajaCorrecta();
            PAUSE;
            CLEAN;
            opcion=0;
            break;
        case 2:///menu libro usuario favoritos
            gotoxy(33,11);
            printf("<-");
            gotoxy (35,29);
            PAUSE;
            CLEAN;
            menu_favoritos(id);
            PAUSE;
            CLEAN;
            break;
        case 3:///ver perfil
            gotoxy(33,15);
            printf("<-");
            gotoxy (35,29);
            PAUSE;
            CLEAN;
            mostrar_mi_perfil(usuario,id);
            gotoxy (48,25);
            PAUSE;
            CLEAN;
            break;
        case 4:
            gotoxy(36,19);
            printf("<-");
            gotoxy (35,29);
            PAUSE;
            CLEAN;
            modificarUsuario(usuario,id);
            break;
        case 0:///desloguear/salir
            gotoxy (27,23);
            printf("<-");
            gotoxy (35,29);
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
            gotoxy (35,29);
            PAUSE;
            CLEAN;
            muestraListaLibrosVal();
            gotoxy(2,60);
            PAUSE;
            CLEAN;
            break;
        case 2:///favoritos
            gotoxy(33,11);
            printf("<-");
            gotoxy (35,29);
            PAUSE;
            CLEAN;
            int cursor=0;

            printf("Como quiere ver su lista:\t");
            printf("[Modo cuadro(1)]\t");
            printf("[Modo apilada(2)]\n");
            fflush(stdin);
            scanf("%d",&cursor);

            if(cursor|=0)
            {
                if(cursor==1)
                {
                    CLEAN;
                    mostrar_Lista_Favoritos(id);
                    gotoxy(3,40);
                    PAUSE;
                    CLEAN;
                }
                else
                {
                    if(cursor==2)
                    {
                        CLEAN;
                        invocar_arbol(id);
                        gotoxy(50,50);
                        PAUSE;
                        CLEAN;
                    }
                    else
                    {
                        CLEAN;
                        printf("Opcion incorrecta.\n");
                        PAUSE;
                        CLEAN;
                    }
                }
            }
            else
            {
                CLEAN;
                printf("Opcion incorrecta.\n");
                PAUSE;
                CLEAN;
            }
            break;

        case 3:///marcar favoritos
            gotoxy(33,15);
            printf("<-");
            gotoxy (35,29);
            PAUSE;
            CLEAN;
            cargar_favoritos(id,favorito,libro);
            PAUSE;
            CLEAN;
            break;

        case 0:///salir
            gotoxy (25,19);
            printf("<-");
            gotoxy (35,29);
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

