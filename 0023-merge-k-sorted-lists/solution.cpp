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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!size(lists)) return nullptr;
        vector<int> var;
        
        for (int i = 0; i < size(lists); ++i)
            while (lists[i]) {
                var.emplace_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        
        if (!size(var)) return nullptr;
        
        sort(begin(var), end(var));
        ListNode *temp[size(var)];
        
        for (int i = 0; i < size(var); ++i) temp[i] = new ListNode();
        
        for (int i = 0; i < size(var) - 1; ++i) {
            temp[i]->val = var[i];
            temp[i]->next = temp[i + 1];
        }
        temp[size(var) - 1]->val = var[size(var) - 1];
        temp[size(var) - 1]->next = nullptr;
        
        return temp[0];
    }
};
