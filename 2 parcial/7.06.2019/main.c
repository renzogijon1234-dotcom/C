#include <stdio.h>
#include <stdlib.h>

typedef char TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void buscar(arbol a, int niv , int *maxNiv, char *sup) ;

void addnodo(arbol* a, TElememtoA e);

int main(){
 arbol a;
 char sup = ' ';
 int maxniv = -1;
 /* carga arbol ejemplo. Ej 1 */
 addnodo(&a, 'd');
 addnodo(&a->izq, 'b');
 addnodo(&a->izq->izq, 'a');
 addnodo(&a->izq->der, 'c');

 addnodo(&a->der, 'f');
 addnodo(&a->der->izq, 'e');
 addnodo(&a->der->izq->der, 'g');
 buscar(a,1,&maxniv,&sup);
 printf("%c",sup);
 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
void buscar(arbol a, int niv , int *maxNiv, char *sup) {
 if (a != NULL) {
 if (a->izq != NULL && a->der != NULL && niv > *maxNiv ) {
    *maxNiv = niv;
    *sup = a->dato;
 }
    buscar(a->izq, niv + 1, maxNiv , sup);
    buscar(a->der, niv + 1, maxNiv , sup);
 }
}

int ContN(arbolG a , posicion p , int niv , int k1 ,int k2 ) {
 int aux = 0 , gr = 0;
    if ( !nulo(p) && niv <= k2) {
        c = HijoMasIzquierda(p,a);
        if ( !nulo(c))
          if (info(c,a) > info(p,a) && niv >= k1) {
            while (HermanoDer(c,a) != NULL) {
                gr ++;
                aux +=ContN(a,c , niv +1 , k1 , k2);
                c = HermanoDer(c,a);
            }
            gr ++;
            aux +=ContN(a,c,niv +1 , k1 , k2);
            aux += gr > 1 && info(c,a) > info(p,a);
          }
          else
            while (!nulo(c)) {
                aux +=ContN(a,c ,niv +1 , k1 , k2);
                c = HermanoDer(c,a);
            }
    }
    return aux;
}

void amplitud(int m[][MAX] , int n ) {
    Tcola c;
    int vv[n] , k = 1 , i , j;
     iniciaC(&c);
      iniciaV(vv, n );
      vv[0] = 1;
       poneC(&c,0);
       while ( k < n && !vacia(c)) {
            sacaC(&c,&i);
           for (j = 0 ; j < n ; j++)
            if (m[i][j] > 0 && vv[j] == 0) {
                k ++;
                vv[j] = 1;
                 poneC(&c,j);
            }
        }
      if (k < n)
        printf(" el grafo no es conexo\n");
      else
        printf(" el grafo es conexo\n");
}
