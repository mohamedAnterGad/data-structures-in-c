/*
author : mohamed
date : 26-12-2021
version : 1.0
stack link base

*/



#include<stdio.h>
#include<stdlib.h>
#include <string.h>  

typedef int stackElement;

typedef struct node{
	struct node* next;
	stackElement data;
}Node;

typedef struct stack{
	Node* top;
	int size;	
}Stack;

//functions prototypes

void stack_void_init(Stack* s_ptr);
stackElement stack_stackElement_pop(Stack* s_ptr);
int stack_int_push(stackElement x,Stack* s_ptr);
int stack_int_size(Stack* s_ptr);
void stack_void_print(Stack* s_ptr);
void stack_void_clear(Stack* s_ptr);
int stack_int_isEmpty(Stack* s_ptr);
int stack_int_isFull(Stack* s_ptr);
void reverse(char arr[],char new_arr[]); // this is a reverse function that takes two strings(array of char with a null terminator) and
// put the reversed version of the first string in the second argument
int isBalanced(char* arr); // function to determine if a string is balanced which means every ( opened is closed )
//string is considered balanced if (dsffsa[sdsdf])
//not balanced if                   (sdasd[)dsds]
int isMatched (char c1, char c2);// this a function that is used inside isbalanced function


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


	//...............................................clear stack function test..........................................................
	
	stack_int_push(5,&s); //top=0
	stack_int_push(3,&s);//top=1
	stack_int_push(90,&s);//top=2
	printf("pushed 5,3,90");
	stack_void_clear(&s);
	printf("clearing the stack");
	printf("\nprinting all  elements in stack\n");
	stack_void_print(&s);


	//............................................... reverse string function test..........................................................
	
	char arr[20] = "esraa mohamed";
	//char arr[20] = {'m','o','h','a','m','e','d','\0'};
	char new_arr[20];
	reverse(arr,new_arr);
	int i =0;
	printf("printing the reversed version of \"esraa mohamed\" \n");
	while (new_arr[i]!='\0'){
	printf("%c",new_arr[i]);
	i++;
	} // you can replace this while loop with printf("%s",new_arr);
	//printf("%s",new_arr);
	
	
	//...............................................is balanced function test..........................................................
	printf("\nprint not balanced %d\n",isBalanced(" i am mohamed (anter) and i work as an [engineer"));
	printf("print  balanced %d\n",isBalanced(" i am mohamed (anter) and i work as ' 'an [engineer]"));
	printf("print  not balanced %d\n",isBalanced(" i am mohamed (anter and i work as ' 'an [)engineer]"));
	
	
	return 0;
}


void stack_void_init(Stack* s_ptr){
	s_ptr->top = NULL;
	s_ptr->size = 0;
}

stackElement stack_stackElement_pop(Stack* s_ptr){
	if(s_ptr->top == NULL){//if stack is empty
		printf("stack is empty you can't pop");
		return 0; // change 0 if you changed stackElement type
	}
	else{
		stackElement element = s_ptr->top->data; // element to be returned
		Node* temp = s_ptr->top->next;           // temp pointer to hold the top location
		free(s_ptr->top);						 // deallocating the memory
		s_ptr->top = temp;						 // updating top pointer value
		s_ptr->size --;							 // decreminting the size
		return element;
	}
}



int stack_int_push(stackElement x,Stack* s_ptr){
	Node* n_ptr = (Node*) malloc(sizeof(Node));  // allocating the space in memory
	if(n_ptr != NULL){ 							// if there is space in memory
		n_ptr->data = x; 						// put element in the data field
		n_ptr->next = s_ptr->top;				// put top value in the next field
		s_ptr->top  = n_ptr;					//update top value
		s_ptr->size++;							//increment the size of the stack
		return 1;
	}
	else return 0; // if allocation failed return 0
}


int stack_int_size(Stack* s_ptr){
	return s_ptr->size;
}

void stack_void_print(Stack* s_ptr){
	Node* temp_ptr = s_ptr->top;
	while(temp_ptr!=NULL){
		printf("%d\n",temp_ptr->data);//change format specifier if you changed stackElement type
		temp_ptr = temp_ptr->next;
	}
	//if stack is empty print nothing
}

void stack_void_clear(Stack* s_ptr){
	Node* temp ;
	while(s_ptr->top != NULL){
		temp = s_ptr->top->next;
		free(s_ptr->top);
		s_ptr->top = temp;
		
	}
	
}

int stack_int_isEmpty(Stack* s_ptr){
	return (s_ptr->top ==NULL);
}


int stack_int_isFull(Stack* s_ptr){
	return 0; //stack with this implementation will never be full
}


void reverse(char arr[],char new_arr[]){
	Stack s;										// make a stack
	stack_void_init(&s);							// initialize the stack (always initialize any stack u create)
	//int length = sizeof(arr)/sizeof(arr[0]);		
	int length = strlen(arr);						//determine length of input string
	//char new_arr[length];								
	int i=0;
	while(arr[i] !=  '\0'){							//while there is elements in the string
		stack_int_push(arr[i],&s);					//push element in the stack
		i++;
	}
	
	
	i=0;
	while(!stack_int_isEmpty(&s)){					//while stack is not empty
	//while(i<length)	{
		new_arr[i] = stack_stackElement_pop(&s);	// pop an element a time
		i++;
	}
	new_arr[i]='\0';								// put the null terminator char in the end to make it a string
}

	
int isBalanced(char* arr){
	int i=0;
	Stack s;
	stack_void_init(&s);
	while(arr[i] !=  '\0'){							//while there is elements in the string
		if(arr[i] == '(' || arr[i]=='{' || arr[i] =='[' ){ // if the element is an open pranthesis
		stack_int_push(arr[i],&s);					//push element in the stack			
		}
		else{
			if(arr[i] == ')' || arr[i]=='}' || arr[i] ==']' ){//else if the element is a closed pranthesis
				if(isMatched(stack_stackElement_pop(&s) , arr[i])) ;//continue 
				else return 0;
			}
			else ;//i.e no pranthesis (normal char) then continue looping
		}
		i++;
	}
	//if reached the end of the string without returning then it is balanced if nothing in the stack
	if(stack_int_isEmpty(&s))
		return 1;
	else if(stack_stackElement_pop(&s) == stack_stackElement_pop(&s))
		return 0;
}

int isMatched(char c1, char c2){
	
    if (c1 == '(' && c2 == ')')
        return 1;
    else if (c1 == '{' && c2 == '}')
        return 1;
    else if (c1 == '[' && c2 == ']')
        return 1;
    else
        return 0;	
}

int pushElement (Stack* ptrSrack , stackElement* ptrElement){
	
}

//push pause to pause when passed ' and if ' is passed again then toggle push pause using -(push pause -1)