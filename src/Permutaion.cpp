#include "Permutation.h"
#include<iostream>
#include<vector>
#include "myTools.h"

namespace Permutation {

using namespace std;

typedef vector<int>::size_type visize;
void reverseVec(vector<int> &vec, visize first, visize last);

void nextPermutation(vector<int> &num)
{

    visize totalSize = num.size();
    if(totalSize <= 1)
        return;

    visize dropIndex = 0;
    for(visize i = totalSize - 1; i > 0; --i) {
        if(num[i] > num[i-1]) {
            dropIndex = i;
            break;
        }
    }
    if(dropIndex == 0) {
        reverseVec(num, 0, totalSize - 1);
        return;
    }
    visize changeIndex = dropIndex - 1;
    int changeNum = num[changeIndex];
    visize minLaterIndex = dropIndex;
    int minLaterNum = num[dropIndex] + 1;
    for(visize i = totalSize - 1; i > dropIndex; --i) {
        if(num[i] > changeNum && num[i] < minLaterNum) {
            minLaterNum = num[i];
            minLaterIndex = i;
        }
    }

    num[minLaterIndex] = num[changeIndex];
    num[changeIndex] = minLaterNum;
    reverseVec(num, dropIndex, totalSize - 1);
    return;
}

void reverseVec(vector<int> &vec, visize first, visize last) {
    while(first < last) {
        int tmp = vec[first];
        vec[first] = vec[last];
        vec[last] = tmp;
        ++first;
        --last;
    }
}

void testNextPermution() {
    vector<int> vec {2, 3, 1, 3, 3};
    nextPermutation(vec);
    printContainer(vec);
}

}// namespace


