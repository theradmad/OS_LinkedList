#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  int x;
  printf("Write your Tests for your linked list implementation\n");
  list_t *mylist;
  mylist = list_alloc();
  list_print(mylist);
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_print(mylist);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);

  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_add_to_front : FAILED, correct list = 100->90->80->70->60->50->40->30->20->10->NULL \n");
				printf("your list = %s ", listToString(mylist));
  }
	printf("my list with nothing removed:");
  list_print(mylist);
  list_remove_at_index(mylist, 3);
	printf("my list with index 3 removed:");
  list_print(mylist);

  if(strcmp("100->90->70->60->50->40->30->20->10->NULL", listToString(mylist)) != 0)
  {
        printf("list_remove_at_index 3 : FAILED, correct list =  100->90->70->60->50->40->30->20->10->NULL\n");
				printf("your list = %s ", listToString(mylist));
  }
	printf("\n");
  list_remove_at_index(mylist, 20);
	printf("my list:");
  list_print(mylist);
	printf("my list w index 1 removed:");
  list_remove_at_index(mylist, 1);
  list_print(mylist);
  list_remove_at_index(mylist, 6);
	printf("my list with index 1 and 6 removed:");
  list_print(mylist);

  if(strcmp("90->70->60->50->40->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index 1 and 6: FAILED, correct list = 90->80->60->50->30->20->10->NULL\n" );
				printf("your list = %s ", listToString(mylist));
  }
  

  // printf("The list length is %d\n", list_length(mylist));

  // list_add_to_back(mylist, 39);
  // list_print(mylist);
  // list_add_to_back(mylist, 18);
  // list_add_to_back(mylist, 42);
  // list_add_to_back(mylist, 190);
  // list_print(mylist);
  // list_free(mylist);
  // list_print(mylist);

  // list_add_to_front(mylist, 81);
  // list_add_to_back(mylist, 4);
  // list_add_to_front(mylist, 308);
  // list_add_to_back(mylist, 70);
  // list_add_to_front(mylist, 290);
  // list_print(mylist);
  // printf("The list length is %d\n", list_length(mylist));
  
  // list_add_at_index(mylist, 21, 1);
  // list_add_at_index(mylist, 65, 0);
  // list_add_at_index(mylist, 10, 8);
  // list_print(mylist);
  // list_add_at_index(mylist, 10, 7);
  // list_print(mylist);

  // list_remove_from_back(mylist);
  // list_print(mylist);
  // list_remove_from_front(mylist);
  // list_print(mylist);
  // list_remove_at_index(mylist, 3);
  // list_print(mylist);

  // printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(mylist, 3));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(mylist, -2));
  printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(mylist, 12));
  printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(mylist, 7));
  
	printf("Index of %d?: %d\n", 70, list_get_index_of(mylist, 70));
  printf("Index of %d?: %d\n", 20, list_get_index_of(mylist, 20));
  printf("Index of %d?: %d\n", 0, list_get_index_of(mylist, 0));
  printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  printf("Index of %d?: %d\n", 90, list_get_index_of(mylist, 90));
  printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  
	printf("How long is the list? %d\n", list_length(mylist));
	list_add_to_back(mylist, 29);
	if(strcmp("90->70->60->50->40->20->10->29->NULL", listToString(mylist)) != 0)
  {
        printf("list_add_to_back 29 : FAILED, correct list =  90->70->60->50->40->30->20->10->29->NULL\n");
				printf("your list = %s ", listToString(mylist));
  }
	list_print(mylist);
	list_add_at_index(mylist, 37, 3);
	if(strcmp("90->70->37->60->50->40->20->10->29->NULL", listToString(mylist)) != 0)
  {
        printf("list_add_at_index 37, 3 : FAILED, correct list =  90->70->37->60->50->40->30->20->10->29->NULL\n");
				printf("your list = %s ", listToString(mylist));
  }
	list_print(mylist);
	list_remove_from_back(mylist);
	printf("removed from back");
	if(strcmp("90->70->37->60->50->40->20->10->NULL", listToString(mylist)) != 0)
  {
        printf("list_remove_from_back : FAILED, correct list =  90->70->37->60->50->40->30->20->10->NULL\n");
				printf("your list = %s ", listToString(mylist));
  }
	list_print(mylist);
	printf("removed from front");
	list_remove_from_front(mylist);
	if(strcmp("70->37->60->50->40->20->10->NULL", listToString(mylist)) != 0)
  {
        printf("list_remove_from_back : FAILED, correct list = 70->37->60->50->40->30->20->10->NULL\n");
				printf("your list = %s ", listToString(mylist));
  }
	list_print(mylist);

	printf("37 is in the list: \n");
	printf( list_is_in(mylist, 37) ? "true":"false");
	if (list_is_in(mylist, 37) != 1) {
		printf("list_is_in FAILED, 37 is in list");
	}
	printf("\nindex of 37\n");
	printf("%d", list_get_index_of(mylist, 37));
	if (list_get_index_of(mylist, 37) != 2) {
		printf("list_get_index_of FAILED, 37 is in list at index 2");
	}
	printf("\n39 is in the list: \n");
	printf( list_is_in(mylist, 39) ? "true":"false");
	if (list_is_in(mylist, 39) != 0) {
		printf("list_is_in FAILED, 39 is NOT in list");
	}
	printf("\nindex of 39");
	printf("%d", list_get_index_of(mylist, 39));
	if (list_get_index_of(mylist, 39) != -1) {
		printf("list_get_index_of FAILED, 39 is not in list");
	}
  list_free(mylist);
	int i;
	for (i=0; i < 100; i++) {
		list_add_to_front(mylist, i);
	}
	for (i=100; i<200; i++) {
		list_add_to_back(mylist, i);
	}
	int j;
	for (j=0; j<50; j++) {
		list_add_at_index(mylist, j, j);
	}
	list_print(mylist);
	for (j=0; j<100; j++) {
		list_remove_at_index(mylist, list_get_index_of(mylist,j));
	}
	int c;
	for (c=0; c<100; c++) {
		list_get_elem_at(mylist, c);
	}
  // list_add_at_index(mylist, -1, -1);
  // list_print(mylist);
  // list_add_at_index(mylist, -1, -1);
  // list_print(mylist);
  // list_add_at_index(mylist, 10, 0);
  // list_print(mylist);
  // list_add_at_index(mylist, 20, 1);
  // list_print(mylist);
  // list_free(mylist);
  // printf("The list length is %d\n", list_length(mylist));
  // list_print(mylist);

  // list_remove_from_back(mylist);
  // list_remove_from_front(mylist);
  // list_remove_at_index(mylist, -3);
  // list_remove_at_index(mylist, 0);
  // list_remove_at_index(mylist, 2);
  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 60);
  // list_add_at_index(mylist, 50, 1);
  // list_add_at_index(mylist, 0, 6);
  // list_add_at_index(mylist, 70, 0);
  // list_add_at_index(mylist, 80, 12);
  // list_print(mylist);

  // list_free(mylist);
  // list_free(mylist);
  // list_add_to_back(mylist, 100);
  // list_print(mylist);
  // list_remove_from_front(mylist);
  // list_print(mylist);
  // list_add_to_back(mylist, 13);  
  // list_print(mylist);
  // list_remove_from_back(mylist);
  // list_print(mylist);

  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);
  // list_remove_at_index(mylist, -2);
  // list_print(mylist);
  // list_remove_at_index(mylist, 7);
  // list_print(mylist);
  // list_remove_at_index(mylist, 4);
  // list_print(mylist);

  // list_free(mylist);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // list_remove_at_index(mylist, 1);
  // list_print(mylist);
  // list_add_to_front(mylist, 80);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);

  // printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  // list_add_to_back(mylist, 50);
  // list_add_to_back(mylist, 60);
  // list_add_to_back(mylist, 70);
  // list_add_to_back(mylist, 80);
  // list_add_to_back(mylist, 90);
  // list_print(mylist);
  // printf("Is %d in the list?: %d\n", 30, list_is_in(mylist, 30));
  // printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  // printf("Is %d in the list?: %d\n", 80, list_is_in(mylist, 80));
  // list_add_to_back(mylist, 70);
  // list_print(mylist);
  // printf("Is %d in the list?: %d\n", 70, list_is_in(mylist, 70));
  
  // printf("The list length is %d\n", list_length(mylist));
  // printf("Value at %d in the list?: %d\n", -4, list_get_elem_at(mylist, -4));
  // printf("Value at %d in the list?: %d\n", 10, list_get_elem_at(mylist, 10));
  // printf("Value at %d in the list?: %d\n", 6, list_get_elem_at(mylist, 6));
  // printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  // printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  // list_free(mylist);
  // list_print(mylist);
  // printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  // list_remove_at_index(mylist, 0);
  // printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  // printf("Index of %d?: %d\n", 21, list_get_index_of(mylist, 21));
  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 50);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  // printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  // printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  // printf("Index of %d?: %d\n", 30, list_get_index_of(mylist, 30));
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  // printf("Index of %d?: %d\n", 60, list_get_index_of(mylist, 60));
  // list_add_to_front(mylist, 10);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  // list_add_to_back(mylist, 40);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 40, list_get_index_of(mylist, 40));
  return 0;
	
}