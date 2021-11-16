#ifndef TDA_USUARIO_H_INCLUDED
#define TDA_USUARIO_H_INCLUDED

typedef struct
{
    char nombreYapellido[60];//mas de 1
    char nombreUsuario[50];//verificar
    int id;///
    char contrasenia[10];///
    int validos;

}stUsuario;


void cargar_usuario();

int login();

void guardar_usuario(stUsuario usuario);

void mostrar_mi_perfil(stUsuario usuario,int id);

void darseBaja(stUsuario usuario,int id);

int verificarNumeroUsuario(stUsuario usuario);

int verificar_Nombre_Usuario(stUsuario usuario,char nombre[]);

int buscarNumeroUsuario(stUsuario usuario,int idUsuario);///en el archivo

void modificarUsuario(stUsuario usuario, int id);

void mostrarListaUsuarios();

#endif // TDA_USUARIO_H_INCLUDED
