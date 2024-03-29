#include <stdio.h>

#define N 8

int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && y >= 0 && x < N && y < N && sol[x][y] == -1);
}

void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            printf("%2d ", sol[x][y]);
        }
        printf("\n");
    }
}

int solveKTUtil(int x, int y, int movei, int sol[N][N]) {
    if (movei == N * N) {
        return 1; // Toate pozițiile au fost acoperite.
    }

    for (int k = 0; k < 8; k++) {
        int next_x = x + moveX[k];
        int next_y = y + moveY[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol)) {
                return 1;
            } else {
                sol[next_x][next_y] = -1;
            }
        }
    }

    return 0;
}

int solveKT(int x, int y) {
    int sol[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sol[i][j] = -1; // Inițializăm tabla de șah cu -1 (nemarcată).
        }
    }

    sol[x][y] = 0; // Poziția de pornire a calului.

    if (solveKTUtil(x, y, 1, sol)) {
        printf("Solutia este:\n");
        printSolution(sol);
        return 1;
    } else {
        printf("Nu există soluție.\n");
        return 0;
    }
}

int main() {
    int x = 0, y = 0;  // Setează coordonatele inițiale la (0, 0) direct.

    solveKT(x, y);

    return 0;
}
