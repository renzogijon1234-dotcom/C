#include "pila.h"


void sacap(tpila *p,telementop *dato)
{
    *dato=p->v[p->n];
    (p->n)--;
}
void ponep(tpila *p,telementop dato)
{
   p->v[p->n]=dato;
   (p->n)++;
}
int vaciap(tpila p)
{
    return (p.n==-1);
}
void iniciap(tpila *p)
{
  p->n=-1;
}

int eliminar(tpila p,telementop num)
{
    int dato,eliminados;
        if (vaciap(p))
            return 0;
        else
        {
           sacap(&p,&dato);
           eliminados=eliminar(p,num);
           if (dato!=num)
                ponep(&p,dato);
           else
               eliminados++;
           return eliminados;
        }
}
