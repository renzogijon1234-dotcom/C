#include "pila.h"

void iniciaP(tpila *p)
{
    p->n=-1;
}
void sacaP(tpila *p,telementoP *dato)
{
    *dato=p->v[p->n];
    (p->n)--;
}
void poneP(tpila *p,telementoP dato){
  (p->n)++;
  p->v[p->n]=dato;
}
void insertarP(tpila *p,telementoP dato)
{
telementoP aux;
   if (!vaciaP(*p))
   {
       sacaP(p,&aux);
       if (aux.h < dato.h)
          poneP(p,dato);
       else
          insertarP(p,dato);
       poneP(p,aux);
   }
   else
      poneP(p,dato);
}
int vaciaP(tpila p)
{
    return p.n==-1;
}
