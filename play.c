#include "demineur.h"

//on fait avec les coordonnées pour l'instant : 

int     is_win(CASE *tab, int size_x, int size_y)
{
    int k;

    k = 0;
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            if (tab->visible)
                k++;
        }
    }
    if (k == (size_x * size_y))
        return (0);
    return (1);
}

int    play(CASE *tab, int size_x, int size_y)
{
    // on récupère les coordonées saisi
    int x;
    int y;
    int k;

    k = 0;
    printf("saisir une valeur en x : ");
    scanf("%d",&x);
    printf("saisir une valeur en y : ");
    scanf("%d",&y);
    printf("\n\n vous avez mis x : %d et y : %d\n\n",x,y);
    while ((x > size_x || y > size_y) || (x < 0 || y < 0))
    {
        printf("bad value\n");
        printf("saisir une valeur en x : ");
        scanf("%d",&x);
        printf("saisir une valeur en y : ");
        scanf("%d",&y);
        printf("\n\n vous avez mis x : %d et y : %d\n\n",x,y);
    }
    for (int i = 0;i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            if (j == x && y == i)
            {
                if (tab[j].val == '*')
                {
                    printf("GAME OVER\n");
                    tab->visible = 1;
                    return (1);
                }
                else if (tab[j].val == '0')
                {
                    tab->visible = 1;
                }
            }
        }
    }
    print_tab(tab, size_x,size_y); 
    return (0);
}
