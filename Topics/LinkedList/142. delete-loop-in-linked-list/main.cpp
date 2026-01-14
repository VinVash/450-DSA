#include <bits/stdc++.h>
using namespace std;

void removeLoop(Node* head) {
    Node *hare = head, *tortoise = head;
    
    while(hare->next != nullptr && tortoise->next != nullptr) {
        hare = hare->next;
        tortoise = tortoise->next;
        
        if(hare != nullptr)
            hare = hare->next;
        if(hare == nullptr)
            return; // there is no loop.
            
        if(hare == tortoise) // there is a loop.
            break;
        
    }
    
    if(hare == tortoise) {
        tortoise = head;
        
        if(hare == tortoise) {
            while(hare->next != tortoise)
                hare = hare->next;
        } else {
            while(tortoise->next != hare->next) {
                tortoise = tortoise->next;
                hare = hare->next;
            }
        }
        hare->next = nullptr;
    }
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}