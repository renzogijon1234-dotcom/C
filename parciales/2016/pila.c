#include "pila.h"
void iniciap(Tpila *p)
{
    p->n=-1;
}
void sacap(Tpila *p,TelementoP *dato)
{
    *dato=p->dato[p->n];
        (p->n)--;
}
void ponep(Tpila *p,TelementoP dato)
{
    (p->n)++;
    p->dato[p->n]=dato;
}
int vaciap(Tpila p)
{
    return p.n==-1;
}
