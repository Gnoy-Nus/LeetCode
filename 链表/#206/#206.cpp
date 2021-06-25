class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr;
        ListNode *cur=head;
        ListNode *temp;
        while(cur!=nullptr){
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        return pre;
    }
};