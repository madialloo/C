#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonc.h"

#define NB_MAX_MOT 10

// main program
int main(){

    // tab contenant les mots 
    mot  tab[NB_MAX_MOT];
    //  = malloc( sizeof(mot));
    for( int j = 0; j < NB_MAX_MOT; j++){
        tab[j] = malloc(sizeof(mot));
    }

    int i ;
    // define a word
    mot *new_word = malloc(sizeof(mot));
    // initialise the new_word
    new_word->orientMot = VERTICAL;
    new_word->posMot.abs = 1;
    new_word->posMot.ordo = 'A';
    new_word->word.chaineMot = "Aliou";
    new_word->word.lmot = 6;
    // add a word to the array of words
    ajouteMot(&tab,NB_MAX_MOT,&new_word);
    // initialize it 
    while (i < NB_MAX_MOT){
        printf("tab[%d]->%s\n", i, tab[i].word.chaineMot);
        i++;
    }
    // display it

    return 0;
    

}