#include <stdio.h>
#include <stdlib.h>
#define MAX 30
typedef struct
{
    int fila,columna,valor;
} tr;
void armarvr(int mat[][MAX],tr vr[],int *k,int n,int m);
void cargamatriz(int mat[][MAX],int *n,int *m);
int main()
{
    int mat[MAX][MAX],n,m,k=0,i;
    tr vr[MAX*MAX];
    cargamatriz(mat,&n,&m);
    armarvr(mat,vr,&k,n,m);
    for (i=0;i<k;i++)
        printf("fila %d columna %d valor %d\n",vr[i].fila,vr[i].columna,vr[i].valor);
    return 0;
}
void cargamatriz(int mat[][MAX],int *n,int *m)
{
    int i,j;
    printf("ingrese n y m \n");
    scanf("%d %d",n,m);
    for (i=0;i<*n;i++)
        for (j=0;j<*m;j++)
    {
        printf("fila %d columna %d\n",i+1,j+1);
        scanf("%d",&mat[i][j]);
    }
}
void armarvr(int mat[][MAX],tr vr[],int *k,int n,int m)
{
  int i,j;
  for (i=0;i<n;i++)
        for (j=0;j<m;j++)
          if (mat[i][j]%(n+m)==0)
          {
            vr[*k].fila=i;
            vr[*k].columna=j;
            vr[*k].valor=mat[i][j];
            (*k)++;
          }
}
