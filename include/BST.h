#ifndef BST_H
#define BST_H

#include <BinaryTree.h>

using std::vector;
class BST : public BinaryTree
{
    public:
        BST();
        virtual ~BST();
        vector<TreeNode* > generateUniqueBST(int n);
        void testUniqueBST();
    private:
        vector<TreeNode* > generateUniBST(int first, int last);
};

#endif // BST_H
