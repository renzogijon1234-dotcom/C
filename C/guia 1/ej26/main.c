#include <stdio.h>
#include <stdlib.h>
#define MAX 30
typedef struct
{
    char nombre[MAX],matricula[MAX];
    float promedio;
} tr;
void cargar(tr *alumno);
int main()
{
    tr alumno;
    cargar(&alumno);
    printf("nombre %s matricula %s promedio %1.f",alumno.nombre , alumno.matricula , alumno.promedio);
    return 0;
}
void cargar(tr *alumno)
{
    printf("Ingrese nombre, matricula y promedio del alumno\n");
    scanf("%s %s %f", alumno->nombre, alumno->matricula, &alumno->promedio);
}
