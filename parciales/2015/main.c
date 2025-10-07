#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    tpila p;
    telementop num;
         iniciap(&p);
         ponep(&p, 5);
         ponep(&p, 3);
         ponep(&p, 5);
         ponep(&p, 7);
         printf("ingrese el numero\n");
         scanf("%d",&num);
         eliminar(&p,num);
    printf("Hello world!\n");
    return 0;
}
