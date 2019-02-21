#include "demineur.h"
//on fait avec les coordonnées pour l'instant : 

int     play(CASE *tab, int size_x, int size_y,int j, int i)
{
    int ret;
    ret = 0;

    if (j > (size_x - 1) ||i > (size_y - 1))
        return (-1);
    if (j < 0 || i < 0)
        return (-1);
    int pos = i * size_x + j;
    if (tab[pos].visible == 1)
    {
        printf("deja découvert\n");
        return (2);
    }
    switch (tab[pos].val)
    {
        case '*': tab[pos].visible = 1;
                  return (-2);
        case '0':
                  tab[pos].visible = 1;
                  //checker si tout fonctione bien
                  play(tab,size_x,size_y,j - 1,i - 1);
                  play(tab,size_x,size_y,j,i - 1);
                  play(tab,size_x,size_y,j + 1,i + 1);
                  play(tab,size_x,size_y,j,i + 1);
                  play(tab,size_x,size_y,j - 1,i + 1);
                  play(tab,size_x,size_y,j - 1,i);
        default: tab[pos].visible = 1;
    }
    return (0);
}
