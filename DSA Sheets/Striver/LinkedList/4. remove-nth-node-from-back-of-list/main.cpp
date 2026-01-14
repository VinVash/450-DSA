struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(n == 0) return head;
      ListNode *a = head;
      ListNode *b = head;

      for(int i = 0; i < n; i++)
        a = a->next;

      if(!a) return head->next;

      while(a->next) {
        b = b->next;
        a = a->next;
      }

      b->next = b->next->next;

      return head;
}