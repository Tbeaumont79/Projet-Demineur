#include "demineur.h"

//on fait avec les coordonnées pour l'instant : 

int     is_win(CASE *tab, int size_x, int size_y)
{
    int k;

    k = 0;
    for (int i = 0; i < size_y; i++)
        for (int j = 0; j < size_x; j++)
            if (tab->visible)
                k++;
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
    int pos;

    pos = 0;
    k = 0;
    printf("saisir une valeur en x : ");
    scanf("%d",&x);
    printf("saisir une valeur en y : ");
    scanf("%d",&y);
    printf("\n\n vous avez mis x : %d et y : %d\n\n",x,y);
    while ((x < size_x || y < size_y) || (x >= 0 || y >= 0) || is_win(tab,size_x,size_y))
    {
        printf("saisir une valeur en x : ");
        scanf("%d",&x);
        printf("saisir une valeur en y : ");
        scanf("%d",&y);
        printf("\n\n vous avez mis x : %d et y : %d\n\n",x,y);
        for (int i = 0;i < size_y; i++)
        {
            for (int j = 0; j < size_x; j++)
            {
                if (i == y && j == x)
                {
                    pos = i * size_x + j;
                    if (tab[pos].val == '*')
                    {
                        printf("GAME OVER\n\n\n");
                        print_tab(tab,size_x,size_y);
                        return (1);
                    }
                    else if (tab[pos].val == '0')
                    {
                        printf("%c  ",tab[pos].val);
                    }
                    else if (tab[pos].val != '0' || tab[pos].val != '*')
                        printf("%c  ",tab[pos].val);
                }
            }
            printf("\n");
        }
    }
    return (0);
}
