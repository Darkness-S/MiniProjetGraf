#include <stdio.h>
#include <math.h>
#define BUFFERSIZE 1024

struct TypVoisins{
	int voisin;
	int poid;
	struct TypVoisins* voisinSuivant;
	struct TypVoisins* voisinPrecedent;
};

struct TypGraphe{
   int estOriente;
   int nbMaxSommets;
   struct TypVoisins* listesAdjacences;
};

void insertionSommet(struct TypGraphe *graphe);
void create(struct TypGraphe *graphe, int nb, char oriente);
void creationGraphe(struct TypGraphe *graphe);
void suppressionSommet(struct TypGraphe *graphe);
int voisinExiste(struct TypGraphe *graphe, int sommet, int voisin);
int sommetExiste(struct TypGraphe *graphe, int sommet);
void ajouterArete(struct TypGraphe *graphe, int gauche, int droite, int poid);
void insertionArete(struct TypGraphe *graphe);
int supprArete(struct TypGraphe *graphe, int sommet, int voisin);
int suppressionArete(struct TypGraphe *graphe);
void afficheGraphe(struct TypGraphe *graphe);
int enregistrerGraphe(struct TypGraphe *graphe);
int lectureGraphe(struct TypGraphe *graphe);
