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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> l1Stack, l2Stack, result;
        int carry = 0;

        while (l1) {
            l1Stack.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            l2Stack.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = nullptr;

        while (!l1Stack.empty() || !l2Stack.empty() || carry) {
            int sum = carry;

            if (!l1Stack.empty()) {
                sum += l1Stack.top();
                l1Stack.pop();
            }

            if (!l2Stack.empty()) {
                sum += l2Stack.top();
                l2Stack.pop();
            }

            carry = sum/10;

            result.push(sum % 10);

            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
        } 
        return head;
    }
};
