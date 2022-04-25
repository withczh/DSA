//leetcode 19.
#include "LinkedList.hpp"
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* virtualHead=new ListNode(-1);
        virtualHead->next=head;
        ListNode* fast=virtualHead;
        ListNode* slow=virtualHead;
        while(n--){
            if(fast->next!=nullptr){
                fast=fast->next;
            }
            else{
                return ;
            }
        }
        fast=fast->next;
        while(fast!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* tmp=slow->next;
        slow->next=slow->next->next;
        delete tmp;
        return virtualHead->next;
    }
};