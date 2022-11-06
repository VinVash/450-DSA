ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*, bool> hmap;
    
    while(headA != nullptr) {
        hmap[headA] = true;
        headA = headA->next;
    }
    
    while(headB != nullptr) {
        if(hmap.count(headB))
            return headB;
        headB = headB->next;
    }
    
    return headA;
}