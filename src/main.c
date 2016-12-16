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

//Fonction d'affichage du TP2
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

//Fonction d'affichage du projet
void afficheMenuProjet(){
	printf("--------------------------------------------\n");
	printf("--                  MENU                  --\n");
	printf("--------------------------------------------\n");
	printf("1- Solution optimale\n");
	printf("2- Parcours du plus proche voisin\n");
	printf("3- Parcours du plus petit détour\n");
	printf("4- Solution ARPM\n");
	printf("5- Affichage\n");
	printf("6- Quitter\n");
	printf("--------------------------------------------\n");
}

//Fonction de choix du menu du TP2
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

void choixProjet(struct TypGraphe *graphe, int nbSommet) {
	int quit = 0;
	while (quit == 0) {
		afficheMenuProjet();
		int choix;
		scanf("%d", &choix);
		int sommetDepart, sommetDepartARPM, sommet1, sommet2, sommet3;
		int bonChoix=0;
		switch (choix) {
		case 1:
			solution_exacte(graphe);
			break;
		case 2:
			while(bonChoix==0){
				printf("Veuillez choisir le sommet de départ\n");
				scanf("%d", &sommetDepart);
				if ((sommetDepart==0)||(sommetDepart>nbSommet)){
					printf("Le sommet n'existe pas dans ce graphe\n");
				}else{
					bonChoix++;
				}
			}
			solutionPlusProcheVoisin(graphe, sommetDepart);
			printf("\n");
			bonChoix=0;
			break;
		case 3:
			while(bonChoix==0){
				printf("Veuillez choisir premier sommet de départ \n");
				scanf("%d", &sommet1);
				if ((sommet1==0)||(sommet1>nbSommet)){
					printf("Le sommet n'existe pas dans ce graphe\n");
				}else{
					bonChoix++;
				}
			}
			bonChoix=0;
			while(bonChoix==0){
				printf("Veuillez choisir second sommet de départ \n");
				scanf("%d", &sommet2);
				if ((sommet2==0)||(sommet2>nbSommet)){
					printf("Le sommet n'existe pas dans ce graphe\n");
				}else if(sommet2==sommet1){
					printf("Le second sommet est le même que le premier\n");
				}else{
					bonChoix++;
				}
			}
			bonChoix=0;
			while(bonChoix==0){
				printf("Veuillez choisir troisième sommet de départ \n");
				scanf("%d", &sommet3);
				if ((sommet3==0)||(sommet3>nbSommet)){
					printf("Le sommet n'existe pas dans ce graphe\n");
				}else if(sommet3==sommet1){
					printf("Le troisième sommet est le même que le premier\n");
				}else if(sommet3==sommet2){
					printf("Le troisième sommet est le même que le second\n");
				}else{
					bonChoix++;
				}
			}
			bonChoix=0;
			solutionPlusPetitDetour(graphe, sommet1, sommet2, sommet3);
			printf("\n");
			break;
		case 4:
			while(bonChoix==0){
				printf("Veuillez choisir le sommet de départ\n");
				scanf("%d", &sommetDepartARPM);
				if ((sommetDepartARPM==0)||(sommetDepartARPM>nbSommet)){
					printf("Le sommet n'existe pas dans ce graphe\n");
				}else{
					bonChoix++;
				}
			}
			solution_ARPM(graphe, sommetDepartARPM);
			printf("\n");
			break;
		case 5:
			afficheGraphe(graphe);
			break;
		case 6:
			free(graphe);
			quit = 1;
			break;
		}
	}
}

//Main, création du graphe par rapport aux nombres de sommet et de la graine d'aléatoire donnée en paramètre
int main(int argc, char **argv){
	if (argc != 3) {
		printf("Erreur nombre d'argument : N , g \n");
		return 1;
	}
	struct TypGraphe *graphe = malloc(sizeof(struct TypGraphe));
	int n = atoi(argv[1]);
	create(graphe, n, 'n');
	int graine = atoi(argv[2]);
	int x[n];
	int y[n];
	sommetAleatoire(graphe, n, graine, x, y);
	creationArrete(graphe, n, x, y);
	afficheGraphe(graphe);
	int i, nbrSommet = graphe->nbMaxSommets - 1;
	/*int **liste;
	liste = (int **)malloc(factorial(nbrSommet) * sizeof(int *));
	for (i = 0; i < factorial(nbrSommet); i++) {
		liste[i] = (int *)malloc((2 * nbrSommet) * sizeof(int));
		liste[i] = NULL;
	}
	char *prefixe = malloc((2 * nbrSommet) * sizeof(int));*/
	choixProjet(graphe, nbrSommet);
	return 0;
}
