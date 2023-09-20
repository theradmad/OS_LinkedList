// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist = (list_t *) (malloc(sizeof(list_t)));
  mylist->head=NULL;
  return mylist;
}
void list_free(list_t *l) {
  if (l == NULL)
    return;
  node_t *current = l->head;
  while (current != NULL) {
    node_t *next = current->next;
    free(current);
    current = next;
  }

  free(l);

}

void list_print(list_t *l) {
  node_t *current = l->head;
    while (current != NULL) {
      printf("%d ", current->value);
      current = current->next;
    }
    printf("\n");
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { 
  int count = 0;
  node_t* cur_node = l->head;
  while (cur_node != NULL){
    count +=1;
    cur_node = cur_node->next;
  }
  return count;
 }

void list_add_to_back(list_t *l, elem value) {
  int count = 0;
  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  node_t* cur_node = l->head;
  while (cur_node != NULL){
    count +=1;
    cur_node = cur_node->next;
    if (count == list_length(l)-1) {
      cur_node->next=new_node;
      new_node->next=NULL;
    }
  }
}
void list_add_to_front(list_t *l, elem value) {
  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value=value;
  new_node->next = NULL;
  
  node_t* head = l->head; //get head of list
 	new_node->next = head;
  l->head = new_node;

}
void list_add_at_index(list_t *l, elem value, int index) {
  if (index < 1 || index > list_length(l) + 1) {
    printf("Invalid index.\n");
    return;
  }

  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  if (index == 1) {
    list_add_to_front(l, value);
		return;
  }
  int count = 1;
  node_t* cur_node = l->head;

  while (count < index - 1) {
    cur_node = cur_node->next;
    count++;
  }

  new_node->next = cur_node->next;
  cur_node->next = new_node;
}


elem list_remove_from_back(list_t *l) {
  if (l->head == NULL) {
    printf("List is empty.\n");
		return -1;
  }
  if (l->head->next == NULL) {
    elem value = l->head->value;
    free(l->head);
    l->head = NULL;
    return value;
  }

  node_t *current = l->head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  elem value = current->next->value;
  current->next = NULL;
  return value;
}

elem list_remove_from_front(list_t *l) {
  if (l->head == NULL) {
    printf( "List is empty.\n");
    return -1;
  }
	l->head=l->head->next;
}
elem list_remove_at_index(list_t *l, int index) { 
  if (index == 1) {
    return list_remove_from_front(l);
  }

  node_t *current = l->head;
  int i;
  for (i = 0; i < index - 2 && current != NULL && current->next != NULL; i++) {
    current = current->next;
  }

  if (current == NULL || current->next == NULL || i != index - 2) {
    printf( "Index out of bounds.\n");
    return -1;
  }

  node_t *temp = current->next;
  elem value = temp->value;
  current->next = temp->next;
  free(temp);
  return value;
}



bool list_is_in(list_t *l, elem value) { 
  node_t* new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  node_t* cur_node = l->head;
  while (cur_node != NULL){
    
    if (cur_node->value==new_node->value) {
      return true;
    }
    cur_node = cur_node->next;
  }
  return false;
 }
elem list_get_elem_at(list_t *l, int index) {
  int count = 1;
  if (index > list_length(l)) {
    return -1;
  }
	if (index <= 0){
		return -1;
	}
  node_t* cur_node = l->head;
  while (cur_node != NULL){
    count +=1;
    cur_node = cur_node->next;
    if (count == index) {
      return cur_node->value;
    }
    
  }
 }
int list_get_index_of(list_t *l, elem value) {
  int count = 1;  
  node_t *current = l->head;

  while (current != NULL) {
    if (current->value == value) {
      return count;  
    }
    current = current->next;
    count++;
  }

  return -1;  
}



