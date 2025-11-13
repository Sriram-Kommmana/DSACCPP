#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    int r = row, c = col;

    // check upper-left diagonal
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r--; c--;
    }

    // check left
    r = row; c = col;
    while (c >= 0) {
        if (board[r][c] == 'Q') return false;
        c--;
    }

    // check lower-left diagonal
    r = row; c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r++; c--;
    }

    return true;
}

bool solve(int col, vector<string>& board, int n) {
    if (col == n) {
        return true; // found one solution
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';

            if (solve(col + 1, board, n))
                return true;   // stop after first solution

            board[row][col] = '.'; // backtrack
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<string> board(n, string(n, '.'));

    if (solve(0, board, n)) {
        for (auto &row : board)
            cout << row << "\n";
    } else {
        cout << "No solution exists";
    }
}
