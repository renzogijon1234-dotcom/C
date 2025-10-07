#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pila.h"
#define d 10

typedef struct nodito
{
    char destino;
    struct nodito *sig;
}nodito;

typedef nodito *sublista;
typedef struct nodo
{
    char cod,nom[31];
    sublista sub;
    struct nodo *ant,*sig;
}nodo;
typedef nodo *tlista;
typedef struct
{
    tlista pri,ult;
}tlistaLD;

void cargaLD(tlistaLD *ld);
tlista buscarC(tlista pri,char cod);
char minC(tlista pri);
char maxC(tlista pri);
void viaje(tlistaLD ld);

int main()
{
    tlistaLD ld;
        cargaLD(&ld);
        viaje(ld);
        return 0;
}

void cargaLD(tlistaLD *ld)
{
    FILE *arch=fopen("inicial.txt","r");
    char cod,nom[31];
    int i,n;
    tlista act;
    sublista nuevo,ant;
          ld->pri=NULL;
          ld->ult=NULL;
          if (arch==NULL)
            printf("error\n");
          else {
               fscanf(arch," %c %s %d",&cod,nom,&n);
               while (!feof(arch)) {
                   act=buscarC(ld->pri,cod);
                   if (act==NULL) {
                      act=(tlista)malloc(sizeof(nodo));
                      act->cod=toupper(cod);
                      strcpy(act->nom,nom);
                      act->sub=NULL;
                      act->sig=NULL;
                      act->ant=ld->ult;
                      if (ld->pri==NULL && ld->ult==NULL)
                        ld->pri=act;
                      else
                          ld->ult->sig=act;
                    ld->ult=act;
                   }
                   ant=act->sub;
                   for (i=1;i<=n;i++){
                      nuevo=(sublista)malloc(sizeof(nodito));
                      fscanf(arch," %c",&(nuevo->destino));
                      nuevo->sig=NULL;
                      if (ant==NULL)
                        act->sub=nuevo;
                      else
                        ant->sig=nuevo;
                      ant=nuevo;
                   }
                   fscanf(arch," %c %s %d",&cod,nom,&n);
               }
          }
          fclose(arch);
}

tlista buscarC(tlista pri,char cod) {
     while (pri!=NULL && pri->cod!=cod)
        pri=pri->sig;
    return pri;
}

char minC(tlista pri) {
  char min='Z',aux;
       while (pri!=NULL) {
            aux=toupper(pri->cod);
           if (aux <min)
              min=aux;
           pri=pri->sig;
       }
      return min;
}

char maxC(tlista pri) {
  char max='A',aux;
       while (pri!=NULL) {
            aux=toupper(pri->cod);
           if (aux >max)
              max=aux;
           pri=pri->sig;
       }
      return max;
}

void viaje(tlistaLD ld)
{
 char parada,min=minC(ld.pri),max=maxC(ld.pri);
 tlista aux;
 int ida=1,incr=1,distancia,contv=0;
 sublista ant,eliminar,act;
 float ac=0;
 tpila p;
           iniciap(&p);
           parada=min;
           while ((parada <= max && ida) || (!ida && parada >= min)){
              aux=buscarC(ld.pri,parada);
              if (aux!=NULL)
              {
                  act=aux->sub;
                  while (act!=NULL && !tope(p)) {
                    ant=act;
                    if ((act->destino >parada && ida) || (act->destino < parada && !ida) ){
                      contv++;
                      eliminar=act;
                      act=act->sig;
                      ponep(&p,eliminar->destino);
                      if (eliminar==aux->sub)
                          if (act==NULL)
                          aux->sub=NULL;
                          else
                          aux->sub=act;
                      else
                          ant->sig=act;
                      distancia=abs(eliminar->destino - parada) *d;
                      ac +=distancia;
                      free(eliminar);
                    }
                    else
                        act=act->sig;
                  }
                  decensop(&p,parada);
              }
              if (parada==max) {
                  ida=0;
                  incr=-1;
              }
              parada +=incr;
           }
           ac /=contv;
           printf("promedio %f\n",ac);
}
