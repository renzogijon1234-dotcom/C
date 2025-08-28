#include <stdio.h>
#include <stdlib.h>
  void main()
{
    int hora=0, minuto=0;
    long segundo;
    scanf("%d",&segundo);
    while (segundo>=3600)
    {
        hora++;
        segundo-=3600;
    }
    while (segundo>=60)
    {
        minuto++;
        segundo-=60;
    }
    printf("%d hora/s %d minuto/s %d segundo/s",hora ,minuto ,segundo);
}
