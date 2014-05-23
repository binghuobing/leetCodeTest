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

void LinkList::testListToBST() {

    TreeNode *p = sortedListToBST(head);
    BinaryTree tree(p);
    vector<int> vec = tree.inorderTraversal();
    printContainer(vec);
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
    //p1 points to the last node less than pivot, p2 points to the first node unprocessed
    ListNode *p1 = first;
    ListNode *p2 = first->next;

    ListNode *pivotNode = first;
    int pivot = first->val;
    while(p2 != lastA)
    {
        if (p2->val < pivot)
        {
            p1 = p1->next;
            int temp = p1->val;
            p1->val = p2->val;
            p2->val = temp;
            p2 = p2->next;
        }
        else
        {
            p2 = p2->next;
        }
    }

    // insert pivot node after p1
    ListNode *newFirst = first;
    if (newFirst != p1)
    {
        newFirst = pivotNode->next;
        pivotNode->next = p1->next;
        p1->next = pivotNode;
    }

    //if(newFirst && newFisrt != pivotNode && newFirst->next != pivotNode)
    if(newFirst && newFirst != pivotNode && newFirst->next != pivotNode)
        newFirst = partitionList(newFirst, pivotNode);
    ListNode *rightFirst = pivotNode->next;
    if (rightFirst && rightFirst != lastA && rightFirst->next != lastA)
        partitionList(rightFirst, lastA);

    return newFirst;
}

void LinkList::testQuickSort() {
    cout << *this << endl;
    quickSort();
    cout << "sorted: " << endl;
    cout << *this << endl;
}







