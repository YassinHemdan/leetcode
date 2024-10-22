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
    ListNode* reverse(ListNode* node){
        if(node->next == nullptr)
            return node;
        ListNode* head = reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        return reverse(head);
    }
};
