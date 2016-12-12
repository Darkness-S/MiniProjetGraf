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

typedef struct{
    int priority;
    int sommet;
}node_t;
 
typedef struct{
    node_t *nodes;
    int len;
    int size;
} heap_t;

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

void sommetAleatoire(struct TypGraphe *graphe ,int n, int graine, int x[], int y[]) {
	// creation de n sommet

	// tirage aléatoire des coordonnées
	int i = 0;

	for (i = 0; i < n; i++) {

		int coordX = i;
		int coordY = i;
		// ALEATOIRE

		x[i] = rand()%100;//coordX;
		y[i] = rand()%100;//coordX;

		//insert le sommet dans le graphe

		insertionSommet(graphe);

	}

}

void afficheCoordonee(int x[], int y[],int n) {
	int i;
	for (i = 0; i < n; i++) {

		printf("%d ; %d\n", x[i], y[i]);

	}
}

void creationArrete(struct TypGraphe *graphe, int n, int x[], int y[]) {

	// Chaque sommet a une arrete vers tous les sommets ( GRAPHE COMPLET )
	/*
	int i = 0;
	int j = 0;

	int gauche = i;
	int droite = j;

	int poid = 0;
	// poid = calcul de la distance entre coordonné de gauche et de droite 


	ajouterArete(graphe, gauche, droite, poid);
	*/
	int i = 0;
	int j = 0;
	//int gauche = 0,droite = 0, poid = 0;
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			int gauche = i;
			int droite = j;

			double poid=0;
			// poid = calcul de la distance entre coordonné de gauche et de droite 
			poid = (double)sqrt(pow((x[i - 1] - x[j - 1]),2) + pow((y[i - 1] - y[j - 1]),2));
			//poid = sqrt((int)i);
			if (gauche != droite) {
				ajouterArete(graphe, gauche, droite, (int)poid);
			}
		}
	}
}
	
void push (heap_t *h, int priority, int sommet) {
    if (h->len + 1 >= h->size) {
        h->size = h->size ? h->size * 2 : 4;
        h->nodes = (node_t *)realloc(h->nodes, h->size * sizeof (node_t));
    }
    int i = h->len + 1;
    int j = i / 2;
    while (i > 1 && h->nodes[j].priority > priority) {
        h->nodes[i] = h->nodes[j];
        i = j;
        j = j / 2;
    }
    h->nodes[i].priority = priority;
    h->nodes[i].sommet = sommet;
    h->len++;
}
 
int pop (heap_t *h) {
    int i, j, k;
    if (!h->len) {
        return NULL;
    }
    int sommet = h->nodes[1].sommet;
    h->nodes[1] = h->nodes[h->len];
    h->len--;
    i = 1;
    while (1) {
        k = i;
        j = 2 * i;
        if (j <= h->len && h->nodes[j].priority < h->nodes[k].priority) {
            k = j;
        }
        if (j + 1 <= h->len && h->nodes[j + 1].priority < h->nodes[k].priority) {
            k = j + 1;
        }
        if (k == i) {
            break;
        }
        h->nodes[i] = h->nodes[k];
        i = k;
    }
    h->nodes[i] = h->nodes[h->len + 1];
    return sommet;
}	

void pushBestVoisin(heap_t *h, struct TypGraphe *graphe,int num){
	struct TypVoisins* listes;
	listes = graphe->listesAdjacences;	
	listes++;
	int i=1;
	while(listes->voisin != NULL){
		if(i== num){
			struct TypVoisins *tmp ;
			push(h, listes->poid, listes->voisin);
			tmp = listes->voisinSuivant;
			if(tmp != NULL){
				while(tmp->voisin != -1){		
					push(h, tmp->poid, tmp->voisin);							
					tmp = tmp->voisinSuivant;
				}
			}
		}
		i++;
		listes++;
	}
}

int taille(int *V){
	int t = 0;
	if (V != NULL) {
		while (V[t]!=NULL) {
			t++;
		}
	}
	return t-1;
}

void change(int *V,int x, int ta) {

	int *tmp = malloc((ta-1) * sizeof(int));
	int t = 0;
	int i = 0;
	while (i < ta) {
		if (i+1 != x) {
			V[t] = i+1;
			t++;
		}
		i++;
		
	}
	t = 0;
	while (V[t] != NULL) {
		printf("%d\t",V[t]);
		t++;
	}
	

	//V = malloc((ta-1) * sizeof(int));

	//*V = *tmp;

}

void ajouteListeParcour(int* liste, int *prefixe, int tprefixe, int x, int cpt) {
	int j = 0;
	int **ltmp = liste;
	printf("\npatte : %d\n", cpt);

	if (cpt < 10) {
		for (j = 0; j < tprefixe; j++) {
			//printf("%d\n", cpt);	
			ltmp[cpt][j] = prefixe[j];
		}
		ltmp[cpt][j] = x;
		printf("\npatte : %d\n", cpt);
	}

	/*while (ltmp != NULL) {
		ltmp++;
		j++;
	}
	printf("%d\n", j);
	/*
	for (j = 0; j<tprefixe+1; j++) {
		printf("%d - ", prefixe[j]);
		//ltmp[0][j] = prefixe[j];
	}
	printf("\n");*/
	//ltmp[0][j] = x;
}


int enumereCycles(int **liste,int *prefixe,int tprefixe, int *V, int t,int cpt) {
	/*action enumereCycles(listeDesParcours, prefixe, V)
		Données(paramètres passés par valeur) :
	prefixe: une liste de sommets constituant le début d’un parcours
		V : l’ensemble des sommets du graphe
		Données / Résultat(paramètre passé par adresse) :
		listeDesParcours : une liste de listes de sommets
		DEBUT
		Si V = { x } Alors // il n’y a plus qu’un seul sommet qui n’est pas dans le parcours
		listeDesParcours  listeDesParcours + (prefixe + x)
		// on ajoute à la liste des parcours le parcours obtenu en rajoutant
		// le sommet x au préfixe
		Sinon
		Pour tout sommet x de V Faire
		enumereCycles(listeDesParcours, prefixe + x, V –{ x })
		FPour
		FSi
		FIN*/
	
	if (t == 1) {
		//printf("done\n");
		int ta = 0;
		while (ta<tprefixe) {
			printf("%d-",prefixe[ta]);
			
			ta++;
		}
		
		printf("%d\n", V[t]);
		//ajouteListeParcour(liste, prefixe, tprefixe, V[t],cpt);
	}
	else {
		
		t = t - 1;
		//printf("%d\n", V[0]);
		int ta = 0;
		while (ta<t) {
			
			prefixe[tprefixe] = V[ta]; // ajoute nbr au prefixe
			change(V,V[ta] , t); // Supprime x de la liste des sommets
			enumereCycles(liste, prefixe, tprefixe+1, V, t,cpt);// Appelle recursif
			ta++;

		}
		//t = t - 1;
		 


	}
	

	
		return cpt;

}

unsigned long factorial(unsigned long f)
{
	if (f == 0)
		return 1;
	return(f * factorial(f - 1));
}

void fctRec( int *l, int *t, int* t2, int n, int k) {
	int i,j,j1;
	int t3[n]; 
	if (k == n) {
		for (i = 0; i<n; i++) {
			for (j = 0; j<n*factorial(n) && t2[j] != n; j++) {
			}
			t2[j] = l[i];
		}
		return;
	}
	for (i = 0; i<n - k; i++) {
		l[k] = t[i];
		for (j = 0, j1 = 0; j<n - k; j++) {
			if (j != i) {
				t3[j1] = t[j];
				j1++;
			}
		}
		fctRec(l, t3, t2, n, k + 1);
	}
}



void commence(int* t,int n) {
	int l[n]; 
	int tmp[n]; 
	int i;
	for (i = 0; i<n; i++) {
		tmp[i] = i;
	}
	for (i = 0; i<(n*factorial(n)); i++) {
		t[i] = n;
	}
	fctRec( l, tmp, t,n, 0);
}

float retournePoid(struct TypGraphe *graphe,int gauche, int droite) {
	float res = 0;
	
	int i = 0;
	struct TypVoisins* listes;
	listes = graphe->listesAdjacences;
	listes++;
	while (listes->voisin != NULL) {
		if (listes->voisin == -1) {
		}
		else {

			if (listes->voisin == gauche) {
				struct TypVoisins *tmp;
				tmp = listes->voisinSuivant;
				if (tmp != NULL) {

					while (tmp->voisin != -1) {
						if (tmp->voisin == droite) {
							return tmp->poid;
						}
						tmp = tmp->voisinSuivant;
					}
				}
			}

		}
		listes++;
		i++;
	}


	return res;
}

void solution_exacte(struct TypGraphe *graphe) {
	int nbSommets = graphe->nbMaxSommets-1;
	int i;
	int t[nbSommets*factorial(nbSommets)];
	commence(t, nbSommets);
	float solutions[factorial(nbSommets)]; 
	t[nbSommets*factorial(nbSommets)] = nbSommets-1;
	for (i = 0; i<factorial(nbSommets); i++) {
		int j;
		float somme = 0;
		for (j = 0; j<nbSommets; j++) { 
			printf("g: %d,   d: %d\t", t[i*nbSommets + j]+1, t[i*nbSommets + j+1]+1);
			float arete = retournePoid(graphe, t[i*nbSommets + j] + 1, t[i*nbSommets + j + 1] + 1);
			somme += arete;
		}
		printf(" ::: %f", somme);
		printf("\n");
		solutions[i] = somme;
	}
	int min = solutions[0];
	int k = 0;
	for (i = 1; i<factorial(nbSommets); i++) {
		if (solutions[i]<min) {
			min = solutions[i];
			k = i;
		}
	}
	printf("La solution optimale est : %f\n", solutions[k]);
	for (i = 0; i<nbSommets; i++) {
		printf("%d -", t[k*nbSommets + i]+1);
	}
	printf("\n");
}

/*
void solutionPlusProcheVoisin(int *V, struct TypGraphe *graphe) {
	int i, sommet, sommetTMP, sommetParcourut=0;
	int nbSommets = graphe->nbMaxSommets - 1;
	int parcours[nbSommets];
	int sommetDejaPris[nbSommets];
	float poids=0, poidsMin=0;
	for (i = 0; i < nbSommets; i++) {
		sommetDejaPris[i] = 0;
	}
	for (i = 1; i <= nbSommet; i++) {
		if (i == 1) {
			heap_t *h = (heap_t *)calloc(1, sizeof(heap_t));
			pushBestVoisin(h, graphe, i);
			//printf("\n");
			sommetDejaPris[0] = 1;
			sommetParcourut++;
			sommet = pop(h);
			poids = poids + retournePoid(graphe, i, sommet);
			while (sommetParcourut<nbSommets) {
				if (sommetDejaPris[sommet - 1] == 1) {
					sommet = pop(h);
				}
				else {
					pushBestVoisin(h, graphe, sommet);
					sommetTMP = pop(h);
					poids = poids + retournePoid(graphe, sommet, sommetTMP);
					sommet = sommetTMP;
					//continuer a comparer les poids de chaque parcours de chaque sommet

				}
			}
		}

	}
}*/
