#include "../include/libgraph.h" 

void insertionSommet(struct TypGraphe *graphe){	
	int i=0;
	for(i=0; i<graphe->nbMaxSommets;i++){
		if(graphe->listesAdjacences[i].voisin == 0 ){
			graphe->listesAdjacences[i].voisin = -1;
			break;
		}
	}
}
	
void create(struct TypGraphe *graphe, int nb, char oriente){	
	graphe->nbMaxSommets = nb+1;
	graphe->listesAdjacences = malloc (sizeof(struct TypVoisins*));	
	int i=0;	
	struct TypVoisins *tab = malloc(sizeof(struct TypVoisins));;
	while (i<nb+2){
		struct TypVoisins *tmpVoisin = malloc(graphe->nbMaxSommets*2*sizeof(struct TypVoisins));
		tab =  tmpVoisin;
		tab++;
		i++;
	}
	graphe->listesAdjacences = tab;	
	// Non-orienté
	if(oriente == 'o'){
		graphe->estOriente = 0;
	}else{
		graphe->estOriente = 1;
	}
	insertionSommet(graphe);
}

void creationGraphe(struct TypGraphe *graphe){
	printf("-> Création d'un graphe\n");	
	// Nombre de sommet 
	printf("Nombre de sommet max?\n");
	int nb;
	char oriente= 'n';
	scanf("%d",&nb);
	printf("Le graphe est-il orienté? (o/n)\n");
	scanf("%c",&oriente);
	scanf("%c",&oriente);
	create(graphe,nb,oriente);
}

void suppressionSommet(struct TypGraphe *graphe){	
	struct TypVoisins *listes;
	listes = graphe->listesAdjacences;	
	struct TypVoisins *tmp= malloc(sizeof(struct TypVoisins));	
	int i=0;
	while(listes->voisin != NULL){	
		tmp = listes;		
		tmp++;
		listes++;
		i++;
	}	
	int j=0;
	while(j<i-1){
		tmp[j]  = graphe->listesAdjacences[j];
		j++;
		
	}	
	graphe->listesAdjacences = tmp;	
}

int voisinExiste(struct TypGraphe *graphe, int sommet, int voisin){
	struct TypVoisins *listes;
	struct TypVoisins *vtmp = malloc(sizeof(struct TypVoisins));
	listes = graphe->listesAdjacences;
	listes++;
	int i=1;
	int done = 0;
	int res = 1;
	while(listes->voisin != NULL && done == 0 ){				
		if(i == sommet){
			if(listes->voisin == voisin){
				res=0;
			}			
			vtmp = listes;
			while(vtmp->voisin != -1 && done == 0){
				vtmp = vtmp->voisinSuivant;
				if(vtmp->voisin == voisin){
					res = 0;
				}
			}
		}
		i++;
		listes++;
	}
	return res;
}

int sommetExiste(struct TypGraphe *graphe, int sommet){
	struct TypVoisins *listes;
	struct TypVoisins *vtmp = malloc(sizeof(struct TypVoisins));
	listes = graphe->listesAdjacences;
	listes++;
	int i=1;
	int res = 1;
	while(listes->voisin != NULL){				
		if(i == sommet){
			res = 0;
		}
		i++;
		listes++;
	}
	return res;
}

void ajouterArete(struct TypGraphe *graphe, int gauche, int droite, int poid){	
	struct TypVoisins *listes;
	listes = graphe->listesAdjacences;
	struct TypVoisins *voisinTmp = malloc(sizeof(struct TypVoisins));
	struct TypVoisins *vtmp = malloc(sizeof(struct TypVoisins));	
	if(listes[gauche].voisin != 0){
		if(listes[gauche].voisin == -1){
			voisinTmp->voisin = -1;
			listes[gauche].poid = poid;
			listes[gauche].voisin = droite;
			listes[gauche].voisinSuivant = voisinTmp;
		}else{
			listes++;
			int i=1;
			int done = 0;			
			//Verifi existance
			if( voisinExiste(graphe, gauche, droite) == 0){
				done = 1;
			}			
			while(listes->voisin != NULL && done == 0 ){				
				if(i == gauche){
					vtmp = listes;
					while(vtmp->voisin != -1 && done == 0){
						vtmp = vtmp->voisinSuivant;
						if(vtmp->voisin == -1){
							vtmp->voisin = droite;
							vtmp->poid = poid;
							voisinTmp->voisin = -1;
							vtmp->voisinSuivant = voisinTmp;
							done = 1;							
						}
					}
				}
				i++;
				listes++;
			}
			
		}
	}
	else{
		printf("Erreur : : %d\n",gauche);
	}
	
}

void insertionArete(struct TypGraphe *graphe){
	printf("Numero de l'extremiter gauche : \n");
	int gauche;
	int droite;
	int poid;
	char sym = 'n';
	scanf("%d",&gauche);	
	if( sommetExiste(graphe,gauche) == 0){	
		printf("Numero de l'extremiter droite : \n");
		scanf("%d",&droite);		
		if(sommetExiste(graphe,droite) == 0){		
			printf("poid de l'arete : \n");
			scanf("%d",&poid);
			if(graphe->estOriente == 0){
				printf("L'arete est-elle symétrique ? (o/n) : \n");
				scanf("%c",&sym);
				scanf("%c",&sym);
				if(sym == 'o'){
					ajouterArete(graphe,droite,gauche,poid);
				}
				ajouterArete(graphe,gauche,droite,poid);
			}else{
				ajouterArete(graphe,droite,gauche,poid);
				ajouterArete(graphe,gauche,droite,poid);
			}
		}else{
			printf("Erreur : : Sommet droite n'existe pas -> %d\n",droite);
		}
	}else{
		printf("Erreur : : Sommet gauche n'existe pas <- %d \n",gauche);
	}
}

int supprArete(struct TypGraphe *graphe, int sommet, int voisin){
	struct TypVoisins *listes;
	struct TypVoisins *vtmp = malloc(sizeof(struct TypVoisins));	
	struct TypGraphe *g = malloc(sizeof (struct TypGraphe));
	create(g,graphe->nbMaxSommets-1,graphe->estOriente);	
	listes = graphe->listesAdjacences;
	listes++;
	int i=1;
	while(listes->voisin != NULL){
		insertionSommet(g);	
		if(listes->voisin != voisin || i!=sommet){
			ajouterArete(g,i,listes->voisin,listes->poid);				
		}			
		vtmp = listes;
		while(vtmp->voisin != -1){
			vtmp = vtmp->voisinSuivant;
			if(vtmp->voisin != voisin || i!=sommet){
				ajouterArete(g,i,vtmp->voisin,vtmp->poid);
			}
		}
	i++;
	listes++;
	}
	return g;	
}

int suppressionArete(struct TypGraphe *graphe){
	printf("Numero de l'extremiter gauche : \n");
	int sommet;
	int voisin;
	scanf("%d",&sommet);
	printf("Numero de l'extremiter droite : \n");
	scanf("%d",&voisin);
	return supprArete(graphe,sommet,voisin);
}

void afficheGraphe(struct TypGraphe *graphe){
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("# nombre maximum de sommets\n");
	printf("%d\n",graphe->nbMaxSommets-1);
	printf("# oriente\n");
	if(graphe->estOriente == 0){
		printf("o\n");
	}else{
		printf("n\n");
	}	
	printf("# sommets : voisins\n");
	int i=0;	
	struct TypVoisins* listes;
	listes = graphe->listesAdjacences;	
	listes++;
	while(listes->voisin != NULL){	
		printf("%d : ",i+1);		
		if(listes->voisin == -1){
	//		printf("(%d)",listes->voisin);
		}else{
			printf("(%d/%d)",listes->voisin, listes->poid);	
			struct TypVoisins *tmp ;
			tmp = listes->voisinSuivant;
			if(tmp != NULL){
				while(tmp->voisin != -1){					
					printf(", (%d/%d)",tmp->voisin,tmp->poid);					
					tmp = tmp->voisinSuivant;
				}
			}
		}		
		listes++;		
		printf("\n");
		i++;
	}	
/*	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");	*/
}

int enregistrerGraphe(struct TypGraphe *graphe) {
	FILE* save = NULL;
	char saveName[50];
	printf("Nom ou chemin du fichier de sauvegarde : \n");
	scanf("%s", &saveName);
	//Créer fichier de sauvegarde
	save = fopen(saveName, "w+");
	//Sauvegarde dans le fichier
	if (save != NULL) {
		fprintf(save, "# Nombre maximum de sommets\n%d\n# oriente\n", graphe->nbMaxSommets - 1);
		printf("# Nombre maximum de sommets\n%d\n# oriente\n", graphe->nbMaxSommets - 1);
		if (graphe->estOriente == 0) {
			fprintf(save, "o\n# sommets : voisins\n");
			printf("o\n# sommets : voisins\n");
		} else {
			fprintf(save, "n\n# sommets : voisins\n");
			printf("n\n# sommets : voisins\n");
		}
		int i=0;
		struct TypVoisins* listes;
		listes = graphe->listesAdjacences;
		listes++;
		while (listes->voisin != NULL) {
			fprintf(save, "%d : ", i + 1);
			printf("%d : ", i + 1);
			if (listes->voisin == -1) {
				//fprintf(save, "(%d)", listes->voisin);
				//printf("(%d)", listes->voisin);
			} else {
				fprintf(save, "(%d/%d)", listes->voisin, listes->poid);
				printf("(%d/%d)", listes->voisin, listes->poid);
				struct TypVoisins *tmp;
				tmp = listes->voisinSuivant;
				if (tmp != NULL) {
					while (tmp->voisin != -1) {
						fprintf(save,", (%d/%d)", tmp->voisin, tmp->poid);
						printf(", (%d/%d)", tmp->voisin, tmp->poid);
						tmp = tmp->voisinSuivant;
					}
				}
			}
			listes++;
			if (listes->voisin != NULL){
				fprintf(save, "\n");
				printf("\n");
			}
			i++;
		}
		fclose(save);
	} else {
		printf("Erreur de création du fichier\n");
		return 1;
	}
	return 0;
}

int lectureGraphe(struct TypGraphe *graphe) {
	FILE* load = NULL;
	//Ouvre fichier
	char loadName[50];
	char buffer[BUFFERSIZE + 1];
	printf("Nom ou chemin du fichier de chargement : \n");
	scanf("%s", &loadName);
	load = fopen(loadName, "r");
	//Enregistre fichier dans le buffer
	if (load != NULL) {
		size_t newLen = fread(buffer, sizeof(char), BUFFERSIZE, load);
		if (ferror(load) != 0) {
			fputs("Erreur lecture fichier", stderr);
		} else {
			buffer[newLen++] = '\0';
		}
	} else {
		printf("Erreur ouverture");
		return 1;
	}
	int i = 0, x = 1, y = 0, z = 0, nbSomMax = 0, somArrD = 0, poids=0;
	char orient;
	char tmpSom[10]="";
	char tmpSomArrD[10] = "";
	char tmpPoids[10] = "";
	//Créer le graphe par rapport aux caractères rencontrés
	while (buffer[i] != NULL) {
		if (buffer[i] == '\n') {
			x++;
			if (x > 5) {
				insertionSommet(graphe);
			}
		}
		if ((x == 2) && (y==0)) {
			tmpSom[z] = buffer[i];
			y = i;
			while ((buffer[y + 1] >= '0') && (buffer[y + 1] <= '9')) {
				tmpSom[z + 1] = buffer[y + 1];
				z++;
				y++;
			}
			nbSomMax = atoi(tmpSom);
		}
		if (x == 4) {
			orient = buffer[i];
			create(graphe, nbSomMax, orient);
		}
		if ((x >= 6) && (x <= (6 + nbSomMax))) {
			if (buffer[i] == '(') {
				y = i;
				z = 0; 
				while ((buffer[y + 1] >= '0') && (buffer[y + 1] <= '9')) {
					tmpSomArrD[z] = buffer[y + 1];
					z++;
					y++;
				}
				somArrD = atoi(tmpSomArrD);
			}
			if (buffer[i] == '/') {
				y = i;
				z = 0; 
				while ((buffer[y + 1] >= '0') && (buffer[y + 1] <= '9')) {
					tmpPoids[z] = buffer[y + 1];
					z++;
					y++;
				}
				poids = atoi(tmpPoids);
			}
			if (buffer[i] == ')') {
				z = 0;
				for (z = 0; z < 10; z++) {
					tmpPoids[z] = "";
					tmpSomArrD[z] = "";
				}
				z = 0;
				ajouterArete(graphe, x-5, somArrD, poids);
			}
		}
		i++;
	}
	printf("%s\n", buffer);
	fclose(load);
	return 0;
}
