#include <bits/stdc++.h>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    double num = 50.0;

    for(int i = 0; i < 262; i++)
        cout << num + 0.05*i << "," << endl;

    num = 63.1;
    for(int i = 0; i < 263; i++)
        cout << num + 0.2*i << "," << endl;
        
   return 0;
    
}