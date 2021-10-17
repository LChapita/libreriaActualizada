
///funciones usuario
/*

void cargar_usuario()
{
    stRegistrarse registro;

    int compararPass;

    char password[10];
    char repassword[10];

    int conta=1;

    char mail[50];
    int verificarMail;

    int verificar=0;
    //char carga='s';

    //while(carga=='s')
    //{
    menuRegistro();

    gotoxy (22,6);
    fflush(stdin);
    gets(registro.nombreUsuario);

    gotoxy (24,10);
    fflush(stdin);
    gets(registro.apellido);

    verificar=verificarNumeroUsuario(registro);///leer el archivo para no pisar el usuario recien cargado

    registro.validos=1;
    registro.numeroDeUsuario=verificar;

    while(conta==1)
    {

        gotoxy (20,14);
        fflush(stdin);
        gets(mail);
        verificarMail=verificar_mail(registro,mail);

        if(verificarMail==0)///si los mail son iguales entonces existe en el archivo
        {
            gotoxy(8,27);
            printf("El Mail ya existe.\n");
        }
        else
        {
            gotoxy(8,28);
            printf("Es valido.\n");
            conta=0;
        }

    }

    strcpy(registro.mail,mail);





    conta=1;
    int flag=1;

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
                strcpy(registro.contrasenia,password);

                conta=0;
            }
            else
            {
                CLEAN;
                contrasInv();
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
                strcpy(registro.contrasenia,password);

                conta=0;
            }
            else
            {
                contrasInv();
                contrasNoCoin();
            }
        }
    }


    guardar_usuario(registro);///guardar el registro del usuario en el archivo



    CLEAN;
    registroExitoso();
    Sleep(750);

//        printf("Desea ingresar? si=SI/ no=NO \n");
//        fflush(stdin);
//        scanf("%c",&carga);

    //}

}
int verificar_mail(stRegistrarse registro, char mail[])
{
    FILE * archivoUsuario;
    archivoUsuario=fopen(archivo_Usuarios,"r");
    int verificarMail;
    int flag=1;
    if(archivoUsuario!=NULL)
    {
        while(fread(&registro,sizeof(stRegistrarse),1,archivoUsuario)>0&&flag==1)
        {
            verificarMail=strcmp(mail,registro.mail);
            if(verificarMail==0)
            {
                flag=0;
            }

        }
        fclose(archivoUsuario);
    }
    return verificarMail;
}
void guardar_usuario(stRegistrarse registro)
{
    FILE * archivoUsuario;
    archivoUsuario=fopen(archivo_Usuarios,"a");
    if(archivoUsuario!=NULL)
    {
        fwrite(&registro,sizeof(stRegistrarse),1,archivoUsuario);
        fclose(archivoUsuario);
    }
    else
    {
        printf("Error.\n");
    }
}
int login(stRegistrarse registro)
{
    FILE * fusuario=fopen(archivo_Usuarios,"rb");

    char mail[50];
    char pass[10];

    char admi[]= {"admi"};
    int iduser;
    int flag=0;

    CLEAN;
    menuIngresar();

    gotoxy (20,7);
    scanf ("%s", &mail);

    gotoxy (53,7);
    scanf ("%s", &pass);
    //printf("Bienvenido adminitrador %s.\n",admi);
    if(strcmp(mail,admi)==0 && strcmp(pass,admi)==0)
    {
        menu_Administrador();
        flag=1;
    }
    else
    {
        if(fusuario!=NULL)
        {
            while(fread(&registro,sizeof(stRegistrarse),1,fusuario)>0 && flag==0)
            {
                if(strcmp(registro.mail,mail)==0 && strcmp(registro.contrasenia,pass)==0)
                {
                    if(registro.validos==1)
                    {
                        iduser=registro.numeroDeUsuario;
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
void mostrar_mi_perfil(stRegistrarse registro,int id)
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r");
    verPerfil();

    if(archivoUsuario!=NULL)
    {
        while(fread(&registro,sizeof(stRegistrarse),1,archivoUsuario)>0)
        {
            if(registro.numeroDeUsuario==id)
            {
                gotoxy (22,6);
                printf("%s",registro.nombreUsuario);
                gotoxy (24,10);
                printf("%s",registro.apellido);
                gotoxy (20,14);
                printf("%s",registro.mail);
                gotoxy (26,18);
                printf("%s",registro.contrasenia);
                gotoxy(20,25);
            }
        }
        fclose(archivoUsuario);
    }
}

void darseBaja(stRegistrarse registro,int id)
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r+b");

    int bandera=0;

    if(archivoUsuario!=NULL)
    {
        while(fread(&registro,sizeof(stRegistrarse),1,archivoUsuario)>0 && bandera ==0)
        {
            if(id == registro.numeroDeUsuario)
            {
                if(registro.validos==1)
                {
                    registro.validos=0;

                    fseek(archivoUsuario,sizeof(stRegistrarse)*-1,SEEK_CUR);
                    fwrite(&registro,sizeof(stRegistrarse),1,archivoUsuario);
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

///funciones admi
void mostrar_usuario(stRegistrarse registro)
{
    printf("NOMBRE:             %s\n",registro.nombreUsuario);
    printf("APELLIDO:           %s\n",registro.apellido);
    printf("NUMERO USUARIO:     %d\n",registro.numeroDeUsuario);
    printf("MAIL:               %s\n",registro.mail);
    printf("CONTRASE%cA:        %s\n",165,registro.contrasenia);

}
void mostrar_registro_archivo(stRegistrarse registro)
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r");

    while(fread(&registro,sizeof(stRegistrarse),1,archivoUsuario)>0)
    {
        mostrar_usuario(registro);
        printf("\n");
    }
    fclose(archivoUsuario);

}
void mostrar_validos(stRegistrarse registro)
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r");

    while(fread(&registro,sizeof(stRegistrarse),1,archivoUsuario)>0)
    {
        if(registro.validos==1)
        {
            mostrar_usuario(registro);
            printf("\n");
        }
    }
    fclose(archivoUsuario);

}
int verificarNumeroUsuario(stRegistrarse registro)
{

    FILE * archivoUsuario=fopen(archivo_Usuarios,"r");
    int num=0;
    if(archivoUsuario!=NULL)
    {
        while(fread(&registro,sizeof(stRegistrarse),1,archivoUsuario)>0)
        {
            if(registro.numeroDeUsuario>num)
            {
                num=registro.numeroDeUsuario;
            }
        }
        fclose(archivoUsuario);
    }

    return num+1;
}
int buscarNumeroUsuario(stRegistrarse registro)
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
        while(fread(&registro,sizeof(stRegistrarse),1,archivoUsuario)>0)
        {
            if(numUsuarioBusca == registro.numeroDeUsuario)
            {
                printf("Este numero de Usuario esta registrado.\n");
                mostrar_usuario(registro);

                noExiste=1;
                fclose(archivoUsuario);
                idUsuario=registro.numeroDeUsuario;
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
void modificarUsuario(stRegistrarse registro, int id)
{

    FILE * archivoUsuario=fopen(archivo_Usuarios,"r+b");
    ///buscar el usuario y mantenerlo
    int verdad;
    int opcion;
    int numUsuarioBusca;
    char nuevoNombre[50];
    char nuevoApellido[50];
    char nuevoMail[50];
    int flag=0;


    if(archivoUsuario!=NULL)
    {
        while(fread(&registro,sizeof(stRegistrarse),1,archivoUsuario)>0)
        {
            if(id == registro.numeroDeUsuario&& flag==0)
            {
                ///entra como variable la opcion
                ///la eleccion sera mediante un switch
                CLEAN;
                modificar_Usuario();
                opcion=opcionModificar();

                switch(opcion)
                {
                case 1:///nombre;
                    CLEAN;

                    printf("Ingrese Nuevo Nombre:\n");
                    fflush(stdin);
                    gets(nuevoNombre);

                    strcpy(registro.nombreUsuario,nuevoNombre);

                    fseek(archivoUsuario,sizeof(stRegistrarse)*-1,SEEK_CUR);
                    fwrite(&registro,sizeof(stRegistrarse),1,archivoUsuario);


                    flag=1;
                    PAUSE;
                    break;

                case 2:///apellido
                    CLEAN;

                    printf("Ingrese Nuevo Apellido:\n");
                    fflush(stdin);
                    gets(nuevoApellido);

                    strcpy(registro.apellido,nuevoApellido);

                    fseek(archivoUsuario,sizeof(stRegistrarse)*-1,SEEK_CUR);
                    fwrite(&registro,sizeof(stRegistrarse),1,archivoUsuario);

                    rewind(archivoUsuario);

                    ///copia el registro completo, lo modifica y pega

                    flag=1;
                    PAUSE;
                    break;

                case 3:///mail
                    CLEAN;

                    printf("Ingrese Nuevo mail:\n");
                    fflush(stdin);
                    gets(nuevoMail);

                    verdad=verificar_mail(registro,nuevoMail);
                    printf("%s\n",registro.mail);
                    printf("%d\n",verdad);
                    PAUSE;
                    if(verdad==0)
                    {
                        mailInv();
                    }
                    else
                    {
                        strcpy(registro.mail,nuevoMail);

                        fseek(archivoUsuario,sizeof(stRegistrarse)*-1,SEEK_CUR);
                        fwrite(&registro,sizeof(stRegistrarse),1,archivoUsuario);
                        mostrar_usuario(registro);
                        flag=1;
                        PAUSE;
                    }

                    break;
                }
            }
        }
    }
    fclose(archivoUsuario);

}
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
void bajalogicaUsuarios(stRegistrarse registro)
{
    FILE * archivoUsuario=fopen(archivo_Usuarios,"r+b");

    char darbaja='s';
    int usuario=0;
    printf("Ingrese numero de usuario para dar de baja:\n");
    scanf("%d",&usuario);

    if(archivoUsuario!=NULL)
    {
        while(fread(&registro,sizeof(stRegistrarse),1,archivoUsuario)>0)
        {
            if(usuario== registro.numeroDeUsuario && registro.validos==1)
            {

                registro.validos=0;

                fseek(archivoUsuario,sizeof(stRegistrarse)*-1,SEEK_CUR);
                fwrite(&registro,sizeof(stRegistrarse),1,archivoUsuario);
                printf("se a dado de baja correctamente\n");
                fclose(archivoUsuario);
            }
            else
            {
                printf("\nEl usuario no existe.\n");
            }
        }
        fclose(archivoUsuario);
    }

}

///funciones libros

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
///****************
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
///****************
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
void mostrar_lista(stLibro libro)
{
    int x=13;
    int y=8;

    FILE * archivoLibros;
    archivoLibros=fopen(archivo_Libros,"r");
    listaLibros();
    if(archivoLibros!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archivoLibros)>0)
        {


            gotoxy(14,y);
            printf("%d",libro.numLibro);
            gotoxy(17,y);
            printf("%s",libro.nombreLibro);
            gotoxy(42,y);
            printf("%s",libro.autor);
            gotoxy(63,y);
            printf("%s",libro.genero);
            y=y+2;
            Sleep(500);

        }
    }
    gotoxy(8,90);
    fclose(archivoLibros);

}
void mostrar_lista_usuarios(stRegistrarse registro)
{
    int x=13;
    int y=8;

    FILE * archRegistro;
    archRegistro=fopen(archivo_Usuarios,"rb");
    listaUsuarios();
    if(archRegistro!=NULL)
    {
        while(fread(&registro,sizeof(stRegistrarse),1,archRegistro)>0)
        {
            if(registro.validos==1)
            {
                gotoxy(14,y);
                printf("%d",registro.numeroDeUsuario);
                gotoxy(17,y);
                printf("%s",registro.nombreUsuario);
                gotoxy(42,y);
                printf("%s",registro.apellido);
                gotoxy(63,y);
                printf("%s",registro.mail);
                y=y+2;
                Sleep(500);
            }

        }
    }
    gotoxy(8,90);
    fclose(archRegistro);

}
void mostrar_lista_validos(stLibro libro)
{
    int x=13;
    int y=8;

    FILE * archivoLibros;
    archivoLibros=fopen(archivo_Libros,"r");
    listaLibros();
    if(archivoLibros!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archivoLibros)>0)
        {
            if(libro.valida==1)
            {
                gotoxy(14,y);
                printf("%d",libro.numLibro);
                gotoxy(17,y);
                printf("%s",libro.nombreLibro);
                gotoxy(42,y);
                printf("%s",libro.autor);
                gotoxy(63,y);
                printf("%s",libro.genero);
                y=y+2;
                Sleep(500);
            }
        }
    }
    gotoxy(8,90);
    fclose(archivoLibros);

}

void mostrar_todos_los_libros(stLibro libro)
{
    FILE * archivoLibros;
    archivoLibros=fopen(archivo_Libros,"r");

    if(archivoLibros!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archivoLibros)>0)
        {
            mostrar_libro(libro);
            printf("\n");
        }
    }
    fclose(archivoLibros);
}
void mostrar_libro(stLibro libro)
{
    printf("Nombre del Libro : %s\n",libro.nombreLibro);
    printf("Nombre de Autor  : %s\n",libro.autor);
    printf("Genero del Libro : %s\n",libro.genero);
    printf("Numero del Libro : %d\n",libro.numLibro);
}
void buscarLibroGenero(stLibro libro)
{

    FILE * archivoLibro=fopen(archivo_Libros,"r");

    char genero[50];
    int comparar;
    int Noexiste=0;
    printf("Ingrese genero del libro que desea buscar:\n");
    fflush(stdin);
    gets(genero);
    ///buscar libro por genero,autor y titulo

    if(archivoLibro!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archivoLibro)>0)
        {
            comparar=strcmp(genero,libro.genero);

            if(comparar==0)
            {
                mostrar_libro(libro);
                Noexiste=1;
            }
        }
        fclose(archivoLibro);
    }
    if(Noexiste==0)
    {
        printf("El genero no esta cargado.\n");
    }

}
void buscarLibroAutor(stLibro libro)
{

    FILE * archivoLibro=fopen(archivo_Libros,"r");

    char autor[50];
    int comparar;
    int Noexiste=0;
    printf("Ingrese Autor del libro que desea buscar:\n");
    fflush(stdin);
    gets(autor);
    ///buscar libro por genero,autor y titulo
    int flag=1;
    if(archivoLibro!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archivoLibro)>0)
        {
            comparar=strcmp(autor,libro.autor);

            if(comparar==0)
            {
                mostrar_libro(libro);
                Noexiste=1;
            }
        }
        fclose(archivoLibro);
    }
    if(Noexiste==0)
    {
        printf("El Autor no esta cargado.\n");
    }

}
void buscarLibroNombre(stLibro libro)
{

    FILE * archivoLibro=fopen(archivo_Libros,"r");

    char nombreLib[50];
    int comparar;
    int Noexiste=0;
    printf("Ingrese Autor del libro que desea buscar:\n");
    fflush(stdin);
    gets(nombreLib);
    ///buscar libro por genero,autor y titulo

    if(archivoLibro!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archivoLibro)>0)
        {
            comparar=strcmp(nombreLib,libro.nombreLibro);

            if(comparar==0)
            {
                mostrar_libro(libro);
                Noexiste=1;
            }
        }
        fclose(archivoLibro);
    }
    if(Noexiste==0)
    {
        printf("El Nombre del libro no esta cargado.\n");
    }

}
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
void favor_archivo(int id,stFavoritos favorito,stLibro libro)
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
                    favorito.idUser=id;
                    favorito.numeroLibro=libro.numLibro;

                    strcpy(favorito.autorFav,libro.autor);
                    strcpy(favorito.nombreLibroFav,libro.nombreLibro);
                    strcpy(favorito.generoFav,libro.genero);
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
            if(id==favorito.idUser)
            {
                if(numerolibro==favorito.numeroLibro)
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

void mostrar_libro_favorito(stFavoritos favorito)
{
    printf("Nombre del Libro : %s\n",favorito.nombreLibroFav);
    printf("Nombre de Autor  : %s\n",favorito.autorFav);
    printf("Genero del Libro : %s\n",favorito.generoFav);
    printf("Numero del Libro : %d\n",favorito.numeroLibro);
}
void mostrar_mis_favoritos(stFavoritos favorito,int id)
{
    FILE * archfavoritos;
    archfavoritos=fopen(archivo_Favoritos,"r");

    int x=13;
    int y=8;
    listaFavoritos();
    if(archfavoritos!=NULL)
    {

        while(fread(&favorito,sizeof(stFavoritos),1,archfavoritos)>0)
        {
            if(id==favorito.idUser)
            {
                gotoxy(14,y);
                printf("%d",favorito.numeroLibro);
                gotoxy(17,y);
                printf("%s",favorito.nombreLibroFav);
                gotoxy(42,y);
                printf("%s",favorito.autorFav);
                gotoxy(63,y);
                printf("%s",favorito.generoFav);
                y=y+2;

            }
        }
        gotoxy(8,30);
        fclose(archfavoritos);
    }
}
///
void dar_alta_again(stLibro libro)
{
    FILE * archivoLibros= fopen(archivo_Libros,"r+b");
    char darbaja='s';
    int manuscrito;

    printf("Ingrese numero del libro para dar de alta otra vez:\n");
    scanf("%d",&manuscrito);

    if(archivoLibros!=NULL)
    {
        while(fread(&libro,sizeof(stLibro),1,archivoLibros)>0)
        {
            if(manuscrito==libro.numLibro && libro.valida==0)
            {
                libro.valida=1;
                fseek(archivoLibros,sizeof(stLibro)*-1,SEEK_CUR);
                fwrite(&libro,sizeof(stLibro),1,archivoLibros);
                printf("Se a dado de alta correctamente.\n");

                fclose(archivoLibros);

            }
            else
            {
                if(manuscrito==libro.numLibro && libro.valida==1)
                {
                    printf("\nEl libro Ya esta dado de alta.\n");

                }
                else
                {
                    printf("\nEl libro no existe.\n");
                }
            }
        }
        fclose(archivoLibros);
    }
}
///---------------
int iniciar()
{
    stRegistrarse registro;
    stLibro libro;
    stFavoritos favorito;
    int id=1;
    ///usuarios
    //cargar_usuario();
    //mostrar_registro_archivo(registro);
    //PAUSE;
    //id=login(registro);
    //printf("\nEste es el id del usuario: %d ",id);
    //buscarNumeroUsuario(registro);
    //modificarUsuario(registro);
    //PAUSE;
    //mostrar_usuario(registro);
    //PAUSE;
    //mostrar_validos(registro);
    //bajalogica(registro);
    //mostrar_validos(registro);
    ///libros

    //mostrar_todos_los_libros(libro);
    //cargar_libro(libro);
    //mostrar_todos_los_libros(libro);
    //favoritos(libro,id);
    //buscarLibroGenero(libro);
    //buscarLibroAutor(libro);
    //buscarLibroNombre(libro);

    ///menu
    //menuInicio();
    //mostrar_registro_archivo(registro);
    //mostrar_validos(registro);
    //fav_pila_aux(&registro,libro,id);
    //menuconwile();
    //CLEAN;
    //mostrar_lista(libro);

    //mostrar_todos_los_libros(libro);
    //favor_archivo(id,favorito,libro);

    //mostrar_mis_favoritos(favorito,id);

    //menuPrincipal_Ingresado();
    //CLEAN;
    //opcionesUsuario();
    //CLEAN;
    //menuAdmin();
    //menuAdmin_Libros();

    ///orden
    menuInicio();
    //mostrar_registro_archivo(registro);
    return 0;
}

void menuInicio()
{
    stRegistrarse registro;
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
            id=login(registro);
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
    stRegistrarse registro;
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
            idUsuario=buscarNumeroUsuario(registro);
            PAUSE;
            CLEAN;
            printf("Esta seguro que quiere dar de baja este usuario.\n");
            fflush(stdin);
            scanf("%c",&control);
            if(control=='s')
            {
                darseBaja(registro,idUsuario);
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
            idUsuario=buscarNumeroUsuario(registro);
            PAUSE;
            CLEAN;
            printf("Esta seguro que quiere modificar este usuario.\n");
            fflush(stdin);
            scanf("%c",&control);
            if(control=='s')
            {
                CLEAN;
                modificarUsuario(registro,idUsuario);
            }
            gotoxy(8,28);
            PAUSE;
            break;

        case 1:///lista usuarios
            gotoxy(37,7);
            printf("<-");
            CLEAN;
            mostrar_lista_usuarios(registro);
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
    stRegistrarse registro;
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
            idusuario=buscarNumeroUsuario(registro);
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
            mostrar_lista(libro);
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
    stRegistrarse registro;
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
            darseBaja(registro,id);
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
            mostrar_mi_perfil(registro,id);
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
    stRegistrarse registro;
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
            mostrar_lista_validos(libro);
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
            favor_archivo(id,favorito,libro);
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
*/
