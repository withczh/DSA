//链表相交
#include<LinkedList.hpp>
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA=headA;
        ListNode* curB=headB;
        int sizeA=0,sizeB=0;
        while(curA!=nullptr){
            sizeA++;
            curA=curA->next;
        }
        while(curB!=nullptr){
            sizeB++;
            curB=curB->next;
        }

        curA=headA;
        curB=headB;

        if(sizeB>sizeA){
            swap(sizeA,sizeB);
            swap(curA,curB);
        }

        int gap=sizeA-sizeB;
        while(gap--){
            curA=curA->next;
        }

        while(curA!=nullptr){
            if(curA==curB){
                return curA;
            }
            curA=curA->next;
            curB=curB->next;
        }

        return nullptr;
        
    }
};