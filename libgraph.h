
#include <stdio.h>

struct TypVoisins{
	int voisin;
	int poid;
	struct TypVoisins* voisinSuivant;
	struct TypVoisins* voisinPrecedent;
};

struct TypGraphe{
   int estOriente;
   int nbMaxSommets;
   struct TypVoisins* listesAdjacences[];
};


void creationGraphe(struct TypGraphe *graphe){
	printf("-> Création d'un graphe\n");
	
	
	printf("Nombre de sommet max??\n");
	int nb;
	scanf("%d",&nb);
	
	graphe->nbMaxSommets = nb;
	graphe->estOriente = 0;
	
	// TEST :
	
	graphe->listesAdjacences[0] = malloc(sizeof(struct TypVoisins));
	graphe->listesAdjacences[1] = malloc(sizeof(struct TypVoisins));
	graphe->listesAdjacences[2] = malloc(sizeof(struct TypVoisins));
	
	graphe->listesAdjacences[0]->poid = 12;
	graphe->listesAdjacences[0]->voisin = 12;
	graphe->listesAdjacences[0]->voisinSuivant = &graphe->listesAdjacences[1];
	graphe->listesAdjacences[0]->voisinPrecedent = &graphe->listesAdjacences[2];
	
	graphe->listesAdjacences[1]->poid = 1;
	graphe->listesAdjacences[1]->voisin = 1;
	graphe->listesAdjacences[1]->voisinSuivant = &graphe->listesAdjacences[2];
	graphe->listesAdjacences[1]->voisinPrecedent = &graphe->listesAdjacences[0];
	
	graphe->listesAdjacences[2]->poid = 3;
	graphe->listesAdjacences[2]->voisin = 3;
	graphe->listesAdjacences[2]->voisinSuivant = &graphe->listesAdjacences[0];
	graphe->listesAdjacences[2]->voisinPrecedent = &graphe->listesAdjacences[1];
	
	printf("%d\n",graphe->listesAdjacences[2]->poid);
	
}

void afficheGraphe(struct TypGraphe *graphe){
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("# nombre maximum de sommets\n");
	printf("%d\n",graphe->nbMaxSommets);
	printf("# oriente");
	// TODO
	
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
}


