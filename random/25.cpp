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
    ListNode* ans = nullptr;
    pair<ListNode*, ListNode*> reverseList(ListNode* end, ListNode* pre, ListNode* head, int k) {
        if(!head || !head->next)
            return {nullptr, nullptr};
        ListNode* toConnect = head;
        ListNode* cur = head;
        while(cur && k--){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if(end)
            end->next = pre;
        if(!ans)
            ans = pre;
        return {toConnect, cur};
    }
    int len(ListNode* cur){
        int length = 0;
        while(cur)
            ++length, cur = cur->next;
        return length;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ans = nullptr;
        int length = len(head);
        int n = length / k;
        pair<ListNode*, ListNode*> p {nullptr, head};
        while(n--){
            ListNode* start = p.second;
            ListNode* prev = p.first;
            p = reverseList(prev, nullptr, start, k);
        }
        if(p.first)
            p.first->next = p.second;
        return ans;
    }
};
