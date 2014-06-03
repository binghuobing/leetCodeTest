#include "LinkList.h"
#include<iostream>
#include "BinaryTree.h"
#include "myTools.h"

using namespace std;
LinkList::LinkList(ListNode *p) :head(p)
{
    //ctor
}

LinkList::LinkList() :head(NULL)
{
    cout << "in put the values in the listNodes" << endl;
    int val;
    while (cin >> val) {
        ListNode *p = new ListNode(val, head);
        head = p;
    }
}

LinkList::~LinkList()
{
    ListNode *p = head;
    while(p) {
        ListNode *pre = p;
        p = p->next;
        delete pre;
    }
}

ostream& operator<<(ostream& os, const LinkList& alist) {     // LinkList 的& 不可少，否则都被析构了
    ListNode *p = alist.head;
    while (p) {
        os << p->val << "\t";
        p = p->next;
    }
    return os << endl;
}

TreeNode * LinkList::sortedListToBST(ListNode *head) {
    ListNode *p = head, *pre = NULL, *po = head;
    while (po) {
        po = po->next;
        if(po)
            po = po->next;
        else
            break;
        pre = p;
        p = p->next;
    }
    TreeNode *root = new TreeNode(p->val);
    if (pre) {
        pre->next = NULL;
        root->left = sortedListToBST(head);
    }
    if (p->next) {
        root->right = sortedListToBST(p->next);
    }
    return root;
}

ListNode* LinkList::quickSort()
{
    if(!head || !head->next)
        return head;
    head = partitionList(head, static_cast<ListNode *>(NULL) );
    return head;
}

ListNode* LinkList::partitionList(ListNode *first, ListNode *lastA)
{
/*
    cout << "befor partition:" << endl;
    for (ListNode *r = first; r != lastA; r = r->next)
        cout << r->val << "\t";
    cout << "finish " << endl;
*/
    //p1 points to the last node less than pivot, p2 points to the first node unprocessed
    ListNode *p1 = first;
    ListNode *pre2 = first;
    ListNode *p2 = first->next;

    ListNode *pivotNode = first;
    int pivot = first->val;
    while(p2 != lastA)
    {
        //cout << "p1, pre2, p2:    " << p1->val << " " << pre2->val << " " << p2->val << endl;
        // insert p2 to the next of p1
        if (p2->val < pivot )
        {
            if (pre2 != p1)
            {
                ListNode *tmp = p2->next;
                pre2->next = tmp;
                p2->next = p1->next;
                p1->next = p2;
                p1 = p2;
                p2 = tmp;
            }
            else
            {
                pre2 = p2;
                p2 = p2->next;
                p1 = p1->next;
            }
        } else {
            pre2 = p2;
            p2 = pre2->next;
        }
    }
    pre2->next = lastA;          // link to the next

// insert pivot node after p1
    ListNode *newFirst = first;
    if (p1 != first)
    {
        newFirst = first->next;
        first->next = p1->next;
        p1->next = first;
    }
/*
    cout << "after partition:" << endl;
    for (ListNode *r = newFirst; r != lastA; r = r->next)
        cout << r->val << "\t";
    cout << "finish " << endl;
*/
//if(newFirst && newFisrt != pivotNode && newFirst->next != pivotNode)
if(newFirst && newFirst != pivotNode && newFirst->next != pivotNode)
    newFirst = partitionList(newFirst, pivotNode);
ListNode *rightFirst = pivotNode->next;
if (rightFirst && rightFirst != lastA && rightFirst->next != lastA)
    pivotNode->next = partitionList(rightFirst, lastA);

return newFirst;
}

ListNode* LinkList::mergeSort(ListNode *head) {
    if (!head || !head->next)
        return head;

    ListNode *fast = head;
    ListNode *slow = head;
    while(fast ) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }else {
            break;
        }
        slow = slow->next;
    }

    ListNode *mid = slow->next;
    slow->next = nullptr;
    ListNode *left = mergeSort(head);
    ListNode *right = mergeSort(mid);

    ListNode *p1 = left, *p2 = right;
    ListNode *newHead , *newTail;

    if (p1 && p2) {
        if( p1->val < p2->val) {
            newHead = newTail = p1;
            p1 = p1->next;
        }else {
            newHead = newTail = p2;
            p2 = p2->next;
        }
    } else if (p1) {
        return p1;
    } else {
        return p2;
    }

    while(p1 && p2) {
        if (p1->val < p2->val) {
            newTail->next = p1;
            newTail = p1;
            p1 = p1->next;
        }else {
            newTail->next = p2;
            newTail = p2;
            p2 = p2->next;
        }
    }
    if (p1) {
        newTail->next = p1;
    } else  {
        newTail->next = p2;
    }
    return newHead;
}

pair<ListNode*, ListNode *> LinkList::mergeSortIterHelper(ListNode *first1, ListNode *last1, ListNode *first2, ListNode *last2)
{
//cout << first1->val <<last1->val << first2->val << endl;
    ListNode *pEnd = last2 ? last2->next : last2;
    ListNode preheadNode(0);
    ListNode *prehead = &preheadNode;
    ListNode *tail = prehead;

    ListNode *p1 = first1, *p2 = first2;
    while( p1 != first2 && p2 != pEnd ) {
        if(p1->val < p2->val) {
            tail->next = p1;
            tail = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            tail = p2;
            p2 = p2->next;
        }
    }

    if(p1 != first2) {
        tail->next = p1;
        tail = last1;
    }
    if(p2 != pEnd) {
        tail->next = p2;
        tail = last2;
    }

    ListNode *first = prehead->next;
    if(tail)
        tail->next = pEnd;
    return pair<ListNode*, ListNode*>(first, tail);
}

ListNode* LinkList::mergeSortIter()
{
    if(!head || !head->next)
        return head;
    ListNode* prehead = new ListNode(0);
    prehead->next = head;
    int numNodes = 0;
    for (ListNode *p = head; p; p = p->next)
        ++numNodes;
    for(int step = 1; step <numNodes; step *= 2)
    {
        ListNode *tail = prehead;
        ListNode *first1 = prehead->next;
        while(true)
        {
            ListNode *last1 = first1;
            for(int i = 1; i < step; ++i)
            {
                if(!last1)
                    break;
                last1 = last1->next;
            }
            if(!last1)
                break;
            ListNode *first2 = last1->next;
            if(!first2)
                break;
            ListNode *last2 = first2;
            for(int i = 1; i < step; ++i)
            {
                if(!last2)
                    break;
                last2 = last2->next;
            }

            auto result = mergeSortIterHelper(first1, last1, first2, last2);
            tail->next = result.first;
            tail = result.second;
            if(tail) {
                first1 = tail->next;
            }else {
                break;
            }
        }
    }
    head = prehead->next;
    delete prehead;
    return head;
}

ListNode* LinkList::insertSort() {
    if(!head || !head->next)
        return head;
    ListNode *prehead = new ListNode(0);
    prehead->next = head;
    for(ListNode *pSorted = head, *pToSort = head->next; pToSort;  ) {
//cout << "pToSort: " << pToSort->val << endl;
        ListNode *pre = prehead, *p = pre->next;   // hte head has changed ,so don't use *p = head
        for (   ;p != pToSort; pre = p, p = p->next) {
            if(p->val > pToSort->val) {
                pSorted->next = pToSort->next;
                pre->next = pToSort;
                pToSort->next = p;

                pToSort = pSorted->next;
                break;
            }
        }
        if(p == pToSort) {
            pSorted = pSorted->next;
            pToSort = pToSort->next;
        }
    }
    head = prehead->next;
    delete prehead;
    return head;
}

void ListInsertSort() {
    LinkList alist;
    alist.insertSort();
    cout << alist << endl;
}

void testListMergeSortIter() {
    LinkList alist;
    alist.mergeSortIter();
    cout << alist;
}




