#include<vector>
#include<stack>
#include "BinaryTree.h"
#include<queue>

using std::vector;
using std::stack;
using std::queue;
using std::cout;
using std::cin;
using std::endl;

BinaryTree::BinaryTree(): nodeNum(0)
{
    root = createTree();
}

BinaryTree::BinaryTree(TreeNode *h): nodeNum(0), root(h)
{
}


BinaryTree::~BinaryTree()
{
    if (root) {
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty()) {
            TreeNode *p = que.front();
            if(p->left)
                que.push(p->left);
            if(p->right)
                que.push(p->right);
            delete p;
        }
    }
}

TreeNode* BinaryTree::createTree()
{
    int n;
    cout << "number of nodes (include empty node) : " << endl ;
    cin >> n;

    if ( n <= 0)
        return NULL;

    cout << "integer array (0 denotes empty node) : " << endl;
    int *a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    queue<TreeNode *> que;
    TreeNode *root = new TreeNode(a[0]);
    this -> nodeNum ++;

    que.push(root);
    int i = 1;
    while ( !que.empty() )
    {
        TreeNode *p = que.front();
        que.pop();
        if (i < n && a[i++] != 0)
        {
            TreeNode *left = new TreeNode(a[i-1]);
            que.push(left);
            p->left = left;
        }
        if (i < n && a[i++] != 0)
        {
            TreeNode *right = new TreeNode(a[i-1]);
            que.push(right);
            p->right = right;
        }
    }
    return root;
}

vector<int> BinaryTree::postorderTraversal() const
{
    vector<int> vec;
    stack<TreeNode*> st;
    TreeNode *p = this -> root, *preVisit = NULL;
    while(p || !st.empty())
    {
        while(p)
        {
            st.push(p);
            p = p->left;
        }
        preVisit = p;
        p = st.top();
        while(preVisit == p->right)    // right child is visited
        {
            vec.push_back(p->val);

            st.pop();
            if(st.empty())
            {
                return vec;
            }
            preVisit = p;
            p = st.top();
        }
        p = p->right;
    }
    return vec;
}

vector<int> BinaryTree::preorderTraversal() const
{
    vector<int> vec;
    stack<TreeNode*> st;
    TreeNode *p = this -> root;
    while(p || !st.empty())
    {
        while (p)
        {
            vec.push_back(p->val);
            st.push(p);
            p = p->left;
        }
        if (!st.empty())
        {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
    return vec;
}

vector<int> BinaryTree::inorderTraversal() const {
        // better version
        vector<int> vec;
        if (!root)
            return vec;
        stack<TreeNode *> stk;
        TreeNode *p = root;
        while (p || !stk.empty() ) {
            if (p) {
                stk.push(p);
                p = p->left;
            } else {
                p = stk.top();
                stk.pop();
                vec.push_back(p->val);
                p = p->right;
            }
        }
        return vec;
    }



