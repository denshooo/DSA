#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data; 
    int size;        // Maximum capacity
    int count;       // Current number of elements
    int head;        // Index where next element will be inserted
} CircularBuffer;

typedef enum{TRUE, FALSE}Bool;

CircularBuffer* createBuffer(int capacity);
void addReading(CircularBuffer *cb, int temperature);
double getAverage(CircularBuffer *cb);
void printReadings(CircularBuffer *cb);
int getMaxTemperature(CircularBuffer *cb);
void freeBuffer(CircularBuffer *cb);

int main() {
    CircularBuffer *buffer = createBuffer(5);
    
    // Add some readings
    addReading(buffer, 72);
    addReading(buffer, 75);
    addReading(buffer, 68);
    addReading(buffer, 80);
    addReading(buffer, 77);
    addReading(buffer, 82); // This should overwrite 72
    
    printReadings(buffer); // Should print: 75, 68, 80, 77, 82
    printf("Average: %.2f\n", getAverage(buffer));
    printf("Max: %d\n", getMaxTemperature(buffer));
    
    freeBuffer(buffer);
    return 0;
}

CircularBuffer* createBuffer(int capacity) { //check
	
	CircularBuffer* cb = malloc(sizeof(CircularBuffer));
	cb->data = malloc(capacity * sizeof(int)); 
	
	if(!cb) {
		printf("Memory allocation failed!");
		return NULL;
	}
	
	cb->count = 0;
	cb->size = 0;
	cb->head = 0;
	cb->size = capacity;
	
	return cb;
	
}

Bool isEmpty(CircularBuffer cb) { //check
	
	return cb.count == 0 ? TRUE : FALSE;
}

void addReading(CircularBuffer *cb, int temperature) { //check
	
	
	cb->data[cb->head] = temperature;
	cb->head = (cb->head + 1) % cb->size;
	
	if (cb->count == cb->size) {
		cb->count = cb->size;
	} else {
		cb->count++;
	}
	

	
}

double getAverage(CircularBuffer *cb) { //check
	
	int i;
	int sum = 0;
	float avg = 0.0;
	
	if(!cb) {
		printf("Memory allocation failed!");
	}
	
	for (i = 0; i < cb->count; i++) {
		sum += cb->data[i];
	}
	
	avg = sum/cb->count;
	
	return avg;
}

void printReadings(CircularBuffer *cb) {
	int i;
		
		for (i = 0; i < cb->count; i++) {
		int j = (cb->head + i) % cb->size;
		printf("%d ", cb->data[j]);
	}

	
	printf("\n");
	
}

int getMaxTemperature(CircularBuffer *cb) {
	int i;
	int max;
	
	if(!cb) {
		printf("Memory allocation failed!");
	}
	
	max = cb->data[0];
	
	for (i = 0; i < cb->count; i++) {
		if(cb->data[i] > max) {
			max = cb->data[i];
		}
	}
	
	return max;
}

void freeBuffer(CircularBuffer *cb) {
	
	if (cb) {
		free(cb->data);
		free(cb);
	}
}


