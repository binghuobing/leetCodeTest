#include "Sequence.h"
#include <set>
#include<iostream>
using namespace std;

Sequence::Sequence()
{
    //ctor
}

Sequence::~Sequence()
{
    //dtor
}

Sequence::Sequence(vector<int> vec) :data(vec)
{
    //ctor
}

int Sequence::getLongestConsecutive()
{
    set<int> mySet(data.begin(), data.end() );
    size_t longest = 1;
    for( auto val : data)
    {
        size_t seqLen = 0;
        if(mySet.find(val) == mySet.end() )
            continue;
        mySet.erase(val);
        seqLen = 1;
        int tmp = val + 1;
        while(mySet.find(tmp) != mySet.end() )
        {
            mySet.erase(tmp);
            ++seqLen;
            ++tmp;
        }
        tmp = val - 1;
        while (mySet.find(tmp) != mySet.end() )
        {
            mySet.erase(tmp);
            ++seqLen;
            --tmp;
        }

        if(seqLen > longest)
            longest = seqLen;
    }
    return longest;
}

void testLongestSeqenceLen() {
    vector<int> vec = {100, 4, 200, 1, 3, 2, 33, 0};
    Sequence seqence(vec);
    cout << seqence.getLongestConsecutive() << endl;
}
