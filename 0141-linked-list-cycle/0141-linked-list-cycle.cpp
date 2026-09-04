/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head==nullptr || head->next==nullptr) return false;
        unordered_map<ListNode*,bool> v;
        ListNode* curr=head;
     
        while(curr!=nullptr) {
            if(v[curr]) return true;

             v[curr]=true;
            curr=curr->next;
           

        }
        return false;
        
    }
};