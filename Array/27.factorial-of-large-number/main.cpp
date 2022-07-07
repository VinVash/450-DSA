#include <bits/stdc++.h>
using namespace std;

#define MAX 500 // the max no. of digits in output.

int multiply(int x, vector<int> &res, int res_size) {
    int carry = 0;
    
    for(int i = 0; i < res_size; i++) {
        int temp = res[i] * x + carry;
        res[i] = temp % 10;
        carry = temp / 10;
    }
    
    while(carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    
    return res_size;
}

vector<int> factorialOfLargeNumber(int n) {
	vector<int> res(500); // consider max size as 500 digits.
        
    res[0] = 1; // starting factorial is 1.
    int res_size = 1; // size of the current res vector.
    
    for(int i = 2; i <= n; i++) {
        res_size = multiply(i, res, res_size);
    }
    
    // reverse the vector res.
    vector<int> ans;
    for(int i = res_size-1; i >= 0; i--)
        ans.push_back(res[i]);
    
    return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	vector<int> res = factorialOfLargeNumber(897);

	for(int i = 0; i < res.size(); i++)
		cout << res[i];
	cout << endl;


	return 0;
}