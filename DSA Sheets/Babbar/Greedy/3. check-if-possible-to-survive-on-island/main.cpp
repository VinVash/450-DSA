#include <bits/stdc++.h>
using namespace std;

int minimumDays(int S, int N, int M){
    int sundays = S / 7;
    int buyingDays = S - sundays;
    int totalFood = S * M; // food required;
    int res = 0;
    
    if(totalFood % N == 0)
        res = totalFood / N;
    else
        res = totalFood / N + 1;
        
    if(res <= buyingDays)
        return res;
    else
        return -1;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}