#include <stdio.h>
#include <stdlib.h>
void carga(int v[],int *n);
void armarv(int a[],int b[],int c[],int n,int m,int i,int j,int *p);
void mostrar(int c[],int p);
int main()
{
    int a[30],b[30],c[60],n,m,p=-1;
    carga(a,&n);
    carga(b,&m);
    armarv(a,b,c,n,m,0,0,&p);
    p++;
    mostrar(c,p);
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
void armarv(int a[],int b[],int c[],int n,int m,int i,int j,int *p)
{
    if (i!=n || j!=m)
        {
          (*p)++;
          if (a[i]==b[j] && (i!=n && j!=m))
          {
              c[*p]=a[i];
              armarv(a,b,c,n,m,i+1,j+1,p);
          }
          else
            if ((a[i]<b[j] || j==m) && i!=n)
          {
              c[*p]=a[i];
              armarv(a,b,c,n,m,i+1,j,p);
          }
          else
          {
              c[*p]=b[j];
              armarv(a,b,c,n,m,i,j+1,p);
          }
        }
}
void mostrar(int c[],int p)
{
    int i;
    for (i=0;i<p;i++)
        printf("%d ",c[i]);
}
