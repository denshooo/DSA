#include <stdio.h>
#define MAX 5

//BRO 1 IS TRUE , 0 IS FALSE
typedef struct {
	int items[MAX];
	int top; //instead of count or last
}Stack;

void initStack(Stack *s) {

	s->top = -1; //doesn't have a top value = empty
}

int isEmpty(Stack s) {

	return s.top == -1 ? 1:0; //checks value of top, if -1 return 1, else 0
}

int isFull(Stack s) {
	return s.top == MAX - 1 ? 1:0; //checks if stack is full (stack is full = MAX - 1) considering your MAX-1 is the last 
				       //index of your array
}

int push(Stack *s, int data) { //essentially insertFirst()
				 //pass ur stack as a pointer and the data you want to push
				 //ask sir why we use isFull when we have isEmpty (can we also use that?)

	if (isFull(*s) == 0) {
		s->items[++(s->top)] = data; //increment first your top before pushing data, otherwise 
					     //you're inserting data to a negative index (-1)
	}
}

int pop(Stack *s) { //WHY ARE WE USING 1 NOT 0

	return isEmpty(*s) != 1 ? s->items[(s->top)--]:printf("Stack is empty"); //why are we post decrementing now
}	

int peek(Stack *s) { //why are we dereferencing if we're just peeking
		      //is it because we're changing the value of topValue?
 	
	int topValue = -1; //initialize

	if (isEmpty(*s) == 0) { //why arent we using isFull(*s) == 1
		topValue = s->items[s->top];
	}

	return topValue;
}
int main() {

	Stack s;

	initStack(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	printf("Top of my stack: %d\n", peek(&s));
	printf("Popped: %d\n", pop(&s));
	printf("New top of stack: %d", peek(&s));

}

