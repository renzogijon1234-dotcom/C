#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n;
    char car;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        car=(i==1 || i==n)? '#':' ';
        printf("#");
        for (j=2;j<=n-1;j++)
        {
            printf("%c",car);
        }
        printf("#\n");
    }
    return 0;
}
