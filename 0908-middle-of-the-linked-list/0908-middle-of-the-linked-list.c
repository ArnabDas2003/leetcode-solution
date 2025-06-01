/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int count=0;
    struct ListNode *ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    
    if(count==0){
        return NULL ;
    }
    count=count/2;
    ptr=head;
    for(int i=1;i<=count;i++){
        ptr=ptr->next;
    }
    return ptr;
    
}