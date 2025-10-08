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
    tlista antld,nuevoLD,act;
    sublista nuevo,ant;
          ld->pri=NULL;
          ld->ult=NULL;
          if (arch==NULL)
            printf("error\n");
          else {
               fscanf(arch," %c %s %d",&cod,nom,&n);
               while (!feof(arch)) {
                   act=ld->pri;
                   while (act!=NULL && act->cod <cod)
                   {
                       antld=act;
                       act=act->sig;
                   }
                   if (act==NULL) {
                      nuevoLD=(tlista)malloc(sizeof(nodo));
                      nuevoLD->cod=toupper(cod);
                      strcpy(nuevoLD->nom,nom);
                      nuevoLD->sub=NULL;
                      if (ld->pri==NULL && ld->ult==NULL) {
                        nuevoLD->sig=NULL;
                        nuevoLD->ant=NULL;
                        ld->pri=nuevoLD;
                        ld->ult=nuevoLD;
                      }
                      else
                      {
                          antld->sig=nuevoLD;
                          nuevoLD->ant=antld;
                          nuevoLD->sig=act;
                          if (act)
                            act->ant=nuevoLD;

                      }
                      act=nuevoLD;
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

void viaje(tlistaLD ld)
{
 char parada;
 tlista aux=ld.pri;
 int ida=1,distancia,contv=0;
 sublista ant,eliminar,act;
 float ac=0;
 tpila p;
           iniciap(&p);
           parada=ld.pri->cod;
           while (aux){
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
              if (ida)
                aux=aux->sig;
              else
                aux=aux->ant;
              if (!aux && ida) {
                  ida=0;
                  aux=ld.ult;
              }
              if (aux && parada !=aux->cod)
                parada=aux->cod;
        }
           ac /=contv;
           printf("promedio %.2f\n",ac);
}
