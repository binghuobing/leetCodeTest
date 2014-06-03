#ifndef LISTNODE_H
#define LISTNODE_H


class ListNode
{
    public:
        ListNode(int v, ListNode *nex = nullptr);
        virtual ~ListNode();

        int val;
        ListNode *next;
};

#endif // LISTNODE_H
