#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

struct Node {

    Node* links[26];
    int cp; // count prefix
    int ew; // count end with

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a']= node;
    }

    void increaseEW() {
        ew++;
    }

    void increaseCP() {
        cp++;
    }

    void reduceEW() {
        ew--;
    }

    void reduceCP() {
        cp--;
    }

};

class Trie{

    private:
    Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());

            node = node->get(word[i]);
            node->increaseCP();
        }

        node->increaseEW();
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }

        return node->ew;
    }

    int countWordsStartingWith(string &word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }

        return node->cp;

    }

    void erase(string &word) {
        Node* node = root;
        for(int i = 0; i< word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->reduceCP();
            } else
                return;
        }

        node->reduceEW();
    }
};


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}