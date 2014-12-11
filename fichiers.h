#ifndef FICHIERS_H_INCLUDED
#define FICHIERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "fonctions.h"

void lectureDb (char listeNiveaux [3][3][100], char addressesSauvegardes [3][100] ); // charge la base de niveaux
void lectureNiveau (char addresse [100], Cases * niveau); //Charge le niveau
void sauvegarde (Partie *partie, char addresse[150]);
void chargement(Partie * partie, char addresse[150]);
void enregistrerHistorique (Partie *partie);
int lireHistorique (ElementHistorique *actuel, FILE * fichier);
void lectureSautLigne( FILE * fichier);

#endif // FICHIERS_H_INCLUDED
