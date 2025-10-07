typedef struct
{
    int dni;
    float prom;
}TelementoP;

typedef struct
{
    TelementoP dato[50];
    int n;
}Tpila;

void iniciap(Tpila *p);
void sacap(Tpila *p,TelementoP *dato);
void ponep(Tpila *p,TelementoP dato);
int vaciap(Tpila p);
