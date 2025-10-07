
typedef struct {
    char dom[8];
}telementoc;

typedef struct {
   telementoc v[100];
   int pri,ult;
}tcola;


void iniciac(tcola *c);
void ponec(tcola *c,telementoc dato);
void sacac(tcola *c,telementoc *dato);
int vaciac(tcola c);
