// Solution #1: Brute Force using Extra Memory
// Time Complexity: O(n + m) goes through all nodes once
// Space Complexity: O(n + m) extra memory to store all nodes of l1 and l2

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *tail, *head = new ListNode();
        
        if(!l1 && !l2)
            return NULL;
        if(!l1 || !l2){
            if(!l1) return l2;
            if(!l2) return l1;
        }
        
        if(l1->val < l2->val){
            head->val = l1->val;
            l1 = l1->next;
        }else{
            head->val = l2->val;
            l2 = l2->next;
        }
        
        tail = head;
        
        while(l1 || l2){
            ListNode *node = new ListNode();
            
            if(!l1){
                node->val = l2->val;
                l2 = l2->next;
            }
            else if(!l2){
                node->val = l1->val;
                l1 = l1->next;
            }
            else {
                if(l1->val < l2->val){
                    node->val = l1->val;
                    l1 = l1->next;
                    
                }else{
                    node->val = l2->val;
                    l2 = l2->next;
                }
                
            }
            
            tail->next = node;
            tail = tail->next;
        }
        
        return head;
    }
};