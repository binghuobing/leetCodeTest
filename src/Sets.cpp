#include "Sets.h"
#include <algorithm>

Sets::~Sets()
{
    //dtor
}

vector<vector<int> > Sets::subsets() {
    vector<vector<int> > dvec;
    vector<int> emptyVec;
    dvec.push_back(emptyVec);
    vsize len = vec.size();
    for (vsize i = 0; i < len; i++) {
        dvsize oldSize = dvec.size();
        for (dvsize j = 0; j < oldSize; ++j) {
            vector<int> tmp(dvec[j]);
            tmp.push_back(vec[i]);
            dvec.push_back(tmp);
        }
    }
    dvsize endLen = dvec.size();
    for (dvsize i = 0; i < endLen; ++i) {
        std::sort(dvec[i].begin(), dvec[i].end());
    }
    return dvec;
}
