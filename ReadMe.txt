Binome : Loudiyi Sammy, Marisa Guillaume, TP1B

Liste des fichiers :
-/include/libgraph.h
  Fichier contenant les differentes fonctions et structures du projet.
-/include/liblist.h
  Fichier contenant les differentes fonctions et structures de liste. Non utilise pour le moment.
-/src/main.c
  Fichier main contenant la fonction d'affichage du menu, la fonction de selection du menu, et la fonction principale du projet.
-/bin/exec
  Fichier exécutable du projet. Apparait après compilation
Le reste des fichiers sont des fichiers dummy pour les dossiers (ils servent a prendre en compte les dossiers sur git, ce dernier ne prenant pas en compte les 
dossiers vide).

La sauvegarde créer un fichier dans le dossier courant. De même le chargement charge un fichier dans le dossier courant. Par exemple si le programme est exécuté
sur la console depuis /bin, alors les fichiers de sauvegarde seront créé dans ce répertoire, et le chargement chargera dans ce répertoire.

Regle de compilation :
Aller dans la racine du projet avec la console de commande et rentrer la commande make. Pour nettoyer le projet (suppression de l'executable) : make clean.