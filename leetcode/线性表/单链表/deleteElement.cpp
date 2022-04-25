#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct node{
    int val;
    struct node* next;
}LNode,*LinkList;

class Solution{
    public:
    LNode* removeElements(LNode* head, int val) {
        LNode* h = head;
        LNode* p;
        while(head->next!=NULL){
            if(head->next->val==val){
               p=head->next;
               head->next=p->next;
               free(p);
            }
            else
                head=head->next;
        }
        return h;
    }
};

//尾插法创建，链表创建时设立虚拟节点
void makeList(LinkList& L){
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode* s,*r=L;
    cin>>x;
    while(x!=999){
        s=(LNode*)malloc(sizeof(LNode));
        s->val=x;
        r->next=s; //讲数据插在虚拟节点后面
        r=s;
        cin>>x;
    }
    r->next=NULL;
}

void printList(LinkList& L){
    LinkList p=L;
    while(p->next!=NULL){
        cout<<p->next->val<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    LinkList L;
    Solution s;
    LNode* p;
    makeList(L);
    printList(L);
    p=s.removeElements(L,7);
    printList(p);
    return 0;
}