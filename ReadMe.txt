Binome : Loudiyi Sammy, Marisa Guillaume, TP1B

Liste des fichiers :
-/include/libgraph.h
  Fichier contenant les entêtes des differentes fonctions et structures du mini-projet du TP2 (certaines sont réutilisé dans le Projet TSP).
-/include/libgraphProjet.h
  Fichier contenant les entêtes des differentes fonctions et structures du Projet TSP.
-/include/liblist.h
  Fichier contenant les differentes fonctions et structures de liste. Non utilise pour le moment.
  
-/src/libgraph.c  
	Fichier contenant les differentes fonctions et structures du mini-projet du TP2 (certaines sont réutilisé dans le Projet TSP).
-/src/libgraphProjet.c
	Fichier contenant les differentes fonctions et structures du Projet TSP.
-/src/main.c
  Fichier main contenant la fonction d'affichage du menu, la fonction de selection du menu, la création d'un graphe suivant des paramètres données, et la fonction principale du projet.
-/bin/exec
  Fichier exécutable du projet. Apparait après compilation
  
Le reste des fichiers sont des fichiers dummy pour les dossiers (ils servent à prendre en compte les dossiers sur git, ce dernier ne prenant pas en compte les 
dossiers vide).

Regle de compilation :
	Aller dans la racine du projet avec la console de commande et rentrer la commande make. Pour nettoyer le projet (suppression de l'executable) : make clean.

Exécution :
	A la racine du projet (le dossier contenant les dossiers bin, include, lib, obj , save et src), compiler le projet, et entrer dans le terminal la commande : "./bin/ exec <N> <g>" avec N le nombre de sommet du graphe à créer, et g la graine de l'aléatoire pour la création des coordonnées des différents sommets.
	
Note : 
	Ce projet à été fait en rajout du mini-projet TP2 car nous réutilisons certaines des fonctions de ce mini-projet. Nous avons par conséquent séparer dans plusieurs fichier les fonctions du mini-projet du TP et du Projet TSP, et avons désactivé le menu du mini-projet du TP2. 
