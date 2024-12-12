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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        for (ListNode* current = head; current != nullptr;
             current = current->next)
            st.push(current);

        ListNode* resultList = nullptr;
        int maxValue = INT_MIN;

        while (!st.empty()) {
            ListNode* current = st.top();
            st.pop();

            if (current->val >= maxValue) {
                ListNode* newNode = new ListNode(current->val);
                newNode->next = resultList;
                resultList = newNode;
                maxValue = current->val;
            }
        }

        return resultList;
    }
}
;
