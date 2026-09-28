class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode dummy(0);
        ListNode* ans = &dummy;
        ListNode* curr = head;

        while (curr) {
            int value = curr->val;
            int count = 0;

            while (curr && curr->val == value) {
                curr = curr->next;
                count++;
            }

            if (count == 1) {
                ans->next = new ListNode(value);
                ans = ans->next;
            }
        }

        return dummy.next;
    }
};