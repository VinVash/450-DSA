#include <bits/stdc++.h>
using namespace std;

long long merge(vector<long long> &vec, vector<long long> &temp, int l, int m, int r) {
    int i = l, j = m, k = l;
    int inv_count = 0;
    
    while(i <= m-1 && j <= r) {
        if(vec[i] <= vec[j]) {
            temp[k] = vec[i];
            i++; k++;
        } else {
            temp[k] = vec[j];
            j++; k++;
            
            inv_count += (m-i); // inv_count pairs found when the element from the right side is smaller.
        }
    }
    
    while(i <= m-1)
        temp[k++] = vec[i++];
    while(j <= r)
        temp[k++] = vec[j++];
        
    for(i = l; i <= r; i++) {
        vec[i] = temp[i];
    }
    
    return inv_count;
}

long long mergeSort(vector<long long> &vec, vector<long long> &temp, int l, int r) {
    int inv_count = 0;

    if(l < r) {
        int mid = (l+r) / 2;
        
        inv_count += mergeSort(vec, temp, l, mid);
        inv_count += mergeSort(vec, temp, mid+1, r);
        
        inv_count += merge(vec, temp, l, mid+1, r);
    }
    
    return inv_count;
}

long long getInversions(vector<long long> &vec, int n){
    
    vector<long long> temp(n);

    // working fine till here.
    
    long long ans = mergeSort(vec, temp, 0, n-1);
    
    return ans;
    
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    vector<long long> vec(n);

    for(int i = 0; i < n; i++)
        cin >> vec[i];

    vector<long long> temp(n);

    int ans = getInversions(vec, n);
    cout << ans << endl;

    return 0;
}