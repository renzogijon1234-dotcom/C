#include <stdio.h>
int main() {
    int num,acumulador=0;
    scanf("%d", &num);
    while (num>0) {
        acumulador=acumulador+num;
        scanf("%d",&num);
    }
    printf("%d",acumulador);
    return 0;
    }

