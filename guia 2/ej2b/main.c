#include <stdio.h>
#include <stdlib.h>
void carga(float v[],int *n);
int busquedad(float v[],float x,int n);
int busquedao(float v[],float x,int pri,int ult);
int main()
{
    float v[30],x;
    int n,pos;
    carga(v,&n);
    printf("ingrese x \n");
    scanf("%f",&x);
    pos=busquedad(v,x,n-1);
    if (pos==-1)
       printf("x no esta en el vector\n");
    else
        printf("x esta en la pocision %d\n",pos);
    pos=busquedao(v,x,0,n-1);
    if (pos==-1)
       printf("x no esta en el vector\n");
    else
        printf("x esta en la pocision %d\n",pos);
    return 0;
}


void carga(float v[],int *n)
{
    int i;
    printf("ingrese n\n");
    scanf("%d",n);
    for (i=0;i<*n;i++)
    {
        printf("ingrese el valor %d\n",i+1);
        scanf("%f",&v[i]);
    }
}

int busquedad(float v[],float x,int n)
{
 if (n==-1 || v[n]==x)
    return n;
 else
    return busquedad(v,x,n-1);
}
int busquedao(float v[],float x,int pri,int ult)
{
  int med=(pri+ult)/2;
  if (pri==ult && v[med]!=x)
    return -1;
  else
    if (v[med]==x)
     return med;
    else
       if (v[med]>x)
        return busquedao(v,x,pri,med-1);
      else
        return busquedao(v,x,med+1,ult);
}
