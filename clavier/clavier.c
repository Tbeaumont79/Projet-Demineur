#include <stdio.h>
#include "monconio.h"


int main(){
	ttyraw(0); 	// mode raw

	printf(">%02X<\r\n",getchar());



	ttyreset(0); 	// necessaire pour remettre le clavier d'avant
	return 0;
}
