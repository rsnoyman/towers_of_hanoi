// Implementation of stack ADT for towers of hanoi		   

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

typedef struct _block {
    struct _block *next;
    int size;
} *block;

struct stack_internals {
	block top;
	int size;
};

void print_block(int n, int size);

// Create a new stack
stack stack_create(void){
	stack s = malloc(sizeof(*s));
	if (s == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    s->top = NULL;
    s->size = 0;

    return s;
}           

// add new block of size 'size' to stack
void stack_push(stack s, int size){
	block b = malloc(sizeof(*b));
	
	b->next = s->top;
	b->size = size;

	s->top = b;
	s->size++;
}

// remove next item from stack and return it
int stack_pop(stack s){
	assert(s->size > 0);

	block tmp = s->top;
	s->top = s->top->next;

	int ret = tmp->size;
	free(tmp);

	s->size--;

	return ret;
}

// return size of top block
int stack_top(stack s){
	assert(s->size > 0);
	return s->top->size;
} 

// free a stack
void stack_free(stack s){
	while (s->size > 0){
		stack_pop(s);
	}
	free(s);
}

// free a board
void board_free(stack board[]){
	for (int i = 0; i < N_POLES; ++i) 
		stack_free(board[i]);
} 

// Move block from f to t
void stack_pop_push(stack f, stack t){
	assert(f->size > 0);

	block tmp = f->top->next;
	f->top->next = t->top;

	t->top = f->top;
	f->top = tmp;

	t->size++;
	f->size--;
}

// show stack
void show_stack(stack s, int n){
	for (block curr = s->top; curr != NULL; curr = curr->next){
		print_block(n, curr->size);
		printf("\n");	
	}
}

// show hanoi board in ASCII art
void show_board(stack board[], int n){

	block curr[N_POLES];

	for (int i = 0; i < N_POLES; ++i){
		curr[i] = board[i]->top;
	}

	for (int j = n; j > 0; --j){
		for (int i = 0; i < N_POLES; ++i){

			// If stack is less than height j, print empty block
			if (board[i]->size < j){
				print_block(n, 0);
				continue;
			}

			print_block(n, curr[i]->size);
			
			if (curr[i] != NULL) curr[i] = curr[i]->next;
		}
		printf("\n");
	}

}

// return stack size
int stack_size(stack s){
	return s->size;
}

// print a block of size 'size' with 'n' white space
void print_block(int n, int size){
	for (int i = 0; i < n - size; ++i)
		printf(" ");

	for (int i = 0; i < size; ++i)
		printf("=");

	printf("|");

	for (int i = 0; i < size; ++i)
		printf("=");

	for (int i = 0; i <= n - size; ++i)
		printf(" ");
}



