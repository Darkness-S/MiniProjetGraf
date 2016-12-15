
/* 
 * 
 * 
 * 
 * 
 * 
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/libgraphProjet.h" 
#include "../include/liblist.h"

void afficheMenu(){
	
	printf("--------------------------------------------\n");
	printf("--                  MENU                  --\n");
	printf("--------------------------------------------\n");
	printf("1- Création\n");
	printf("2- Lecture\n");
	printf("3- Insertion de sommet\n");
	printf("4- Insertion d'arrete\n");
	printf("5- Suppression d'un sommet\n");
printf("6- Suppression d'une arrète\n");
printf("7- Affichage\n");
printf("8- Sauvegarde\n");
printf("9- Quitter\n");
printf("--------------------------------------------\n");

}

void choix(struct TypGraphe *graphe) {

	int quit = 0;
	while (quit == 0) {

		afficheMenu();

		int choix;
		scanf("%d", &choix);

		switch (choix) {
		case 1:
			creationGraphe(graphe);
			break;
		case 2:
			lectureGraphe(graphe);
			break;
		case 3:
			insertionSommet(graphe);
			break;
		case 4:
			insertionArete(graphe);
			break;
		case 5:
			suppressionSommet(graphe);
			break;
		case 6:
			graphe = suppressionArete(graphe);
			break;
		case 7:
			afficheGraphe(graphe);
			break;
		case 8:
			enregistrerGraphe(graphe);
			break;
		case 9:
			free(graphe);
			quit = 1;
			break;
		}

	}

}

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Erreur nombre d'argument : N , g \n");
		return 1;
	}

	struct TypGraphe *graphe = malloc(sizeof(struct TypGraphe));
	//choix(graphe);

	int n = atoi(argv[1]);
	create(graphe, n, 'n');

	int graine = atoi(argv[2]);
	srand(graine);

	int x[n];
	int y[n];

	sommetAleatoire(graphe, n, graine, x, y);
	//afficheCoordonee(x, y, n);
	creationArrete(graphe, n, x, y);
	afficheGraphe(graphe);
	filePrio *f = (filePrio *)calloc(1, sizeof(filePrio));
	pushBestVoisin(f, graphe, 1);
	printf("\n");
	for (int i = 0; i < (graphe->nbMaxSommets) - 3; i++) {
		printf("%d - ", pop(f));
	}
	printf("%d\n", pop(f));

	int i, nbrSommet = graphe->nbMaxSommets - 1;
	//printf("nbr :%d\n", factorial(nbrSommet));

	int **liste;
	liste = (int **)malloc(factorial(nbrSommet) * sizeof(int *));
	for (i = 0; i < factorial(nbrSommet); i++) {
		liste[i] = (int *)malloc((2 * nbrSommet) * sizeof(int));
		liste[i] = NULL;
	}

	char *prefixe = malloc((2 * nbrSommet) * sizeof(int));
	//printf("\n");
	/*int tab[10]={1,5,6,7,2,8,0,0,0,0};
	ajoutDansTableau(tab, 10, 3, 3);
	for(int z=0; z<10; z++){
		printf("%d - ", tab[z]);
	} */
	solutionPlusPetitDetour(graphe, 1, 2, 3);
	
	printf("\n");
	int *V = malloc(nbrSommet * sizeof(int));

	for (i = 0; i<nbrSommet; i++) {
		V[i] = i + 1;
		//printf("%d\n", i+1);
	}

	//int res = enumereCycles(liste, prefixe,0, V, nbrSommet,0);

	//printf("%d\n", res);
	//solution_exacte(graphe);

	solutionPlusProcheVoisin(graphe, 1);

	printf("\n");
	solution_ARPM(graphe);
	printf("\n");
	
	return 0;
}





