
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head==nullptr) {
            return head;
        }

    ListNode* current=head;
    int size=1;

    while (current->next) {
      current=current->next;
      size++; 
    }

    k%=size;
    if (k == 0) return head;
    current->next=head;
    int index=size-k-1;
    current=head;


    while (index!=0) {
        current=current->next;
        index--;
    }

    head=current->next;
    current->next=nullptr;

    return head;




        
    }
};