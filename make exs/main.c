#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonc.h"

#define SIZE 10

// main program
int main(){

    int i = 0;
    int tab[SIZE];

    // initialize it 
    while (i < SIZE ){
        printf("Enter value :");
        scanf("%d", &tab[i]);
        i++;
    }
    // display it
    displayTab(tab,SIZE);

    return 0;
    

}