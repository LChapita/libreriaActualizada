#include "estructuras.h"

stUsuario cargar_usuario()
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
    printf("Ingrese nombre y apellido\n");
    fflush(stdin);
    gets(usuario.nombreYapellido);


    printf("Ingrese nombre para su usuario\n");
    fflush(stdin);
    gets(nombreUser);



    while(conta==1)
    {
        verificarUser=verificar_Nombre_Usuario(usuario,nombreUser);
        if(verificarUser==1)
        {
            printf("Nombre ya registrado");
            printf("\nIngrese otro nombre\n");
            fflush(stdin);
            gets(nombreUser);
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

    verificarID=verificarNumeroUsuario(usuario)+1;///leer el archivo para no pisar el usuario recien cargado

    usuario.id=verificarID;

    usuario.validos=1;


    while(conta == 1)
    {
        if(flag == 1)
        {
            printf("Ingrese Pass\n");
            fflush(stdin);
            gets(password);

            printf("Ingrese reescriba la Pass\n");
            fflush(stdin);
            gets(repassword);
            compararPass=strcmp(password,repassword);

            if(compararPass==0)
            {
                strcpy(usuario.contrasenia,password);

                conta=0;
                flag=0;
            }
            else
            {
                CLEAN;
                printf("pass no coinsiden\n");
                Sleep(1500);
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

    printf("Ingrese nombre usuario:\n");
    scanf ("%s", &nomUser);

    printf("Ingrese pass:\n");
    scanf ("%s", &pass);

    if((strcmp(nomUser,admi)==0) && (strcmp(pass,admi)==0))
    {
        //printf("Bienvenido adminitrador %s.\n",admi);
        ///debe de ingresar al menu admi
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
                        gotoxy (8,24);
                        printf("Este usuario no existe.\n");
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
                printf("%s",usuario.nombreYapellido);
                printf("%s",usuario.nombreUsuario);
                printf("%s",usuario.id);
                printf("%s",usuario.contrasenia);

            }
        }
        fclose(archivoUsuario);
    }
}

void mostrar_lista_usuarios()
{
    stUsuario usuarios;
    FILE * archUsuarios=fopen(archivo_Usuarios,"rb");
    if(archUsuarios!=NULL)
    {
        while(fread(&usuarios,sizeof(stUsuario),1,archUsuarios)>0)
        {
            if(usuarios.validos==1)
            {
                printf("%s\n",usuarios.nombreYapellido);
                printf("%s\n",usuarios.nombreUsuario);
                printf("%d\n",usuarios.id);
            }

        }
        fclose(archUsuarios);
    }

}

void darseBaja(stUsuario usuario,int id)
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r+b");

    int bandera=0;

    if(archivoUsuario!=NULL)
    {
        while(fread(&usuario,sizeof(stUsuario),1,archivoUsuario)>0 && bandera ==0)
        {
            if(id == usuario.id)
            {
                if(usuario.validos==1)
                {
                    usuario.validos=0;

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

int buscarNumeroUsuario(stUsuario usuario)///en el archivo
{
    int idUsuario;
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r");
    ///buscar en el archivo el numero de usuario que el usuario presione
    int numUsuarioBusca;
    int noExiste=0;
    printf("Ingrese el numero del Usuario que desea buscar: ");
    scanf("%d",&numUsuarioBusca);

    if(archivoUsuario!=NULL)
    {
        while(fread(&usuario,sizeof(stUsuario),1,archivoUsuario)>0)
        {
            if(numUsuarioBusca == usuario.id)
            {
                printf("Este numero de Usuario esta registrado.\n");
                mostrar_mi_perfil(usuario,usuario.id);

                noExiste=1;
                fclose(archivoUsuario);
                idUsuario=usuario.id;
            }

        }
        fclose(archivoUsuario);
    }
    if(noExiste==0)
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
        while(fread(&usuario,sizeof(stUsuario),1,archivoUsuario)>0)
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


                    flag=1;
                    PAUSE;
                    break;

                case 2:///nombre usuario
                    CLEAN;

                    printf("Ingrese Nuevo Apellido:\n");
                    fflush(stdin);
                    gets(nuevoNombreUsuario);

                    strcpy(usuario.nombreUsuario,nuevoNombreUsuario);

                    fseek(archivoUsuario,sizeof(stUsuario)*-1,SEEK_CUR);
                    fwrite(&usuario,sizeof(stUsuario),1,archivoUsuario);

                    //rewind(archivoUsuario);

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
    }
    fclose(archivoUsuario);

}










