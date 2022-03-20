/*
author : mohamed
date : 26-12-2021
version : 1.0
stack array base

*/



#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000

typedef int stackElement;

typedef struct stack {
	
	stackElement arr[MAX_SIZE];
	int top;
	int size;
	
} Stack;


// functions prototypes:

void stack_void_init(Stack* s_ptr);
stackElement stack_stackElement_pop(Stack* s_ptr);
int stack_int_push(stackElement x,Stack* s_ptr);
int stack_int_size(Stack* s_ptr);
void stack_void_print(Stack* s_ptr);
void stack_void_clear(Stack* s_ptr);
int stack_int_isEmpty(Stack* s_ptr);
int stack_int_isFull(Stack* s_ptr);

//main
int main(void){
	
	Stack s;
	stack_void_init(&s);
	stack_int_push(5,&s); //top=0
	stack_int_push(3,&s);//top=1
	stack_int_push(90,&s);//top=2
	printf("pushed 5,3,90");
	stack_stackElement_pop(&s);//top=1
	printf("\npopped 1 element");
	printf("\nprinting all  elements in stack\n");
	stack_void_print(&s);
	stack_stackElement_pop(&s);	//top=0
	printf("\npopped 1 element");
	printf("\nprinting all  elements in stack\n");
	stack_void_print(&s);
	printf("\nprinting all  elements in stack if it's not empty\n");
	if(!stack_int_isEmpty(&s)) 	stack_void_print(&s);
	stack_stackElement_pop(&s);	//top=-1
	printf("\npopped 1 element");
	printf("\nprinting all  elements in stack if it's not empty\n");
	if(!stack_int_isEmpty(&s)) 	stack_void_print(&s);

	
	return 0;
}



// functions implementations

void stack_void_init(Stack* s_ptr){
	s_ptr->size = 0;
	(*s_ptr).top  = -1;
}


stackElement stack_stackElement_pop(Stack* s_ptr){
	stackElement element;
	if(s_ptr->top!=-1){//if stack is not empty 
		element = s_ptr->arr[s_ptr->top];
		s_ptr->top--;
		s_ptr->size--;
		return element;
	}
	else{
		printf("no elements in the stack, you can't pop!!");
		return 0;	
	}
}


int stack_int_push(stackElement x,Stack* s_ptr){
	if (s_ptr->top != MAX_SIZE-1){//if stack is not full
		s_ptr->top++;
		s_ptr->arr[s_ptr->top] = x;
		s_ptr->size++;
		return 1;
	}
	else {
		printf("stack is full you can't push elements");
		return 0;
}
}


int stack_int_size(Stack* s_ptr){
	return s_ptr->size;	
}


void stack_void_print(Stack* s_ptr){
	for(int i =s_ptr->top; i>=0; i--){
		printf("%d\n",s_ptr->arr[i]); // you have to change the specifier if you changed stackElement type 
	}	
}

void stack_void_clear(Stack* s_ptr){
	s_ptr-> size =0;
	s_ptr->top = -1;
}

int stack_int_isEmpty(Stack* s_ptr){
	return (s_ptr->top==-1);
}

int stack_int_isFull(Stack* s_ptr){
	return (s_ptr->top == MAX_SIZE-1);
}








