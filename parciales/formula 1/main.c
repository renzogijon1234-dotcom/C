#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#define MAXCOD 4
#define MAXCON 21
#define MAXNOM 31
#define Punto 5
typedef struct nodito
{
    int h;
    char cod[MAXCOD];
    struct nodito *sig;
}nodito;

typedef nodito *sublista;
typedef struct nodoLC
{
    int p;
    sublista sub;
    struct nodoLC *sig;
}nodoLC;


typedef nodoLC *Tlc;

typedef struct nodoLS
{
    char cod[MAXCOD],nom[MAXNOM],con[MAXCON];
    tpila p;
    struct nodoLS *sig;
}nodoLS;
typedef nodoLS *Tls;

void actLC(Tlc lc)
{
  FILE *arch=fopen("MEDICIONES.TXT","r");
  Tlc antLC,nuevo,actLC;
  sublista ant,act,sub;
  int h;
  char cod[MAXCOD];
     nuevo=(Tlc)malloc(sizeof(nodoLC));
     nuevo->p=Punto;
     nuevo->sub=NULL;
       if(arch)
          while (fscanf(arch," %d %s ",&h,cod)==2)
           {
             sub=(sublista)malloc(sizeof(nodito));
             sub->h=h;
             strcpy(sub->cod,cod);
             act=nuevo->sub;
             while (act && act->h < sub->h)
             {
                 ant=act;
                 act=act->sig;
             }
             sub->sig=act;
             if (act==nuevo->sub)
                 nuevo->sub=sub;
             else
                 ant->sig=sub;
           }
          if (lc)
          {
              actLC=lc;
              do {
                 antLC=actLC;
                 actLC=actLC->sig;
              }while (actLC->p < Punto);
              antLC->sig=nuevo;
              nuevo->sig=actLC;
          }
    fclose(arch);

}

Tls buscarTLS(Tls ls,char nom[])
{
    while (ls && strcmp(ls->nom,nom))
        ls=ls->sig;
    return ls;
}
sublista buscarSUB(sublista sub,char cod[])
{
       while (sub && strcmp(sub->cod,cod))
        sub=sub->sig;
    return sub;
}
void cargaLS(Tlc lc,Tls ls,char nom[])
{
    telementoP dato;
    int ant;
    sublista sub;
    ls=buscarTLS(ls,nom);
    if (ls)
    {
        iniciaP(&(ls->p));
        if (lc)
        {
            dato.i=0;
            sub=buscarSUB(lc->sub,ls->cod);
            ant=0;
            while (sub)  {
                if (sub)
                {
                    (dato.i)++;
                    dato.h=sub->h-ant;
                    ant =sub->h;
                    insertarP(&(ls->p),dato);
                    sub=sub->sig;
                }
                sub=buscarSUB(sub,ls->cod);
             }
           }
    }
}

void eliminarX(Tlc lc,Tls ls,char x[])
{
    int i=0;
    Tlc aux;
    char cod[MAXCOD];
    sublista ant,eliminar,act;
    while (i!=2 && ls)
    {
      while (ls && strcmp(ls->con,x))
           ls=ls->sig;
        if (ls) {
            i++;
            strcpy(cod,ls->cod);
            ls=ls->sig;
              aux=lc;
              do{
                   aux=aux->sig;
                   act=aux->sub;
              do {
                   while (act && strcmp(act->cod,cod)){
                       ant=act;
                       act=act->sig;
                     }
                   if (act) {
                      eliminar=act;
                      act=act->sig;
                    if (eliminar==aux->sub)
                        aux->sub=act;
                    else
                        ant->sig=act;
                    free(eliminar);
                }
            }while (act);
            }while (aux!=lc);
        }
    }
}

int main()
{
    Tls ls;
    Tlc lc;
    char x[MAXCON],nom[MAXNOM];
    actLC(lc);
    printf("ingrese el nombre \n");
    scanf("%s ",nom);
    cargaLS(lc,ls,nom);
    printf("ingrese x\n");
    scanf(" %s",x);
    eliminarX(lc,ls,x);
        return 0;
}
