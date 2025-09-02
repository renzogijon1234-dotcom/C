#include <stdio.h>
#include <stdlib.h>
void cargar(int mat[][30],int *n,int *m);
void armarv(int mat[][30],int v[],int m,int n,int j,int max);
void mostrar(int v[],int m);
int main()
{
    int mat[30][30],v[30],n,m;
    cargar(mat,&n,&m);
    armarv(mat,v,m-1,n-1,n-1,mat[m-1][n-1]);
    mostrar(v,m);
    return 0;
}
void cargar(int mat[][30],int *n,int *m)
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
            scanf("%d",&mat[i][j]);
        }
    }
}
void armarv(int mat[][30],int v[],int m,int n,int j,int max)
{
  if (m!=-1)
    if (j==-1)
  {
      v[m]=max;
      armarv(mat,v,m-1,n,n,mat[m-1][n]);
  }
  else
    if (mat[m][j]>max)
    armarv(mat,v,m,n,j-1,mat[m][j]);
  else
    armarv(mat,v,m,n,j-1,max);

}
void mostrar(int v[],int m)
{
    int i;
    for (i=0;i<m;i++)
    {
        printf("%d ",v[i]);
    }
}
