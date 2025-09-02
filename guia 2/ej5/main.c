#include <stdio.h>
#include <stdlib.h>
void cargar(int mat[][30],int *n);
int val(int a[][30],int n,int j);
int main()
{
    int a[30][30],n;
    cargar(a,&n);
    if (val(a,n-1,n-2)==1)
        printf("la matriz es simetrica\n");
    else
        printf("la matriz no es simetrica\n");
    return 0;
}


void cargar(int mat[][30],int *n)
{
    int i,j;
    printf("ingrese n\n ");
    scanf("%d",n);
    for (i=0;i<*n;i++)
    {
        printf("fila %d\n",i);
        for (j=0;j<*n;j++)
        {
            printf("columna %d\n",j);
            scanf("%d",&mat[i][j]);
        }
    }
}
int val(int a[][30],int n,int j)
{
    if (n==0)
        return 1;
    else
        if (j==-1)
           return val(a,n-1,n-1);
        else
            if (a[n][j]==a[j][n])
              return val(a,n,j-1);
            else
                return 0;
}
