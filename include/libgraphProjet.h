#include "./libgraph.h" 
typedef struct {
    int prio;
    int sommet;
}nodeFilePrio;
 
typedef struct {
    nodeFilePrio *nodes;
    int lon;
    int taille;
}filePrio;

void sommetAleatoire(struct TypGraphe *graphe ,int n, int graine, int x[], int y[]);
void afficheCoordonee(int x[], int y[],int n);
void creationArrete(struct TypGraphe *graphe, int n, int x[], int y[]);
void push (filePrio *f, int prio, int sommet);
int pop (filePrio *f);
void pushBestVoisin(filePrio *f, struct TypGraphe *graphe,int num);
int taille(int *V);
void change(int *V,int x, int ta);
void ajouteListeParcour(int* liste, int *prefixe, int tprefixe, int x, int cpt);
unsigned long factorial(unsigned long f);
void fctRec( int *l, int *t, int* t2, int n, int k);
void commence(int* t,int n);
float retournePoid(struct TypGraphe *graphe,int gauche, int droite);
void solution_exacte(struct TypGraphe *graphe);
void solutionPlusProcheVoisin(struct TypGraphe *graphe, int sommetDepart);
void solutionPlusPetitDetour(struct TypGraphe *graphe, int s1, int s2, int s3);
void ajoutDansTableau(int *tableau, int tailleTableau, int indiceAjout, int sommetAAjouter);
int estDans(struct TypGraphe *graphe,int *V, int x, int ta);
int extraireMin(struct TypGraphe *graphe, int *F, int tf, int x);
void solution_ARPM(struct TypGraphe *graphe);
