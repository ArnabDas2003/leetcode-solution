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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Append remaining nodes
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Iteratively merge lists in pairs
        while (lists.size() > 1) {
            vector<ListNode*> newLists;

            for (int i = 0; i < lists.size(); i += 2) {
                if (i + 1 < lists.size()) {
                    newLists.push_back(mergeTwoLists(lists[i], lists[i + 1]));
                } else {
                    newLists.push_back(lists[i]); // if odd count, keep last list as is
                }
            }

            lists = newLists; // update the list with merged results
        }

        return lists[0];
    }
};