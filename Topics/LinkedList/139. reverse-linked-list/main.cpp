#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reverseLinkedList(ListNode* head) {
	ListNode* newHead = nullptr;

	while(head != nullptr) {
		ListNode* temp = head->next;
		head->next = newHead;
		newHead = head;
		head = temp;
	}

	return newHead;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif




	return 0;
}