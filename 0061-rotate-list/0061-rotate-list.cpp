class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        // Step 1: Store values from linked list into a vector
        vector<int> v;
        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        int n = v.size();
        k = k % n; // Handle cases where k > n

        // Step 2: Rotate the values
        vector<int> rotated;
        for (int i = n - k; i < n; i++) {
            rotated.push_back(v[i]);
        }
        for (int i = 0; i < n - k; i++) {
            rotated.push_back(v[i]);
        }

        // Step 3: Create a new linked list from rotated values
        ListNode* newHead = new ListNode(rotated[0]);
        ListNode* curr = newHead;
        for (int i = 1; i < rotated.size(); i++) {
            curr->next = new ListNode(rotated[i]);
            curr = curr->next;
        }

        return newHead;
    }
};
