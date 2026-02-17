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
private:
    ListNode* reverses(ListNode* first) {
        ListNode* current = first;
        ListNode* prev = nullptr;
        ListNode* forward = nullptr;

        while (current != nullptr) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
        }
        return prev; // new head
    }


    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy->next;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1: Reverse both lists
       // l1 = reverses(l1);
        //l2 = reverses(l2);

        // Step 2: Add them
        ListNode* sum = add(l1, l2);

        // Step 3: Reverse result to restore proper order
        return sum;
    }
};