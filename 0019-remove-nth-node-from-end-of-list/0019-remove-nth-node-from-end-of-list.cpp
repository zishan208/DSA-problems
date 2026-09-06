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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        ListNode* curr=head;

        int count=0;
        while(curr!=nullptr){
            count++;
            curr=curr->next;
        }
        if (n == count) return head->next;
        count=count-n-1;
        curr=head;
        while(count){
            count--;
            curr=curr->next;
        }
        if(curr->next->next){
            curr->next=curr->next->next;

        }else{
            curr->next=nullptr;
            
        }
    

        return head;
        
    }
};