/*cursor-based - implementation for languages that dont support pointers
essentially an arraylist data structure, but manipulated similar to LINKED list

we define our own virtual heap*/

#include <stdio.h>
#define MAX 10 

typedef struct {
	int data;
	int next;
}node;

typedef struct {
	node elems[MAX];
	int avail;
}vHeap;

typedef int cList;

/*pre req func for vheap*/

void initVheap(vHeap* VH) {
	//we want to link the data elem together
	//set avail to 0 (first node)
	
	VH->avail = 0;
	
	//update Vheap
	int i;
	
	for (i = VH->avail; i < MAX-1; i++) {
		VH->elems[i].next = i + 1;
	}
	
	VH->elems[i].next = -1; //no more space
	
}

int allocSpace(vHeap* VH) {
	int allocIndex = VH->avail;
	
	if(allocIndex != -1) {
		VH->avail = VH->elems[allocIndex].next;
	}
	
	return allocIndex;
}

int deallocSpace (vHeap *VH, int pos) {
	VH->elems[pos].next = VH->avail;
	VH->avail = pos;
}

//Cursor based functions

void initCList(cList* CL) {
	*CL = -1;
}

void insertFirst(cList* CL, vHeap* VH, int data) {
	cList temp;
	
	temp = allocSpace(VH);
	
	if (temp!= -1) {
		VH->elems[temp].data = data;
		VH->elems[temp].next = *CL;
		*CL = temp;
	}
	
}

void deleteMem (cList* CL, vHeap* VH, int data) {
	cList temp, *trav;
	
	for (trav=CL; *trav != -1 && VH->elems[*trav].data != data; trav = &VH->elems[*trav].next){}
	if(*trav != -1) {
		temp = *trav;
		*trav = VH->elems[*trav].next;
		deallocSpace(VH, temp);
	}
}

void displayCList(cList CL, vHeap VH) {
	for (; CL != -1; CL = VH.elems[CL].next) {
		printf("%d, ", VH.elems[CL].data);
	}
}
int main (void) {
	
	vHeap myHeap;
	cList myList;
	
	initVheap(&myHeap);
	initCList(&myList);
	
	insertFirst(&myList, &myHeap, 10);
	insertFirst(&myList, &myHeap, 20);
	insertFirst(&myList, &myHeap, 30);
	insertFirst(&myList, &myHeap, 40);
	insertFirst(&myList, &myHeap, 50);
	
	displayCList(myList, myHeap);
	
}
