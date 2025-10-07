


typedef int telementoc;
typedef struct {
   telementoc v[100];
   int pri,ult;
}tcola;


void iniciaC(tcola *c);
void poneC(tcola *c,telementoc dato);
void sacaC(tcola *c,telementoc *dato);
int vaciaC(tcola c);
