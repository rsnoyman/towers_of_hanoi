/*
Stack Abstract Data Type

https://en.wikipedia.org/wiki/Abstract_data_type
 
Actual implementation of stack opaque to (hidden from) user
*/

#define N_POLES 3

typedef struct stack_internals *stack;

stack stack_create(void);              // create a new stack
void stack_free(stack s);              // free a stack
void board_free(stack board[]);		   // free a board
void stack_push(stack s, int item);    // add new item to stack
int stack_pop(stack s);                // remove next item from stack and return it
int stack_top(stack s);				   // return size of top block
void stack_pop_push(stack f, stack t); // move node from one stack to next
void show_stack(stack s, int n);	   // show stack
void show_board(stack board[], int n); // show hanoi board in ASCII art
int stack_size(stack s);			   // return stack size
