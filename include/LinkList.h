#ifndef LINKLIST_H
#define LINKLIST_H
#include "listNode.h"
#include "TreeNode.h"
class LinkList
{
    public:
        LinkList(ListNode *p);
        LinkList();
        virtual ~LinkList();
        TreeNode *sortedListToBST(ListNode *head);
        void testListToBST();
        ListNode *quickSort();
        void testQuickSort();

        friend std::ostream& operator<<(std::ostream& os, const LinkList& alist);
    private:
        ListNode *head;
        ListNode *partitionList(ListNode *first, ListNode *last);
};

#endif // LINKLIST_H
