#ifndef FICHIERS_H_INCLUDED
#define FICHIERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "fonctions.h"

void lectureDb (char listeNiveaux [3][3][100], char addressesSauvegardes [3][100] ); // charge la base de niveaux
void lectureNiveau (char addresse [100], Cases * niveau); //Charge le niveau
void sauvegarde (Partie *partie, char addresse[150]); //ENregistre la partie en cour
void chargement(Partie * partie, char addresse[150]); //Charge une parite à l'addresse demandé
void enregistrerHistorique (Partie *partie); //Ajoute une entrée à l'historique
int lireHistorique (ElementHistorique *actuel, FILE * fichier); //Stocke l'historique dans une liste chaine, et renvoie l'addresse de début
void lectureSautLigne( FILE * fichier); //Lors d'une lecture, avance jusqu'au \n suivant
void sauvegardeGrilleInt(FILE * fichier, int **grille, int x, int y, char nom[50]); //Ecrit dans un ficheir une grille d'int
void sauvegardeGrilleChar(FILE * fichier, char **grille, int x, int y, char nom[50]); //Ecrit dans un ficheir une grille d'int
#endif // FICHIERS_H_INCLUDED
