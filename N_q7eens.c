#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int board[MAX];
int N;
int solutionCount = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void printSolution() {
    solutionCount++;
    printf("Solution %d: ", solutionCount);
    for (int i = 0; i < N; i++) {
        printf("%d ", board[i] + 1); // +1 for 1-based indexing
    }
    printf("\n");
}

void solveNQueens(int row) {
    if (row == N) {
        printSolution();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1);
        }
    }
}

int main() {
    printf("Enter the value of N (max %d): ", MAX);
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        printf("Invalid value of N\n");
        return 1;
    }

    printf("Solutions to the %d-Queens problem (as column positions):\n\n", N);
    solveNQueens(0);

    if (solutionCount == 0) {
        printf("No solutions exist for N = %d\n", N);
    }

    return 0;
}
