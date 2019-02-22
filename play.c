#include "demineur.h"

int     is_win(CASE *tab,int size_x, int size_y, int num_min)
{
    int k;
    int i;
    int j;

    k = 0;
    for (i = 0; i < size_y; i++)
    {
        for (j = 0; j < size_x; j++)
        {
            if (tab[j].visible)
                k++;
            if (k == (size_x * size_y) - num_min)
                return (1);
        }
    }
    return (0);
}

int     play(CASE *tab, int size_x, int size_y,int j, int i)
{
    int ret;
    int pos;

    pos = i * size_x + j;
    ret = 0;
    if (j > (size_x - 1) ||i > (size_y - 1) || j < 0 || i < 0)
        return (-1);
    if (tab[pos].visible == 1)
        return (2);
    switch (tab[pos].val)
    {
        case '*': return (-2);
        case '0':
                  tab[pos].visible = 1;
                  play(tab,size_x,size_y,j - 1,i - 1);
                  play(tab,size_x,size_y,j,i - 1);
                  play(tab,size_x,size_y,j + 1,i + 1);
                  play(tab,size_x,size_y,j,i + 1);
                  play(tab,size_x,size_y,j - 1,i + 1);
                  play(tab,size_x,size_y,j - 1,i);
                  break;
        default: tab[pos].visible = 1;
                 return (1);
    }
    return (0);
}
