#include "Celdas.h"

int buscarUsuarioEnCelda(stCelda adl[], stUsuario user,int validos)
{
    int rta=-1;
    int i=0;
    while((i<validos)&&(rta==-1))
    {
        if(adl[i].usuario.id == user.id)
        {
            rta=i;
        }
        i++;
    }
    return rta;
}

int agregarCelda(stCelda adl[], stUsuario user,int validos)
{
    adl[validos].usuario=user;
    adl[validos].listaFavoritos=inicListaFav();
    validos++;
    return validos;
}

///carga de listas de fav en una lista simple
///guardar si o no
int alta(stCelda adl[], stUsuario user,int validos)
{
    int posicion=buscarUsuarioEnCelda(adl,user,validos);
    if(posicion==-1)
    {
        validos=agregarCelda(adl,user,validos);
        posicion=validos-1;
    }
    adl[posicion].listaFavoritos=pasar_archivo_Favoritos_a_lista(adl[posicion].listaFavoritos);

    return validos;
}

int archivo2adl(stCelda adl[], int val, int dim)
{
    FILE* arch=fopen(archivo_Usuarios, "rb");
    if(arch!=NULL)
    {
        stUsuario rg;
        stUsuario aux;
        rewind(arch);

        while((fread(&rg,sizeof(stUsuario),1,arch)>0)&&(val<dim))
        {

            aux.id=rg.id;

            strcpy(aux.nombreUsuario,rg.nombreUsuario);

            aux.validos= rg.validos;

            strcpy(aux.contrasenia,rg.contrasenia);

            strcpy(aux.nombreYapellido,rg.nombreYapellido);

            val = alta(adl,aux,val);
        }
        fclose(arch);
    }
    return val;
}

void mostrarADL(stCelda adl[], int validos) ///muestra todos los usuario con su lista de favoritos
{
    printf("\nMostrando el arreglo de listas: \n");
    int i=0;
    while(i<validos)
    {
        printf("\n\nUsuarios \n");
        mostrar_usuario(adl[i].usuario);
        printf("lista Favoritos\n");
        mostrarNodos_Fav(adl[i].listaFavoritos,adl[i].usuario.id);
        i++;
    }
}

void lista_UsuariosEC(stCelda adl[], int validos)///muestra los usuario en alta o baja en stCelda
{
    int i=0;
    listaUsuarios();
    int x=13;
    int y=8;
    while(i<validos)
    {
        gotoxy(x,y);
        printf("%s",adl[i].usuario.nombreYapellido);
        gotoxy(x+26,y);
        printf("%s",adl[i].usuario.nombreUsuario);
        gotoxy(x+44,y);
        printf("%d",adl[i].usuario.id);
        gotoxy(x+53,y);
        printf("%s",adl[i].usuario.contrasenia);
        gotoxy(x+64,y);
        printf("%d",adl[i].usuario.validos);
        y=y+2;
        i++;
    }
    gotoxy(60,60);
}

void buscarEnCelda_y_MuestaListaFav(stCelda adl[], int validos)
{
    int i=-1;
    int user;

    printf("Ingrese ID de un Usuario para ver su lista de Favoritos.\n");
    fflush(stdin);
    scanf("%d",&user);

    int condicion=0;
    //printf("%d\n",condicion);

    condicion=verificar_Celdas(adl,validos,user);

    if(condicion==1)
    {
        listaFavoritos();
        i=retorna_posicion_enElArreglo(adl,validos,user);
        mostrarNodos_Fav(adl[i].listaFavoritos,user);

    }
    else
    {
        printf("Este Usuario No existe");
    }
}

int verificar_Celdas(stCelda adl[], int validos,int user)
{
    int flag=0;
    int i;
    for(i=0;i<validos;i++)
    {
        if(adl[i].usuario.id == user)
        {
            flag=1;

        }
    }
    return flag;
}
int retorna_posicion_enElArreglo(stCelda adl[], int validos,int user)
{
    int flag=0;
    int i;
    for(i=0; i<validos && flag==0; i++)
    {
        if(adl[i].usuario.id==user)
        {
            flag=1;
        }
    }
    return i;
}


void mostrarListaFavortiosEC()///muestra la lista de favoritos de 1 usuario
{
    stCelda adl[20];
    int validos=0;
    int dim = 20;

    validos  = archivo2adl(adl,validos,dim);

    buscarEnCelda_y_MuestaListaFav(adl,validos);

}

void mostrandoLista_Users() ///Muestra lista de usuarios mediante stCelda
{
    stCelda adl[20];
    int validos=0;
    int dim = 20;

    validos  = archivo2adl(adl,validos,dim);

    lista_UsuariosEC(adl,validos);

}

