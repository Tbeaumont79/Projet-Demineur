#include "demineur.h"

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
        case '*': tab[pos].visible = 1;
                  return (-2);
        case '0':
                  tab[pos].visible = 1;
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
