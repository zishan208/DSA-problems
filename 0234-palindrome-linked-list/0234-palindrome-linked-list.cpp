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
    bool isPalindrome(ListNode* head) {
        ListNode* current=head;
        vector<int> arr;
        while (current!=nullptr)
        {
            arr.push_back(current->val);
            current=current->next;
            
        }
   int n=arr.size();
        for (int i = 0; i < n/2; i++)
        {
            if (arr[i]!=arr[n-i-1]) return false;
        }
        
        
        return true;

        
    }
};