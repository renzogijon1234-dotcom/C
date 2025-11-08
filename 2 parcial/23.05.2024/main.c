#include <stdio.h>
#include <stdlib.h>
#define MAX 3
typedef struct nodoB {
    int dato;
    struct nodoB *izq;
    struct nodoB *der;
} *arbol;

typedef struct nodoG {
    int info;
    struct nodoG *hijoIzq;
    struct nodoG *herDer;
} *arbolG, *posicion;

//funciones para crear el arbol y arbolG
arbol crearNodoB(int x);
arbol crearArbolBinarioEjemplo();
int grado(arbol a);
int val(arbol a, int GrRaiz);
int cumple(arbol a);
posicion crearNodoG(int x);
arbolG crearArbolGEjemplo();

int Nulo(posicion p);
posicion HijoMasIzquierda(posicion p, arbolG a);
posicion HermanoDer(posicion p, arbolG a);
int info(posicion p, arbolG a);

//fin
// punto 1
int grado(arbol a) ;
int val(arbol a , int GrRaiz);
int cumple(arbol a);
// punto 3
int contV(int m[][MAX] , int n , int i , int j , int gr) ;
//punto 2
int gradoAG(arbolG a , posicion p ) ;
int buscar(arbolG a, posicion p);

int main()
{
    arbol a = crearArbolBinarioEjemplo();
    arbolG g = crearArbolGEjemplo();
    int m[MAX][MAX] = {
    {1 , 1 , 1} ,
    {1 , 0 , 1} ,
    {1 , 1 , 0}
    };

    printf("punto 1) %d punto 2) %d   punto 3) %d !\n",cumple(a),buscar(g,g),contV(m,MAX - 1,MAX - 1 , 0 , 0));
    return 0;
}

int grado(arbol a) {
int gr = 0;
   while ( a!= NULL) {
      gr ++;
      a = a->der;
   }
   return gr;
}
int val(arbol a , int GrRaiz) {
 if (a == NULL)
    return 1;
  else
     if (grado(a->izq) > GrRaiz)
       return 0;
      else
        return val(a->izq, GrRaiz) && val(a->der,GrRaiz);
}
int cumple(arbol a) {
  while ( a != NULL && val(a,grado(a->izq)))
         a = a->der;
  return a == NULL ;
}

int contV(int m[][MAX] , int n , int i , int j , int gr) {
 int incr = 0;
    if ( i >= 0)
        if (m[i][i] == 0 || (j < 0 && gr))
            incr = contV(m, n , i - 1 , n, 0);
        else
            if (j < 0 && gr == 0)
              incr = 1 + contV(m, n , i - 1 , n, 0);
            else
              incr = contV(m, n , i , j - 1, gr + (m[j][i] != 0) - (m[i][j] != 0));
   return incr ;
}

int gradoAG(arbolG a , posicion p ) {
 int gr = 0;
    if ( !Nulo(p)) {
        p = HijoMasIzquierda(p,a);
        while (!Nulo(p)) {
            gr ++;
            p = HermanoDer(p,a);
        }
    }
    return gr ;
}
int buscar(arbolG a, posicion p) {
 int gr = -1 , grAux , cumple = 0;
 posicion c;
   if ( !Nulo(p)) {
     c = HijoMasIzquierda(p,a);
     if (!Nulo(c)) {
        cumple = 1;
        while ( !Nulo(c) && cumple) {
            grAux = gradoAG(a,c);
            if (grAux >= gr)
                gr = grAux;
            else
                cumple = 0;
            c = HermanoDer(c,a);
        }
        if ( cumple == 0)
            cumple = buscar(a,HijoMasIzquierda(p,a)) || buscar(a,HermanoDer(p,a));
     }
     else
          cumple = buscar(a,HermanoDer(p,a)) ;
   }
   return cumple;
}



// no prestar atencion a los siguiente o tendra cancer

int Nulo(posicion p) {
    return p == NULL;
}

posicion HijoMasIzquierda(posicion p, arbolG a) {
    if (p != NULL)
        return p->hijoIzq;
    else
        return NULL;
}

posicion HermanoDer(posicion p, arbolG a) {
    if (p != NULL)
        return p->herDer;
    else
        return NULL;
}

int info(posicion p, arbolG a) {
    if (p != NULL)
        return p->info;
    else
        return 0;
}

arbol crearNodoB(int x) {
    arbol nuevo = (arbol)malloc(sizeof(struct nodoB));
    nuevo->dato = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

arbol crearArbolBinarioEjemplo() {
    arbol a = crearNodoB(5);
    a->izq = crearNodoB(3);
    a->der = crearNodoB(8);
    a->izq->izq = crearNodoB(1);
    a->izq->der = crearNodoB(4);
    return a;
}

posicion crearNodoG(int x) {
    posicion nuevo = (posicion)malloc(sizeof(struct nodoG));
    nuevo->info = x;
    nuevo->hijoIzq = NULL;
    nuevo->herDer = NULL;
    return nuevo;
}

arbolG crearArbolGEjemplo() {
    arbolG raiz = crearNodoG(10);
    raiz->hijoIzq = crearNodoG(5);
    raiz->hijoIzq->herDer = crearNodoG(8);
    raiz->hijoIzq->herDer->herDer = crearNodoG(12);

    raiz->hijoIzq->hijoIzq = crearNodoG(3);
    raiz->hijoIzq->hijoIzq->herDer = crearNodoG(4);

    return raiz;
}
