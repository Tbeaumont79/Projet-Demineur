#include <stdio.h>
#include "monconio.h"

#define HAUT 65
#define BAS 66
#define DROITE 67
#define GAUCHE 68
#define ECHAP 27
#define MODEFLECHE '['

#define TRUE 1
#define FALSE 0

int main(){
	ttyraw(0); 	// mode raw
	
	unsigned char ch[4];
	
	int echapFlag ;
	int modeFlecheFlag ;
	int nblu ;
	
	nblu = read(STDIN_FILENO,ch,sizeof(ch)); // lit sur stdin au maximum 4 caractères

	//DEBUG
	for(int i = 0 ; i < nblu ; i++)
		printf("[%d] = %02X\r\n",i,ch[i]);


	if(nblu >= 3){ // si plus d'un caratère mode echaptement détecté
		if((ch[0] == ECHAP) && ch[1] == MODEFLECHE ){
			printf("MODE ECHAPEMENT DETECTE FLECHE\r\n");
		}
        switch (ch[2]) {
            case HAUT:
                printf("HAUT\r\n");
                break;
            case BAS:
                printf("BAS\r\n");
                break;
            case DROITE:
                printf("DROITE\r\n");
                break;
            case GAUCHE:
                printf("GAUCHE\r\n");
                break;
            default:
                break;
        }
	}
	else{
		printf(">%02X<\r\n",ch[0]);
	}



	ttyreset(0); 	// necessaire pour remettre le clavier d'avant
	return 0;
}


