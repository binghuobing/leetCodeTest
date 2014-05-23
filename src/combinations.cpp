#include <vector>

using namespace std;

vector<vector<int> > combine(int n, int k)
{

    typedef vector<vector<int> >::iterator dvec_iter;
    vector<vector<int> > dvec;
    if (n < k)
        return dvec;

    if (k == 1)
    {
        for (int i = 1; i <=n ; i++)
        {
            dvec.push_back(vector<int>(1, i) );
        }
        return dvec;
    }

    for (int i = n; i >= k; i--)          // the biggest num of the line is i
    {
        vector<vector<int> > dvec1 = combine(i - 1, k - 1);
        for(dvec_iter iter = dvec1.begin(); iter != dvec1.end(); iter++)
        {
            iter->push_back(i);
            dvec.push_back(*iter);
        }
    }
    return dvec;
}
