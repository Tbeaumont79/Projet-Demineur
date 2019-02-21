#include "demineur.h"

//on fait avec les coordonnées pour l'instant : 

int     play(CASE *tab, int size_x, int size_y,int j, int i)
{
    if (j > (size_x - 1) ||i > (size_y - 1))
        return (-1);
    if (j < 0 || i < 0)
        return (-1);
    int pos = i * size_x + j; 
    if (!tab[pos].visible)
        tab[pos].visible = 1;
    switch (tab[pos].val)
    {
        case '*': return (-2);
        case '0': break; //todo
        default: return (1);
    }
    return (0);
}
