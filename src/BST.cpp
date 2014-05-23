#include "BST.h"

BST::BST()
{
    //ctor
}

BST::~BST()
{
    //dtor
}

vector<TreeNode* > BST::generateUniqueBST(int n)
{
    return generateUniBST( 1, n);
}

vector<TreeNode *>  BST::generateUniBST(int first, int last)
{
    if (first > last) {
        return vector<TreeNode *>(1, static_cast<TreeNode *>(NULL) );
    }

    vector<TreeNode *> ret;
    for (int mid = first; mid <= last; ++mid) {

        vector<TreeNode *> left = generateUniBST(first, mid - 1);
        vector<TreeNode *> right = generateUniBST(mid + 1, last);
        for (size_t i = 0; i < left.size(); ++i) {
            for (size_t j = 0; j < right.size(); j++) {
                TreeNode *root = new TreeNode(mid);
                root->left = left[i];
                root->right = right[j];
                ret.push_back(root);
            }
        }
    }
    return ret;
}
