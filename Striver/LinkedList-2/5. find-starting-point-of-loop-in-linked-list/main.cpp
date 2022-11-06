ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    
    while(fast->next != nullptr && slow->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
        
        if(fast != nullptr)
            fast = fast->next;
        
        if(fast == nullptr)
            break;
        
        if(slow == fast)
            break;
    }
    
    if(slow != fast) {
        return nullptr;
    }
    
    slow = head;
    
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow; // or fast, since both are pointing to the same node.
}