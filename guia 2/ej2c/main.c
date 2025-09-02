#include <stdio.h>
#include <stdlib.h>
void cargar(int mat[][30],int *n);
int min(int mat[][30],int n,int i,int j);
int main()
{
    int mat[30][30],n;
    cargar(mat,&n);
    printf("valor minimo %d\n",min(mat,n-1,n-1,n-1));
        return 0;
}
void cargar(int mat[][30],int *n)
{
    int i,j;
    printf("ingrese n\n");
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
int min(int mat[][30],int n,int i,int j)
{
    int aux;
    if (i==0 && j==0)
        return mat[i][j];
    else
    {
        if (j==-1)
            aux=min(mat,n,i-1,n);
        else
            aux= min(mat,n,i,j-1);
        if (aux<mat[i][j])
            return aux;
        else
            return mat[i][j];
    }
}
