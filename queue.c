#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum {
	FALSE, TRUE
}Boolean; 

typedef struct node {
	int data;
	struct node* next;
}node, *LL;

typedef struct {
	LL front;
	LL rear;
}Queue;

void initQueue(Queue *Q) {
	Q->front = Q->rear = NULL;
}

Boolean isEmpty(Queue *Q) {
	return Q->front == NULL ? TRUE : FALSE;
}

void enqueue(Queue *Q, int data) { //insertLast
	LL newNode = (LL)malloc(sizeof(node));
	
	if(newNode!=NULL){
		newNode->data = data;
		newNode->next = NULL;
	
	
	if(!isEmpty(Q)) {
		Q->rear->next = newNode;
	} else {
		Q->front = newNode;
	}
	
	Q->rear = newNode;
}
}

void dequeue(Queue *Q) { //delete first
	if(!isEmpty(Q)) {
		LL temp = Q->front;
		Q->front = temp->next;
	
	
	if(temp == Q->rear) {
		Q->rear = NULL;
	}

	free(temp);
	
	}
	
	
}

void display(Queue Q) {
	LL trav;
	
	for(trav = Q.front; trav!=NULL; trav = trav->next) {
		printf("%d ", trav->data);
	}
}
int main(void) {
	Queue Q;
	
	initQueue(&Q);
	enqueue(&Q, 10);
	enqueue(&Q, 20);
	enqueue(&Q, 30);
	
	display(Q);
	
	dequeue(&Q);
	
	printf("\nQueue after dequeue: ");
	
	display(Q);
	
}

