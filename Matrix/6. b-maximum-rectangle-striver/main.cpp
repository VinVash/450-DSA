int largestArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);
    
    int area = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        int l = heights[i];

        if(next[i] == -1) {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

vector<int> nextSmallerElement(vector<int>& arr, int n) {
     stack<int> stk;
    stk.push(-1);
    
    vector<int> ans(n);
    
    for(int i = n-1; i >= 0; i--) {
        int curr = arr[i];
        while(stk.top() != -1 && arr[stk.top()] >= curr) {
            stk.pop();
        }
        
        // ans is stack ka top
        ans[i] = stk.top();
        stk.push(i);
    }
    
    return ans;
}

vector<int> prevSmallerElement(vector<int>& arr, int n) {
    stack<int> stk;
    stk.push(-1);
    
    vector<int> ans(n);
    
    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        while(stk.top() != -1 && arr[stk.top()] >= curr) {
            stk.pop();
        }
        
        // ans is stack ka top
        ans[i] = stk.top();
        stk.push(i);
    }
    
    return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> heights(n, 0);
    int maxi = 0; // ans

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        maxi = max(maxi, largestArea(heights));
    }

    return maxi;
}
