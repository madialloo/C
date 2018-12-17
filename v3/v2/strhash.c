#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "strhash.h"
#include "liste_chaine.h"

strhash_table * strhash_create(int size){
	strhash_table * tab = malloc(size * sizeof(strhash_table));
	tab->size = size;
	int i;
	for(i = 0; i < tab->size; i++){
		tab[i]->values->first = list_create();
		tab[i]->values->nbElements = 1;
	}

	return tab;
	
}

void strhash_destroy(strhash_table * tab){
	int i;
	for(i = 0; i < tab->size; i++){
		list_destroy(tab[i]->values->first);
		// free(tab[i]);
	}
	free(tab);
	
}

static unsigned int getKey(const char * word,int hashTableSize){
	int key = 0;
	int i = 0;
	while(word[i]!= '\0'){
		key = key * 2;
		key = key + (int) word[i];	
	}
	key = key % hashTableSize;
	return key;
}

strhash_table * add_word(const char * word,strhash_table * tab){

	int i;
	int hash = getKey(word,tab->size);
	s_node * node;
	for(i=0;i<tab->size;i++){
		while(tab[i]->values->first!=NULL){
			if(tab[i]->values->first->data == word){
				printf("Element existant\n");
				return tab;
			}
			tab[i]->values->first = tab[i]->values->first->next;
		}
	}

	for(i=0;i<tab->size;i++){
			if(i==hash){
				while(tab[i]->values->first!=NULL){
					tab[i]->values->first = tab[i]->values->first->next;
				}
				tab[i]->values->first->next = node;
				node->next = NULL;
				node->data = word;
				tab[i]->values->nbElements++;
			}
	}
	
}

void liberate_data(const char * word,strhash_table * tab){

	int i;
	for(i=0;i<tab->size;i++){
		while(tab[i]->values->first!=NULL){
			free(tab[i]->values->first->data);
			tab[i]->values->first = tab[i]->values->first->next;
		}
	}
}

void delete_word(const char * word,strhash_table * tab){

	int i;
	for(i=0;i<tab->size;i++){
		while(tab[i]->values->first!=NULL){
			if(tab[i]->values->first->data == word){
				tab[i]->values->first = list_remove(tab[i]->values->first, word);
				tab[i]->values->nbElements--;
			}
			tab[i]->value->first = tab[i]->value->first->next;
		}
	}
}

void strhash_show(strhash_table * tab){

	int i;
	int sumElements = 0;
	int max =0;
	int min = 0;
	double moyenne = 0.0;
	double s_Ecart = 0.0;
	double ecart = 0.0;
	(void*) temp;

	for(i=0;i<tab->size;i++){
		/*while(tab[i]->values->first!=NULL){
			// if(tab[i]->values->first->data == word){
				tab[i]->values->first = tab[i]->values->first->next;
				sumElements++;
			}*/
		// calculate the sum 
		sumElements = sumElements + tab[i]->values->nbElements;
		// calculate the max and min
		if(max < tab[i]->values->nbElements){
			max = tab[i]->values->nbElements;
		}
		if(min > tab[i]->values->nbElements){
			min = tab[i]->values->nbElements;
		}

	}
	// calculate the average
	moyenne = sumElements / tab->size;
	// calcute the "ecart-type"
	for(i=0;i<tab->size;i++){
		s_Ecart += ( (tab[i]->values->nbElements - moyenne) * (tab[i]->values->nbElements - moyenne) );
	}
	ecart = sqrt( s_Ecart / size );




	
}

