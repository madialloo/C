#include "liste_chaine.h"


struct strhash_table{
	unsigned int size;
	struct keyList{
		s_node * first;
		int nbElements;
	} *values;
};
/*
strhash_table *ht = malloc(size * sizeof(strhash_table));
ht->size = size;
ht->values->first->next = NULL;
ht->values->first->data = 0;
ht->values->nbElements = 1;

*/
// liste chainée de la table de hashage
/*struct keylist {
		s_node * first;
		int nbElements;
};

struct strhash_tab{
	int size;
	struct keylist *values;
}*/
// ------------------------------------

typedef struct strhash_table strhash_table;

strhash_table * strhash_create(int size);
void strhash_destroy(strhash_table * tab);
static unsigned int getKey(const char * word,int hashTableSize);
void liberate_data(const char * word,strhash_table * tab);
void delete_word(const char * word,strhash_table * tab);
strhash_table * add_word(const char * word,strhash_table * tab);
void strhash_show(strhash_table * tab);
//decrementer le nombre d'elements sur la liste supp et lib mot
