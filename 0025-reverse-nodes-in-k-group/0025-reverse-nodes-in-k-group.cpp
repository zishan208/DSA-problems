class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int total = 0;
        while (curr) {
            total++;
            curr = curr->next;
        }

        int times = total / k;
        curr = head;

        ListNode* newHead = nullptr;   
        ListNode* prev_tail = nullptr; 

        while (times--) {
            ListNode* grh = curr;
            ListNode* prev = nullptr;

            for (int i = 0; i < k; i++) {
                ListNode* forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }

            if (prev_tail) prev_tail->next = prev;
            else newHead = prev;

            prev_tail = grh;
        }

        if (prev_tail) prev_tail->next = curr;

        return newHead;
    }
};