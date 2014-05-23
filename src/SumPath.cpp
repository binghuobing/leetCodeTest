#include "SumPath.h"
#include "myTools.h"
#include <stack>
SumPath::SumPath()
{
    //ctor
}

SumPath::~SumPath()
{
    //dtor
}

int SumPath::sumRootToLeaves() const
{
    // just like post order traversal
    std::stack<TreeNode *> st;
    int stackValue = 0;          // the value of all numbers in the stack combined
    int sum = 0;
    TreeNode *p = root, *pre = NULL;
    while(p || !st.empty())
    {
        while(p)
        {
            st.push(p);
            stackValue = stackValue * 10 + p->val;
            p = p->left;
        }
        pre = p;
        p = st.top();
        while(pre == p->right)
        {
            if (!p->left && !p->right)         // if p is a leaf
            {
                sum += stackValue;
            }
            st.pop();
            if(st.empty())
                return sum;
            stackValue /= 10;
            pre = p;
            p = st.top();
        }
        pre = p;
        p = p->right;
    }
    return sum;
}

vector<vector<int> > SumPath::pathSum(const int sum) const
{
    vector<vector<int> > dvec;
    vector<TreeNode* > vec;
    vector<int> ivec;
    int thisSum = 0;
    TreeNode *p = root, *pre = NULL;
    while(p || !vec.empty())
    {
        while (p)
        {
            vec.push_back(p);
            ivec.push_back(p->val);
            thisSum += p->val;
            p = p ->left;
        }
        p = vec.back();
        if (! p ->right || pre == p->right) {
            if( !p -> left && !p->right && sum == thisSum)
                dvec.push_back(ivec);
            vec.pop_back();
            ivec.pop_back();
            thisSum -= p->val;
            pre = p;
            p = NULL;
        } else {
            p = p -> right;
        }
    }
    return dvec;
}






















