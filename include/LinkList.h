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

        ListNode *quickSort();
        ListNode *mergeSort(ListNode *h);
        ListNode *mergeSortIter();
        ListNode *insertSort();

        friend std::ostream& operator<<(std::ostream& os, const LinkList& alist);
    private:
        ListNode *head;
        ListNode *partitionList(ListNode *first, ListNode *last);
        std::pair<ListNode*, ListNode *> mergeSortIterHelper(ListNode *first1, ListNode *last1, ListNode *first2, ListNode *last2);
};

#endif // LINKLIST_H
