#include "cola.h"

void  iniciaC(tcola *c) {
  c->pri=-1;
  c->ult=-1;
}
void sacaC(tcola *c,telementoc *dato) {
   (c->pri)++;
   *dato=c->v[c->pri];
}
int  vaciaC(tcola c) {
     return c.pri==c.ult;
}
