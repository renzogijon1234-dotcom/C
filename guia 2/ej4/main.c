#include <stdio.h>
#include <stdlib.h>
void cargar(float mat[][30],int *n,int *m);
void contx(float a[][30],float x,int n,int m,int j,int cont);
int contador(float a[][30],float x ,int n,int m,int j);
int main()
{
    float a[30][30],x;
    int n,m;
    cargar(a,&n,&m);
    printf("ingrese x \n");
    scanf("%f",&x);
    contx(a,x,n-1,m-1,m-1,0);
    printf("x aparece %d veces\n",contador(a,x,n-1,m-1,m-1));
    return 0;
}

void cargar(float mat[][30],int *n,int *m)
{
    int i,j;
    printf("ingrese n y m\n");
    scanf("%d %d",n,m);
    for (i=0;i<*m;i++)
    {
        printf("fila %d\n",i);
        for (j=0;j<*n;j++)
        {
            printf("columna %d\n",j);
            scanf("%f",&mat[i][j]);
        }
    }
}

void contx(float a[][30],float x ,int n,int m,int j,int cont)
{
    if (n==-1)
        printf("x aparece %d veces\n",cont);
    else
        if (j==-1)
           contx(a,x,n-1,m,m,cont);
        else
            if (a[n][j]==x)
           contx(a,x,n,m,j-1,cont+1);
            else
           contx(a,x,n,m,j-1,cont);
}
int contador(float a[][30],float x ,int n,int m,int j)
{
    if (n==-1)
        return 0;
    else
        if (j==-1)
        return contador(a,x,n-1,m,m);
        else
            if (a[n][j]==x)
               return 1+contador(a,x,n,m,j-1);
            else
               return contador(a,x,n,m,j-1);

}
