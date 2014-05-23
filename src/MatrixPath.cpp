#include "MatrixPath.h"

MatrixPath::MatrixPath()
{
    //ctor
}


MatrixPath::MatrixPath(vector<vector<int> > m)
    : grid(m)
{ }

MatrixPath::~MatrixPath()
{
    //dtor
}

int MatrixPath::uniquePathsWithObstacles()
{
    vector<vector<int> > grid1(grid);
    size_t rowNum = grid1.size();
    size_t colNum = grid1[0].size();
    if (grid1[0][0] == 0)
        grid1[0][0] = 1;
    else
        grid1[0][0] = 0;
    for(size_t j = 1; j < colNum; ++j) {
        if (grid1[0][j] == 0)
            grid1[0][j] = grid1[0][j-1];
        else
            grid1[0][j] = 0;
    }
    for(size_t i = 1; i < rowNum; ++i) {
        if (grid1[i][0] == 0)
            grid1[i][0] = grid1[i - 1][0];
        else
            grid1[i][0] = 0;
    }
    for(size_t i = 1; i < rowNum; ++i) {
        for(size_t j = 1; j < colNum; ++j) {
            if(grid1[i][j] == 0)
                grid1[i][j] = grid1[i][j-1] + grid1[i-1][j];
            else
                grid1[i][j] = 0;
        }
    }
    return grid1[rowNum - 1][colNum - 1];
}

void MatrixPath::testUniquePathWith() {
    int a[3] = {0, 0, 0};
    int b[3] = {0, 1, 0};
    vector<vector<int> > dvec;
    dvec.push_back(vector<int> (a, a + 3));
    dvec.push_back(vector<int> (b, b + 3) );
    dvec.push_back(vector<int> (a, a + 3));

    MatrixPath matrix(dvec);
    std::cout << matrix.uniquePathsWithObstacles() << std::endl;
}
