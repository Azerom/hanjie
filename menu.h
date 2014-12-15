#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
#include "fonctions.h"
#include "hanjie.h"
#include "fichiers.h"

void menuHead(char chaine[80]);
void menuPrincipal(Partie * partie);
void menuHistorique();
void menuJeu(Partie * partie);
void afficherHistorique(ElementHistorique * historique);
void menuPartie(Partie * partie);

#endif // MENU_H_INCLUDED
