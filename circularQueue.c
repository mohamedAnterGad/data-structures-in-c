/*
author : mohamed
date : 26-12-2021
version : 1.0
circular Queue Link base

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
int queue_void_isFull(Queue* q_ptr);
int queue_void_isEmpty(Queue* q_ptr);
int queue_int_size(Queue* q_ptr);
int queue_void_print(Queue* q_ptr);

/*................................................Main.............................................*/
int main(void){
	Queue q;
	queue_void_init(&q);
	queue_int_enqueue(5,&q);
	printf("printing all the queue after enqueueing 5 only\n");
	queue_void_print(&q);
	queue_int_enqueue(6,&q);
	queue_int_enqueue(7,&q);
	queue_int_enqueue(8,&q);
	printf("enqueued 6,7,8 in the queue\n");
	queue_queueElement_dequeue(&q);
	printf("dequeued 1 element from the queue\n");
	printf("printing all the queue\n");
	queue_void_print(&q);
	queue_int_enqueue(8,&q);
	printf("8 is enqueued again \n");
	printf("printing all elements in the queue\n");
	queue_void_print(&q);
	queue_queueElement_dequeue(&q);
	queue_queueElement_dequeue(&q);
	queue_queueElement_dequeue(&q);
	queue_queueElement_dequeue(&q);
	printf("printing all elements in the queue after dequeuing 4 times\n");
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
		n_ptr->next = q_ptr->front;						//make the next point to the first element
		if(q_ptr->front == NULL) 
		{	
			q_ptr->front = n_ptr;       				// handling the corner case ( first enqueue in the queue)
			n_ptr->next = q_ptr->front;					//make the next point to the same element
		}
		else 
		{
			q_ptr->rear->next = n_ptr;					//last element next points to the new element			
		}
		q_ptr->rear = n_ptr;							//update the rear
		q_ptr->size++;									//increment size
		return 1;
	}
	else {												//if allocation failed
		printf("allocation failed");					
		return 0;										
	}
}
	
queueElement queue_queueElement_dequeue(Queue* q_ptr){
	if(queue_void_isEmpty(q_ptr)) { 		// if the queue is empty
		printf("the queue is empty you can not dequeue!");
		return 0;							//change this if u changed queueElement type
	}
	else {										//if queue include elements
		if(q_ptr->front == q_ptr->rear)			// the corner case if last element dequeue
			{	
				queueElement e = q_ptr->front->data;	//put the data in a temp var
				free(q_ptr->front);						//deallocate the memory				
				q_ptr->rear = q_ptr->front = NULL;
				return e;
			}	
		queueElement e = q_ptr->front->data;	//put the data in a temp var
		Node* temp_ptr = q_ptr->front->next;	//hold the next element in a temp ptr
		free(q_ptr->front);						//deallocate the memory
		q_ptr->front = temp_ptr;				//make the front points to the next element
		q_ptr->rear->next = q_ptr->front;		//make the rear next points to the front element
		q_ptr->size--;							//decrement the size
		return e;							
		//corner case if last element in the queue (the same code will work cuz front next points to null) we just want to edit rear
	}	
}

int queue_void_isFull(Queue* q_ptr){
	return 0; // queue will never be full in this implementation
}
int queue_void_isEmpty(Queue* q_ptr){
	return (q_ptr->rear == NULL);
}

int queue_int_size(Queue* q_ptr){
	return q_ptr->size;
}

int queue_void_print(Queue* q_ptr){
	if(q_ptr->front != NULL){
		Node* temp_ptr = q_ptr->front;
		do{
			printf("%d\n",temp_ptr->data); // change format specifier if you change queueElement type
			temp_ptr = temp_ptr->next;
		}
		while (temp_ptr != q_ptr->front);
	}
	return 1;
}
