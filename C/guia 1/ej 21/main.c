#include <stdio.h>
#include <stdlib.h>
void menu()
{
    printf("que desea saber");
    printf("los elementos en pocisiones impares (a)\n");
    printf("generar otro vector con elementos divisibles por k (b)\n");
    printf("buscar la pocision de un valor x (si devuelve 0 no esta en el vector)\n");
    printf("finalizar (f)\n");
}
int busqueda(int v[],int n)
{
    int x,i=1;
    printf("ingrese x\n");
    scanf("%d",&x);
    while (i<=n && v[i]!=x)
        i++;
    return (v[i]==x)? i:0;
}
void muestra(int v[],int n)
{
    int i;
    for (i=1;i<=n;i=i+2)
        printf("%d ",v[i]);
        printf("\n");
}
void crear(int v[],int va[],int n,int *m)
{
    int i,k;
    *m=0;
    printf("ingrese k\n");
    scanf("%d",&k);
    for (i=1;i<=n;i++)
       if (v[i]%k==0)
       {
           (*m)++;
           va[*m]=v[i];
       }
    for (i=1;i<=*m;i++)
        printf("%d ",va[i]);
        printf("\n");
}
int main()
{
    char opcion;
    int v[30],va[30],n,m,i;
    printf("ingrese n\n");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        printf("ingrese el %d valor\n",i);
        scanf("%d",&v[i]);
    }
    menu();
    do {
        printf("ingrese la opcion\n");
        scanf(" %c",&opcion);
        switch (opcion)
        {
            case 'a':muestra(v,n); break;
            case 'b':crear(v, va, n, &m); break;
            case 'c':printf("pocision %d\n",busqueda(v,n)); break;
        }
    }    while (opcion!='f');
    return 0;
}
