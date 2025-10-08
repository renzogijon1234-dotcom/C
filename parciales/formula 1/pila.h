typedef struct
{
    int i,h;
}telementoP;

typedef struct {
  telementoP v[20];
  int n;
}tpila;

void iniciaP(tpila *p);
void sacaP(tpila *p,telementoP *dato);
void poneP(tpila *p,telementoP dato);
void insertarP(tpila *p,telementoP dato);
int vaciaP(tpila p);
