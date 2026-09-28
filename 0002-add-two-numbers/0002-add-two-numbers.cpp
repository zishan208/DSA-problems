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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            ListNode* ans=new ListNode();
            ListNode* head=ans;
            

            ListNode* curr1=l1;
            ListNode* curr2=l2;

            int carry=0;

            while(curr1 || curr2 || carry){

                int sum=0;
                if(curr1){
                    sum+=curr1->val;
                    curr1=curr1->next;
                }
                if(curr2){
                    sum+=curr2->val;
                    curr2=curr2->next;
                }

                ans->val=(sum+carry)%10;
                carry=(sum+carry)/10;

                if(curr1 || curr2 || carry){
                    ans->next=new ListNode();
                    ans=ans->next;
                }
                
                

            }
           return head;
        
    }
};