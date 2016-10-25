
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
	graphe->listesAdjacences = malloc (sizeof(struct TypVoisins*));
	
	int i=0;
	
	struct TypVoisins *tab = malloc(sizeof(struct TypVoisins));;
	while (i<nb){
		struct TypVoisins *tmpVoisin = malloc(sizeof(struct TypVoisins));
		tab =  tmpVoisin;
		tab++;
		i++;
	}
	graphe->listesAdjacences = tab;
	
	// Non-orienté
	graphe->estOriente = 1;
	
}
void insertionSommet(struct TypGraphe *graphe){
	
	// Insertion d'un nouveau sommet
	//printf("Numero du sommet ??\n");
	
	
	//if(num > graphe->nbMaxSommets){
	//	printf("Erreur");
	//}
	//else{
		// Création du sommet : Ajout du voisin fictif "-1"
		
		//struct TypVoisins *VoisinTemp=malloc(sizeof(struct TypVoisins));
		//VoisinTemp->voisin = -1;
		/*while(graphe->listesAdjacences->voisin != NULL){
		
			graphe->listesAdjacences++;
			
		}*/
		int i=0;
		for(i=0; i<graphe->nbMaxSommets;i++){
			if(graphe->listesAdjacences[i].voisin == 0 ){
				graphe->listesAdjacences[i].voisin = -1;
				break;
			}
		}
		
		//graphe->listesAdjacences->voisin = -1;
		printf("%d\n",graphe->listesAdjacences->voisin);
		//g
		
		
		//while( graphe->listesAdjacences->voisin != NULL){
			
			//graphe->listesAdjacences++;
		//}
		
		
		
		
		//graphe->listesAdjacences++;
		
			
		//struct TypVoisins *tmp = malloc(sizeof(struct TypVoisins));
		//tmp->voisin = -1;
		
		
		//graphe->listesAdjacences[num-1]->voisin = -1;
			
		
		//graphe->listesAdjacences++;
			
		
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

void suppressionSommet(struct TypGraphe *graphe){
	//printf("Numero de sommet à supprimer : \n");
	//int num;
	//scanf("%d",&num);
	
	//if(num>0 && num<graphe->nbMaxSommets){
		
		//graphe->listesAdjacences[num-1];
		
		
		
	//}
	//else{
	//	printf("Erreur \n");
	//}
	
	
	struct TypVoisins *listes;
	listes = graphe->listesAdjacences;
	
	int i=0;
	while(listes->voisin != NULL){	
		listes++;
		i++;
	}
	
	// Suppression du noeud
	//graphe->listesAdjacences[i]= malloc(sizeof(struct TypVoisins));;
	

	
	
	
}

void insertionArete(struct TypGraphe *graphe){
	printf("Numero de l'extremiter gauche : \n");
	int gauche;
	int droite;
	scanf("%d",&gauche);
	printf("Numero de l'extremiter droite : \n");
	scanf("%d",&droite);
	
	
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
	struct TypVoisins* listes;
	listes = graphe->listesAdjacences;
	
	
	listes++;
	while(listes->voisin != NULL){
		
		printf("%d : ",i+1);
		
		printf("%d ",listes->voisin);
		
		if(listes->voisin == -1){
			printf("()");
		}
		else{
			printf("voisins");
			
			// TODO - Affichage des voisin
		}
		
		
		listes++;
		
		printf("\n");
		i++;
	}
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
}


