/*
author : mohamed
date : 30-12-2021
version : 1.0
Linked list component

*/


#include<stdio.h>
#include<stdlib.h>

typedef int listElement;

typedef struct listNode{
	listElement data;
	struct listNode* next;
}ListNode; // Do not forget the semi colon

typedef struct list {
	ListNode* head;
	int size;
} List;

/* .......................................functions prototypes.........................................*/
void list_void_init(List* l_ptr);
void list_void_insert(listElement e, int pos , List* l_ptr);
listElement list_listElement_getElement(List* l_ptr, int pos);
void list_void_deleteElement(List* l_ptr,int pos);
int  list_int_isEmpty(List* l_ptr);
int  list_int_isFull(List* l_ptr);
int  list_int_size(List* l_ptr);
void list_void_print(List* l_ptr);
void list_void_destroyList(List* l_ptr);

/*.........................................main..................................*/

int main(void){
	int size;
	listElement RetrivedValue;
    List L;

    list_void_init(&L);

    list_void_insert(14,0,&L);
    list_void_insert(54,1,&L);
    list_void_insert(3,2,&L);
    
    size= list_int_size(&L);

    printf("The size of the list is= %d\n", size);
    printf("The elements of the list are\n");
    list_void_print(&L);
	
	 RetrivedValue = list_listElement_getElement(&L,2);
	printf("The RetrivedValue is= %d\n", RetrivedValue);
	
	list_void_deleteElement(&L,1);
	 size= list_int_size(&L);

    printf("The size of the list after deleting one element at position(1) is= %d\n", size);
	printf("The elements of the list are\n");
    list_void_print(&L);
	return 0;
}

void list_void_init(List* l_ptr){
	l_ptr->size=0;
	l_ptr->head=NULL;
}

void list_void_insert(listElement e, int pos , List* l_ptr){
	ListNode* tempNode = l_ptr->head;
	int i;
	ListNode* n_ptr = (ListNode*) malloc (sizeof(ListNode)); 		//create the node
	n_ptr->data = e;												//assign the data
	if (pos ==0) 													//handiling the corner case (insertion at first)
	{
		n_ptr->next = l_ptr->head;
		l_ptr->head = n_ptr;
	}
	else 
		{
		for( i=0 , tempNode = l_ptr->head ; i<pos-1 ; i++){         // < pos-1 to stop before the insertion node
			tempNode = tempNode->next;
		}
		
		n_ptr->next = tempNode->next;
		tempNode->next = n_ptr;
	}
	l_ptr->size ++;
		
}

listElement list_listElement_getElement(List* l_ptr, int pos){
	ListNode* tempNode;
	listElement e;
	int i;
	for( i=0 , tempNode = l_ptr->head ; i<pos ; i++){         
			tempNode = tempNode->next;
		}
	e = tempNode->data;
	return e;
}


void list_void_deleteElement(List* l_ptr,int pos){
	ListNode* tempNode, *q;
	listElement e;
	int i;
	if (pos == 0)			//handling the corner case where we delete the head element
	{
		tempNode = l_ptr->head;
		l_ptr->head = tempNode->next;
		free(tempNode);		
	}
	else 
	{
		for( i=0 , tempNode = l_ptr->head ; i<pos-1 ; i++){         
				tempNode = tempNode->next;
		}
		q = tempNode->next->next;
		free(tempNode->next);	
		tempNode->next = q;
	}
	l_ptr->size--;
}

int  list_int_isEmpty(List* l_ptr){
	return (l_ptr->head == NULL);
}
int  list_int_isFull(List* l_ptr){
	return 0;
}
int  list_int_size(List* l_ptr){
	return l_ptr->size;
}
void list_void_print(List* l_ptr){
	ListNode* tempNode= l_ptr->head;

    while(tempNode != NULL)
    {
        printf("%d\n", tempNode->data);
        tempNode= tempNode->next;
    }
}

void list_void_destroyList(List* l_ptr){
	ListNode* tempNode;

    while(l_ptr->head != NULL)         
    {
        tempNode = l_ptr->head->next;
        free(l_ptr->head);
        l_ptr->head= tempNode;
    }

    l_ptr->size=0;
}
	
	


