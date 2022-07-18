#include <bits/stdc++.h>
using namespace std;

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *r = nullptr, *q = nullptr, *temp = head;
    ListNode *lastfirst = nullptr, *t = nullptr;
    bool flag = false;
    
    int l = 0; // stores the length of the linked list.
    while(temp != nullptr) {
        l++;
        temp = temp->next;
    }
    
    int rep = l / k;
    temp = head;
    
    while(rep) {
        r = q = nullptr;
        for(int i = 0; i < k; i++) {
            r = q;
            q = temp;
            temp = temp->next;
            q->next = r;
        }
        
        if(!flag) {
            flag = 1;
            head = q;
        }
        
        if(lastfirst) {
            while(lastfirst->next)
                lastfirst = lastfirst->next;
            lastfirst->next = q;
            lastfirst = q;
        } else {
            lastfirst = q;
        }
        
        rep--;
    }
    
    while(lastfirst->next)
        lastfirst = lastfirst->next;
    lastfirst->next = temp;
    
    return head;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}