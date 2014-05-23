#ifndef MATRIXPATH_H
#define MATRIXPATH_H
#include<vector>
#include<iostream>
using std::vector;
class MatrixPath
{

    public:
        MatrixPath();
        MatrixPath(vector<vector<int> > m);
        ~MatrixPath();
        int uniquePathsWithObstacles();
        void testUniquePathWith();
    private:
        vector<vector<int> > grid;
};

#endif // MATRIXPATH_H
