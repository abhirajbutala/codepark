#include<iostream>

using namespace std;

#define UNASSIGNED 0
#define N 9


bool findUnassignedPos(int grid[N][N], int &row, int &col) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == UNASSIGNED) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int val) {

    // If value already exists in the given row or column, return false
    for (int i = 0; i < N; i++) {
        if ((grid[row][i] == val) || (grid[i][col] == val)) {
            return false;
        }
    }

    // If value already exists in the given 3*3 box, return false
    int boxStartRow = row - row%3;
    int boxStartCol = col - col%3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[boxStartRow + i][boxStartCol + j] == val) {
                return false;
            }
        }
    }

    // Else, return true, meaning that it is safe to put this value
    // in the given row/col position.
    return true;
}


bool solveSudoku(int grid[N][N]) {
    int row, col;

    if (findUnassignedPos(grid, row, col) == false) {
        return true;
    }

    for (int i = 1; i <= 9; i++) {
        if (!isSafe(grid, row, col, i)) {
            continue;
        }
        grid[row][col] = i;
        if (solveSudoku(grid)) {
            return true;
        }
        // Backtrack
        grid[row][col] = UNASSIGNED;
    }

    return false;
}


void printSudoku(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solveSudoku(grid) == true) {
        printSudoku(grid);
    } else {
        cout << "No Solution Exists!" << endl;
    }

    return 0;
}

