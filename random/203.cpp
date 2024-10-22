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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return nullptr;
        
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while(cur){
            if(cur->val == val){
                if(cur == head){
                    pre = cur;
                    cur = cur->next;
                    pre->next = nullptr;
                    delete pre;
                    pre = nullptr;
                    head = cur;
                }
                else{
                    ListNode* next = cur->next;
                    pre->next = next;
                    cur->next = nullptr;
                    delete cur;
                    cur = next;
                }
            }
            else
                pre = cur, cur = cur->next;
        }
        return head;
    }
};
