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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *middle = getMiddle(head);
        ListNode *nextOfMiddle = middle->next;
        middle->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(nextOfMiddle);

        return merge(left, right);
    }

    ListNode* getMiddle(ListNode* head) {
        if (!head) return head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode *left, ListNode *right) {
        ListNode *dummyHead = new ListNode();
        ListNode *current = dummyHead;

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
            if (left) {
                current->next = left;
            } else {
                current->next = right;
            }

        ListNode *sortedHead = dummyHead->next;
        delete dummyHead;
        return sortedHead;
    }
};
