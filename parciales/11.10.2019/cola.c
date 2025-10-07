
#include "cola.h"

void sacaC(tcola *c,telementoc *dato)
{
    (c->pri)++;
    *dato=c->v[c->pri];
}

void poneC(tcola *c,telementoc dato)
{
    (c->ult)++;
    c->v[c->ult]=dato;
}

void iniciaC(tcola *c)
{
    c->pri=-1;
    c->ult=-1;
}

int vaciaC(tcola c)
{
    return c.pri==c.ult;
}
