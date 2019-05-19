#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int invalid_move(stack board[], int from, int to);

int main(int argc, char *argv[]){

	stack board[N_POLES];
	for (int i = 0; i < N_POLES; i++)
		board[i] = stack_create();
	
	int n;

	if (argc == 2){
		n = atoi(argv[1]);
	} else {
		printf("Enter number of disks: ");
		scanf("%d", &n);
	}

	while (n < 0){
		printf("Enter a positive number: ");
		scanf("%d", &n);
	}

	for (int i = n; i > 0; i--)
		stack_push(board[0], i);

	show_board(board, n);

	int moves = 0;

	while (stack_size(board[2]) != n){
		int from;
		printf("Move disk from pole (0, 1, 2): ");
		scanf("%d", &from);

		while (from < 0 || from > 2){
			printf("Enter a number between 0 and 2: ");
			scanf("%d", &from);
		}

		int to;
		printf("Move disk to pole (0, 1, 2): ");
		scanf("%d", &to);

		while (to < 0 || to > 2){
			printf("Enter a number between 0 and 2: ");
			scanf("%d", &to);
		}

		if (invalid_move(board, from, to)){
			printf("Invalid move!\n");
			continue;
		}

		stack_pop_push(board[from], board[to]);
		show_board(board, n);
		moves++;	
	}

	printf("Congratulations! You completed the puzzle in %d moves.\n", moves);

	board_free(board);
	
	return 0;
}

int invalid_move(stack board[], int from, int to){
	if (from == to){
		printf("Can't move disk to same pole.\n");
		return 1;
	}

	if (stack_size(board[from]) == 0){
		printf("Pole %d is empty.\n", from);
		return 1;
	}

	if (stack_size(board[to]) == 0) {
		return 0;
	}

	if (stack_top(board[from]) > stack_top(board[to])){
		printf("You must move a smaller disk onto a larger disk.\n");
		return 1;
	}

	return 0;
}
