#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonc.h"

void  displayTab(int *tab, int tabLength){

    int i = 0;

    while (i < tabLength){
        printf("tab[%d]->%d\n", i, i);
        i++;
    }
}