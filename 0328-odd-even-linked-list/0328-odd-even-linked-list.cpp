/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
    
        ListNode* fast=head;
        int count=0;
    
        while(fast->next) {
             count++;
            fast=fast->next;
           
        }
        count++;
        if(count <=2) return head;
        ListNode* slow=head;
        int i=count/2;

        while(i){
            ListNode* temp=slow->next;
            slow->next=slow->next->next;
            fast->next=temp;
            temp->next=nullptr;
            fast=fast->next;
            slow=slow->next;
            i=i-1;


        }
return head;
        
    }
};