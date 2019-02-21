#include "demineur.h"

int main (void)
{
    int x;
    int y;
    CASE sizeX;
    CASE sizeY;
    CASE num_b;
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
    if ((tab = (CASE *)malloc(sizeof(CASE) * sizeX.x * sizeY.y)) == NULL)
    {
        printf("problem d'allocation mémoire ! 😀\n");
        return (1);
    }
    fill_tab(tab,sizeX.x,sizeY.y,num_b.mine);
    print_tab(tab,sizeX.x,sizeY.y);
    while (is_win(tab,sizeX.x,sizeY.y,num_b.mine) != 1)
    {// mettre en place le systeme de curseur afin de pouvoir jouer avec les fleches ! 
        printf("entrez les coordonées de x : \n");
        scanf("%d",&x);
        printf("entrez les coordonées de y : \n");
        scanf("%d",&y);
        if (play(tab,sizeX.x,sizeY.y,x,y) == -1)
            printf("bad value");
        if (play(tab,sizeX.x,sizeY.y,x,y) == -2)
        {
            printf("GAMEOVER\n\n");
            print_tab(tab,sizeX.x,sizeY.y);
            return (0);
        }
        if (is_win(tab,sizeX.x,sizeY.y,num_b.mine))
        {
            printf("FELICITATION Tu as gagné .\n");
            print_tab(tab,sizeX.x,sizeY.y);
            return (0);
        }
        print_tab(tab,sizeX.x,sizeY.y);
    }
    free(tab);
    return (0);
}
