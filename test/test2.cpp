#include <bits/stdc++.h>
using namespace std;

int parity(int a) {
    return a % 2;
}

// Function to return the minimum
// number of operations required
int solve(vector<int> &array, int size) {
    int n = size;
    int x1 = 0, x2 = 0;
    vector<int> array2 = array;

    bool flag = parity(array[0]);

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1 && parity(array[i]) == flag)
        {
            int pari1 = parity(array[i]);
            int pari2 = pari1; // initial value of pari1.

            while (pari1 == pari2)
            {
                array[i] = floor(array[i] / 2);
                x1++;
                pari1 = parity(array[i]);
            }
        }

        if (i % 2 == 0 && parity(array[i]) != flag)
        {
            int pari1 = parity(array[i]);
            int pari2 = pari1; // initial value of pari1.

            while (pari1 == pari2)
            {
                array[i] = floor(array[i] / 2);
                x1++;
                pari1 = parity(array[i]);
            }
        }
    }

    while (parity(array2[0]) == flag)
    {
        array2[0] = floor(array2[0] / 2);
    }

    flag = !flag;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1 && parity(array2[i]) == flag)
        {
            int pari1 = parity(array2[i]);
            int pari2 = pari1; // initial value of pari1.

            while (pari1 == pari2)
            {
                array2[i] = floor(array2[i] / 2);
                x2++;
                pari1 = parity(array2[i]);
            }
        }

        if (i % 2 == 0 && parity(array2[i]) != flag)
        {
            int pari1 = parity(array2[i]);
            int pari2 = pari1; // initial value of pari1.

            while (pari1 == pari2)
            {
                array2[i] = floor(array2[i] / 2);
                x2++;
                pari1 = parity(array2[i]);
            }
        }
    }

    return x1 > x2 ? x2 : x1;
}

int getMinimumOperations(vector<int> items) {
    return solve(items, items.size());
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << getMinimumOperations(nums) << endl;

	return 0;
}