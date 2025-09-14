/*
 * STACK PRACTICE PROBLEM: Balanced Parentheses Checker
 * 
 * PROBLEM DESCRIPTION:
 * Implement a stack using an array and use it to check if parentheses, 
 * brackets, and braces are balanced in a given string.
 * 
 * REQUIREMENTS:
 * 1. Implement a stack with the following operations:
 *    - push(item): Add item to top of stack
 *    - pop(): Remove and return top item
 *    - peek(): Return top item without removing it
 *    - isEmpty(): Check if stack is empty
 *    - isFull(): Check if stack is full
 * 
 * 2. Use the stack to check if brackets are balanced:
 *    - Characters to check: '()', '[]', '{}'
 *    - Return 1 if balanced, 0 if not balanced
 * 
 * EXAMPLES:
 * Input: "({[]})" -> Output: 1 (balanced)
 * Input: "([)]" -> Output: 0 (not balanced)
 * Input: "{[()()]}" -> Output: 1 (balanced)
 * Input: "(((" -> Output: 0 (not balanced)
 * 
 * TODO: Complete the implementation below
 */

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

// Stack structure
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// TODO: Initialize the stack
void initStack(Stack* s) {
    // Your code here
    
    s->top = -1;

}

// TODO: Check if stack is empty
int isEmpty(Stack* s) {
    // Your code here
    
    return s->top == -1 ? 1:0; // placeholder
}

// TODO: Check if stack is full
int isFull(Stack* s) {
    // Your code here

    return s->top == MAX_SIZE - 1 ? 1 : 0 ; // placeholder
}

// TODO: Push an element onto the stack
int push(Stack* s, char item) {

    // Return 1 if successful, 0 if stack is full
    if (isFull(s)==1) {
		return 0;
    }
    
    s->data[++(s->top)] = item;
    return 1; //i thought bawal duha ka return but essentially ur
    		  //basically just returning either
		
	
}

// TODO: Pop an element from the stack
char pop(Stack* s) {
   
    // Return the popped element if not empty
    
    if(isEmpty(s)==1) {
    	return '\0';
	}
    
    return s->data[(s->top)--]; //return popped elem
}
// TODO: Peek at the top element without removing it
char peek(Stack* s) {
    // Your code here
    // Return the top element, or '\0' if stack is empty
    
    if(isEmpty(s)==1) {
    	return '\0';
	}
	
	return s->data[s->top];
}

// TODO: Check if a character is an opening bracket
int isOpeningBracket(char c) {
    // Your code here
    return c == '(' || c == '{' || c == '[' ? 1:0 ; // placeholder
}

// TODO: Check if a character is a closing bracket
int isClosingBracket(char c) {
    // Your code here
    return c == ')' || c == '}' || c == ']' ? 1:0 ; // placeholder
}

// TODO: Check if opening and closing brackets match
int isMatchingPair(char open, char close) {
    // Your code here
    
     return (open == '(' && close == ')') ||
	 		(open == '{' && close == '}') ||
			(open == '[' && close == ']');
}

// TODO: Main function to check if brackets are balanced
int isBalanced(char* str) {
    Stack s;
    initStack(&s);
    int i;
    
    // Your code here
    // Iterate through the string and use the stack to check balance
    
    for(i = 0; i<strlen(str); i++) 
    {
    	char current = str[i];
    	
    	if(isOpeningBracket(current) == 1) {
    		push(&s, current);
    	
		} else if (isClosingBracket(current) == 1) {
			if (isEmpty(&s) == 1) {
				return 0;
			}
			
			char last = pop(&s);
			
			if(isMatchingPair(last, current) == 0) {
				return 0;
			}
		}
	}
	
		return isEmpty(&s) ? 1:0;
}

// Test function - DO NOT MODIFY
void runTests() {
    char test1[] = "({[]})";
    char test2[] = "([)]";
    char test3[] = "{[()()]}";
    char test4[] = "(((";
    char test5[] = ")))";
    char test6[] = "";
    char test7[] = "((()))";
    char test8[] = "{[}]";
    
    printf("Test Results:\n");
    printf("'%s' -> %s\n", test1, isBalanced(test1) ? "BALANCED" : "NOT BALANCED");
    printf("'%s' -> %s\n", test2, isBalanced(test2) ? "BALANCED" : "NOT BALANCED");
    printf("'%s' -> %s\n", test3, isBalanced(test3) ? "BALANCED" : "NOT BALANCED");
    printf("'%s' -> %s\n", test4, isBalanced(test4) ? "BALANCED" : "NOT BALANCED");
    printf("'%s' -> %s\n", test5, isBalanced(test5) ? "BALANCED" : "NOT BALANCED");
    printf("'%s' -> %s\n", test6, isBalanced(test6) ? "BALANCED" : "NOT BALANCED");
    printf("'%s' -> %s\n", test7, isBalanced(test7) ? "BALANCED" : "NOT BALANCED");
    printf("'%s' -> %s\n", test8, isBalanced(test8) ? "BALANCED" : "NOT BALANCED");
}

int main() {
    printf("=== STACK PRACTICE PROBLEM ===\n");
    printf("Implement the stack operations and balanced parentheses checker.\n\n");
    
    runTests();
    
    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Test Results:
 * '({[]})' -> BALANCED
 * '([)]' -> NOT BALANCED
 * '{[()()]}' -> BALANCED
 * '(((' -> NOT BALANCED
 * ')))' -> NOT BALANCED
 * '' -> BALANCED
 * '((()))' -> BALANCED
 * '{[}]' -> NOT BALANCED
 * 
 * BONUS CHALLENGES:
 * 1. Add error handling for stack overflow/underflow
 * 2. Extend to handle other bracket types like '<>'
 * 3. Implement a function to display the current stack contents
 * 4. Add line and column number reporting for unbalanced brackets
 */
