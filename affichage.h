#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
void affichage (Partie * niveau); //charge l'affichage que l'on a créé dans le .c
void menuHead(char chaine[80]); //permet d'avoir le menu créé par un autre membre du groupe
void score(Partie * partie); //charge l'affichage du score une fois le hanjie terminé
#endif // FICHIERS_H_INCLUDED
