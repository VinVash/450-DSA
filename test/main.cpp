#include <bits/stdc++.h>
using namespace std;

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