#include "demineur.h"

//on fait avec les coordonnées pour l'instant : 

int     is_win(CASE *tab, int size_x,int size_y)
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
int     print_area(int i, int j, int x,int y,int k)
{
   if (getposAdj(i,j,x,y,k) != -1)
       return (0)
   if (getposAdj(i + 1,j,x,y,k) != -1)
       return (1)
   if (getposAdj(i,j + 1,x,y,k) != -1)
       return (2);
   if (getposAdj(i + 1,j + 1,x,y,k) != -1)
       return (3);
   if (getposAdj(i - 1,j,x,y,k) != -1)
       return (4);
   if (getposAdj(i,j - 1,x,y,k) != -1)
       return (5);
   if (getposAdj(i - 1,j - 1,x,y,k) != -1)
       return (6);
   return (print_area(i,j,x,y,k));
}
int     play(CASE *tab, int size_x, int size_y,CASE value)
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
                        value.visible = 1;
                        print_tab(tab,size_x,size_y,value);
                        return (1);
                    }
                    if (tab[pos].val == '0')
                        value.visible = 2;
                    print_tab(tab,size_x,size_y,value);
                }
            }
            printf("\n");
        }
    }
    return (0);
}
