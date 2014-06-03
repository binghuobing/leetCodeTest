#ifndef COMBINATIONSUM_H
#define COMBINATIONSUM_H
#include<vector>
using std::vector;

class CombinationSum
{
    public:
        CombinationSum(const vector<int> &vec);
        virtual ~CombinationSum();

        vector<vector<int> > combinationSum(int target);
    protected:
    private:
        void combinationhelper(vector<vector<int> > &results, vector<int> &collect, const vector<int> &data, vector<int>::size_type start, int target);
        vector<int> data;
};

#endif // COMBINATIONSUM_H
