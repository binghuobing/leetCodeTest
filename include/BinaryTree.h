// LeetCodeLib.h

#pragma once
#include "TreeNode.h"
#include <vector>

class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(TreeNode* root);
    std::vector<int> preorderTraversal() const;
    std::vector<int> postorderTraversal()const;
    std::vector<int> inorderTraversal() const;

    virtual ~BinaryTree();
protected:
    TreeNode *root;
    int nodeNum;
private:
    TreeNode *createTree();
};

