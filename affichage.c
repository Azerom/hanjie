#include "affichage.h"
#include <time.h>

void affichage (Partie * niveau) //première fonction qui permet l'affichage de la grille, des cases, des lignes, des colonnes
{

    int i,j,k; //Initialisation des variables

    system("clear");
    menuHead("Hanjie n°1");

    for(j = 0; j < niveau->nbIndiceMaxLigne; j++) //Première boucle for pour afficher les lettres désignant les différentes colonnes au dessus du hanjie
    {
        printf("  ");
    }
    printf("     ");

    for (i = 0; i < niveau->actuel.x; i++)
    {

        printf("\x1b[36m%c\x1b[0m   ",i+65);

    } //Fin boucle for pour afficher les lettres désignant les différentes colonnes au dessus du hanjie

    printf("\n"); //Les différents printf("\n") servent à passer des lignes donc à aérer pour plus d'esthétique

    for (i = 0; i < niveau->nbIndiceMaxColonne; i++) //Début deuxième boucle for, double imbriquée, qui parcourt tout le tableau et espace les différentes cases, et permet également d'espacer la grille pour qu'elle ne soit pas proche du bord gauche
    {
        printf("    ");

        for (j = 0; j < niveau->nbIndiceMaxLigne; j++)
        {
            printf("  ");
        }
        for (j = 0; j < niveau->actuel.x; j++)
        {
            if(niveau->indiceColonne[j][i] == 0)
            {
                printf("    ");
            }
            else
            {
                printf(" %d  ", niveau->indiceColonne[j][i]);
            }
        }
        printf("\n");
    } //Fin deuxième boucle for

    for (i = 0; i < niveau->actuel.y; i++) //Troisième boucle for , double imbriquée aussi
    {

        printf("\x1b[36m%2d |\x1b[0m ",i+1); //affiche les chiffres désignant les différentes lignes à gauche du hanjie

        //test a partir d'ici
        for(k = 0; k < niveau->nbIndiceMaxLigne; k++)
        {
            if(niveau->indiceLigne[i][k] == 0)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", niveau->indiceLigne[i][k]);
            }
        }
        //fin de test
        for(j = 0; j < niveau->actuel.x; j++) //boucle for qui parcourera les 0 du tableau et les transformera en case grisées et les 1 en case vide
        {
            if (niveau->actuel.grille[i][j] == '1')
            {
                printf("%c%c%c | ", 0xE2, 0x96, 0xA9);
            }

            else
            {
                printf("%c%c%c | ", 0xE2, 0x96, 0xA1);
            }
        } //fin boucle for
        printf("\n");
        for(j = 0; j < niveau->nbIndiceMaxLigne; j++)
        {
            printf("  ");
        }

        printf("    ");

        for(j = 0; j < niveau->actuel.x; j++) //boucle for qui affichera un tableau grâce à des caractères UTF-8 entourant toutes les cases
        {
            printf("%c%c%c", 0xE2, 0x94, 0x80);
            printf("%c%c%c", 0xE2, 0x94, 0x80);
            printf("%c%c%c", 0xE2, 0x94, 0x80);
            printf("%c%c%c", 0xE2, 0x94, 0xBC);
        } //fin boucle for
        printf("\n");
    }

} //fin première fonction

void score(Partie * partie) //première fonction qui permettra l'affichage du score en heure:minutes:secondes lorsque le hanjie sera correctement fini et réussi
{
    int h = partie->temp / 3600;
    int s = (int)partie->temp % 3600;
    int m = s / 60;
    s = s % 60;

    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;

    char lettre[9];
    sprintf(lettre,"%d:%d:%d", h, m, s); //pour vérification...



        for (i = 0; i < sizeof(lettre); i++)
        {
            printf("%c", lettre[i]);
        }

    printf("\n\n");
    printf("\n\n");

    int tab[5][3]; //initialisation des tableaux -> tab à deux dimensions et temps à trois dimensions
    int temps[8][5][3];

    if (h < 10 && m < 10 && s < 10){sprintf (lettre,"0%d:0%d:0%d",h,m,s);} // lors de l'affichage du score, ces if, else if et else empêchent le dépassement de tableau
    else if (h < 10 && m < 10 && s >= 10){sprintf (lettre,"0%d:0%d:%d",h,m,s);}
    else if (h < 10 && m >= 10 && s < 10){sprintf (lettre,"0%d:%d:0%d",h,m,s);}
    else if (h < 10 && m >= 10 && s >= 10){sprintf (lettre,"0%d:%d:%d",h,m,s);}
    else if (h >= 10 && m < 10 && s < 10){sprintf (lettre,"%d:0%d:0%d",h,m,s);}
    else if (h >= 10 && m < 10 && s >= 10){sprintf (lettre,"%d:0%d:%d",h,m,s);}
    else if (h >= 10 && m >= 10 && s < 10){sprintf (lettre,"%d:%d:0%d",h,m,s);}
    else {sprintf (lettre,"%d:%d:%d",h,m,s);} //fin différents if else if et else qui empêchent le dépassement de tableau

    for (z = 0; z < 8; z++) //première boucle for
    {
        switch (lettre[z]) // switch case qui affichera les chiffres à l'aide de plusieurs 0 et plusieurs 1
        {
            case '0':
            {
                int tab [5][3] = {{1,1,1},{1,0,1},{1,0,1},{1,0,1},{1,1,1}}; //affiche un 0
                for (k =0; k < 8; k++) //triple boucle for car tableau à trois dimensions
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case '1':
            {
                int tab [5][3] = {{0,0,1},{0,1,1},{0,0,1},{0,0,1},{0,0,1}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case '2':
            {
                int tab [5][3] = {{1,1,1},{0,0,1},{1,1,1},{1,0,0},{1,1,1}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case '3':
            {
                int tab [5][3] = {{1,1,1},{0,0,1},{1,1,1},{0,0,1},{1,1,1}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case '4':
            {
                int tab [5][3] = {{0,0,1},{0,1,1},{1,0,1},{1,1,1},{0,0,1}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case '5':
            {
                int tab [5][3] = {{1,1,1},{1,0,0},{1,1,1},{0,0,1},{1,1,1}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case '6':
            {
                int tab [5][3] = {{1,0,0},{1,0,0},{1,1,1},{1,0,1},{1,1,1}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case '7':
            {
                int tab [5][3] = {{1,1,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case '8':
            {
                int tab [5][3] = {{1,1,1},{1,0,1},{1,1,1},{1,0,1},{1,1,1}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case '9':
            {
                int tab [5][3] = {{1,1,1},{1,0,1},{1,1,1},{0,0,1},{0,0,1}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            case ':':
            {
                int tab [5][3] = {{0,0,0},{0,1,0},{0,0,0},{0,1,0},{0,0,0}};
                for (k =0; k < 8; k++)
                {
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            temps[z][i][j] = tab[i][j];
                        }
                    }
                }
            }
            break;

            default:
            {
                printf("Erreur");
            }
        } //fin switch case
    } //fin première boucle for

    for (i = 0; i < 5; i++) //dernière boucle for qui remplacera les 1 en case blanche et les 0 en espace, cela permettra d'afficher des chiffres comme on voulait
    {
        for (k = 0; k < 8; k++)
        {
            for (j = 0; j < 3; j++)
            {
                if (temps[k][i][j] == 1)
                {
                    printf("%c%c%c",0xE2, 0x96, 0x88);
                }
                else
                {
                    printf(" ");
                }
            }
            printf(" ");
        }
        printf("\n");
    } //fin deuxième boucle for
}
