typedef struct
{
    char cod[16];
    float cont;
}telementoc;

typedef struct
{
    telementoc v[100];
    int pri,ult;
}tcola;

void  iniciaC(tcola *c);
void sacaC(tcola *c,telementoc *dato);
int  vaciaC(tcola c);
