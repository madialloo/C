#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonc_3.h"

// #define MAX_SIZE 1000


void  loadtext(char* fileName){

    char buffer[1000];
    // number of characters---
    int nbChar = 0;
    /*** get_read the file ***/
    FILE * fpOne = fopen(fileName,"r+");
    if( fpOne == NULL){
        printf("file error\n");
    }
    // allocation an array to store each file 
    char *fpFileOne = malloc(sizeof(char));

    // process-read the file into the array ------
    char c;
    int i = 0;
    while (fscanf(fpOne,"%c",&fpFileOne[i]) != EOF ){
       ++i;
    }
    // copy fpFileOne content to the buffer ---
    // strcpy(buffer,fpFileOne); 
    // display  the file 
    for(i = 0; i < strlen(fpFileOne); i++){
        printf("%c", fpFileOne[i]);
        nbChar++;
    }
    // print out the sum of char
    printf("\n%d\n", nbChar);


}