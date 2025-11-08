#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 3
typedef struct nodoB {
    int dato;
    struct nodoB *izq;
    struct nodoB *der;
} *arbol;

typedef struct nodoG {
    char info;
    struct nodoG *hijoIzq;
    struct nodoG *herDer;
} *arbolG, *posicion;

typedef struct {
 int vertice , gr ;
}Tdato;

//funciones para crear el arbol y arbolG
arbol crearNodoB(int x);
arbol crearArbolBinarioEjemplo();
int grado(arbol a);
int val(arbol a, int GrRaiz);
int cumple(arbol a);
posicion crearNodoG(char x);
arbolG crearArbolGEjemplo();

int Nulo(posicion p);
posicion HijoMasIzquierda(posicion p, arbolG a);
posicion HermanoDer(posicion p, arbolG a);
char info(posicion p, arbolG a);

// funciones del parcial

int grado(arbol a);
int suma(arbol a, int k);
int buscar(arbolG a , posicion p);
int EsVocal(char dato);
void crearV(int m[][MAX] , int n , Tdato v[], int *k , int gr ,int i , int j) ;


int main()
{
    arbol a = crearArbolBinarioEjemplo();
    arbolG ag = crearArbolGEjemplo();
    int k = 0 , n = MAX - 1;
    int m[MAX][MAX] = {
    {1 , 1 , 1} ,
    {1 , 0 , 1} ,
    {1 , 1 , 0}
    };
    Tdato v[MAX];
    crearV(m, n , v, &k , 0 , n , n);
    printf(" punto 1) %d\n",suma(a, 2));
    printf(" punto 2) %d \n",buscar(ag,ag));
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
int suma(arbol a, int k)
{
    if ( a == NULL || k < 0)
        return 0;
    else
        if (grado(a->izq) % 2 == 1)
          return a->dato + suma(a->izq, k - 1) + suma(a->der , k);
        else
          return suma(a->izq, k - 1) + suma(a->der , k);

}

int buscar(arbolG a , posicion p) {
 int cumple = 0, gr = 0;
 posicion c;
   if (!Nulo(p)) {
     c = HijoMasIzquierda(p,a);
     if (!Nulo(c)) {
        cumple = EsVocal(info(p,a));
        while ( !Nulo(c) && cumple) {
            gr ++ ;
            cumple = EsVocal(info(c,a));
            c = HermanoDer(c,a);
        }
        if ( cumple == 0 || gr % 2 == 1)
            cumple = buscar(a,HijoMasIzquierda(p,a)) || buscar(a,HermanoDer(p,a));

     }
     else
        cumple = buscar(a ,HermanoDer(p,a));
   }
   return cumple && gr % 2 == 0;
}

int EsVocal(char dato) {
 dato = toupper(dato);
 return dato =='A' || dato =='E' || dato =='I' || dato == 'O' || dato == 'U';
}

void crearV(int m[][MAX] , int n , Tdato v[], int *k , int gr ,int i , int j) {
 if ( i >= 0)
     if (m[i][i] == 0)
        crearV(m, n , v, k ,0 ,i-1, n);
     else
     if (j < 0) {
        (*k)++;
        v[*k].vertice = i;
        v[*k].gr = gr;
        crearV(m, n , v, k , 0 , i-1 , n);
     }
     else
        crearV(m , n , v ,k , gr + (m[i][j] != 0), i, j-1);
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

char info(posicion p, arbolG a) {
    if (p != NULL)
        return p->info;
    else
        return ' ';
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

posicion crearNodoG(char x) {
    posicion nuevo = (posicion)malloc(sizeof(struct nodoG));
    nuevo->info = x;
    nuevo->hijoIzq = NULL;
    nuevo->herDer = NULL;
    return nuevo;
}

arbolG crearArbolGEjemplo() {
    arbolG raiz = crearNodoG('a');
    raiz->hijoIzq = crearNodoG('e');
    raiz->hijoIzq->herDer = crearNodoG('i');
    raiz->hijoIzq->hijoIzq = crearNodoG('e');
    raiz->hijoIzq->hijoIzq->herDer = crearNodoG('f');

    return raiz;
}

