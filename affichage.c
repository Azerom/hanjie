#include "affichage.h"
#include <time.h>

void affichage (Partie * niveau)
{

    int i,j,k;

    system("clear");
    menuHead("Hanjie n°1");

    for(j = 0; j < niveau->nbIndiceMaxLigne; j++)
        {
            printf("  ");
        }
        printf("     ");

for (i = 0; i < niveau->actuel.x; i++)
{

        printf("\x1b[36m%c\x1b[0m   ",i+65);

}

    printf("\n");

    for (i = 0; i < niveau->nbIndiceMaxColonne; i++)
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
    }

    for (i = 0; i < niveau->actuel.y; i++)
    {

        printf("\x1b[36m%2d |\x1b[0m ",i+1);

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
        for(j = 0; j < niveau->actuel.x; j++)
        {
            if (niveau->actuel.grille[i][j] == '1')
            {
                printf("%c%c%c | ", 0xE2, 0x96, 0xA9);
            }

            else
            {
                printf("%c%c%c | ", 0xE2, 0x96, 0xA1);
            }
        }
        printf("\n");
        for(j = 0; j < niveau->nbIndiceMaxLigne; j++)
        {
            printf("  ");
        }

        printf("    ");

        for(j = 0; j < niveau->actuel.x; j++)
        {
            printf("%c%c%c", 0xE2, 0x94, 0x80);
            printf("%c%c%c", 0xE2, 0x94, 0x80);
            printf("%c%c%c", 0xE2, 0x94, 0x80);
            printf("%c%c%c", 0xE2, 0x94, 0xBC);
        }
        printf("\n");
    }

}

void score(Partie * niveau)
{

int h = 1;
int m = 47;
int s = 21;

int i = 0;
int j = 0;
int k = 0;
int z = 0;

char lettre[9];
sprintf(lettre,"%d:%d:%d", h, m, s);

    for (i = 0; i < sizeof(lettre); i++)
    {
        printf("%c", lettre[i]);
    }

    printf("\n\n");
    printf("\n\n");

    int tab[5][3];
    int temps[8][5][3];

for (z = 0; z < 8; z++)
{

    switch (lettre[z])
    {
        case '0':
        {
        int tab [5][3] = {{1,1,1},{1,0,1},{1,0,1},{1,0,1},{1,1,1}};
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
        int tab [5][3] = {{1,1,1},{1,0,1},{1,0,1},{1,0,1},{1,1,1}};
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
    }

}

for (i = 0; i < 5; i++)
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
    }

}
