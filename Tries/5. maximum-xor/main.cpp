#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

struct Node {
    Node *links[2];

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            } else {
                node = node->get(bit);
            }
        }

        return maxNum;
    }

};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;

    for(int i = 0; i < arr1.size(); i++)
        trie.insert(arr1[i]);

    int maxi = 0;
    for(auto& it: arr2) {
        maxi = max(maxi, trie.getMax(it));
    }

    return maxi;

}


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}