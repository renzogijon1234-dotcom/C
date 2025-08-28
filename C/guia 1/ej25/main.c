#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define x 40
typedef struct {
 char nombre[MAX];
 int edad;
 } tr;
 void cargarvr(tr vr[],int *n);
 void listado(tr vr[],int n);
 float porcentaje(tr vr[],int n);

int main()
{
    tr vr[MAX];
    int n;
    cargarvr(vr,&n);
    listado(vr,n);
    printf("porcentaje de gente mayores de edad %2.f\n",porcentaje(vr,n));
    return 0;
}
 void cargarvr(tr vr[],int *n)
 {
     int i;
     printf("ingrese n\n");
     scanf("%d",n);
     for (i=0;i<*n;i++)
     {
         printf("ingrese el %d nombre y edad\n",i+1);
         scanf("%s %d",vr[i].nombre, &vr[i].edad);
     }
 }
  void listado(tr vr[],int n)
{
    int i;
    for (i=0;i<n;i++)
        if (vr[i].edad>x)
            printf("%s con %d años\n",vr[i].nombre,vr[i].edad);
        printf("fin de lista\n");
}
 float porcentaje(tr vr[],int n)
{
    int i,cont=0;
    for (i=0;i<n;i++)
        if (vr[i].edad>x)
        cont++;
    return cont*100/n;
}
