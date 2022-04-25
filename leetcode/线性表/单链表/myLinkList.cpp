//leetcode 707.

#include "LinkedList.hpp"
MyLinkedList::MyLinkedList(){
    virtualHead=new ListNode(-1);
}
ListNode* MyLinkedList::getLinkedListVirtualHead(){
    return virtualHead;
}
int MyLinkedList::get(int index){

    if(index>(size-1)||index<0){
        return -1;
    }
    ListNode* cur=virtualHead->next;
    while(index--){
        cur=cur->next;
    }
    return cur->val;
}

void MyLinkedList::addAtHead(int val){
    ListNode* newNode=new ListNode(val);
    newNode->next=virtualHead->next;
    virtualHead->next=newNode;
    size++;
}

void MyLinkedList::addAtTail(int val){
    ListNode* newNode=new ListNode(val);
    ListNode* current=virtualHead;
    while(current->next!=nullptr){
        current=current->next;
    }

    current->next=newNode;
    size++;
}

void MyLinkedList::addAtIndex(int index,int val){
    if(index>size){
        return;
    }
    ListNode* newNode=new ListNode(val);
    ListNode* current=virtualHead;
    while(index--){
        current=current->next;
    }
    newNode->next=current->next;
    current->next=newNode;
    size++;
}

void MyLinkedList::deleteAtIndex(int index){
    if(index>(size-1)||index<0){
        return ;
    }
    ListNode* cur=virtualHead;
    while(index--){
        cur=cur->next;
    }
    ListNode* tmp=cur->next;
    cur->next=cur->next->next;
    delete tmp;
    size--;
}

void MyLinkedList::print(){
    
    ListNode* cur=virtualHead->next;
    while(cur!=nullptr){
        std::cout<<cur->val<<"->";
        cur=cur->next;
    }
    std::cout<<"NULL"<<std::endl;
}

// class MyLinkedList {
// public:

//     struct LinkedNode{
//         int val;
//         LinkedNode* next;
//         LinkedNode():val(0),next(nullptr){}
//         LinkedNode(int x):val(x),next(nullptr){}
//     };

//     MyLinkedList() {
//         virtualHead=new LinkedNode(-1);
//         size=0;
//     }
    
//     int get(int index) {
//         if(index>(size-1)||index<0){
//             return -1;
//         }
//         LinkedNode* cur=virtualHead->next;
//         while(index--){
//             cur=cur->next;
//         }
//         return cur->val;
//     }
    
//     void addAtHead(int val) {
//         LinkedNode* newNode=new LinkedNode(val);
//         newNode->next=virtualHead->next;
//         virtualHead->next=newNode;
//         size++;
//     }
    
//     void addAtTail(int val) {
//         LinkedNode* newNode=new LinkedNode(val);
//         LinkedNode* current=virtualHead;
//         while(current->next!=nullptr){
//             current=current->next;
//         }
//         current->next=newNode;
//         size++;
//     }
    
//     void addAtIndex(int index, int val) {
//         if(index>size){
//             return ;
//         }
//         LinkedNode* newNode=new LinkedNode(val);
//         LinkedNode* current=virtualHead;
//         while(index--){
//             current=current->next;
//         }
//         newNode->next=current->next;
//         current->next=newNode;
//         size++;
//     }
    
//     void deleteAtIndex(int index) {
//         if(index>(size-1)||index<0){
//             return;
//         }
//         LinkedNode* cur=virtualHead;
//         while(index--){
//             cur=cur->next;
//         }
//         LinkedNode* tmp=cur->next;
//         cur->next=cur->next->next;
//         delete tmp;
//         size--;
        
//     }

//     void print(){
//         LinkedNode* cur=virtualHead->next;
//         while(cur!=nullptr){
//             cout<<cur->val<<"->";
//             cur=cur->next;
//         }
//         cout<<"NULL"<<endl;
//     }

    

// private:
//     int size;
//     LinkedNode* virtualHead;

// };

