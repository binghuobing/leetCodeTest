#include "ListNode.h"

ListNode::ListNode():val(0), next(0)
{
}

ListNode::ListNode(int v, ListNode *nex)
    : val(v), next(nex)
{ }

ListNode::~ListNode()
{
}
