// Implementation of stack ADT with a linked list
//
// completion left as an exercise

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

void stack_free(stack s){
	while (s->size > 0){
		stack_pop(s);
	}
	free(s);
} 

void board_free(stack board[]){
	for (int i = 0; i < N_POLES; ++i) 
		stack_free(board[i]);
}

void stack_push(stack s, int size){
	block b = malloc(sizeof(*b));
	
	b->next = s->top;
	b->size = size;

	s->top = b;
	s->size++;
}

int stack_pop(stack s){
	assert(s->size > 0);

	block tmp = s->top;
	s->top = s->top->next;

	int ret = tmp->size;
	free(tmp);

	s->size--;

	return ret;
}

int stack_top(stack s){
	assert(s->size > 0);
	return s->top->size;
}  

void stack_pop_push(stack f, stack t){
	assert(f->size > 0);

	block tmp = f->top->next;
	f->top->next = t->top;

	t->top = f->top;
	f->top = tmp;

	t->size++;
	f->size--;
}

void show_stack(stack s, int n){
	for (block curr = s->top; curr != NULL; curr = curr->next){
		print_block(n, curr->size);
		printf("\n");	
	}
}

void show_board(stack board[], int n){

	block curr[N_POLES];

	for (int i = 0; i < N_POLES; ++i){
		curr[i] = board[i]->top;
	}

	for (int j = n; j > 0; --j){
		for (int i = 0; i < N_POLES; ++i){

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

int stack_size(stack s){
		return s->size;
		return s->top->size;
}

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



