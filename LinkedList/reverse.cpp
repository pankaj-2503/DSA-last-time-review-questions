class Solution {
public:
    // reverse linked list using three pointers
    ListNode* reverseList(ListNode* head) {
        ListNode*cur=head;
        ListNode*next;
        ListNode*prev=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;

    }
};