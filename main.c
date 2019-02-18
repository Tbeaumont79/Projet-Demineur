#include "demineur.h"

int main (void)
{
    CASE sizeX;
    CASE sizeY;
    CASE num_b;
   
    printf("Veuillez saisir une taille en largeur \n");
    scanf("%d",&sizeX.x);
    printf("Veuillez saisir une taille en hauteur \n");
    scanf("%d",&sizeY.y);
    printf("veuillez saisir le nombre de mine \n ");
    scanf("%d",&num_b.mine);
    printf("x = %d et y = %d\n",sizeX.x,sizeY.y);
    CASE *tab;
    if ((tab = (CASE *)malloc(sizeof(CASE) * sizeX.x * sizeY.y)) == NULL)
    {
        printf("problem\n");
        return (1);
    }
    tab->visible = 0;
    fill_tab(tab,sizeX.x,sizeY.y,num_b.mine);
    play(tab,sizeX.x,sizeY.y);
   // faire un s@:wcanf pour récupérer la taille du démineur
   // size X
   // size Y
   // scanf pour récupérer les coordonées entrée par l'utilisateur
   return (0);
}
