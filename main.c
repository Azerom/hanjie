#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "menu.h"

int main()
{

    Partie partie;
    partie.pattern.grille = NULL;

    menuPrincipal(&partie);


    if(partie.pattern.grille != NULL)
    {
        liberationPartie(&partie);
    }

    return 0;
}
