#include "demineur.h"

static int getposAdj(int i, int j, int x, int y, int k)
{
    int ret;
    ret = 0;
    //checker si tout fonctione bien
    switch(k){
        case 0 :if(j == 0) ret = -1 ;
                    else if(i == 0) ret = -1 ;
                    else ret = (i - 1) * x + i - 1 ;
                    break ;
        case 1 :        
                    if(i == 0) ret = -1 ;        
                    else ret = (i - 1) * x + i ;       
                    break ;         
        case 2 :        
                    if(j == x - 1) ret = -1 ;       
                    else if(i == 0) ret = -1 ;
                    else ret = (i - 1) * x + j + 1 ;
                    break ;         
        case 3 :      
                    if(j == x - 1) ret = -1 ;      
                    else ret = (i) * x + j + 1;   
                    break ;     
        case 4 :
                    if(j == x - 1) ret = -1 ;   
                    else if(i == y - 1) ret = -1 ; 
                    else ret = (i + 1) * x + j + 1 ; 
                    break ;    
        case 5 :    
                    if(i == y - 1) ret = -1 ; 
                    else ret = (i + 1) * x + j ;
                    break ;       
        case 6 :       
                    if(j == 0) ret = -1 ; 
                    else if(i == y - 1) ret = -1 ; 
                    else ret = (i + 1) * x + j - 1 ;
                    break ;       
        case 7 :   
                    if(j == 0) ret = -1 ;
                    else ret = i * x + j - 1 ;   
                    break ; 
    }   
    return (ret);    
}
void    bombes_adjacentes(CASE *tab,int x,int y,int i,int j)
{
    char num;
    int pos;

    pos = (i * x) + j;
    if (tab[pos].val == '*')
    {
        for (int k = 0;k < 8; k++)
        {
            int posA;
            posA = getposAdj(i,j,x,y,k);//pos ou -1
            if (posA >= 0)
                if (tab[posA].val != '*')
                    tab[posA].val++;
        }
    }

}

CASE    *fill_tab(CASE *tab, int x,int y,int num_min)
{
    CASE c;
    int i;
    int j;
    int rand_value;
    int rand_num;

    srand(time(NULL));
    for (i = 0; i < (y * x); i++)
        tab[i].val = '0';
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

void    print_tab(CASE *tab, int x, int y)
{
    int i;
    int j;

    j = 0;
    i = 0;
    for (i = 0; i < y;i++)
    {
        for (j = 0; j < x;j++)
        {
            bombes_adjacentes(tab,x,y,i,j);
        }            
        printf("\n");
    }
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			int pos = i * x + j;
			printf("%c ", tab[pos].val);
		}
		printf("\n");
	}
}
