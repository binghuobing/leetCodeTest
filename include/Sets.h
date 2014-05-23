#ifndef SETS_H
#define SETS_H

#include<vector>
using std::vector;
class Sets
{

    typedef vector<int>::iterator vIter;
    typedef vector<int>::size_type vsize;
    typedef vector<vector<int> >::size_type dvsize;
    public:
        Sets(vector<int> v): vec(v) {}
        virtual ~Sets();
        vector<vector<int> > subsets();
    private:
        vector<int> vec;
};

#endif // SETS_H
