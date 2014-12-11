#include "hanjie.h"

void hanjie (Partie *partie){


char posCol,posLig;
int i,j,g,POS,POS1;
int posCol1,posLig1;
char position1[4];
char lettreM[16]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
char lettrem[16]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'};
char chiffre[16]={'1','2','3','4','5','6','7','8','9','10','11','12','13','14','15'};
char dizaine[3];
do{
    affichage(partie);
    printf("Quelle case voulez vous selectionner ? (pour plus d'information taper HELP) ");
    scanf ("%s",&position1);
if (position1[0]=='H'&&position1[1]=='E'&&position1[2]=='L'&&position1[3]=='P'){

printf("Pour quitter taper : EXIT\nPour sauvegarder taper : SAVE\n");
SystemPause();
affichage(partie);
}

if(position1[0]=='E'&&position1[1]=='X'&&position1[2]=='I'&&position1[3]=='T')
{
menuJeu(partie);

}
if(position1[0]=='S'&&position1[1]=='A'&&position1[2]=='V'&&position1[3]=='E'){

sauvegarde(partie, "  ");
}
//Recherche pour savoir à quelle position se trouve la premiere lettre (en majuscule ou minuscule)//

    POS= -1;
    for (i=0;(i<partie->actuel.x)&&(POS==-1);i++){
        if (lettreM[i]==position1[0])
            POS=i;
        else if (lettrem[i]==position1[0])
            POS=i;

}
//Recherche pour savoir à quelle position se trouve le second chiffre
if (position1[2]==0){
    POS1= -1;
    for (j=0;(j<partie->actuel.y)&&(POS1==-1);j++){
        if (chiffre[j]==position1[1])
            POS1=j;

            }
}

else if(position1[1]=='1'&&position1[2]=='0'){
POS1=9;
}
 else if(position1[1]=='1'&&position1[2]=='1'){
POS1=10;
}
 else if(position1[1]=='1'&&position1[2]=='2'){
POS1=11;
}
 else if(position1[1]=='1'&&position1[2]=='3'){
POS1=12;
}
 else if(position1[1]=='1'&&position1[2]=='4'){
POS1=13;
}
 else if(position1[1]=='1'&&position1[2]=='5'){
POS1=14;
}
else {
POS=-1;
    }


//Condition si l'utilisateur donne une coordonnée non valide
if (POS==-1||POS1==-1){
            system("clear");
            affichage(partie);
            score(partie);
}
//Modifie la case demandée
else {
        if (partie->actuel.grille[POS1][POS]=='0'){
            partie->actuel.grille[POS1][POS]='1';
}

    else{
        partie->actuel.grille[POS1][POS]='0';
}
}
    system("clear");
    affichage(partie);
    score(partie);

}

while (partie->pattern.grille!=partie->actuel.grille);
printf ("Vous avez gagne !!");
}








