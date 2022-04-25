#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include<iostream>

struct ListNode{
        int val;
        ListNode* next;
        ListNode():val(0),next(nullptr){}
        ListNode(int x):val(x),next(nullptr){}
    };

class MyLinkedList {
public:

    MyLinkedList();

    ListNode* getLinkedListVirtualHead();
    
    int get(int index);
    
    void addAtHead(int val);
    
    void addAtTail(int val);
    
    void addAtIndex(int index, int val);
    
    void deleteAtIndex(int index) ;

    void print();
    
private:
    int size;
    ListNode* virtualHead;

};


#endif