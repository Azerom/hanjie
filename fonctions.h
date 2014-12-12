#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structures.h"

void SystemPause();
void viderTampon();
void calculIndice(Partie * partie);
void ajouterElement(ElementHistorique *pile, ElementHistorique *nouveau);

#endif // FICHIERS_H_INCLUDED
