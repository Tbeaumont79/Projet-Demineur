#include "demineur.h"


int getposAdj(int i, int j, int x, int y, int k)
{
    int ret;
    ret = 0;
    //checker si tout fonctione bien
    switch(k){
        case 0 :
                    if (j == 0) ret = -1 ;
                    else if (i == 0) ret = -1 ;
                    else ret = (i - 1) * x + (j - 1);
                    break ;
        case 1 :        
                    if (i == 0) ret = -1 ;        
                    else ret = (i - 1) * x + (j); 
                    break ;         
        case 2 :        
                    if (j == x - 1) ret = -1 ;       
                    else if (i == 0) ret = -1 ;
                    else ret = (i - 1) * x + (j + 1);
                    break;     
        case 3 :    
                    if (j == x - 1) ret = -1;
                    else ret = (i) * x + (j + 1);   
                    break;     
        case 4 :
                    if (j == x - 1) ret = -1 ;   
                    else if(i == y - 1) ret = -1 ; 
                    else ret = (i + 1) * x + (j + 1); 
                    break;    
        case 5 :    if (i == y - 1) ret = -1;
                    else ret = (i + 1) * x + j;
                    break;       
        case 6 :       
                    if(j == 0) ret = -1 ; 
                    else if(i == y - 1) ret = -1 ; 
                    else ret = (i + 1) * x + (j - 1);
                    break;       
        case 7 :   
                    if(j == 0) ret = -1 ;
                    else ret = i * x + (j - 1);   
                    break; 
    }   
    return (ret);    
}

void    check_allCase(CASE *tab,int x,int y,int i,int j)
{
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
                {
                    tab[posA].val++;
                }
        }
    }

}
