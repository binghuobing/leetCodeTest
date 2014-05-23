#ifndef SUMPATH_H
#define SUMPATH_H
#include "BinaryTree.h"
using std::vector;
class SumPath: public BinaryTree
{
    public:
        SumPath();
        virtual ~SumPath();
        int sumRootToLeaves() const;
        vector<vector<int> > pathSum(int sum) const;
    private:
};

#endif // SUMPATH_H
