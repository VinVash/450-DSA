#include <bits/stdc++.h>
using namespace std;

#define MAX 500 // the max no. of digits in output.

void multiply(int x, vector<int> &res) {
    int carry = 0;

    for(int i=0; i < res.size(); i++) {
        int temp = res[i] * x + carry;
        res[i] = temp % 10;
        carry = temp / 10;
    }

    while(carry) {
        res.push_back(carry % 10);
        carry = carry / 10;
    }
}

vector<int> factorialOfLargeNumber(int n) {
	vector<int> res; // consider max size as 500 digits.
        
    res.push_back(1); // starting factorial.
    
    for(int i = 2; i <= n; i++) {
         multiply(i, res);
    }
    
    // reverse the vector res.
    vector<int> ans;
    for(int i = res.size(); i >= 0; i--)
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