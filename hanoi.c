#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void solve_hanoi(stack board[N_POLES], int n);
void solve(stack board[N_POLES], int n, int start, int end, int aux, int spacing);

int main(int argc, char *argv[]){

	stack board[N_POLES];
	for (int i = 0; i < N_POLES; i++)
		board[i] = stack_create();
	
	if (argc != 2){
		fprintf(stderr, "Incorrect usage\n");
		return 1;
	}

	int n = atoi(argv[1]);

	if (n < 0){
		fprintf(stderr, "Incorrect usage\n");
		return 1;
	}

	printf("TOWERS OF HANOI: %d DISKS\n", n);

	for (int i = n; i > 0; i--)
		stack_push(board[0], i);

	show_board(board, n);

	solve_hanoi(board, n);

	board_free(board);
	
	return 0;
}

// Wrapper call to solve initial board
void solve_hanoi(stack board[N_POLES], int n){
	solve(board, n, 0, 2, 1, n);
}

// Recursive Solver
void solve(stack board[N_POLES], int n, int start, int end, int aux, int spacing){

	if (n == 0) return;

	solve(board, n-1, start, aux, end, spacing);
	
	printf("\nMOVE DISK FROM POLE %d TO POLE %d\n", start + 1, end + 1);
	stack_pop_push(board[start], board[end]);
	show_board(board, spacing);

	solve(board, n-1, aux, end, start, spacing);

	return;
}
