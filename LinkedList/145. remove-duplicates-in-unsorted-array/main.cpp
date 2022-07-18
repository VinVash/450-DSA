#include <bits/stdc++.h>
using namespace std;

Node * removeDuplicates( Node *head) {
    unordered_set<int> hset;
    
    Node *p = head, *q = nullptr; // q will remain behind p.
    
    while(p) {
        if(hset.find(p->data) != hset.end()) {
            q->next = p->next;
            delete p;
        } else {
            hset.insert(p->data);
            q = p;
        }
        p = p->next;
    }
    
    return head;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}