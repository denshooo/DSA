#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct {
	Node *top; //pointer to the top node
}Stack;

void initStack(Stack *s) {
	s->top = NULL; //empty stack has no top node
}

int isEmpty(Stack s) {
	return s.top == NULL ? 1:0;
}

//no isFull() function 


int push(Stack *s, int data) {
	
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	if(newNode == NULL) {
		return 0;
	}
	
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode;
	
	return 1;
}

int pop(Stack *s) {
	
	if(isEmpty(*s)==1) {
		return 0;
	}
	
	int data = s->top->data;
	Node *temp = s->top;
	s->top = s->top->next;
	
	free(temp);
	
	return data;
	
	
}

int peek(Stack *s) {
	return s->top->data;
}

void display(Stack *s) {

 if(!isEmpty(*s)) {
 	//initialize temporary stack
 	
 	Stack s2;
	initStack(&s2);
 	
 	//push elems to temporary stack
 	while(!isEmpty(*s)) {
 		
 	push(&s2, peek(s));
	pop(s);
	
	 }
	 
	 printf("\nStack elements from top to bottom: ");
	 
	 while(!isEmpty(s2)) {
	 	int value = (peek(&s2));
	 	printf("%d ", value);
	 	push(s, value);
	 	pop(&s2);
	 }
	 
	 printf("\n");
 	
 }
 
}

void freeStack(Stack *s) {
	while(!isEmpty(*s)) {
		pop(s);
	}
}

int main(){
 	
 	Stack s;
 	
 	initStack(&s);
 	
 	push(&s, 10);
 	push(&s, 20);
 	push(&s, 30);
 	
 	printf("\nTop of my stack: %d", peek(&s));
 	
 	display(&s);
 	
 	printf("\nPopped: %d", pop(&s));
 	printf("\n\nNew top of my stack: %d", peek(&s));
 	
 	display(&s);
 	
 	freeStack(&s);
 	
 	return 0;
 	
 	
 	
}

