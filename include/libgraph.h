
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
   struct TypVoisins* listesAdjacences;
};


void creationGraphe(struct TypGraphe *graphe){
	printf("-> Création d'un graphe\n");
	
	// Nombre de sommet 
	printf("Nombre de sommet max??\n");
	int nb;
	scanf("%d",&nb);
	
	graphe->nbMaxSommets = nb;
	graphe->listesAdjacences = malloc (nb*sizeof(struct TypVoisins));
	
	// Non-orienté
	graphe->estOriente = 1;
	
}
void insertionSommet(struct TypGraphe *graphe){
	
	// Insertion d'un nouveau sommet
	//printf("Numero du sommet ??\n");
	//int num;
	//scanf("%d",&num);
	
	//if(num > graphe->nbMaxSommets){
	//	printf("Erreur");
	//}
	//else{
		// Création du sommet : Ajout du voisin fictif "-1"
		
		graphe->listesAdjacences++;
		
		while(graphe->listesAdjacences->voisin != NULL){
			graphe->listesAdjacences++;
		}
			
		struct TypVoisins *tmp = malloc(sizeof(struct TypVoisins));
		tmp->voisin = -1;
		
		graphe->listesAdjacences = tmp; 
		//graphe->listesAdjacences[num-1]->voisin = -1;
			
		printf("%d\n",graphe->listesAdjacences->voisin);
			
		// FinSi
	//}
	
	
	
	// TEST :
	
	//graphe->listesAdjacences[0] = malloc(sizeof(struct TypVoisins));
	//graphe->listesAdjacences[1] = malloc(sizeof(struct TypVoisins));
	//graphe->listesAdjacences[2] = malloc(sizeof(struct TypVoisins));
	
	//graphe->listesAdjacences[0]->poid = 12;
	//graphe->listesAdjacences[0]->voisin = 12;
	//graphe->listesAdjacences[0]->voisinSuivant = graphe->listesAdjacences[1];
	//graphe->listesAdjacences[0]->voisinPrecedent = graphe->listesAdjacences[2];
	
	//graphe->listesAdjacences[1]->poid = 1;
	//graphe->listesAdjacences[1]->voisin = 1;
	//graphe->listesAdjacences[1]->voisinSuivant = graphe->listesAdjacences[2];
	//graphe->listesAdjacences[1]->voisinPrecedent = graphe->listesAdjacences[0];
	
	//graphe->listesAdjacences[2]->poid = 3;
	//graphe->listesAdjacences[2]->voisin = 3;
	//graphe->listesAdjacences[2]->voisinSuivant = graphe->listesAdjacences[0];
	//graphe->listesAdjacences[2]->voisinPrecedent = graphe->listesAdjacences[1];
	
	//printf("%d\n",graphe->listesAdjacences[2]->voisinSuivant->poid);
	
}

void afficheGraphe(struct TypGraphe *graphe){
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("# nombre maximum de sommets\n");
	printf("%d\n",graphe->nbMaxSommets);
	printf("# oriente\n");
	if(graphe->estOriente == 0){
		printf("o\n");
	}
	else{
		printf("n\n");
	}
	
	printf("# sommets : voisins\n");
	int i;
	
	while(graphe->listesAdjacences->voisin != NULL){
		
		printf("%d : ",i+1);
		// Parcous et affichage des voisin + le poid
		// printf("tust");
		
		if(graphe->listesAdjacences->voisin == -1){
			printf("()");
		}
		else{
			printf("voisins");
		}
		
		
		graphe->listesAdjacences++;
		
		printf("\n");
		i++;
	}
	
	/*for(i=0; i<graphe->nbMaxSommets; i++){
		printf("%d :",i+1);
		
		//TODO
		if(graphe->listesAdjacences[i]->voisin != NULL){
			printf("tust");
		}
		
		printf("\n");
	}*/
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
}


