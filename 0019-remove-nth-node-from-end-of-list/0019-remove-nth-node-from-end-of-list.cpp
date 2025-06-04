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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr=head;
        int count=0;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;

        }
         if (n == count) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        
        // Step 3: Go to the node just before the target node
        ptr = head;
        for (int i = 0; i < count - n - 1; i++) {
            ptr = ptr->next;
        }

        // Step 4: Delete the target node
        ListNode* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;

        return head;
    }
      

    
};