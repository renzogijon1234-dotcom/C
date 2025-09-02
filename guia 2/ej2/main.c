#include <stdio.h>
#include <stdlib.h>
int suma(int v[],int n);
void muestra(int v[],int i ,int n);
void muestra_2(int v[],int n);
void carga(int v[],int *n);
int main()
{
    int v[30], n;
    carga(v,&n);
    printf("suma %d\n",suma(v,n-1));
    muestra(v,0,n-1);
    muestra_2(v,n-1);

    return 0;
}
void carga(int v[],int *n)
{
    int i;
    printf("ingrese n\n");
    scanf("%d",n);
    for (i=0;i<*n;i++)
    {
        printf("ingrese el valor %d\n",i+1);
        scanf("%d",&v[i]);
    }
}
int suma(int v[],int n)
{
    if (n==0)
        return v[n];
    else
        return v[n]+suma(v,n-1);
}
void muestra(int v[],int i,int n)
{
    if (i==n)
        printf("%d\n ",v[i]);
    else
    {
        printf("%d ",v[i]);
        muestra(v,i+1,n);
    }
}
void muestra_2(int v[],int n)
{
    if (n==0)
        printf("%d\n ",v[n]);
    else
    {
        printf("%d ",v[n]);
        muestra_2(v,n-1);
    }
}
