#include "../include/libgraphProjet.h" 

//Fonction donnant les coordonnées des nouveaux sommet à rajouter
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

//Fonction d'affichage des coordonnées d'un sommet pour le déboggage
void afficheCoordonee(int x[], int y[],int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ; %d\n", x[i], y[i]);
	}
}

//Autre fonction de création d'arête par rapport à certaines coordonnées données et calcul de son poids
void creationArrete(struct TypGraphe *graphe, int n, int x[], int y[]) {
	// Chaque sommet a une arrete vers tous les sommets ( GRAPHE COMPLET )
	int i = 0;
	int j = 0;	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			int gauche = i;
			int droite = j;
			double poid=0;
			// poid = calcul de la distance entre coordonné de gauche et de droite 
			poid = (double)sqrt(pow((x[i - 1] - x[j - 1]),2) + pow((y[i - 1] - y[j - 1]),2));
			if (gauche != droite) {
				ajouterArete(graphe, gauche, droite, (int)poid);
			}
		}
	}
}

//Fonction d'ajout d'un sommet dans une file de priorité	
void push (filePrio *f, int prio, int sommet) {	
    if (f->lon + 1 >= f->taille) {
        f->taille = f->taille ? f->taille * 2 : 4;
        f->nodes = (nodeFilePrio *)realloc(f->nodes, f->taille * sizeof (nodeFilePrio));
    }
    int i = f->lon + 1;
    int j = i / 2;
    while (i > 1 && f->nodes[j].prio > prio) {
        f->nodes[i] = f->nodes[j];
        i = j;
        j = j / 2;
    }
    f->nodes[i].prio = prio;
    f->nodes[i].sommet = sommet;
    f->lon++;
}
 
//Fonction permettant de récupérer et retirer le premier élément de la file de priorité 
int pop (filePrio *f) {
    int i, j, k;
    if (!f->lon) {
        return NULL;
    }
    int sommet = f->nodes[1].sommet;
    f->nodes[1] = f->nodes[f->lon];
    f->lon--;
    i = 1;
    while (1) {
        k = i;
        j = 2 * i;
        if (j <= f->lon && f->nodes[j].prio < f->nodes[k].prio) {
            k = j;
        }
        if (j + 1 <= f->lon && f->nodes[j + 1].prio < f->nodes[k].prio) {
            k = j + 1;
        }
        if (k == i) {
            break;
        }
        f->nodes[i] = f->nodes[k];
        i = k;
    }
    f->nodes[i] = f->nodes[f->lon + 1];
    return sommet;
}	

//Fonction permettant d'ajouter le voisin le plus proche d'un sommet dans la fille de priorité
void pushBestVoisin(filePrio *f, struct TypGraphe *graphe,int num){
	struct TypVoisins* listes;
	listes = graphe->listesAdjacences;	
	listes++;
	int i=1;
	while(listes->voisin != NULL){
		if(i== num){
			struct TypVoisins *tmp ;
			push(f, listes->poid, listes->voisin);
			tmp = listes->voisinSuivant;
			if(tmp != NULL){
				while(tmp->voisin != -1){		
					push(f, tmp->poid, tmp->voisin);							
					tmp = tmp->voisinSuivant;
				}
			}
		}
		i++;
		listes++;
	}
}

/*
//Fonction censé retourner la taille d'un tableau. Non utilisé
int taille(int *V){
	int t = 0;
	if (V != NULL) {
		while (V[t]!=NULL) {
			t++;
		}
	}
	return t-1;
}*/

//Fonction de réorganisation d'un tableau avant diminution d'un indice
void change(int *V,int x, int ta) {
	int t = 0;
	int i = 0;
	while (i < ta) {
		if (i+1 != x) {
			V[t] = i+1;
			t++;
		}
		i++;		
	}
}

/*
//Fonction d'ajout d'un parcours dans la liste des parcours. Non utilisé
void ajouteListeParcour(int* liste, int *prefixe, int tprefixe, int x, int cpt) {
	int j = 0;
	int **ltmp = liste;
	if (cpt < 10) {
		for (j = 0; j < tprefixe; j++) {
			ltmp[cpt][j] = prefixe[j];
		}
		ltmp[cpt][j] = x;
	}
}*/

//Fonction d'énumération de tout les cycles eulériens (donnée dans le cours). Non utilisé
/*int enumereCycles(int **liste,int *prefixe,int tprefixe, int *V, int t,int cpt) {
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
		/*if (t == 1) {
		//printf("done\n");
		int ta = 0;
		while (ta<tprefixe) {
			printf("%d-",prefixe[ta]);
			
			ta++;
		}	
		printf("%d\n", V[t]);
		//ajouteListeParcour(liste, prefixe, tprefixe, V[t],cpt);
	}else {		
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
}*/

//Fonction de calcul d'un factioriel
unsigned long factorial(unsigned long f){
	if (f == 0){
		return 1;
	}
	return(f * factorial(f - 1));
}

//Fonction récursive construisant les parcours
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

//Fonction d'appel pour la fonctionb récursive qui récupère les paramètres à lui passer
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

//Fonction retournant le poids d'une arête
float retournePoid(struct TypGraphe *graphe,int gauche, int droite) {
	float res = 0;
	int i = 1;
	struct TypVoisins* listes;
	listes = graphe->listesAdjacences;
	listes++;
	while (listes->voisin != NULL) {
		if (i == gauche) {
			//printf("GAUCHE %d\n", i);
			if (listes->voisin == droite) {
				res = listes->poid;
			}
			struct TypVoisins *tmp;
			tmp = listes->voisinSuivant;
			while (tmp->voisin != -1) {
				//printf("PASSE %d",tmp->voisin);
				if (tmp->voisin == droite) {
					res = tmp->poid;
				}
				tmp = tmp->voisinSuivant;
			}
		}
		listes++;
		i++;
	}
	return res;
}

//Fonction calculant la solution optimale
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
		for (j = 0; j<nbSommets-1; j++) {
			float arete = retournePoid(graphe, t[i*nbSommets + j] + 1, t[i*nbSommets + j + 1] + 1);
			somme += arete;
		}
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
		if(i==nbSommets-1){
			printf("%d", t[k*nbSommets + i]+1);
		}else{
			printf("%d - ", t[k*nbSommets + i]+1);
		}
	}
	printf("\n");
}

//Fonction calculant le parcours selon l'heuristique du plus proche voisin
void solutionPlusProcheVoisin(struct TypGraphe *graphe, int sommetDepart) {
	int i, sommet, sommetParcourut=1;
	int nbSommets = graphe->nbMaxSommets - 1;
	int parcours[nbSommets];
	int sommetDejaPris[nbSommets];
	for (i = 0; i < nbSommets; i++) {
		sommetDejaPris[i] = 0;
	}
	filePrio *f = (filePrio *)calloc(1, sizeof(filePrio));
	pushBestVoisin(f, graphe, sommetDepart);
	parcours[0]=sommetDepart;
	sommetDejaPris[sommetDepart-1]=1;
	while(sommetParcourut<nbSommets){
		sommet = pop(f);
		while(sommetDejaPris[sommet-1]==1){
			sommet=pop(f);
		}
		sommetDejaPris[sommet-1]=1;
		parcours[sommetParcourut]=sommet;
		pushBestVoisin(f, graphe, sommet);
		sommetParcourut++;
	}	
	printf("Parcours du plus proche voisin : \n");
	for (i=0; i<nbSommets; i++){
		if (i==0){
			printf("%d ", parcours[i]);
		}else{
			printf("- %d ", parcours[i]);
		}
	}
}	

//Fonction calculant le parcours selon l'heuristique du plus petit détour
void solutionPlusPetitDetour(struct TypGraphe *graphe, int s1, int s2, int s3){
	int i, sommet, sommetParcourut=3;
	int gauche, droite, sommetARajout;
	int nbSommets = graphe->nbMaxSommets - 1;
	int tabParcours[nbSommets];
	int sommetDejaPris[nbSommets];
	float poids=0, poidsMin=9999;
	for (i = 0; i < nbSommets; i++) {
		sommetDejaPris[i] = 0;
		tabParcours[i]=0;
	}
	tabParcours[0]=s1;
	tabParcours[1]=s2;
	tabParcours[2]=s3;
	sommetDejaPris[s1-1]=1;
	sommetDejaPris[s2-1]=1;
	sommetDejaPris[s3-1]=1;
	while(sommetParcourut<nbSommets){
		for(i=0; i<sommetParcourut; i++){
			if(i==sommetParcourut){
				for(int j=0; j<nbSommets; j++){
				 	if(sommetDejaPris[j]==0){
						poids=retournePoid(graphe, tabParcours[i], j+1);
						poids=poids+retournePoid(graphe, j+1, tabParcours[0]);
						if (poids<poidsMin){
							poidsMin=poids;
							gauche=i;
							sommetARajout=j+1;
						}
					}
				}
			}else{
				for(int j=0; j<nbSommets; j++){
				 	if(sommetDejaPris[j]==0){
						poids=retournePoid(graphe, tabParcours[i], j+1);
						poids=poids+retournePoid(graphe, j+1, tabParcours[i+1]);
						if (poids<poidsMin){
							poidsMin=poids;
							gauche=i;
							sommetARajout=j+1;
						}
					}
				}
			}
		}
		sommetParcourut++;
		sommetDejaPris[sommetARajout-1]=1;
		ajoutDansTableau(tabParcours, nbSommets, gauche+1, sommetARajout);
		poids=0;
		poidsMin=9999;
	}
	printf("Parcours du plus petit détour : \n");
	for (i=0; i<nbSommets; i++){
		if (i==0){
			printf("%d ", tabParcours[i]);
		}else{
			printf("- %d ", tabParcours[i]);
		}
	}
}

//Fonction d'ajout d'un élément dans un tableau à un indice donnée
void ajoutDansTableau(int *tableau, int tailleTableau, int indiceAjout, int sommetAAjouter){
	int tableauTmp[tailleTableau];
	int i=0;
	for (i=0; i<tailleTableau; i++){
		tableauTmp[i]=0;
	}
	for (int x = indiceAjout-1, i=0; x<tailleTableau; x++, i++){
		tableauTmp[i]=tableau[x];
	}
	tableau[indiceAjout-1]=sommetAAjouter;
	for(int x =indiceAjout, i=0; x<tailleTableau;x++,i++){
		tableau[x]=tableauTmp[i];
	}	
}

//Fonction vérifiant si un sommet est dans un tableau de sommet : x => sommet, V => tableau de sommet
int estDans(struct TypGraphe *graphe,int *V, int x, int ta) {
	int i = 0;
	int res = 1;
	while (i < ta) {
		if (V[i] == x) {
			res = 0;
		}
		i++;
	}
	return res;
}

//Fonction permettant d'extraire le sommet donc l'arête est la plus légère par rapport à un sommet de départ
int extraireMin(struct TypGraphe *graphe, int *F, int tf, int x) {
	int i,res = -1,indice=0;
	float poid = 9999;
	for (i = 0; i < tf; i++) {
		if (F[i] != x) {
			float tmp = retournePoid(graphe, x, F[i]);
			if (tmp < poid) {
				poid = tmp;
				indice = i;
				res = F[i];
			}
		}
	}
	return res;
}

//Fonction créant un arbre de recouvrement et calculant la solution ARPM
void solution_ARPM(struct TypGraphe *graphe) {
	/*	POUR chaque sommet u de V FAIRE
			prio[u] <- infini // tab de nbr 2222;
			pere[u] <- null   // tab 
		FPOUR

		r <- choisir un sommet de V // sommet: 1
		prio[r]<-0;
		F<-V // F est la file de priorité
		TQ F!=0 FAIRE
			u<-extraireMin(F)
			POUR chaque voisin v de u FAIRE
				SI v de F et poids(u,v)<prio[v] ALORS
					pere[v]<-u
					prio[v]<-poids(u,v)
				FSI
			FPOUR
		FTQ*/
	// Initialisation de V
	int i = 0;
	int  nbrSommet = graphe->nbMaxSommets - 1;
	int *V = malloc(nbrSommet * sizeof(int));
	int *F = malloc(nbrSommet * sizeof(int));

	for (i = 0; i < nbrSommet-1; i++) {
		V[i] = i + 2;
		F[i] = i + 2;
	}
	int *pere = malloc(nbrSommet * sizeof(int));
	float *prio = malloc(nbrSommet * sizeof(float));
	i = 0;
	for (i = 0; i < nbrSommet; i++) {
		pere[i] = 33;
		prio[i] = 2222;
	}
	int r = 0; // choisir un sommet de V (-1) les sommets commence par 1
	i = 0;
	pere[r] = 1;
	int tailleF = nbrSommet-1;
	for (i = 0; i < nbrSommet - 1; i++) {
		F[i] = i + 2;
	}
	while ( tailleF != 0) {
		i = 0;
		int t = 0;
		int *tmp = malloc((tailleF - 1) * sizeof(int));
		int u = extraireMin(graphe,F,tailleF,pere[r]); // arrete de plus petit poid(sommet qui correspond au bout de l'arrete depuis pere[r]
		for (i = 0; i < tailleF; i++) {
			if (F[i] != u) {
				tmp[t] = F[i];
				t++;
			}
		}
		F = tmp;
		tailleF--;
		for (i = 1; i < nbrSommet; i++) {
			if ((estDans(graphe,F,i+1,nbrSommet)==0) /*&& (retournePoid(graphe,u,i)<prio[i])*/) {
				pere[r+1] = u;
				prio[i] = retournePoid(graphe,u,i+1); 
			}
		}
		if (tailleF == 0) {
			pere[nbrSommet-1] = u;
		}
		r++;
	}
	i = 0;
	float somme = 0;	
	for (i = 0; i < nbrSommet; i++) {
		if (i == nbrSommet - 1) {
		}
		else {
			somme += retournePoid(graphe, pere[i], pere[i + 1]);
		}
	}	
	printf("La solution ARPM est : \n");
	for (i = 0; i<nbrSommet; i++) {
		if(i==nbrSommet-1){
			printf("%d ", pere[i]);
		}else{
			printf("%d - ", pere[i]);
		}
	}		
	printf("\n");
}
