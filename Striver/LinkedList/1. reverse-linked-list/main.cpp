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


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *newHead = nullptr; // initialise newHead
    
    while(head != nullptr) {
        LinkedListNode<int> *temp = head->next;
        head->next = newHead;
        newHead = head;
        head = temp;
    }
    
    return newHead;
}