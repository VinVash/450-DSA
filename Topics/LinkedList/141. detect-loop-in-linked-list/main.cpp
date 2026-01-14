#include <bits/stdc++.h>
using namespace std;

bool hasCycle(ListNode *head) {
    if(head == nullptr) return false;
    ListNode *hare = head, *tortoise = head;
    
    while(hare->next != nullptr && tortoise->next != nullptr) {
        tortoise = tortoise->next;
        hare = hare->next;
        
        if(hare != nullptr)
            hare = hare->next;
        
        if(hare == nullptr) return false;
        if(hare == tortoise)
            return true;
    }
    
    return false;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}