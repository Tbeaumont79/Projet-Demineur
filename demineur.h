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
void    check_allCase(CASE *tab,int x,int y,int i,int j);
int     getposAdj(int i, int j, int x, int y, int k);
int     is_win(CASE *tab, int size_x, int size_y);
int     play(CASE *tab, int size_x, int size_y);
#endif
