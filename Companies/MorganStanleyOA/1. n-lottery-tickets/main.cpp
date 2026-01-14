#include <bits/stdc++.h>
using namespace std;

/*
    Steps to select winner:

    1. Lottery tickets are numbered 1 to n.
    2. Delete first ticket, and then every alternative ticket till it reaches end.
    3. Start from right, delete first ticket, and then every alternative ticket till it reaches end (start of the array).
    4. Repeat steps 2. and 3. till only single ticket remains.
    5. That ticket is the winner, return that ticket number.


    Eg: There are 21 tickets:
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
    2 4 6 8 10 12 14 16 18 20
    2 6 10 14 20
    6 14
    6

*/

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
        
    int n; cin >> n;
    
    vector<int> vec;
    for(int i = 1; i <= n; i++)
        vec.push_back(i);

    vector<int> num;
    
    while(vec.size() != 1) {

        for(int i = 0; i < vec.size(); i++) {

            if((i+1) % 2 != 1)
                num.push_back(vec[i]);
        }
        
        reverse(num.begin(), num.end());

        vec.clear();
        for(auto i: num) {
            vec.push_back(i);
        }

        num.clear();
    }
    
    cout << vec[0];
}