#include "demineur.h"

static int getposAdj(int i, int j, int x, int y, int k)
{
    int ret;
    ret = 0;
    //checker si tout fonctione bien
    switch(k){
        case 0 :
                    printf("DEBUG1\n");
                    if (j == 0) ret = -1 ;
                    else if (i == 0) ret = -1 ;
                    else ret = (i - 1) * x + (j - 1);
                    break ;
        case 1 :        
                    printf("DEBUG2\n");
                    if (i == 0) ret = -1 ;        
                    else ret = (i - 1) * x + (j); 
                    break ;         
        case 2 :        
                    printf("DEBUG3\n");
                    if (j == x - 1) ret = -1 ;       
                    else if (i == 0) ret = -1 ;
                    else ret = (i - 1) * x + (j + 1);
                    break;     
        case 3 :      
                    printf("DEBUG4\n");
                    if (j == x - 1) ret = -1 ;      
                    else ret = (i) * x + (j + 1);   
                    break;     
        case 4 :
                    printf("DEBUG5\n");
                    if (j == x - 1) ret = -1 ;   
                    else if(i == y - 1) ret = -1 ; 
                    else ret = (i + 1) * x + (j + 1); 
                    break;    
        case 5 :    
                    printf("DEBUG6\n");
                    if(i == y - 1) ret = -1 ; 
                    else ret = (i + 1) * x + j;
                    break;       
        case 6 :       
                    printf("DEBUG7\n");
                    if(j == 0) ret = -1 ; 
                    else if(i == y - 1) ret = -1 ; 
                    else ret = (i + 1) * x + (j - 1);
                    break;       
        case 7 :   
                    printf("DEBUG8\n");
                    if(j == 0) ret = -1 ;
                    else ret = i * x + (j - 1);   
                    break; 
    }   
    return (ret);    
}
void    bombes_adjacentes(CASE *tab,int x,int y,int i,int j)
{
    int pos;

    pos = (i * x) + j;
    if (tab[pos].val == '*')
    {
        for (int k = 0;k < 8; k++)
        {
            int posA;
            posA = getposAdj(i,j,x,y,k);//pos ou -1 
            printf("La valeur de pos[A] est de :  %d\n",tab[posA].val);
            if (posA >= 0)
                if (tab[posA].val != '*')
                {
                    tab[posA].val++;
                }
        }
    }

}

CASE    *fill_tab(CASE *tab, int x,int y,int num_min)
{
    int i;
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
