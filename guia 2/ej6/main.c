#include <stdio.h>
#include <stdlib.h>
void cargar(int mat[][30],int *n,int *m);
int val(int mat[][30],int n,int m,int i,int j,int suma,int suma_aux);
int main()
{
    int mat[30][30],n,m;
    cargar(mat,&n,&m);
    if (val(mat,n,m,0,m-1,0,0)==1)
      printf("todas las filas cumplen\n");
    else
     printf("no todas las filas cumplen\n");
    return 0;
}

void cargar(int mat[][30],int *n,int *m)
{
    int i,j;
    printf("ingrese n y m\n");
    scanf("%d %d",n,m);
    for (i=0;i<*n;i++)
    {
        printf("fila %d\n",i);
        for (j=0;j<*m;j++)
        {
            printf("columna %d\n",j);
            scanf("%d",&mat[i][j]);
        }
    }
}

int val(int mat[][30],int n,int m,int i,int j,int suma,int suma_aux)
{
    if (i==n )
           return 1;
    else
        if (j!=-1)
           return val(mat,n,m,i,j-1,suma+mat[i][j],suma_aux);
        else
          if (i==0)
          {
            if (suma%2==1)
                return 0;
              else
                return val(mat,n,m,i+1,m-1,0,suma);
          }
          else
            if (suma<suma_aux)
                return 0;
            else
            return val(mat,n,m,i+1,m-1,0,suma);
}
