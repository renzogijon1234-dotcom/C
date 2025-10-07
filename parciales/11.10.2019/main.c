#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#define MAXN 20
#define MAXM 50

typedef struct nodito
{
    int nume;
    char fecha[9],rec;
    struct nodito *sig;
}nodito;

typedef nodito *sublista;

typedef struct nodo
{
    int norma,conte;
    char nombre[9];
    sublista sub;
    struct nodo *sig;
}nodo;

typedef nodo *tlistaLS;

void crearLS(tlistaLS *ls);
void insertarSUB(sublista *pri,sublista nuevo);
int buscar(sublista sub,int num);
void mostrar(tlistaLS ls);
void crearM(tlistaLS ls,char m[][MAXM]);
void crearC(char m[][MAXM],int x,tcola *c,int i,int j,int cont,int contE);
void buscarC(tcola *c,int *val,int num);
void eliminar(tlistaLS ls,tcola *c,int num);


int main()
{
    tlistaLS ls;
    tcola c;
    int num,x;
    char m[MAXN][MAXM];
      crearLS(&ls);
      mostrar(ls);
      crearM(ls,m);
      printf("ingrese x\n");
      scanf(" %d",&x);
      crearC(m,x,&c,MAXN-1,MAXM-1,0,0);
      printf("ingrese nume\n");
      scanf(" %d",&num);
      eliminar(ls,&c,num);
    printf("Hello world!\n");
    return 0;
}


void crearLS(tlistaLS *ls)
{
    FILE *arch=fopen("CARGAACTUAL.txt","r");
    tlistaLS nuevo,act;
    sublista nuevoSub;
    char nom[9];
    int norma,conte,i;
        *ls=NULL;
        act=*ls;
         if (arch==NULL)
            printf("error\n");
         else
            while (fscanf(arch," %d %s %d ",&norma,nom,&conte)==3)
         {
             nuevo=(tlistaLS)malloc(sizeof(nodo));
             strcpy(nuevo->nombre,nom);
             nuevo->norma=norma;
             nuevo->conte=conte;
             nuevo->sub=NULL;
             nuevo->sig=NULL;
             for (i=0;i<conte;i++)
             {
                 nuevoSub=(sublista)malloc(sizeof(nodito));
                 fscanf(arch," %d %s %c ",&(nuevoSub->nume),nuevoSub->fecha,&(nuevoSub->rec));
                 insertarSUB(&(nuevo->sub),nuevoSub);

             }
              if (*ls==NULL)
                *ls=nuevo;
              else
                act->sig=nuevo;
              act=nuevo;
         }
         fclose(arch);
}
void insertarSUB(sublista *pri,sublista nuevo)
{
    sublista ant,act=*pri;
      while (act!=NULL && act->nume < nuevo->nume)
      {
          ant=act;
          act=act->sig;
      }
      nuevo->sig=act;
      if (act==*pri)
        *pri=nuevo;
      else
        ant->sig=nuevo;
}
int buscar(sublista sub,int num)
{
      while (sub!=NULL && sub->nume < num)
        sub=sub->sig;
      return (sub && sub->nume==num);

}
void mostrar(tlistaLS ls)
{
    int i,n,maxcont=-1,maxe,cont,num;
    tlistaLS aux;
          printf("ingrese n\n");
          scanf(" %d",&n);
          for (i=0;i<n;i++)
          {
              cont=0;
              aux=ls;
              printf("ingrese num\n");
              scanf(" %d",&num);
              while (aux!=NULL)
              {
                  cont +=buscar(aux->sub,num);
                  aux=aux->sig;
              }
              if (cont >maxcont)
              {
                  maxcont=cont;
                  maxe=num;
              }
              printf(" %d %d \n",num,cont);
          }
        printf(" %d %d \n",maxe,maxcont);

}
void crearM(tlistaLS ls,char m[][MAXM])
{
    int i,j;
    sublista aux;
    char car;
        for (i=0;i<MAXN;i++)
        {
            if (ls!=NULL) {
                aux=ls->sub;
                ls=ls->sig;
            }
            else
                aux=NULL;
            for (j=0;j<MAXM;j++)
            {
                if (aux!=NULL)
                {
                    car=aux->rec;
                    aux->sig;
                }
                else
                    car='N';
                m[i][j]=car;
            }
        }
}
void crearC(char m[][MAXM],int x,tcola *c,int i,int j,int cont,int contE)
{
  telementoc dato;
    if (j==-1) {
        printf(" contador %d \n",contE);
        iniciaC(c);
      }
    else
          if (cont>=x) {
           dato=j;
           crearC(m,x,c,MAXN-1,j-1,0,contE+1);
           poneC(c,dato);
          }
          else
          if (i==-1)
            crearC(m,x,c,MAXN-1,j-1,0,contE);
           else {
                cont+=m[i][j]=='S';
                crearC(m,x,c,i-1,j,cont,contE);
           }
}
void buscarC(tcola *c,int *val,int num)
{
    tcola aux;
    telementoc dato;
         iniciaC(&aux);
         *val=0;
         while (!vaciaC(*c) && !(*val))
         {
             sacaC(c,&dato);
             poneC(&aux,dato);
             *val=dato==num;
         }
        while (!vaciaC(aux))
         {
             sacaC(&aux,&dato);
             poneC(c,dato);
         }
}
void eliminar(tlistaLS ls,tcola *c,int num)
{
    int val;
    sublista ant,eliminar,act;
         buscarC(c,&val,num);
         if (val)
         {
             while (ls==NULL)
             {
                 act=ls->sub;
                 while (act!=NULL && act->nume< num)
                 {
                     ant=act;
                     act=act->sig;
                 }
                 if (act!=NULL && act->nume==num && act->rec=='N')
                 {
                     eliminar=act;
                     act=act->sig;
                     if (eliminar==ls->sub)
                        ls->sub=act;
                     else
                        ant->sig=act;
                     free(eliminar);
                 }
                 ls=ls->sig;
             }
         }
}
