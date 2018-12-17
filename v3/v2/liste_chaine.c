#include <stdio.h>
#include <stdlib.h>
#include "liste_chaine.h"


s_node * list_create(void){
	//creation d'une nouvelle liste vide
	s_node * list=NULL;
	list = (s_node*) malloc(sizeof(s_node));
	list->data=NULL;
	list->next=NULL;
	return list;
}

void * list_get_data(s_node * node){
	//lire la donnee d'un noeud
	return node->data;
}

void list_set_data(s_node * node,void * data){
	//ecrire la donnee d'un noeud
	node->data = data;
	
}

s_node * list_insert(s_node * head,void * data){
	//creation et insertion d'un noeud en tete de liste
	//retourne la tete de liste
	s_node * node = list_create();
	list_set_data(node, data);
	head = node;
	return head;
}

s_node * list_append(s_node * head,void * data){
	//creation et ajout d'un noeud en queue de liste
	//retourne la tete de liste
	s_node * node = list_create();
	s_node * node_parc = head;
	while(node_parc->next!=NULL){
		node_parc=node_parc->next;	
	}
	list_set_data(node, data);
	node_parc->next = node;
	return head;
	
	
	
}



int list_process(s_node * head, int (*fct)(s_node * node,void * param),void * param,s_node ** last){
	//application d'une fonction sur les donnees enregistrees
	//dans la liste. last est le dernier noeud traite
	//retourne 1 sur le parcours et arrete avant la fin de la liste
	s_node * node_parc = head;

	while (node_parc->next!=NULL){

		if((*fct)(node_parc,param)==1){
			*last = node_parc;
			return 1;	
		}
		node_parc = node_parc->next;
		
	}
	*last = node_parc;
	if((*fct)(node_parc,param)==1){
	return 0;
	}
	else
	{
		return -1;	
	}
}

s_node * ordered_list_append(s_node * head, int (*fct)(s_node * node,void * param),void * param){
	if(head == NULL){
		return NULL;	
	}
	s_node * node_parc = head;
	s_node * node = list_create();
	while (node_parc->next!=NULL){
		if((*fct)(node_parc,param)==1){ 
			if ((*fct)(node_parc->next,param)==-1){
				break;
			}
		}
		else{
			continue;		
		}
		node_parc = node_parc->next;
	}
	
	if(node_parc!=NULL){
			s_node * tmp;
			tmp = node_parc->next;
			node_parc->next = node;
			node->next = tmp;	
			
			//node->data = param;
			list_set_data(node,param);
			return head;
	}
	if((*fct)(node_parc,param)==1){
			node->next = NULL;	
			node_parc->next = node;
			node->data = param;
			return head;
	}
	else{return NULL;}
}


s_node * list_remove(s_node * head, void * data){
	/*suppression de la premiere instance d'une donnee
	dans la liste, retourne la tete de liste*/

	if(head == NULL){
		return NULL;	
	}
	//si le noeud est en tete de liste
	if(head->data == data){
		head = 	list_headRemove(head);
	}
	//si le noeud est en queue de liste
	//temp le noeud avant dernier
	s_node * node_fin, *temp;
	node_fin = head;
	while(node_fin->next != NULL){  
		temp = node_fin;
		node_fin = node_fin->next;
	}
	if(node_fin->data == data){
		if(temp != NULL){
			temp->next = NULL;
		}
		free(node_fin);
	}
	//si le noeud est au milieu de liste
	s_node * node;
	node = head;
	while(node->next!=NULL){
		if(node->next->data==data){
			break;	
		}
		node = node->next;	
	}
	if(node != NULL){
		s_node * tmp = node ->next;
		node->next = tmp ->next;
		tmp ->next = NULL;
		free(tmp);	
	}

	return head;
}

s_node * list_headRemove(s_node * head){
	//suppression de la tete de liste 
	//retourne la nouvelle tete de liste
	if(head==NULL){
		return NULL;
	}
	s_node * nouveau_head;
	nouveau_head = head;
	head = head->next;
	nouveau_head->next = NULL;
	if (nouveau_head == head){
		head = NULL;	
	} 
	free(nouveau_head);
	return head;
}

void list_destroy(s_node * head){
	//la destruction d'une liste
	s_node * node_par, *temp;
	if(head!=NULL){
		node_par = head->next;
		head->next = NULL;
		free(head);
		while(node_par!=NULL){
			temp = node_par->next;
			//node_par->next = NULL;
			free(node_par);
			node_par=temp;		
		}			
	}
}
















