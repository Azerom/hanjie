#include "structures.h"

int** initialisationGrilleInt(int x, int y)
{

    int **tableau;//On crée le pointeur de pointeur qui permetra d'acceder au tableau
    tableau = malloc(y*sizeof(int*));//On lui alloue un tableau de pointeur

    int i,j;
    for(i = 0; i < y; i++)
    {                                      //Pour chaque pointeur du tableau que l'on vient de crée
        tableau[i] = malloc(x*sizeof(int));//On alloue un tableau d'entier
        for(j = 0; j < x; j++)
        {
            tableau[i][j] = 0;//On initialisse toutes les valeurs à 0
        }
    }

    return tableau;
}
char** initialisationGrilleChar(int x, int y)
{

    char **tableau;//On crée le pointeur de pointeur qui permetra d'acceder au tableau
    tableau = malloc(y*sizeof(char*));//On lui alloue un tableau de pointeur

    int i, j;
    for(i = 0; i < y; i++)
    {                                      //Pour chaque pointeur du tableau que l'on vient de crée
        tableau[i] = malloc(x*sizeof(char));//On alloue un tableau d'entier
        for(j = 0; j < x; j++)
        {
            tableau[i][j] = '0';//On initialisse toutes les valeurs à 0
        }
    }

    return tableau;
}
void liberationGrilleInt(int **grille, int y)
{
    int i;
    for(i = 0; i < y; i++)
    {
        free(grille[i]);//Liberation des tableau d'entiers
    }
    free(grille);
}
void liberationGrilleChar(char **grille, int y)
{
    int i;
    for(i = 0; i < y; i++)
    {
        free(grille[i]);//Liberation des tableau de charcactere
    }
    free(grille);
}
void liberationPartie(Partie *partie)
{
    liberationGrilleChar(partie->pattern.grille, partie->pattern.y);
    liberationGrilleChar(partie->actuel.grille, partie->actuel.y);
    liberationGrilleInt(partie->indiceColonne, partie->actuel.y);
    liberationGrilleInt(partie->indiceLigne, partie->actuel.y);
}
