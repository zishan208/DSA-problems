class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0, head); 
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
 
                while (current->next != nullptr && current->next->val == current->val) {
                    ListNode* delet = current->next;
                    current->next = current->next->next;
                    delete delet;
                }
      
                prev->next = current->next;
                delete current;
                
                current = prev->next;
            } else {

                prev = current;
                current = current->next;
            }
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};