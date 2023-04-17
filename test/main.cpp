#include <bits/stdc++.h>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    long long n; cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i++)
      cin >> a[i];
    
    int ans = 0;
      
    for(long long i = 0; i < n-1; i++) {
      if((a[i] + a[i+1]) % 2) { // is odd.
        if(a[i+1] % 2) { // first no. is even, second no.is odd.
          if(i+2 < n && a[i+2] % 2 == 0)
            a[i+1] = a[i];
        } else { // first no. is odd, second no. is even.
          if(i+2 < n && a[i+2] % 2 == 1)
            a[i+1] = a[i];
        }
        
        ans++;
      }
    }
    
    cout << ans << endl;
        
   return 0;
    
}