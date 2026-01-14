ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *next = nullptr;
    
    while(head != nullptr) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    
    return pre;
}

bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head;
    
    if(head == nullptr || head->next == nullptr) {
        return true; // empty or single node linked list is palindrome.
    }
    
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    slow->next = reverseList(slow->next);
    slow = slow->next;
    
    while(slow != nullptr) {
        if(head->val != slow->val)
            return false;
        slow = slow->next;
        head = head->next;
    }
    
    return true;
}