/*
author : mohamed
date : 26-12-2021
version : 1.0
Queue Link base

*/



#include<stdio.h>
#include<stdlib.h>

typedef int queueElement;

typedef struct queueNode{
	queueElement data;
	struct queueNode* next;
}Node; // Do not forget the semi colon

typedef struct queue {
	Node* front;
	Node* rear;
	int size;
} Queue;



/*.........................................functions prototypes.........................................*/
void queue_void_init(Queue* q_ptr);
int  queue_int_enqueue(queueElement e , Queue* q_ptr);
queueElement queue_queueElement_dequeue(Queue* q_ptr);
int queue_int_isFull(Queue* q_ptr);
int queue_int_isEmpty(Queue* q_ptr);
int queue_int_size(Queue* q_ptr);
void queue_void_print(Queue* q_ptr);

/*................................................Main.............................................*/
int main(void){
	Queue q;
	queue_void_init(&q);
	queue_int_enqueue(5,&q);
	queue_int_enqueue(6,&q);
	queue_int_enqueue(7,&q);
	queue_int_enqueue(8,&q);
	printf("enqueued 5,6,7,8 in the queue\n");
	queue_queueElement_dequeue(&q);
	printf("dequeued 1 element from the queue\n");
	printf("printing all the queue\n");
	queue_void_print(&q);
	queue_int_enqueue(8,&q);
	printf("8 is enqueued again \n");
	printf("printing all elements in the queue\n");
	queue_void_print(&q);
	return 0;
}


void queue_void_init(Queue* q_ptr){
	q_ptr->front= NULL;
	q_ptr->rear = NULL;
	q_ptr->size = 0;
}

int  queue_int_enqueue(queueElement e , Queue* q_ptr){
	Node* n_ptr = (Node*)malloc(sizeof(Node));			//create the node
	if(n_ptr != NULL){									//if allocation succeeded
		n_ptr->data = e;								//put the data field
		n_ptr->next = NULL;								//make the next point to null
		if(q_ptr->rear != NULL)
			q_ptr->rear->next = n_ptr;						//last element next points to the new element
		q_ptr->rear = n_ptr;							//update the rear
		if(q_ptr->front == NULL) q_ptr->front = n_ptr;       // handling the corner case ( first enqueue in the queue)
		q_ptr->size++;									//increment size
		return 1;
	}
	else {												//if allocation failed
		printf("allocation failed");					
		return 0;										
	}
}
	
queueElement queue_queueElement_dequeue(Queue* q_ptr){
	if(queue_int_isEmpty(q_ptr)) 
	{ 		// if the queue is empty
		printf("the queue is empty you can not dequeue!");
		return 0;								//change this if u changed queueElement type
	}
	
	else 
	{											//if queue include elements
		queueElement e = q_ptr->front->data;	//put the data in a temp var
		Node* temp_ptr = q_ptr->front->next;	//hold the next element in a temp ptr
		free(q_ptr->front);						//deallocate the memory
		q_ptr->front = temp_ptr;				//make the front points to the next element
		if(queue_int_isEmpty(q_ptr))			// the corner case if last element dequeued
		{
			q_ptr->rear = NULL; 
		}	
		q_ptr->size--;							//decrement the size
		return e;							
		//corner case if last element in the queue (the same code will work cuz front next points to null) but we have to 
		//edit the rear
	}
	
}

int queue_int_isFull(Queue* q_ptr){
	return 0; // queue will never be full in this implementation
}
int queue_int_isEmpty(Queue* q_ptr){
	return (q_ptr->rear == NULL);
}

int queue_int_size(Queue* q_ptr){
	return q_ptr->size;
}

void queue_void_print(Queue* q_ptr){
	Node* temp_ptr = q_ptr->front;
	while (temp_ptr != NULL){
		printf("%d\n",temp_ptr->data); // change format specifier if you change queueElement type
		temp_ptr = temp_ptr->next;
	}
}