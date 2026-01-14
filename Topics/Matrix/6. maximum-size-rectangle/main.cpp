#include <bits/stdc++.h>
using namespace std;

int maxHist(vector<int> &row, int c) {
    // Create an empty stack. The stack holds indexes of hist[] array.
    // The bars stored in stack are always in increasing order of their heights.
    stack<int> result;
 
    int top_val; // Top of stack
 
    int max_area = 0; // Initialize max area in current row (or histogram)
 
    int area = 0; // Initialize area with current top
 
    // Run through all bars of given histogram (or row)
    int i = 0;
    while (i < c) {
        // If this bar is higher than the bar on top stack, push it to stack
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else {
            // If this bar is lower than top of stack, then
            // calculate area of rectangle with stack top as
            // the smallest (minimum height) bar. 'i' is
            // 'right index' for the top and element before
            // top in stack is 'left index'
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
 
    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
 
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(vector<vector<int>> &A, int r, int c) {
    // Calculate area for first row and initialize it as result.
    int result = maxHist(A[0], c);
 
    // Iterate over row to find maximum rectangular area
    // considering each row as histogram
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++)
            if (A[i][j]) // if A[i][j] is 1 then add A[i -1][j]
                A[i][j] += A[i - 1][j];
 
        // Update result if area with current row (as last row) of rectangle) is more
        result = max(result, maxHist(A[i], c));
    }
 
    return result;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int r, c;
	cin >> r >> c;

	vector<vector<int>> matrix(r, vector<int>(c, 0));

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++)
			cin >> matrix[i][j];
	}

	int res = maxRectangle(matrix, r, c);

	cout << res << endl;


	return 0;
}