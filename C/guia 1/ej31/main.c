#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char apellido[30],nombre[30],nacionalidad[30];
    float puntaje;
} tr;
void buscar(int pos);
int main()
{
    int pos;
    printf("ingrese la pocision\n");
    scanf("%d",&pos);
    buscar(pos);
    return 0;
}
void buscar(int pos)
{
 FILE *arch=fopen("archivo.dat","rb");
 tr registro;
 if (arch==NULL)
    printf("no se pudo abrir el archivo");
 else
 {
     fseek(arch,(pos-1)*sizeof(registro),SEEK_CUR);
    fread(&registro, sizeof(registro), 1, arch);
     printf("apellido :%s nombre : %s nacionalidad %s puntaje %1.f",registro.apellido,registro.nombre,registro.nacionalidad,registro.puntaje);
 }
 fclose(arch);
}
