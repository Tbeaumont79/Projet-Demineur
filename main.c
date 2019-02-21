#include "demineur.h"

int main (void)
{
    CASE sizeX;
    CASE sizeY;
    CASE num_b;
    int x;
    int y;
    CASE *tab;

    x = 0;
    y = 0;
    system("clear");
    printf("Veuillez saisir une taille en largeur \n");
    scanf("%d",&sizeX.x);
    printf("Veuillez saisir une taille en hauteur \n");
    scanf("%d",&sizeY.y);
    printf("veuillez saisir le nombre de mine \n ");
    scanf("%d",&num_b.mine);
    printf("x = %d et y = %d\n",sizeX.x,sizeY.y);
    if ((tab = (CASE *)malloc(sizeof(CASE) * sizeX.x * sizeY.y)) == NULL)
    {
        printf("problem d'allocation mémoire ! 😀\n");
        return (1);
    }
    fill_tab(tab,sizeX.x,sizeY.y,num_b.mine);
    print_tab(tab,sizeX.x,sizeY.y);
    while (1)
    {
        printf("entrez les coordonées de x : \n");
        scanf("%d",&x);
        printf("entrez les coordonées de y : \n");
        scanf("%d",&y);
        if (play(tab,sizeX.x,sizeY.y,x,y) == -1)
            printf("bad value");
        if (play(tab,sizeX.x,sizeY.y,x,y) == -2)
        {
            printf("GAMEOVER");
            return (0);
        }
        print_tab(tab,sizeX.x,sizeY.y);
    }
   // faire un s@:wcanf pour récupérer la taille du démineur
   // size X
   // size Y
   // scanf pour récupérer les coordonées entrée par l'utilisateur
   return (0);
}
