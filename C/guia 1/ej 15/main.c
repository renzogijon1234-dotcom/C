#include <stdio.h>
#include <stdlib.h>
const char* val(int a,int b,int c)
 {
     int aux;
     if (b<a)
     {
         aux=a;
         a=b;
         b=aux;
     }
     if (c<a)
     {
        aux=a;
         a=c;
         c=aux;
     }
     if (c<b)
     {
         aux=c;
         c=b;
         b=aux;
     }
     if (a+1==b && b+1==c)
        return "son consecutivos";
    else
        return "no son consecutivos";


 }
int main()
{
    int a,b,c;
    scanf("%d %d %d" , &a, &b, &c);
    printf("%d %d %d\n " , a, b, c);

         printf("%s",val(a,b,c));
    return 0;
}
