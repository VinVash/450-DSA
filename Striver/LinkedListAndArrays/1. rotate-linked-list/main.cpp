struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* rotateRight(ListNode* head, int k) {
    ListNode *slow = head;
    ListNode *fast = head;
    
    if (head == nullptr) {
        return nullptr;
    }
    
    ListNode *tmp = head;
    int count = 0;
    while (tmp!= nullptr) {
        tmp = tmp->next;
        count ++;
    }
    
    k = k % count;
    for (int i = 0; i < k ; i++) {
        fast = fast->next;
    }
    
    while(fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = head;
    ListNode *result = slow->next;
    slow->next = nullptr;
    return result;
    
}