#include "CombinationSum.h"
#include <algorithm>
#include "myTools.h"

CombinationSum::CombinationSum(const vector<int>& vec) :data(vec)
{
}

CombinationSum::~CombinationSum()
{
}

typedef vector<int>::size_type visize;
void CombinationSum::combinationhelper(vector<vector<int> > &results, vector<int> &collect, const vector<int> &data, visize start, int target)
{
    visize numTotal = data.size();
    visize collectSize = collect.size();
    for(visize i = start; i < numTotal; ++i)
    {
        if(target < data[i])
        {
             return;
        }
        else
        {
            collect.push_back(data[i]);
            if(target == data[i])
            {
                results.push_back(collect);
            }
            else
            {
                combinationhelper(results, collect, data, i, target - data[i]);
            }
        }
        collect.resize(collectSize);
    } // for
}

// reference http://blog.csdn.net/xiaobaohe/article/details/7897966
vector<vector<int> > CombinationSum::combinationSum(int target) {
    vector<vector<int> > results;
    std::sort(data.begin(), data.end());

    vector<int> collect;
    combinationhelper(results,collect, data, 0, target);

    return results;
}

void testCombinationSum1() {
    vector<int> vec {2, 3, 6, 7};
    CombinationSum comb(vec);
    int target = 7;
    vector<vector<int> > dvec = comb.combinationSum(target);
    printDoubleVector(dvec);
}
