#include "fichiers.h"


void lectureDb (char listeNiveaux [3][3][100], char addressesSauvegardes [3][100] )
{
    //Cette fonction charge le fichier contenant la base de donnée et trenvoie les addresses des niveaux et des sauvegardes.
    FILE * fichier;

    fichier = fopen("db.bin" , "rb");//On ouvre le fichier db.bin en lecture seule en binaire

    fread( listeNiveaux , sizeof(char)*100 , 3*3 , fichier); //On lit dans le fichier le tableau listeNiveau (tableau de char a 3 dimension)
    fread( addressesSauvegardes , sizeof(char)*100 , 3 , fichier); //On lit dans le fichier le tableau addressesSauvegardes (tableau de char à 2 dimensions)

}
// lectureNiveau charge un hanjie contenu dans le fichier situé a "adresse" dans "niveau"
void lectureNiveau (char addresse [100], Cases * niveau)
{
    FILE * fichier;//On crée un FILE

    fichier = fopen(addresse, "r");//On Ouvre en lecture seule le fichier .pbm
    //Penser a verifier si l'ouverture s'est bien passé
    if (fichier==NULL) perror ("Erreur a l'ourverture du fichier");
    else
    {
    //----Lecture du fichier
    int i = 0, j = 0, etat = 0;//Etat permet de savoir quelle information a déja été lu
                                // 0 = Rien, 1 = Le numéro magique, 2 = Les dimensions
    char test = 0;
    while (etat < 3)
    {//On lit le premier caractére de chaque ligne
        do
        {
            test = fgetc(fichier);

        }while(test == '\n' || test == ' ');//Si on lit un retour a la ligne ou un espace, la ligne lu est respectivemnt vide ou commence par une série d'espace
                                            //donc, on relit un caractére

        fseek(fichier, -1, SEEK_CUR);//On revient avant le carac actuel, pour permetre son traitement

            if(test != '#')//On vérifie qu'il ne s'agit pas d'un commentaire
            {
                switch(etat)//On regarde ce qui a déja été lu
                {
                    case 0 : //Rien n'a été lu
                        //On ne récupére pas le numéro magique, le type du fichier est déja connu
                        etat++;//On passe a l'état suivant
                        lectureSautLigne(fichier);//On passe a la ligne suivante
                        break;
                    case 1 : //On a lu le numéro magique

                        fscanf(fichier, "%d %d", &(niveau->x), &(niveau->y));//On récuppére les dimensions de l'hanjie
                        niveau->grille=initialisationGrilleChar(niveau->x,niveau->y);//On initialise la grille selon les dimensions récupéré ci-dessus    lectureSautLigne(fichier);
                        etat++;//On passe a l'état suivant
                        lectureSautLigne(fichier);//On passe a la ligne suivante
                        break;
                    case 2 : //On a lu les dimensions
                        //------lecture de la grille--------
                        if( j < niveau->y)//On vérifie qu'il reste des lignes a récupéré
                        {
                            for (i = 0; i < niveau->x ; i++)//Cette boucle dait défiler les caractéres de chaques lignes
                            {
                                test  = fgetc(fichier);//On récupére le caractére
                                niveau->grille[j][i] = test;


                                fseek(fichier, 1, SEEK_CUR);//On passe le caractére blanc

                            }
                            //On passe à la ligne suivante
                            fseek(fichier, -1, SEEK_CUR);//Avec certains éditeur de texte, le pbm avait des retours a la ligne en
                                            // 2 caractéres, on prévoit les deux cas en revenant un caractére en arriére
                                        // à chaque ligne puis en utilisant la fonction lectureSautligne
                            lectureSautLigne(fichier);//On passe a la ligne suivante
                            j++;//On incremente l'index des lignes
                        }
                        else etat++;//On passe a l'état suivant

                        break;
                }//Fin de switch
            }//fin de if
            else//Si il s'agit d'un commentaire, on passe a la ligne suivante
                lectureSautLigne(fichier);
        }//fin de while

        fclose(fichier);
    }



}
//Cette fonction permet de se déplacer dans un fichier lu, a la ligne suivante
void lectureSautLigne( FILE * fichier)
{
    //On lit le fichier caractére par caractére jusque trouver le caractére de retour a la ligne
    char test = 0;
    while(test != '\n' && test != EOF)
    {
        test = fgetc(fichier);
    }//Le curseur du FILE est donc juste avant le premier caractére de la ligne suivante
    if (test == EOF) fseek(fichier, 1, SEEK_CUR); //Si on a atteint la fin du fichier, a reviens de 1 en arriére pour permettre la detectiond e EOF
}

void sauvegarde(Partie * partie, char addresse[150])
{
        FILE * fichier = NULL;//On crée un FILE

    char format[50];
    time_t temps;
    struct tm date;
    // On récupère la date et l'heure actuelles.
    time(&temps);
    date=*localtime(&temps);
    strftime(format, 50, "%d/%m/%y à %X", &date);

    fichier = fopen(addresse, "w+");

    if (fichier==NULL) perror ("Erreur a l'ourverture du fichier");
    else
    {
        fprintf(fichier, "# Fichier de sauvegarde du jeu exia.hanjie, générée le %s\n", format);
        fprintf(fichier, "# Toute modification peut mener à la corruption de la sauvegarde\n");
        fprintf(fichier, "#--------------------------------------------------------------------\n");

        fprintf(fichier, "t_debut: %f\n",  partie->date);//Date de début
        fprintf(fichier, "t_save: %f\n",  partie->temp);//Temp passé
        fprintf(fichier, "pseudo: %s\n",  partie->pseudo);//pseudo
        fprintf(fichier, "type: %d\n",  partie->type);//Type de niveau
        fprintf(fichier, "taille_score: %d\n",  partie->tailleResultats);//Taille des resultats
        fprintf(fichier, "difficultee: %d\n",  partie->difficulte);//Difficulté

        sauvegardeGrilleChar(fichier, partie->pattern.grille, partie->pattern.x, partie->pattern.y, "grille_pattern");

        sauvegardeGrilleChar(fichier, partie->actuel.grille, partie->actuel.x, partie->actuel.y, "grille_actuel");

        sauvegardeGrilleInt(fichier, partie->indiceLigne, partie->nbIndiceMaxLigne, partie->pattern.y, "indices_lignes");

        sauvegardeGrilleInt(fichier, partie->indiceColonne, partie->nbIndiceMaxColonne, partie->pattern.x, "indices_colonnes");

        fprintf(fichier, "# Fin du fichier");

        fclose(fichier);
    }
}
void sauvegardeGrilleInt(FILE * fichier, int **grille, int x, int y, char nom[50])
{
    fprintf(fichier, "#---------------\n");
    fprintf(fichier, "%s:", nom);
    fprintf(fichier, " %d %d\n", y, x);
    int i, j;
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            fprintf(fichier, "%d ", grille[i][j]);
        }
        fprintf(fichier, "\n");
    }
    fprintf(fichier, "#---------------\n\n");
}
void sauvegardeGrilleChar(FILE * fichier, char **grille, int x, int y, char nom[50])
{
    fprintf(fichier, "#---------------\n");
    fprintf(fichier, "%s:", nom);
    fprintf(fichier, " %d %d\n", y, x);
    int i, j;
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            fprintf(fichier, "%c ", grille[i][j]);
        }
        fprintf(fichier, "\n");
    }
    fprintf(fichier, "#---------------\n\n");
}
void chargement(Partie * partie, char addresse[150])
{
  FILE * fichier;
  fichier = fopen (addresse,"r");//On ouvre le fichier à l'addresse demandé

  char lu = 0;
  char chaine [51];
  int i,j, grilleLu = 0, int_temp;

  if (fichier==NULL) perror ("Erreur a l'ourverture du fichier");
  else
  {
    while (fgetc(fichier) != EOF)
    {
        fseek(fichier, -1, SEEK_CUR);

        while( (lu = fgetc(fichier) ) == ' ');

        if (lu != '#' && lu !='\n')
        {
            fseek(fichier, -1, SEEK_CUR);

            fscanf(fichier, "%50s", chaine);

            if(!strcmp(chaine, "t_debut:"))
                fscanf(fichier, " %lf", &(partie->date));
            else if(!strcmp(chaine, "t_save:"))
                fscanf(fichier, " %lf", &(partie->temp));
            else if(!strcmp(chaine, "pseudo:"))
                fscanf(fichier, " %[^\n]s", &(partie->pseudo));
            else if(!strcmp(chaine, "type:"))
            {
                fscanf(fichier, " %d", &(int_temp));
                partie->type = (TypeNiveau) int_temp;
            }
            else if(!strcmp(chaine, "taille_score:"))
            {
                fscanf(fichier, " %d", &(int_temp));
                partie->tailleResultats = (TailleResultats) int_temp;
            }
            else if(!strcmp(chaine, "difficultee:"))
            {
                fscanf(fichier, " %d", &(int_temp));
                partie->difficulte = (Difficulte) int_temp;
            }
            else if(!strcmp(chaine, "grille_pattern:"))
            {
                fscanf(fichier, " %d %d", &(partie->pattern.y), &(partie->pattern.x));
                partie->pattern.grille=initialisationGrilleChar(partie->pattern.x,partie->pattern.y);
                grilleLu = 1;
                j = 0;
            }
            else if(!strcmp(chaine, "grille_actuel:"))
            {
                fscanf(fichier, " %d %d", &(partie->actuel.y), &(partie->actuel.x));
                partie->actuel.grille=initialisationGrilleChar(partie->actuel.x,partie->actuel.y);
                grilleLu = 2;
                j = 0;
            }
            else if(!strcmp(chaine, "indices_lignes:"))
            {
                fscanf(fichier, " %*d %d", &(partie->nbIndiceMaxLigne));
                partie->indiceLigne=initialisationGrilleInt(partie->nbIndiceMaxLigne,partie->pattern.y);
                grilleLu = 3;
                j = 0;
            }
            else if(!strcmp(chaine, "indices_colonnes:"))
            {
                fscanf(fichier, " %*d %d", &(partie->nbIndiceMaxColonne));
                partie->indiceColonne=initialisationGrilleInt(partie->nbIndiceMaxColonne,partie->pattern.x);
                grilleLu = 4;
                j = 0;
            }

            else if(chaine[0] >= '0' && chaine[0] <= '9')
            {
                lu = chaine[0];
                switch (grilleLu)
                {
                    case 1:
                        for(i = 0; i < partie->pattern.x; i++)
                        {
                            partie->pattern.grille[j][i] = lu;
                            while ((lu = fgetc(fichier)) == 32);
                            if(j+1 == partie->pattern.y && i+1 == partie->pattern.x)
                            {
                                grilleLu = 0;
                            }
                        }
                    break;
                    case 2:
                        for(i = 0; i < partie->actuel.x; i++)
                        {
                            partie->actuel.grille[j][i] = lu;
                            while ((lu = fgetc(fichier)) == 32);
                            if(j+1 == partie->actuel.y && i+1 == partie->actuel.x)
                            {
                                grilleLu = 0;
                            }
                        }
                    break;
                    case 3:
                        for(i = 0; i < partie->nbIndiceMaxLigne; i++)
                        {
                            partie->indiceLigne[j][i] = lu - '0';
                            while ((lu = fgetc(fichier)) == 32);
                            if((j+1) == partie->pattern.y && (i+1) == partie->nbIndiceMaxLigne)
                            {
                                grilleLu = 0;
                            }
                        }
                    break;
                    case 4:
                        for(i = 0; i < partie->nbIndiceMaxColonne; i++)
                        {
                            partie->indiceColonne[j][i] = lu - '0';
                            while ((lu = fgetc(fichier)) == 32);
                            if(j+1 == partie->pattern.x && i+1 == partie->nbIndiceMaxColonne)
                            {
                                grilleLu = 0;
                            }
                        }
                    break;

                }
                j++;
                fseek(fichier, -1, SEEK_CUR);
            }

        }

        lectureSautLigne(fichier);
    }

    fclose (fichier);
  }

}

void enregistrerHistorique (Partie *partie)
{
    char date[50];
    time_t temps;
    struct tm t_local;
    // On récupère la date et l'heure actuelles.
    time(&temps);
    t_local=*localtime(&temps);
    strftime(date, 50, "%d/%m/%y-%X", &t_local);

    FILE * fichier = NULL;

    fichier = fopen("historique.log", "a+");

    if (fichier==NULL) perror ("Erreur a l'ourverture du fichier");
    else
    {
        fprintf(fichier, "%s~%f~%s~%d~%d~%f\n", date, (double)temps, partie->pseudo, partie->type, partie->difficulte, partie->temp);
    }

    fclose(fichier);
}

long lireHistorique (ElementHistorique *actuel, FILE * fichier)
{
    ElementHistorique *nouveau = malloc(sizeof(*nouveau));

    fscanf(fichier, "%*[^~]s");
    fseek(fichier, 1, SEEK_CUR);
    fscanf(fichier,"%lf", &(nouveau->date));
    fseek(fichier, 1, SEEK_CUR);
    fscanf(fichier,"%[^~]s", nouveau->pseudo);
    fseek(fichier, 1, SEEK_CUR);
    fscanf(fichier,"%d", &(nouveau->type));
    fseek(fichier, 1, SEEK_CUR);
    fscanf(fichier,"%d", &(nouveau->difficulte));
    fseek(fichier, 1, SEEK_CUR);
    fscanf(fichier,"%lf", &(nouveau->temp));
    fseek(fichier, 1, SEEK_CUR);
    nouveau->suivant = NULL;

    if( actuel == NULL)
    {
        actuel = nouveau;
    }
    else
    {
        ajouterElement(actuel, nouveau);
    }

    if(fgetc(fichier) != EOF)
    {
        fseek(fichier, -1, SEEK_CUR);
        lireHistorique(nouveau, fichier);
    }

    return (long)actuel;

}

void freeHistorique(ElementHistorique *actuel)
{
    if(actuel != NULL)
    {
        ElementHistorique *transition = actuel->suivant;
        free(actuel);

        freeHistorique(transition);
    }

}
