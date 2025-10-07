#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

typedef struct nodito {
    char fecha[11];
    float precio;
    int cant;
    struct nodito *sig;
}nodito;
typedef nodito *sublista;

typedef struct nodoLS {
 char cod[16];
 float precio,stock,margen;
 sublista sub;
 struct nodoLS *sig;
 }nodoLS;

 typedef nodoLS *tlistaLS;

 typedef struct nodoLD
 {
   char cod[16];
   float stock;
   struct nodoLD *ant,*sig;
 }nodoLD;
 typedef struct
 {
     nodoLD *pri,*ult;
 }tlistaLD;

 void cargaLS(tlistaLS *ls,tlistaLD *ld) ;
void actLS(tlistaLS ls,tcola *c,tlistaLD *ld);
void insertarLS(tlistaLS *ls,tlistaLS aux);
void eliminarLD(tlistaLD *ld,char cod[]);
tlistaLS buscarLS(tlistaLS ls,char cod[]);

int main()
{
    tlistaLS ls;
    tlistaLD ld;
    tcola c;
        ld.pri=NULL;
        ld.ult=NULL;
        actLS(ls,&c,&ld);
        cargaLS(&ls,&ld);
        return 0;
}

void cargaLS(tlistaLS *ls,tlistaLD *ld) {
 FILE *arch=fopen("proveen.txt","r");
 char fecha[11],cod[16];
 tlistaLS aux;
 float cont,precio;
 sublista nuevo;
          if (arch==NULL)
            printf("error\n");
          else {
             fscanf(arch," %s %s %f %f ",fecha , cod ,&cont ,&precio);
             while (!feof(arch)) {
                 if (!strncmp(fecha,"2025/04",7)) {
                     nuevo=(sublista) malloc(sizeof(nodito));
                     strcpy(nuevo->fecha,fecha);
                     nuevo->precio=precio;
                     nuevo->cant=cont;
                     aux=buscarLS(*ls,cod);
                     if (aux==NULL) {
                        aux=(tlistaLS) malloc(sizeof(nodoLS))   ;
                        strcpy(aux->cod,cod);
                        aux->margen=0.5;
                        aux->stock=0;
                        aux->sub=NULL;
                        insertarLS(ls,aux);
                     }
                     aux->precio=precio*(1+aux->margen);
                     aux->stock +=cont;
                     nuevo->sig=aux->sub;
                     aux->sub=nuevo;
                     if (aux->stock>0)
                        eliminarLD(ld,cod);
                 }
                 fscanf(arch," %s %s %f %f ",fecha , cod ,&cont ,&precio);

             }
          }
          fclose(arch);
}

void actLS(tlistaLS ls,tcola *c,tlistaLD *ld)
{
    telementoc dato;
    nodoLD *nuevo;
    tlistaLS aux;
    float ac=0;
    int cont=0;
         while (!vaciaC(*c))
         {
             sacaC(c,&dato);
             aux=buscarLS(ls,dato.cod);
            aux->stock -=dato.cont;
             if (aux->stock > 0)
             {
                 ac +=dato.cont*aux->precio;
                 cont++;
             }
             else {
                 nuevo=(nodoLD*)malloc(sizeof(nodoLD));
                 strcpy(nuevo->cod,dato.cod);
                 nuevo->stock=dato.cont;
                 nuevo->sig=NULL;
                 nuevo->ant=ld->ult;
                 if (ld->pri==NULL && ld->ult==NULL)
                    ld->pri=nuevo;
                 else
                    ld->ult->sig=nuevo;
                 ld->ult=nuevo;
             }
         }
         printf("importe total %f\n",ac);
         ac /=cont;
         printf("promedio %f\n",ac);
}

void insertarLS(tlistaLS *ls,tlistaLS aux)
{
    tlistaLS ant,act=*ls;
         while (act!=NULL && strcmp(act->cod,aux->cod)<0) {
            ant=act;
            act=act->sig;
         }
         aux->sig=act;
         if (act==*ls)
            *ls=aux;
         else
            ant->sig=aux;
}
void eliminarLD(tlistaLD *ld,char cod[])
{
    nodoLD *act=ld->pri,*eliminar;
        while (act!=NULL)
        {
            if (!strcmp(act->cod,cod)) {
                eliminar=act;
                act=act->sig;
                if (eliminar==ld->pri && eliminar==ld->ult)
                {
                    ld->pri=NULL;
                    ld->ult=NULL;
                }
                else
                if (eliminar==ld->pri) {
                    act->ant=NULL;
                    ld->pri=act;
                }
                else
                    if (eliminar==ld->ult) {
                       ld->ult=ld->ult->ant;
                       ld->ult->sig=NULL;
                    }
                    else {
                        eliminar->ant->sig=act;
                        act->ant=eliminar->ant;
                    }
                    free(eliminar);

             }
             else
             act=act->sig;
        }
}

tlistaLS buscarLS(tlistaLS ls,char cod[])
{
    while (ls!=NULL && strcmp(ls->cod,cod))
        ls=ls->sig;
    return ls;
}
