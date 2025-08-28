#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arch;
    int suma=0,num;
    arch=fopen("archivos.txt","r");
    while (!feof(arch))
    {
        fscanf(arch,"%d",&num);
        suma +=num;
    }
    fclose(arch);
    printf("suma de los numeros %d\n",suma);
    return 0;
}
