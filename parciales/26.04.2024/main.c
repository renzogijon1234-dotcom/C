#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

typedef struct nodols {
 char dom[8],fecha[9],hora[6];
  struct nodols *sig;
}nodols;

typedef struct nodito {
  char dom[8];
   int cont;
   struct nodito *sig;
}nodito;

typedef nodito *sublista;

typedef struct nodold {
 char puesto[4];
 sublista sub;
 struct nodold *ant,*sig;
 }nodold;

 typedef struct {
  nodold *pri,*ult;
}tlistald;

typedef nodols *tlistals;

void eliminarLT(tlistals *lt);
int validar(tlistals act);
void cargaSUB(tlistals lt,tlistald pa,tcola *c);
int contp(nodold *aux);
int valLT(tlistals lt,char dom[]);
nodold *buscar(nodold *aux,char puesto[]);
void cargaLD(tlistald pa);
void cargaPA(tlistald *pa);
void cargaLS(tlistals *lt);
void cargaC(tcola *c);

int main()
{
    tlistals lt;
    tlistald pa;
    tcola c;
        cargaPA(&pa);
        cargaLS(&lt);
        cargaC(&c);
        eliminarLT(&lt);
        cargaSUB(lt,pa,&c);
        cargaLD(pa);
        return 0;
}


void eliminarLT(tlistals *lt) {
 tlistals ant,eliminar,act=*lt;
 float ac=0;
 int n=0;
          while (act!=NULL) {
             n++;
             if (!validar(act))
             {
                 ac++;
                 eliminar=act;
                 act=act->sig;
                 if (eliminar==*lt)
                    *lt=act;
                 else
                    ant->sig=act;
                 free(eliminar);
             }
             else {
                ant=act;
                act=act->sig;
             }
          }
          ac /=(n!=0)? n:1;
          printf("promedio %f \n",ac);
}
int validar(tlistals act)
{
    char car;
        if (act->fecha[4]=='1' && act->fecha[5]!='0')
            return 1;
        else
        {
            car=act->dom[strlen(act->dom)-1];
            return (act->fecha[5]==car);
        }
}
void cargaSUB(tlistals lt,tlistald pa,tcola *c)
{
    telementoc dato;
    tcola auxc;
    int n,pos,i,val,rech=0;
    sublista ant,act,nuevo;
    nodold *aux;
          n=contp(pa.pri);
          iniciac(&auxc);
          while (!vaciac(*c))
          {
              sacac(c,&dato);

              val=valLT(lt,dato.dom);
              if (val==1)
              {
                  pos=rand()%n+1;
                  aux=pa.pri;
                  for (i=1;i<pos;i++)
                    aux=aux->sig;
                  nuevo=(sublista)malloc(sizeof(nodito));
                  strcpy(nuevo->dom,dato.dom);
                  nuevo->cont=0;
                  act=aux->sub;
                  while (act!=NULL) {
                    ant=act;
                    act=act->sig;
                  }
                  nuevo->sig=act;
                  if (act==aux->sub)
                    aux->sub=nuevo;
                  else
                    ant->sig=nuevo;
              }
              else {
                  rech++;
                  if (!val)
                    ponec(&auxc,dato);
                  else
                    printf("%s\n",dato.dom);
              }
          }
          while (!vaciac(auxc))
          {
              sacac(&auxc,&dato);
              ponec(c,dato);
          }
}


int contp(nodold *aux)
{
    int n=0;
       while (aux!=NULL) {
          n++;
          aux=aux->sig;
       }
       return n;
}



int valLT(tlistals lt,char dom[])
{
    while (lt!=NULL && strcmp(lt->dom,dom)<0) {
        lt=lt->sig;
    }

    if (lt==NULL || strcmp(lt->dom,dom) )
        return -1;
    else
        return lt->fecha[5]=='4';
}


nodold *buscar(nodold *aux,char puesto[])
{
    while (aux!=NULL && strcmp(aux->puesto,puesto)<0)
        aux=aux->sig;
    return (aux!=NULL && !strcmp(aux->puesto,puesto)) ? aux:NULL;
}


void cargaLD(tlistald pa)
{
    FILE *arch=fopen("testeo.txt","r");
    nodold *aux;
    sublista ant,eliminar,act;
    char puesto[4],dom[8],car;
    int cant ;
         if (arch==NULL)
            printf("error\n");
         else
            while (fscanf(arch," %s %s %d %c ",puesto,dom,&cant,&car)==4) {
                aux=buscar(pa.pri,puesto);
                if (aux!=NULL) {
                    act=aux->sub;
                    while (act!=NULL && strcmp(act->dom,dom))
                           {
                               ant=act;
                               act=act->sig;
                           }
                    if (act!=NULL)
                        if (car=='R') {
                            eliminar=act;
                            act=act->sig;
                            if (eliminar ==aux->sub)
                                aux->sub=act;
                            else
                                ant->sig=act;
                            free(eliminar);
                        }
                        else
                            act->cont+=cant;
                }
            }
            fclose(arch);
}
void cargaPA(tlistald *pa)
{
    int i, N=3; // Ejemplo: 3 puestos, podés cambiarlo
    nodold *nuevo, *ant=NULL;

    pa->pri = pa->ult = NULL;

    for (i=1;i<=N;i++) {
        nuevo = (nodold*)malloc(sizeof(nodold));
        sprintf(nuevo->puesto,"P%02d",i); // P01, P02, P03
        nuevo->sub = NULL;
        nuevo->ant = ant;
        nuevo->sig = NULL;

        if (pa->pri==NULL)
            pa->pri = nuevo;
        else
            ant->sig = nuevo;

        pa->ult = nuevo;
        ant = nuevo;
    }
}

void cargaLS(tlistals *lt)
{
    FILE *arch;
    char dom[8], fecha[9], hora[6];

    *lt = NULL;
    arch = fopen("turnos.txt","r");
    if (arch == NULL) {
        printf("Error al abrir turnos.txt\n");
    } else {
        while (fscanf(arch," %7s %8s %5s", dom, fecha, hora) == 3) {
            nodols *nuevo = (nodols*)malloc(sizeof(nodols));
            strcpy(nuevo->dom, dom);
            strcpy(nuevo->fecha, fecha);
            strcpy(nuevo->hora, hora);
            nuevo->sig = NULL;

            // insertar ordenado
            nodols *ant = NULL, *act = *lt;
            while (act != NULL && strcmp(act->dom, dom) < 0) {
                ant = act;
                act = act->sig;
            }

            nuevo->sig = act;
            if (ant == NULL) {
                // insertar al principio
                *lt = nuevo;
            } else {
                // insertar entre ant y act
                ant->sig = nuevo;
            }
        }
        fclose(arch);
    }
}


void cargaC(tcola *c)
{
    FILE *arch = fopen("cola.txt","r");
    telementoc dato;

    iniciac(c);

    if (arch==NULL) {
        printf("Error al abrir cola.txt\n");
        return;
    }

    while (fscanf(arch," %s",dato.dom)==1) {
        ponec(c,dato);
    }

    fclose(arch);
}
