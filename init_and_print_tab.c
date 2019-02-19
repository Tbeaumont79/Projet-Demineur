#include "demineur.h"



CASE    *fill_tab(CASE *tab, int x,int y,int num_min)
{
    int i;
    int rand_num;

    srand(time(NULL));
    for (i = 0; i < (y * x); i++)
    {
        tab[i].val = '0';
    }
    for (i = 0; i < num_min;i++)
    {
        rand_num = rand() % ((y * x) + 1);
        if (tab[rand_num].val == '*')
            i--;
        else
            tab[rand_num].val = '*';
    }
    return (tab);
}

void    print_tab(CASE *tab, int x, int y, CASE value)
{
    int i;
    int j;


    j = 0;
    i = 0;
    for (i = 0; i < y;i++)
    {
        for (j = 0; j < x;j++)
        {
            check_allCase(tab,x,y,i,j);
        }            
    }
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			int pos = i * x + j;
            if (value.visible)
			    printf("%c ", tab[pos].val);
            else
                printf("-  ");
		}
		printf("\n");
	}
}
