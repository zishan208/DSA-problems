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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

      priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minorder;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* current=lists[i];
            while(current!=nullptr){

                minorder.push({current->val,current});
                current=current->next;
            }
            
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!minorder.empty()) {
            auto node = minorder.top().second;
            minorder.pop();
            tail->next = node;
            tail = tail->next;
        }

      
        tail->next = nullptr;

        return dummy.next;


        
    }
};