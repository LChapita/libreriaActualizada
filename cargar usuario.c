#include "estructuras.h"

void cargar_usuario()
{
    stUsuario usuario;

    int compararPass;
    char password[10];
    char repassword[10];

    int conta=1;
    int flag=1;

    int verificarID=0;
    int verificarUser=0;
    char nombreUser[50];
    //char carga='s';

    //while(carga=='s')
    //{
    //printf("Ingrese nombre y apellido\n");
    gotoxy (33,6);
    fflush(stdin);
    gets(usuario.nombreYapellido);


    //printf("Ingrese nombre para su usuario\n");
    gotoxy (33,10);
    fflush(stdin);
    gets(nombreUser);

    int existeUser=0;

    while(conta==1)
    {
        verificarUser=verificar_Nombre_Usuario(usuario,nombreUser);

        if(verificarUser==1)
        {
            CLEAN;
            usuario_ya_existe();
            printf("\nIngrese otro nombre\n");
            fflush(stdin);
            gets(nombreUser);
            existeUser=1;
        }
        else
        {
            strcpy(usuario.nombreUsuario,nombreUser);
            conta=0;
        }
    }
    conta=1;

//    gotoxy (24,10);
//    fflush(stdin);
//    gets(usuario.apellido);
    if(existeUser==1)
    {
        CLEAN;
        menuRegistro();
        gotoxy (33,6);
        printf("%s",usuario.nombreYapellido);
        gotoxy (33,10);
        printf("%s",nombreUser);
    }
    verificarID=verificarNumeroUsuario(usuario)+1;///leer el archivo para no pisar el usuario recien cargado

    usuario.id=verificarID;

    usuario.validos=1;


    while(conta==1)
    {
        if(flag==1)
        {
            gotoxy (26,18);
            fflush(stdin);
            gets(password);

            gotoxy (34,22);
            fflush(stdin);
            gets(repassword);
            compararPass=strcmp(password,repassword);

            if(compararPass==0)
            {
                strcpy(usuario.contrasenia,password);

                conta=0;
            }
            else
            {
                CLEAN;
                contrasInv();
                PAUSE;
                CLEAN;
                contrasNoCoin();
                flag=0;
            }

        }
        if(conta==1)
        {

            gotoxy(26,6);
            fflush(stdin);
            gets(password);

            gotoxy(34,10);
            fflush(stdin);
            gets(repassword);
            compararPass=strcmp(password,repassword);


            if(compararPass==0)
            {
                strcpy(usuario.contrasenia,password);

                conta=0;
            }
            else
            {
                contrasInv();///no coinciden
                PAUSE;
                CLEAN;
                contrasNoCoin();///menu repass
            }
        }
    }


    guardar_usuario(usuario);///guardar el registro del usuario en el archivo

    CLEAN;
    registroExitoso();
    gotoxy(1,12);
    Sleep(750);

//        printf("Desea ingresar? si=SI/ no=NO \n");
//        fflush(stdin);
//        scanf("%c",&carga);

//}

}

int login()
{
    stUsuario usuario;
    FILE * fusuario=fopen(archivo_Usuarios,"rb");

    char nomUser[50];
    char pass[10];

    char admi[]= {"admi"};
    int iduser;
    int flag=0;

    CLEAN;

    menuIngresar();

    //printf("Ingrese nombre usuario:\n");
    gotoxy (36,7);
    fflush(stdin);
    scanf ("%s", &nomUser);

    //printf("Ingrese pass:\n");
    gotoxy (26,10);
    fflush(stdin);
    scanf ("%s", &pass);

    if((strcmp(nomUser,admi)==0) && (strcmp(pass,admi)==0))
    {
        //printf("Bienvenido adminitrador %s.\n",admi);
        ///debe de ingresar al menu admi
        menu_Administrador();
        flag=1;
    }
    else
    {
        if(fusuario!=NULL)
        {
            while(fread(&usuario,sizeof(stUsuario),1,fusuario)>0 && flag==0)
            {
                if(strcmp(usuario.nombreUsuario,nomUser)==0 && strcmp(usuario.contrasenia,pass)==0)
                {
                    if(usuario.validos==1)
                    {
                        iduser=usuario.id;
                        menu_login(iduser);
                        flag=1;
                    }
                    else
                    {

                        CLEAN;
                        usuario_Bajado();
                        gotoxy(10,15);
                        PAUSE;
                        flag=1;
                    }

                }
            }

        }
        fclose(fusuario);
    }


    if(flag==0)
    {
        gotoxy (8,24);
        printf("El usuario no esta registrado.\n");
        gotoxy (30,15);
        PAUSE;
    }

    return iduser;
}

void guardar_usuario(stUsuario usuario)
{
    FILE * archivoUsuario;
    archivoUsuario=fopen(archivo_Usuarios,"a");
    if(archivoUsuario!=NULL)
    {
        fwrite(&usuario,sizeof(stUsuario),1,archivoUsuario);
        fclose(archivoUsuario);
    }
    else
    {
        printf("Error.\n");
    }
}
void mostrar_usuario(stUsuario usuario)
{
    printf("NOMBRE y APELLIDO:    %s\n",usuario.nombreYapellido);
    printf("NOMBRE USUARIO:       %s\n",usuario.nombreUsuario);
    printf("ID USER:              %d\n",usuario.id);
    printf("PASSWORD:             %s\n",usuario.contrasenia);
    printf("ALTA:                 %d\n",usuario.validos);
    printf("\n");

}
void mostrar_mi_perfil(stUsuario usuario,int id)
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r");
    verPerfil();

    if(archivoUsuario!=NULL)
    {
        while(fread(&usuario,sizeof(stUsuario),1,archivoUsuario)>0)
        {
            if(usuario.id==id)
            {
                gotoxy (35,6);
                printf("%s",usuario.nombreYapellido);
                gotoxy (35,10);
                printf("%s",usuario.nombreUsuario);
                gotoxy (35,14);
                printf("%d",usuario.id);
                gotoxy (35,18);
                printf("%s",usuario.contrasenia);

            }
        }
        fclose(archivoUsuario);
    }
}

void darseBaja(stUsuario usuario,int id)
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r+b");
    int baja=0;
    int bandera=0;

    if(archivoUsuario!=NULL)
    {

        while(fread(&usuario,sizeof(stUsuario),1,archivoUsuario)>0)
        {
            if(id == usuario.id)
            {
                if(usuario.validos==1)
                {
                    usuario.validos=baja;

                    fseek(archivoUsuario,sizeof(stUsuario)*-1,SEEK_CUR);
                    fwrite(&usuario,sizeof(stUsuario),1,archivoUsuario);
                    bandera=1;

                    fclose(archivoUsuario);
                }
            }
        }
        fclose(archivoUsuario);

    }

    if(bandera==0)
    {
        printf("\nEl usuario no existe.\n");
    }

}

void dar_alta_again(stUsuario usuario)///esto lo hace el admi///depende de que si quiero o no meterla dentro de menu admi
{
    FILE * archiUsuario= fopen(archivo_Usuarios,"r+b");
    char darbaja='s';
    char nombreUser[50];
    int flag=0;

    printf("Ingrese nombre de usuario para dar de alta:\n");
    scanf("%s",&nombreUser);

    if(archiUsuario!=NULL)
    {
        while(fread(&usuario,sizeof(stUsuario),1,archiUsuario)>0 && flag==0)
        {
            if((strcmp(usuario.nombreUsuario,nombreUser)==0) && usuario.validos ==0)
            {
                usuario.validos=1;
                fseek(archiUsuario,sizeof(stUsuario)*-1,SEEK_CUR);
                fwrite(&usuario,sizeof(stUsuario),1,archiUsuario);
                printf("Se a dado de alta correctamente.\n");
                flag=1;

            }
            else
            {
                if((strcmp(usuario.nombreUsuario,nombreUser)==0) && usuario.validos ==1)
                {
                    printf("\nEl libro Ya esta dado de alta.\n");
                    flag=1;

                }
            }
        }
        fclose(archiUsuario);
    }
    if(flag==0)
    {
        printf("\nEl Usuario no existe.\n");
    }
}
int verificarNumeroUsuario(stUsuario usuario)
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r");
    int num=0;
    if(archivoUsuario!=NULL)
    {
        while(fread(&usuario,sizeof(stUsuario),1,archivoUsuario)>0)
        {
            if(usuario.id>num)
            {
                num=usuario.id;
            }
        }
        fclose(archivoUsuario);
    }

    return num;
}

int verificar_Nombre_Usuario(stUsuario usuario,char nombre[])
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r");
    int flag=0;
    if(archivoUsuario!=NULL)
    {
        while(fread(&usuario,sizeof(stUsuario),1,archivoUsuario)>0 && flag==0)
        {
            if(strcmp(usuario.nombreUsuario,nombre) == 0)
            {
                flag=1;
            }
        }
        fclose(archivoUsuario);
    }

    return flag;
}

int buscarNumeroUsuario(stUsuario usuario,int idUsuario)///en el archivo
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"rb");
    ///buscar en el archivo el numero de usuario que el usuario presione
    int flag=0;
    if(archivoUsuario!=NULL)
    {
        rewind(archivoUsuario);
        while(fread(&usuario,sizeof(stUsuario),1,archivoUsuario)>0 && flag==0)
        {
            if(idUsuario == usuario.id)
            {
                if(usuario.validos==1)
                {
                    printf("Este numero de Usuario esta registrado.\n");
                    mostrar_mi_perfil(usuario,usuario.id);
                    flag=1;
                    idUsuario=usuario.id;
                }
            }

        }
        fclose(archivoUsuario);
    }
    if(flag==0)
    {
        printf("Este numero de Usuario NO se encuentra en el Archivo.\n");
    }
    return idUsuario;
}

void modificarUsuario(stUsuario usuario, int id)
{

    FILE * archivoUsuario=fopen(archivo_Usuarios,"r+b");
    ///buscar el usuario y mantenerlo
    int verdad;
    int opcion;
    int numUsuarioBusca;
    char nuevoNombreYApellido[60];
    char nuevoNombreUsuario[50];
    int flag=0;


    if(archivoUsuario!=NULL)
    {
        while(fread(&usuario,sizeof(stUsuario),1,archivoUsuario)>0 && flag==0)
        {
            if(id == usuario.id && flag==0)
            {
                ///entra como variable la opcion
                ///la eleccion sera mediante un switch
                CLEAN;
                modificar_Usuario();
                opcion=opcionModificar();

                switch(opcion)
                {
                case 1:///nombre y apellido
                    CLEAN;

                    printf("Ingrese Nuevo Nombre y apellido:\n");
                    fflush(stdin);
                    gets(nuevoNombreYApellido);

                    strcpy(usuario.nombreYapellido,nuevoNombreYApellido);

                    fseek(archivoUsuario,sizeof(stUsuario)*-1,SEEK_CUR);
                    fwrite(&usuario,sizeof(stUsuario),1,archivoUsuario);

                    printf("Se modifico con exito.");

                    fclose(archivoUsuario);
                    rewind(archivoUsuario);

                    flag=1;
                    PAUSE;
                    break;

                case 2:///nombre usuario
                    CLEAN;

                    printf("Ingrese Nuevo Nombre de Usuario:\n");
                    fflush(stdin);
                    gets(nuevoNombreUsuario);

                    while(verificar_Nombre_Usuario(usuario,nuevoNombreUsuario)==1)
                    {
                        printf("Ingrese Otro Nombre de Usuario:\n");
                        fflush(stdin);
                        gets(nuevoNombreUsuario);
                    }

                    strcpy(usuario.nombreUsuario,nuevoNombreUsuario);

                    fseek(archivoUsuario,sizeof(stUsuario)*-1,SEEK_CUR);
                    fwrite(&usuario,sizeof(stUsuario),1,archivoUsuario);

                    printf("Se modifico con exito.");

                    fclose(archivoUsuario);
                    rewind(archivoUsuario);

                    ///copia el registro completo, lo modifica y pega

                    flag=1;

                    PAUSE;
                    break;


                case 0:///salir

                    flag=1;

                    break;
                }
            }
        }
        fclose(archivoUsuario);
    }

}


void mostrarListaUsuarios()
{

    stUsuario usuario;
    NodoUsuario * lista;
    lista=inicListaUsuario();

    lista=pasar_archivo_lista_Usuarios(usuario,lista);
    listaUsuarios();
    mostrarNodos_Usuario(lista);
}

void dar_baja_admi()
{

    int idUsuario=0;
    char control='s';
    ///buscar en el archivo el numero de usuario que el usuario presione
    stUsuario usuario;

    int numUsuarioBusca;
    int noExiste=0;

    printf("Ingrese el numero del Usuario que desea buscar: ");
    fflush(stdin);
    scanf("%d",&numUsuarioBusca);

    idUsuario=buscarNumeroUsuario(usuario,numUsuarioBusca);

    if(idUsuario!=0)
    {
        gotoxy(8,25);
        printf("Esta seguro que quiere dar de baja este usuario. s/n\n");
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
    }
    return 0;
}

void modificar_admi()
{
    int idUsuario=0;
    char control='s';
    ///buscar en el archivo el numero de usuario que el usuario presione
    stUsuario usuario;

    int numUsuarioBusca;
    int noExiste=0;

    printf("Ingrese el numero del Usuario que desea buscar: ");
    fflush(stdin);
    scanf("%d",&numUsuarioBusca);

    idUsuario=buscarNumeroUsuario(usuario,numUsuarioBusca);

    if(idUsuario!=0)
    {
        gotoxy(8,25);
        printf("Esta seguro que quiere modificar este usuario.s/n\n");
        fflush(stdin);
        scanf("%c",&control);
        if(control=='s')
        {
            CLEAN;
            modificarUsuario(usuario,idUsuario);
        }
    }
}
