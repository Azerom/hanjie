#include "fonctions.h"
#include <time.h>

void SystemPause()
{
   char magickey;
   fflush(stdin);
   printf("Appuyez sur une touche pour continuer...");
   scanf("%c", &magickey);
   magickey = getc(stdin);
}

void viderTampon()// On lit tous les caractéres du tampon jusqua la fin du fichier
{
    int a;
    while ((a = getchar ()) != '\n' && a != EOF);
}

void calculIndice(Partie * partie)
{
    //On calcul le nombre maximum d'indice possible (soit la taille de la grille / 2, arrondi au supérieur
    partie->nbIndiceMaxLigne = ceil((double)partie->pattern.x / 2);
    partie->nbIndiceMaxColonne = ceil((double)partie->pattern.y / 2);

    //On initialise les tableaux contenant les indices en fonctions de ce que l'on vient de calculer
    partie->indiceLigne = initialisationGrilleInt(partie->nbIndiceMaxLigne, partie->pattern.y);
    partie->indiceColonne = initialisationGrilleInt(partie->nbIndiceMaxColonne, partie->pattern.x);

//-----------Compte des indices sur les lignes-------------
//  On va parcourire chaque ligne en comptant combien d'élément contiennent chaque suite de 1

    int i, j, k, etat; //i, j et k servent d'index, etat permet de savoir si le dernier caractére lu était ou non un 1
                        // k indique combien d'indice on déja été compté, et donc la case sur laquelle s'inscrit le suivant

    for (i = 0; i < partie->pattern.y; i++)// Bloucle sur les différentes lignes
    {
        k = 0; etat = 0; //Analyse d'une nouvelle ligne, on remet 'etat' et 'k' à 0
        for( j = 0; j < partie->pattern.x; j++)// Bloucle sur les cases de la ligne actuelle
        {
            if(partie->pattern.grille[i][j] == '1')// Si le case actuelle contient un 1
            {
                partie->indiceLigne[i][k]++; // On inscrit sur l'index que l'indice actuel contient une case de plus
                etat = 1;// L'état passe (ou reste) a 1, pour indiquer au prochain passage que l'on vient de lire un 1
            }
            else if(etat == 1)// Si on lit autre chose qu'un 1, et que l'état était à 1 (donc l'élément précédent était un 1)
            {
                k++;// On inscrira ensuite les indices dans la case du tableau d'indice suivante
                etat = 0;//L'état repasse à 0
            }
        }

    }

//-----------Compte des indices sur les colonnes-------------
//Le fonctionement est le même que le compte sur les lignes, on lit simplemment les colonnes à la passe des lignes
    for (i = 0; i < partie->pattern.x; i++)
    {
        k = 0; etat = 0;
        for( j = 0; j < partie->pattern.y; j++)
        {
            if(partie->pattern.grille[j][i] == '1')
            {
                partie->indiceColonne[i][k]++;
                etat = 1;
            }
            else if(etat == 1)
            {
                k++;
                etat = 0;
            }
        }

    }

}

void ajouterElement(ElementHistorique *pile, ElementHistorique *nouveau)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->suivant = pile->suivant;
    pile->suivant = nouveau;
}
