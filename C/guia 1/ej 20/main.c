#include <stdio.h>
#include <stdlib.h>

void main()
{
    long numero;
    int bin[32],n=0,i;
    printf("ingrese el numero\n");
    scanf("%d",&numero);
    while (numero>0)
    {
        n++;
        bin[n]=numero%2;
        numero /=2;
    }
        for (i=n;i>0;i--)
    {
        printf("%d",bin[i]);
    }
}
