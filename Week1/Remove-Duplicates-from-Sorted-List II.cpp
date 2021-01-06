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

// Solution #1: Recursion
// Time Complexity: O(n) number of nodes until the end
// Space Complexity: O(m) number of duplicate numbers

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        if(head->val == head->next->val){
            int val = head->val;
            
            while(head and head->val == val)
                head = head->next;
            return deleteDuplicates(head);
        }
        else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};