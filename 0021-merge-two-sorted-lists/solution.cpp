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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        ListNode *mergeList = nullptr;

        if (list1->val <= list2->val) {
            mergeList = list1;
            list1 = list1->next;
        } else {
            mergeList = list2;
            list2 = list2->next;
        }

        ListNode *temp = mergeList;

        while (list1 != nullptr && list2 != nullptr) {
            ListNode *temp1 = nullptr;
            if (list1->val <= list2->val) {
                temp1 = list1;
                list1 = list1->next;
            } else {
                temp1 = list2;
                list2 = list2->next;
            }
            temp->next = temp1;
            temp = temp1;
        }

        if (list1 != nullptr)
            temp->next = list1;
        else if (list2 != nullptr)
            temp->next = list2;

        return mergeList;
    }
};
