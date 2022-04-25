//leetcode 142

#include "LinkedList.hpp"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode* index1=fast;
                ListNode* index2=head;
                while(index1!=index2){
                    index1=index1->next;
                    index2=index2->next;
                }
                return index1;
            }
        }
        return nullptr;
    }
};