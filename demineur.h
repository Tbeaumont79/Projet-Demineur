#ifndef DEMINEUR_H
#define DEMINEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    char visible;
    char val;
    int x;
    int y;
    int mine;
}       CASE;

CASE    *fill_tab(CASE *tab, int x,int y,int num_min);
void    print_tab(CASE *tab,int x, int y);
#endif
