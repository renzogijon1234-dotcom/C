#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nombre[7],fecha[16];
    int vr,vm;
} tr;
void cargar();
int main()
{
    cargar();
    return 0;
}
void cargar()
{
  FILE*arch=fopen("archivo.txt","r");
  FILE*arch2=fopen("archivo.dat","wb");
  tr registro;
  char c;
  int n=0,m=0;
  if ((arch==NULL) || (arch2==NULL))
    printf("algun archivo no se pudo abrir correctamente\n");
   else
    while (!feof(arch))
   {
       n++;
       fscanf(arch,"%s %d %d %c %s \n",registro.nombre,&registro.vr,&registro.vm,&c,registro.fecha);
       if (registro.vr>registro.vm*1.2)
       {
        m++;
        fwrite(&registro,sizeof(tr),4,arch2);
       }
   }
   printf("total de registro en txt %d\n",n);
   printf("total de registros en el archivo binario %d\n",m);
}
