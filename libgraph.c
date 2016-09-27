
#include <stdio.h>

struct TypVoisins{
	int voisin;
	int poid;
	TypVoisins *voisinSuivant;
	TypVoisins *voisinPrecedent;
};

struct TypGraphe{
   int estOriente;
   int nbMaxSommets;
   TypVoisins *listesAdjacences[];
};


