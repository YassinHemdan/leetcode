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
    ListNode* add(ListNode* list, int val){
        ListNode* node = new ListNode(val);
        if(list)
            list->next = node;
        return node;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedList = nullptr;
        ListNode* cur = nullptr;
        while(list1 || list2){
            if(list1 && list2){
                if(list1->val <= list2->val)
                    cur = add(cur, list1->val), list1 = list1->next;
                else
                    cur = add(cur, list2->val), list2 = list2->next;
            }
            else if(list1)
                cur = add(cur, list1->val), list1 = list1->next;
            else
                cur = add(cur, list2->val), list2 = list2->next;
            if(!mergedList)
                mergedList = cur;
        }
        return mergedList;
    }
};
