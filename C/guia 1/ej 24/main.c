#include <stdio.h>
#include <stdlib.h>
#define col 20
void buscarx(int n,int m ,int matriz[][col])
{
    int i=0,j=0,x;

    printf("ingrese x\n");
    scanf("%d",&x);
    while (i<n && matriz[i][j]!=x)
    {

        while (j<m && matriz[i][j]!=x)
        {

            j++;
        }
        if (matriz[i][j]!=x)
        {
            j=0;
            i++;
        }
    }
        if (i<n)
    printf("fila %d columna %d\n", i, j);
    else
    printf("no existe\n");
}
void promC(int n,int m,int matriz[][col])
{
    int i,j;
    float prom;
    for (j=0;j<m;j++)
    {
        prom=0;
        for (i=0;i<n;i++)
           prom+=matriz[i][j];
        prom /=n;
        printf("columna %d promedio %.2f\n",j,prom);
    }
}
float promM(int n,int m,int matriz[][col])
{
    int i,j;
    float acumulador=0;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
          acumulador +=matriz[i][j];
    acumulador /=n*m;    return acumulador;
}
void puntoc (int n, int m,int matriz[][col])
{
    float prom;
    int i,j,val,cont;
    prom=promM(n,m,matriz);
    for (i=0;i<n;i++)
    {
        cont=0;
        val=1;
        for (j=0;j<m;j++)
        {
            if (matriz[i][j]==0)
                val=0;
            if (matriz[i][j]>prom)
                cont++;
        }
        if (val==0)
            printf("fila %d tiene %d numeros que superan el promedio\n ",i,cont);
    }
}
int main()
{
    int matriz[20][20],n,m,i,j;
    printf("ingrese n y m\n");
    scanf("%d",&n);
    scanf("%d",&m);
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
        {
        printf("fila %d columna %d\n  ",i,j);
        scanf("%d",&matriz[i][j]);
        }
        buscarx(n,m,matriz);
    promC(n,m,matriz);
    puntoc(n,m,matriz);


    return 0;
}
