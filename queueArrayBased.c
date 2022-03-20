/*
author : mohamed
date : 26-12-2021
version : 1.0
Queue array base

*/



#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000

typedef int queueElement;

typedef struct queue {
	
	queueElement arr[MAX_SIZE];
	int front;
	int rear;
	int size;
	
} Queue;

//functions prototypes
void queue_void_init(Queue* q_ptr);
int  queue_int_enqueue(queueElement e , Queue* q_ptr);
queueElement queue_queueElement_dequeue(Queue* q_ptr);
int queue_int_isFull(Queue* q_ptr);
int queue_int_isEmpty(Queue* q_ptr);
int queue_int_size(Queue* q_ptr);
void queue_void_print(Queue* q_ptr);

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
	printf("printing all elements in the queue");
	queue_void_print(&q);	
	return 0;
}


void queue_void_init(Queue* q_ptr){
	(*q_ptr).front =-1;
	q_ptr->rear = -1;
	q_ptr->size = 0;
}

int  queue_int_enqueue(queueElement e , Queue* q_ptr){
	if(q_ptr->front == -1) q_ptr->front++; //if first enqueue in the queue
	
	if(q_ptr->rear == MAX_SIZE-1){		// if queue is full
		printf("the queue is full you can't enqueue");
		return 0;
	}
	//else:
	q_ptr->rear++;
	q_ptr->arr[q_ptr->rear] = e;
	q_ptr->size++;
	return 1;
}


queueElement queue_queueElement_dequeue(Queue* q_ptr){
	//if queue is empty then return
	if(queue_int_isEmpty(q_ptr)){
		printf("queue is empty you can't dequeue\n");
		return 0; // change this if u changed queueElement type
	}
	//else :														//if it is not empty
	queueElement e = q_ptr->arr[q_ptr->front];						//put the data in a temp var
	q_ptr->front++;													//increment front
	q_ptr->size--;													//decrement the size
	if(q_ptr->front > q_ptr->rear) q_ptr->front = q_ptr->rear = -1;  //corner case if front exceeded rear then reset both
	return e;														 // return the dequeued data
}



int queue_int_isFull(Queue* q_ptr){
	return (q_ptr->rear == MAX_SIZE-1);
}


int queue_int_isEmpty(Queue* q_ptr){
	return (q_ptr->front == -1);								//same if you checked on rear
}
int queue_int_size(Queue* q_ptr){
	return q_ptr->size;
}
void queue_void_print(Queue* q_ptr){
	int temp = q_ptr->front;
	while (temp <= q_ptr->rear) {
		printf("%d\n",q_ptr->arr[temp]);
		temp++;
	}

}


