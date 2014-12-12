#include "hanjie.h"

int hanjie (Partie *partie)
{


    char posCol,posLig;
    int i,j,g,POS,POS1,POS2;
    int a=0;
    int posCol1,posLig1;
    char position1[4];
    char lettreM[16]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
    char lettrem[16]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'};
    char chiffre[16]= {'1','2','3','4','5','6','7','8','9','10','11','12','13','14','15'};
    int etat=0;

    do
    {
        //Recupere les coordonnées
        affichage(partie);
        printf("Quelle case voulez vous selectionner ? (pour plus d'information taper HELP) ");
        scanf ("%s",&position1);
        //Affiche les aides
        if (position1[0]=='H'&&position1[1]=='E'&&position1[2]=='L'&&position1[3]=='P')
        {

            printf("Pour quitter taper : EXIT\nPour sauvegarder taper : SAVE\n");
            SystemPause();
            affichage(partie);
        }
        //Quitte la partie
        if(position1[0]=='E'&&position1[1]=='X'&&position1[2]=='I'&&position1[3]=='T')
        {
            etat=1;

        }
        //Sauvegarde la partie
        if(position1[0]=='S'&&position1[1]=='A'&&position1[2]=='V'&&position1[3]=='E')
        {

            etat=2;
        }

//Recherche pour savoir à quelle position se trouve la premiere lettre (en majuscule ou minuscule)//ĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵĵ

        POS= -1;
        for (i=0; (i<partie->actuel.x)&&(POS==-1); i++)
        {
            if (lettreM[i]==position1[0])
                POS=i;
            else if (lettrem[i]==position1[0])
                POS=i;

        }
//Recherche pour savoir à quelle position se trouve le second chiffre
        if (position1[2]==0)
        {
            POS1= -1;
            for (j=0; (j<partie->actuel.y)&&(POS1==-1); j++)
            {
                if (chiffre[j]==position1[1])
                    POS1=j;

            }
        }
//Si le la deuxieme coordonnée est une dizaine
        else if(position1[1]=='1'&&position1[2]=='0'&&partie->actuel.y>9)
        {
            POS1=9;
        }
        else if(position1[1]=='1'&&position1[2]=='1'&&partie->actuel.y>9)
        {
            POS1=10;
        }
        else if(position1[1]=='1'&&position1[2]=='2'&&partie->actuel.y>9)
        {
            POS1=11;
        }
        else if(position1[1]=='1'&&position1[2]=='3'&&partie->actuel.y>9)
        {
            POS1=12;
        }
        else if(position1[1]=='1'&&position1[2]=='4'&&partie->actuel.y>9)
        {
            POS1=13;
        }
        else if(position1[1]=='1'&&position1[2]=='5'&&partie->actuel.y>9)
        {
            POS1=14;
        }
        else
        {
            POS=-1;
        }


//Condition si l'utilisateur donne une coordonnée non valide
        if (POS==-1||POS1==-1)
        {
            system("clear");
            affichage(partie);
        }

//Modifie la case demandée
        else
        {
            if (partie->actuel.grille[POS1][POS]=='0')
            {
                partie->actuel.grille[POS1][POS]='1';
            }

            else
            {
                partie->actuel.grille[POS1][POS]='0';
            }
        }




    }
//Sortie du do si reussite du jeu ou alors si je joueur le demande
    while(verification(partie)&&etat==0);

    if (etat==2)
    return etat;
    if (etat==1)
    return etat;
    else  { system("clear");
    printf ("                     \n\n\n\n\n\n\n\n \n\n                          Bravo vous avez reussi !!\n\n\n\n");
    SystemPause();}
    return 3;
}
int verification(Partie *partie)
{
//La fonction parcourt le tableau et verifie si les deux grilles sont differentes
    int i,j,a=0;
    for (i=0; i<partie->actuel.x; i++)
    {
        for (j=0; j<partie->actuel.y; j++)
        {

            if (partie->actuel.grille[i][j]!=partie->pattern.grille[i][j])
                a=1;




        }

    }

    return a;




}









