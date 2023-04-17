#include <bits/stdc++.h>
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *p = head;
    ListNode *q;
    
    if(!head) return NULL;
    if(head->next) 
        q = head->next;
    else
        return head;
    
    while(q != NULL) {
        if(p->val != q->val) {
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
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