#include <bits/stdc++.h>
using namespace std;

void solveSudoku(vector<vector<char>> &board) {
	solve(board);
}

bool solve(vector<vector<char>> &board) {
	int m = board.size();
	int n = board[0].size();

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == '.') {
				for(char c = '1'; c <= '9'; c++) {
					if(isValid(board, i, j, c)) {
						board[i][j] = c;

						if(solve(board) == true)
							return true;
						else
							board[i][j] = '.';
					}
				}

				return false;
			}
		}
	}

	return true;
}

bool isValid(vector<vector<char>> &board, int row, int col, char c) {
	for(int i = 0; i < 9; i++) {
		if(board[i][col] == c) // checking if same no. is present in the same column.
			return false;

		if(board[row][i] == c) // checking if same no. is present in the same row.
			return false;

		if(board[3 * (row/3) + i/3][3 * (col/3) + i % 3] == c) // checking if same no. is present in the same nonant, i.e., the 3x3 sub-matrix in the sudoku.
			return false;
	}

	return true;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}