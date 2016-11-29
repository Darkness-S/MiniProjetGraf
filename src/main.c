
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
#include "../include/libgraph.h"
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

void choix(struct TypGraphe *graphe){
	
	int quit = 0;
	while(quit == 0){
		
		afficheMenu();
		
		int choix;
		scanf("%d",&choix);
		
		switch(choix){
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
	create(graphe,n,'n');
	
	int graine = atoi(argv[2]);
	
	srand(graine);

	int x[n];
	int y[n];
	
	sommetAleatoire(graphe,n,graine,x,y);
	//afficheCoordonee(x, y, n);
	creationArrete(graphe, n, x, y);
	afficheGraphe(graphe);

	return 0;
}





