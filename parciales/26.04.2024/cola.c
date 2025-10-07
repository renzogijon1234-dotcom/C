#include "cola.h"

void sacac(tcola *c,telementoc *dato)
{
    (c->pri)++;
    *dato=c->v[c->pri];
}

void ponec(tcola *c,telementoc dato)
{
    (c->ult)++;
    c->v[c->ult]=dato;
}

void iniciac(tcola *c)
{
    c->pri=-1;
    c->ult=-1;
}

int vaciac(tcola c)
{
    return c.pri==c.ult;
}
