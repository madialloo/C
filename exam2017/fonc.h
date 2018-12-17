#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** structure de données du mot ***/
// definir la position 
typedef enum orientation {
    VERTICAL,
    HORIZONTAL
} orientation;
// definir le la position
typedef struct position {
    char abs;
    int ordo;
} position;
// definir lla struct les letres de mots
typedef struct lettres {
    char *chaineMot;
    int lmot;
} lettres;
// definition de la structure mot 
typedef struct mot {
    // position : ordonnée et abs
    position posMot;
    // orientation : vertical ou horizontal
    orientation orientMot;
    // (longueur) lettres du mot
    lettres word;
} mot;

/*** -------------------------------------- ***/
// ajoute un mot et retourne le numéro de lelement du tableau où le mot est enregistré
int ajouteMot(mot *tab, int NB_MAX_MOT, mot *mot);