#include "common.h"

struct ListNode
{
    ListNode(int d)
    {
        data = d;
        next = NULL;
    }
    ListNode()
    {
        data = 0;
        next = NULL;
    }
    int data;
    struct ListNode *next = NULL;
};

void printList(struct ListNode* start)
{
    while(start)
    {
        cout << start->data << "->";
        start = start->next;
    }
    cout<< "NULL" << endl;
}

void reverseList(struct ListNode* start, struct ListNode* last, struct ListNode* nextlist)
{
    if(!start)
        return;
    struct ListNode *prev = NULL;
    struct ListNode *temp1 = start, *temp2;
    while(start!=last)
    {
        temp2 = start;
        start = start->next;
        temp2->next = prev;
        prev = temp2;
    }
    temp1->next= nextlist;

    printList(prev);
}
void InsertNode(struct ListNode *start, int val)
{
    if(!start)
        return;

    while(start->next)
        start = start->next;

    start->next = new ListNode(val);
    start->next->next = NULL;
}

void retainandDelete(ListNode *start, int M, int N)
{
    ListNode *prev;
    ListNode *temp;
    while(start)
    {
        for(int i=0;i<M;i++)
        {
            if(!start)
                return;
            prev = start;
            start = start->next;
        }

        for(int i=0;i<N;i++)
        {
            if(!start)
                break;
            temp=start;
            start = start->next;
            delete(temp);
        }
        prev->next = start;
    }
}

ListNode* mergeSortedLists(ListNode* l1, ListNode* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;

    ListNode *prev = NULL, *start;

    if(l1->data > l2->data)
        swap(l1,l2);

    start= l1;

    while(l1 && l2)
    {
        if(l1->data <= l2->data)
        {
            if(prev)
                prev->next = l1;
            prev = l1;
            l1 = l1->next;
            //printList(start);
        }
        else
        {
            prev->next = l2;
            prev = l2;
            l2 = l2->next;
            //printList(start);
        }
    }

    if(l1)
        prev->next = l1;
    if(l2)
        prev->next = l2;
    //printList(start);

    return start;
}
