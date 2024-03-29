#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
typedef long long ll;

struct Node {
    Node *links[26]; 
    bool flag = false; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }

    Node* get(char ch) {
        return links[ch-'a']; 
    }

    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }

    void setEnd() {
        flag = true; 
    }
    
    bool isEnd() {
        return flag; 
    }
};

class Trie {
    private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }

    bool checkIfAllPrefixExists(string word) {
        Node *node = root;
        for(int i = 0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]); 
                if(node->isEnd() == false) return false;
            } else {
                return false;
            }
        }

        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie* obj = new Trie();
    for(auto word : a) obj->insert(word); 

    string longest = ""; 
    for(auto word: a) {
        if(obj->checkIfAllPrefixExists(word)) {
            if(word.size() > longest.size()) {
                longest = word; 
            }
            else if(word.size() == longest.size() && word < longest) { // word < longest, since we need lexographically smallest string.
                longest = word; 
            }
        }
    }
    if(longest == "") return "None"; 
    return longest; 

}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}