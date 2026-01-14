#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {

    ListNode* pre = NULL;
    ListNode* next = NULL;

    while(head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    return pre;
}