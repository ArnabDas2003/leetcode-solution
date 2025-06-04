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
        ListNode* head = NULL;    // Head of the result list
    ListNode* tail = NULL;    // Tail to keep adding nodes
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry > 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        ListNode* newNode = new ListNode(digit);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;

        
    }

    void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val;
        if (node->next != NULL) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}
};