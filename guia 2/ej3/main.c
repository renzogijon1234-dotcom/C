#include <stdio.h>
#include <stdlib.h>
void carga(int v[],int *n);
int suma(int v[],int n);
int main()
{
    int v[30],n;
    carga(v,&n);
    printf("promedio %f",suma(v,n-1)*1.0/n);
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
