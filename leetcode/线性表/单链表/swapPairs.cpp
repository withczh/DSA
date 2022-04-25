//leetcode 24

#include "LinkedList.hpp"
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* virtualNode=new ListNode(-1);
        virtualNode->next=head;
        ListNode* cur=virtualNode;
        while(cur->next!=nullptr&&cur->next->next!=nullptr){
            ListNode* tmp=cur->next;
            ListNode* tmp1=cur->next->next->next;
            
            cur->next=cur->next->next;
            cur->next->next=tmp;
            cur->next->next->next=tmp1;
            
            cur=cur->next->next;
        }
        return virtualNode->next;
    }
};

