class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* tmp = head;
        int cnt = 1;
        while (tmp->next != NULL) {
            tmp = tmp->next;
            cnt++;
        }
        k %= cnt;
        if (k == 0) return head;
        tmp->next = head;
        int steps = cnt - k;
        ListNode* res = head;
        for(int i = 1 ;i<steps ;i++){
            res = res->next;
        }
        ListNode* nwhead = res->next;
        res->next = NULL;
        return nwhead;
    }
};