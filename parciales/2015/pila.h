typedef int telementop;
typedef struct
{
    telementop v[100];
    int n;
}tpila;

void sacap(tpila *p,telementop *dato);
void ponep(tpila *p,telementop dato);
int vaciap(tpila p);
void iniciap(tpila *p);
int eliminar(tpila *p,telementop num);

