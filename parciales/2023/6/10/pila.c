#include "pila.h"

void iniciap(tpila *p) {
   p->n=-1;
}
void ponep(tpila *p,char dato) {
  (p->n)++;
  p->v[p->n]=dato;
}
void sacap(tpila *p,char *dato) {
  *dato=p->v[p->n];
    (p->n)--;
  }
int vaciap(tpila p)
{
    return p.n==-1;
}
int tope(tpila p)
{
    return p.n==capacidad;
}
void decensop(tpila *p,char parada)
{
 char dato;
    if (!vaciap(*p))
    {
        sacap(p,&dato);
        decensop(p,parada);
        if (dato!=parada)
            ponep(p,dato);
    }
}
