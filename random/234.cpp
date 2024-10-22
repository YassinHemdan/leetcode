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
        int n = 0;
        ListNode* cur = head;
        while(cur)
            ++n, cur = cur->next;
        
        int mid = ((n + 2 - 1) / 2) + 1;
        ListNode* tail = nullptr;
        cur = head;
        while(cur){
            --mid;
            if(mid <= 0){
                ListNode* next = cur->next;
                tail->next = (mid == 0 ? nullptr : tail->next);
                cur->next = tail;
                tail = cur;
                cur = next;
            }
            else
                tail = cur, cur = cur->next;
        }
        while(head && tail){
            if(head->val != tail->val)
                return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};
