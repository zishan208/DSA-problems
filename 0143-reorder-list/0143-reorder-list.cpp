class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        stack<ListNode*> st;
        ListNode* curr = head;
        while (curr) {
            st.push(curr);
            curr = curr->next;
        }


        int n = st.size();
        curr = head;
        for (int i = 0; i < n / 2; i++) {
            ListNode* last = st.top();
            st.pop();
            ListNode* temp = curr->next;
            curr->next = last;
            last->next = temp;
            curr = temp;
        }
        curr->next = nullptr; 
    }
};