#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonc.h"

// ajoute un mot et retourne le numéro de lelement du tableau où le mot est enregistré
int ajouteMot(mot tab[], int NB_MAX_MOT, mot *mot){
    int i = 0;
    int poqition_added_Element = 0;
    for(int i = 0; i < NB_MAX_MOT; i++){
        if( &tab[i] == 0){
            tab[i].posMot.abs = mot->posMot.abs;
            tab[i].posMot.ordo = mot->posMot.ordo ;
            tab[i].word.chaineMot = mot->word.chaineMot ;
            tab[i].orientMot = mot->orientMot;
            break;
        poqition_added_Element = tab[i];
        }
    }
    return poqition_added_Element;
}




void  displayTab(int *tab, int tabLength){

    int i = 0;

    while (i < tabLength){
        printf("tab[%d]->%d\n", i, i);
        i++;
    }
}