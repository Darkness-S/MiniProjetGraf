
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

int main(int argc, char **argv)
{
	
	struct TypGraphe *graphe = malloc(sizeof (struct TypGraphe));
	
	int quit = 0;
	while(quit ==0){
		
		afficheMenu();
		
		int choix;
		scanf("%d",&choix);
		
		switch(choix){
			case 1:
				creationGraphe(graphe);
			break;
			case 2:
				printf("%d\n",graphe->nbMaxSommets);
			break;
			case 3:
				insertionSommet(graphe);
			break;
			case 7:
				afficheGraphe(graphe);
			break;
			case 9:
				quit = 1;
			break;
		}
	
	}
	
	return 0;
}

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



