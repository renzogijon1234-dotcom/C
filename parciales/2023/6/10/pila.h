#define capacidad 100
typedef struct
{
    int n;
    char v[capacidad];

}tpila;

void iniciap(tpila *p);
void ponep(tpila *p,char dato);
void sacap(tpila *p,char *dato);
int vaciap(tpila p);
int tope(tpila p);
void decensop(tpila *p,char parada);
