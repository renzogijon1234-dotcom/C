#include <stdio.h>
#include <stdlib.h>
void cargar();
void leer();
int main()
{
    cargar();
    leer();
    return 0;
}

void cargar()
{
    FILE* arch=fopen("archivos.dat","ab");
    float num;
    int i=5;
    printf("para %d temperatura ingrese un valor (0 para fin)\n",i);
    scanf("%f",&num);
    while (num!=0)
    {
      fwrite(&num,sizeof(float),1,arch);
      i +=5;
      printf("para %d temperatura ingrese un valor o 0\n",i);
      scanf("%f",&num);
    }
    fclose(arch);
}
void leer()
{
  FILE* arch=fopen("archivos.dat","rb");
  float num,max=-1,min=999999,ac=0;
  int n=0;
    if (fread(&num, sizeof(float), 1, arch) == 1) {
        max = min = num;
        ac  = num;
        n   = 1;
    }
  while (fread(&num, sizeof(float), 1, arch) == 1)
  {
      ac +=num;
      n++;
      max=(num>max)? num:max;
      min=(num<min)? num:min;

  }
  remove("archivos.dat");
  fclose(arch);
  ac=ac/n;
  printf("maximo %1.f minimo %1.f promedio %1.f n %d",max,min,ac,n);
}
