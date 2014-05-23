#ifndef LISTNODE_H
#define LISTNODE_H


class ListNode
{
    public:
        ListNode();
        ListNode(int v, ListNode *nex);
        virtual ~ListNode();

        int val;
        ListNode *next;
};

#endif // LISTNODE_H
