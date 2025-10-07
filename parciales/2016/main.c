#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
typedef struct nodols
{
    char facultad[21];
    Tpila p;
    struct nodols *sig;
}nodols;

typedef struct nodolc
{
    char facultad[21];
    int dni,orden;
    float promedio;
    struct nodolc *sig;
}nodolc;

typedef nodols *tlistaLS;
typedef nodolc *tlistaLC;

void cargaLS(tlistaLS *ls);
tlistaLS buscarf(tlistaLS ls,char facultad[]);
void insertarls(tlistaLS *ls,tlistaLS nuevo);
void retirarT(tlistaLS *ls,tlistaLC *lc);
void eliminarlc(tlistaLC *lc,int dni);
void retirarT(tlistaLS *ls,tlistaLC *lc);
void listadox(tlistaLC lc,char x[]);


int main()
{
    tlistaLS ls=NULL;
    tlistaLC lc=NULL;
    char x[21];
    int dni;
       printf("punto a\n");
       cargaLS(&ls);
       printf("punto b\n");
       retirarT(&ls,&lc);
       printf("punto c\n");
       printf("ingrese el nombre de la facultad \n");
       scanf("%s",x);
       listadox(lc,x);
       printf("punto d\n");
       printf("ingrese el dni\n");
       scanf("%d",&dni);
       eliminarlc(&lc,dni);
       return 0;
}

void cargaLS(tlistaLS *ls)
{
    FILE *arch=fopen("titulos.txt","r");
    TelementoP dato;
    tlistaLS nuevo;
    char facultad[21];
              if (arch==NULL)
                printf("error\n");
              else
              {
                  while (fscanf(arch,"%s %d %f",facultad,&dato.dni,&dato.prom)==3)
                  {
                      printf("%s\n",facultad);
                      nuevo=buscarf(*ls,facultad);
                      if (nuevo==NULL)
                      {
                          nuevo=(tlistaLS)malloc(sizeof(nodols));
                          strcpy(nuevo->facultad,facultad);
                          iniciap(&(nuevo->p));
                          insertarls(ls,nuevo);
                      }
                      ponep(&(nuevo->p),dato);
                  }
              }
              fclose(arch);
}
tlistaLS buscarf(tlistaLS ls,char facultad[])
{
    while (ls!=NULL && strcmp(ls->facultad,facultad))
        ls=ls->sig;
    return ls;
}
void insertarls(tlistaLS *ls,tlistaLS nuevo)
{
    tlistaLS ant,act=*ls;
         while (act!=NULL && strcmp(act->facultad,nuevo->facultad)<0)
         {
             ant=act;
             act=act->sig;
         }
         if (act==*ls)
         {
             nuevo->sig=*ls;
             *ls=nuevo;
         }
         else
         {
             ant->sig=nuevo;
             nuevo->sig=act;
         }
}

void retirarT(tlistaLS *ls,tlistaLC *lc)
{
    Tpila aux;
    tlistaLS ant=NULL,act=*ls;
    TelementoP dato;
    int dni;
    char facultad[21];
    tlistaLC auxlc;
                printf("ingrese la facultad \n");
                while (act!=NULL && strcmp(act->facultad,facultad))
                {
                    ant=act;
                    act=act->sig;
                }
                if (act==NULL)
                    printf("no exsiste\n");
                else
                {
                    iniciap(&aux);
                    printf("ingrese el dni \n");
                    scanf(" %d",&dni);
                    sacap((&(act->p)),&dato);
                    while (!vaciap(act->p) && dato.dni!=dni)
                    {
                        ponep(&aux,dato);
                        sacap((&(act->p)),&dato);
                    }
                    if (dato.dni==dni) {
                        if (vaciap(act->p) && vaciap(aux)) {
                           if (act==*ls)
                              *ls=(*ls)->sig;
                           else
                               ant->sig=act->sig;
                           free(act);
                        }
                            auxlc=(tlistaLC)malloc(sizeof(nodolc));
                            strcpy(auxlc->facultad,facultad);
                            auxlc->dni=dni;
                            auxlc->promedio=dato.prom;
                            if (*lc==NULL)
                            {
                                auxlc->orden=1;
                                auxlc->sig=auxlc;
                                *lc=auxlc;
                            }
                            else
                            {
                                auxlc->orden=(*lc)->orden+1;
                                auxlc->sig=(*lc)->sig;
                                (*lc)->sig=auxlc;
                                *lc=auxlc;
                            }
                    }
                     while (!vaciap(aux))
                            {
                               sacap(&aux,&dato);
                               ponep(&(act->p),dato);
                            }

                }
}

void eliminarlc(tlistaLC *lc,int dni)
{
    tlistaLC ant,act;
         if (*lc!=NULL)
         {
             ant=*lc;
             act=(*lc)->sig;
             while (act!=*lc && act->dni!=dni) {
                ant=act;
                act=act->sig;
             }
             if (act!=dni) {
                printf("orden de entrega %d\n",act->orden);
                if (act==*lc && ant==*lc)
                    *lc=NULL;
                else{
                    ant->sig=act->sig;
                    if (act==*lc)
                        *lc=ant;
                }
                free(act);
             }
         }
}

void listadox(tlistaLC lc,char x[])
{
    float maxprom=-1;
    int maxdni,maxorden;
    tlistaLC aux;
           if (lc!=NULL) {
                aux=lc;
              do
              {
                  aux=aux->sig;
                  if (!strcmp(aux->facultad,x))
                  {
                      printf("%d  %d %1.f \n",aux->dni,aux->orden,aux->promedio);
                      if (aux->promedio > maxprom)
                      {
                          maxprom=aux->promedio;
                          maxdni=aux->dni;
                          maxorden=aux->orden;
                      }
                  }
              } while (aux!=lc);
           }
        if (maxprom==-1)
            printf("no exsiste\n");
        else
            printf(" maximo estudiante %d  %d %1.f\n",aux->dni,aux->orden,aux->promedio);

}
