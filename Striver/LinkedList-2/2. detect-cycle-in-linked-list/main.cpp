bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    
    if(head == nullptr)
        return false;
    
    while(slow->next != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
        
        if(fast != nullptr)
            fast = fast->next;
        
        if(fast == nullptr)
            return false;
        if(fast == slow)
            return true;
    }
    
    return false;
}