#include <stdio.h>
#include <stdlib.h>
int suma(int sumados,int num1,int num2)
{
    if (sumados!=2)
        return num1+suma(sumados+1,num1,num2);
    else
        return num2;
}
int main()
{
    int num1,num2;
    printf("ingrese num1 y num2\n");
    scanf("%d %d",&num1,&num2);
    printf("suma %d",suma(1,num1,num2));
    return 0;
}
